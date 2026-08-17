#pragma once

#include "Typing.hpp"

#include <exception>

namespace Melon::Exceptions
{
        class BufferOverflow : public std::exception
        {
                Typing::Size requested_size;
                Typing::Size buffer_size;

        public:
                BufferOverflow(Typing::Size requested_size, Typing::Size buffer_size);

                const char *what() const noexcept;
        };
} // namespace Melon::Exceptions