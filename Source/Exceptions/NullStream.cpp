#include <Internal/Exceptions/NullStream.hpp>

namespace Melon::Exceptions
{
        NullStream::NullStream()
        {}

        const char *NullStream::what() const noexcept
        {
                const char *message = "stream is null";
                return message;
        }
} // namespace Melon::Exceptions