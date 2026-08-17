#pragma once

#include "Typing.hpp"
#include "Exceptions.hpp"

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
                Buffer(T *data, Typing::USize size)
                        : data(data), __size(size)
                {}

                Buffer<T> &copy(this Buffer<T> &self, Buffer<T> &dest, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);
                        if (size > dest.__size)
                                throw Exceptions::BufferOverflow(size, dest.__size);

                        memcpy(dest.data, self.data, size);

                        return dest;
                }

                Buffer<T> &set(this Buffer<T> &self, T c, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);

                        memset(self.data, c, size);

                        return self;
                }

                Buffer<T> &move(this Buffer<T> &self, Buffer<T> &dest, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);
                        if (size > dest.__size)
                                throw Exceptions::BufferOverflow(size, dest.__size);

                        memmove(dest.data, self.data, size);

                        return dest;
                }

                int compare(this const Buffer<T> &self, const Buffer<T> &other, Typing::USize size)
                {
                        if (size > self.__size)
                                throw Exceptions::BufferOverflow(size, self.__size);
                        if (size > other.__size)
                                throw Exceptions::BufferOverflow(size, other.__size);

                        int result = memcmp(self.data, other.data, size);

                        return result;
                }

                const T *get(this const Buffer<T> &self)
                {
                        return self.data;
                }

                Typing::USize size(this const Buffer<T> &self)
                {
                        return self.__size;
                }

                bool operator ==(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        return self.__size == other.__size and self.compare(other, self.__size) == 0;
                }

                bool operator <(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        Typing::USize size = self.__size < other.__size ? self.__size : other.__size;
                        int result = self.compare(other, size);
                        if (result != 0)
                                return result < 0;
                        return self.__size < other.__size;
                }

                bool operator >(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        Typing::USize size = self.__size < other.__size ? self.__size : other.__size;
                        int result = self.compare(other, size);
                        if (result != 0)
                                return result > 0;
                        return self.__size > other.__size;
                }

                bool operator <=(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        return self < other or self == other;
                }

                bool operator >=(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        return self > other or self == other;
                }
        };
} // namespace Melon::Memory