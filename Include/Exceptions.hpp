#pragma once

#include <exception>

namespace Melon::Exceptions
{
        class BufferOverflow : public std::exception
        {
                const char *message;

        public:
                BufferOverflow(const char *message);

                const char *what() const noexcept;
        };
} // namespace Melon::Exceptions