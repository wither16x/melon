#include <String.hpp>
#include <Typing.hpp>

namespace Melon::String
{
        String::String(const char *s)
        {
                while (*s)
                        this->chars.pushBack(*s++);
        }

        const char *String::raw(this const String &self)
        {
                return self.chars.data();
        }
} // namespace Melon::String