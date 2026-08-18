#pragma once

#include "../../Typing.hpp"
#include "../../Exceptions.hpp"

#include <string.h>
#include <type_traits>

/// @brief Contains various classes and functions for memory management.
namespace Melon::Memory 
{
        /// @brief Container for raw memory.
        ///
        /// This container stores allocated raw memory and the size of the allocated area.
        /// Know that as you can see below, `T` must be trivially constructible.
        template<typename T>
                requires std::is_trivially_constructible_v<T>
        class Buffer
        {
                T *data;
                Typing::USize __size;

        public:
                /// @brief Constructs the buffer from existing raw memory.
                /// @param data memory to construct the buffer from
                /// @param size maximum size of the buffer
                Buffer(T *data, Typing::USize size)
                        : data(data), __size(size)
                {}

                /// @brief Copies some objects from here to another buffer.
                /// @param dest destination buffer
                /// @param size object count
                /// @return destination buffer
                Buffer<T> &copy(this const Buffer<T> &self, Buffer<T> &dest, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);
                        if (size > dest.__size)
                                throw Exceptions::BufferOverflow(size, dest.__size);

                        memcpy(dest.data, self.data, size);

                        return dest;
                }

                /// @brief Sets some objects from this buffer to a given value.
                /// @param c value to set
                /// @param size object count
                /// @return self
                Buffer<T> &set(this Buffer<T> &self, T c, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);

                        memset(self.data, c, size);

                        return self;
                }

                /// @brief Moves some objects from here to another buffer.
                ///
                /// This method is similar to copy() but it prevents both buffers
                /// from overlapping.
                /// @param dest destination buffer
                /// @param size object count
                /// @return destination buffer
                Buffer<T> &move(this const Buffer<T> &self, Buffer<T> &dest, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);
                        if (size > dest.__size)
                                throw Exceptions::BufferOverflow(size, dest.__size);

                        memmove(dest.data, self.data, size);

                        return dest;
                }

                /// @brief Compares some objects between this buffer and another one.
                /// @param other buffer to compare
                /// @param size object count
                /// @return <0 if self < dest, 0 if self == dest and >0 if self > dest
                int compare(this const Buffer<T> &self, const Buffer<T> &other, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);
                        if (size > other.__size)
                                throw Exceptions::BufferOverflow(size, other.__size);

                        int result = memcmp(self.data, other.data, size);

                        return result;
                }

                /// @brief Gets a constant pointer to the raw memory.
                /// @return constant raw buffer
                const T *get(this const Buffer<T> &self)
                {
                        return self.data;
                }

                /// @brief Gets the size of the buffer.
                /// @return buffer size
                Typing::USize size(this const Buffer<T> &self)
                {
                        return self.__size;
                }

                /// @brief Checks if a buffer has same size and same content.
                /// @param other other buffer
                /// @return comparison result
                bool operator ==(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        return self.__size == other.__size and self.compare(other, self.__size) == 0;
                }

                /// @brief Checks if a buffer does not have same size or same content.
                /// @param other other buffer
                /// @return comparison result
                bool operator !=(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        return not (self == other);
                }

                /// @brief Checks if this buffer is smaller than another.
                /// @param other other buffer
                /// @return comparison result
                bool operator <(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        Typing::USize size = self.__size < other.__size ? self.__size : other.__size;
                        int result = self.compare(other, size);
                        if (result != 0)
                                return result < 0;
                        return self.__size < other.__size;
                }

                /// @brief Checks if this buffer is bigger than another.
                /// @param other other buffer
                /// @return comparison result
                bool operator >(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        Typing::USize size = self.__size < other.__size ? self.__size : other.__size;
                        int result = self.compare(other, size);
                        if (result != 0)
                                return result > 0;
                        return self.__size > other.__size;
                }

                /// @brief Checks if this buffer is smaller than or equals another.
                /// @param other other buffer
                /// @return comparison result
                bool operator <=(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        return self < other or self == other;
                }

                /// @brief Checks if this buffer is bigger than or equals another.
                /// @param other other buffer
                /// @return comparison result
                bool operator >=(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        return self > other or self == other;
                }

                /// @brief Gets an object from the buffer.
                ///
                /// The object is returned by index. If the index is too high,
                /// Exceptions::OutOfRange will be thrown.
                /// @param index position of the object in the buffer
                const T &operator [](this const Buffer<T> &self, Typing::USize index)
                {
                        if (index >= self.__size)
                                throw Exceptions::OutOfRange(index, self.__size);

                        return self.data[index];
                }
        };
} // namespace Melon::Memory