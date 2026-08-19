#pragma once

#include "Internal/Memory/Buffer.hpp"

#include "Typing.hpp"

namespace Melon::Vector
{
        /// @brief A linear dynamic generic container.
        template<typename T>
        class Vector
        {
                Memory::Buffer<T> buf;
                Typing::USize obj_count;
                Typing::USize __capacity;

        public:
                /// @brief Default constructor.
                ///
                /// Allocates minimal space to store the buffer.
                Vector()
                        : obj_count(0), __capacity(1)
                {
                        this->buf = Memory::Buffer<T>(new T[this->__capacity], this->__capacity);
                }

                /// @brief Constructs the vector from existing objects.
                /// @param objects array of objects
                template<Typing::USize N>
                Vector(const T (&objects)[N])
                {
                        this->__capacity = N;
                        this->buf = Memory::Buffer<T>(new T[this->__capacity], this->__capacity);

                        for (Typing::USize i = 0; i < N; i++) {
                                this->buf[i] = objects[i];
                                ++this->obj_count;
                        }
                }

                /// @brief Destructor.
                ~Vector()
                {
                        // TODO
                }

                /// @brief Gets a pointer to the internal buffer.
                /// @return constant pointer to the internal buffer
                const T *data(this const Vector<T> &self)
                {
                        return self.buf.get();
                }

                /// @brief Gets the length of the vector.
                /// @return object count
                Typing::USize length(this const Vector<T> &self)
                {
                        return self.obj_count;
                }

                /// @brief Gets the capacity of the vector.
                /// @return capacity
                Typing::USize capacity(this const Vector<T> &self)
                {
                        return self.__capacity;
                }

                /// @brief Gets an object from the vector.
                /// @param index object position
                T &operator [](this Vector<T> &self, Typing::USize index)
                {
                        return self.buf[index];
                }
        };
} // namespace Melon::Vector