#include <String.hpp>
#include <Typing.hpp>

namespace Melon::String
{
        String::String(const char *s)
        {
                while (*s)
                        this->chars.pushBack(*s++);
        }
} // namespace Melon::String