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

                        Typing::USize i = 0;
                        for (; i < N; i++)
                                this->buf[i] = objects[i];
                        this->obj_count = i;
                }

                /// @brief Destructor.
                ~Vector()
                {
                        // TODO
                }

                /// @brief Gets a pointer to the base of the data.
                /// @return constant pointer to base of data
                const T *begin(this const Vector<T> &self)
                {
                        return self.buf.begin();
                }

                /// @brief Gets a pointer to the end of the data.
                /// @return constant pointer to end of data
                const T *end(this const Vector<T> &self)
                {
                        return self.buf.end();
                }

                /// @brief Add an element to the end of the vector.
                ///
                /// If the number of objects in the vector exceeds the vector's capacity,
                /// the buffer is extended to two times the current capacity.
                /// @param object object to add
                void pushBack(this Vector<T> &self, const T &object)
                {
                        if (self.obj_count >= self.__capacity)
                                self.buf.resize(self.__capacity * 2);

                        self.buf[self.obj_count++] = object;
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

                /// @brief Checks if the vector is empty.
                /// @return boolean
                bool isEmpty(this const Vector<T> &self)
                {
                        return self.obj_count == 0;
                }

                /// @brief Gets an object from the vector.
                /// @param index object position
                T &operator [](this Vector<T> &self, Typing::USize index)
                {
                        return self.buf[index];
                }
        };
} // namespace Melon::Vector