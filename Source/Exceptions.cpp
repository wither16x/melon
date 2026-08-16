#include "Exceptions.hpp"

namespace Melon::Exceptions
{
        BufferOverflow::BufferOverflow(const char *message)
                : message(message)
        {}

        const char *BufferOverflow::what() const noexcept
        {
                return this->message;
        }
} // namespace Melon::Exceptions