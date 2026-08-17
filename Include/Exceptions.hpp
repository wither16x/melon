#pragma once

#include "Typing.hpp"

#include <exception>

namespace Melon::Exceptions
{
        class BufferOverflow : public std::exception
        {
                Typing::USize requested_size;
                Typing::USize buffer_size;

        public:
                BufferOverflow(Typing::USize requested_size, Typing::USize buffer_size);

                const char *what() const noexcept;
        };
} // namespace Melon::Exceptions