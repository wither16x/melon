#pragma once

#include "Typing.hpp"

namespace Melon::Vector
{
        /// @brief A linear dynamic generic container.
        template<typename T>
        class Vector
        {
                T *buf;
                Typing::USize obj_count;
                Typing::USize __capacity;

        public:
                /// @brief Default constructor.
                ///
                /// Allocates minimal space to store the buffer.
                Vector()
                        : buf(new T[1]), obj_count(0), __capacity(1)
                {}

                /// @brief Destructor.
                ///
                /// Frees the buffer if it is not null.
                ~Vector()
                {
                        if (this->buf)
                                delete[] buf;
                }

                /// @brief Gets a pointer to the internal buffer.
                /// @return constant pointer to the internal buffer
                const T *data(this const Vector<T> &self)
                {
                        return self.buf;
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