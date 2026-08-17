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
                Typing::Size size;

        public:
                Buffer(T *data, Typing::Size size)
                        : data(data), size(size)
                {}

                Buffer<T> &copy(this Buffer<T> &self, Buffer<T> &dest, Typing::Size size)
                {
                        if (size > self.size)
                                throw Exceptions::BufferOverflow(size, self.size);

                        memcpy(dest.data, self.data, size);

                        return dest;
                }

                Buffer<T> &set(this Buffer<T> &self, T c, Typing::Size size)
                {
                        if (size > self.size)
                                throw Exceptions::BufferOverflow(size, self.size);

                        memset(self.data, c, size);

                        return self;
                }

                Buffer<T> &move(this Buffer<T> &self, Buffer<T> &dest, Typing::Size size)
                {
                        if (size > self.size)
                                throw Exceptions::BufferOverflow(size, self.size);

                        memmove(dest.data, self.data, size);

                        return self;
                }

                int compare(this const Buffer<T> &self, const Buffer<T> &other, Typing::Size size)
                {
                        if (size > self.size)
                                throw Exceptions::BufferOverflow(size, self.size);
                        if (size > other.size)
                                throw Exceptions::BufferOverflow(size, other.size);

                        int result = memcmp(self.data, other.data, size);

                        return result;
                }

                const T *get(this const Buffer<T> &self)
                {
                        return self.data;
                }
        };
} // namespace Melon::Memory