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
        };
} // namespace Melon::Vector