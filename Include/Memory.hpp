#pragma once

#include "Typing.hpp"

namespace Melon::Memory {

        template<typename T>
        class Buffer
        {
                T *data;
                Typing::Size size;

        public:
                Buffer(T *data, Typing::Size size)
                        : data(data), size(size)
                {}

                T *copy(this Buffer<T> &self, T *dest, const T *src, Typing::Size size)
                {
                        if (size > self.size)
                                return nullptr;

                        T *pdest = dest;
                        const T *psrc = src;

                        for (Typing::Size i = 0; i < size; i++)
                                pdest[i] = psrc[i];

                        return dest;
                }

                T *set(this Buffer<T> &self, T *s, int c, Typing::Size size)
                {
                        // TODO
                }

                T *move(this Buffer<T> &self, T *dest, const T *src, Typing::Size size)
                {
                        // TODO
                }

                int compare(this const Buffer<T> &self, const Buffer<T> &s2, Typing::Size size)
                {
                        // TODO
                }

                const T *get(this const Buffer<T> &self)
                {
                        return self.data;
                }
        };
} // namespace Melon::Memory