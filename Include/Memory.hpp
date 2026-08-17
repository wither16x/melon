#pragma once

#include "Typing.hpp"
#include "Exceptions.hpp"

#include <string.h>

namespace Melon::Memory 
{
        template<typename T>
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

                        memmove(dest.data, self.data, size);

                        return self;
                }

                int compare(this const Buffer<T> &self, const Buffer<T> &other, Typing::USize size)
                {
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
                        return self.compare(other, self.__size) == 0;
                }

                bool operator <(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        Typing::USize size = sizeof(self.data) < sizeof(other.data)
                                ? sizeof(self.data)
                                : sizeof(other.data);
                        return self.compare(other, size) < 0;
                }

                bool operator >(this const Buffer<T> &self, const Buffer<T> &other)
                {
                        Typing::USize size = sizeof(self.data) < sizeof(other.data)
                                ? sizeof(self.data)
                                : sizeof(other.data);
                        return self.compare(other, size) > 0;
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