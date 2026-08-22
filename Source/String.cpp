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

        Typing::USize String::length(this const String &self)
        {
                return self.chars.length();
        }

        char &String::operator [](this String &self, Typing::USize index)
        {
                return self.chars[index];
        }

        bool String::operator ==(this const String &self, const String &other)
        {
                return strcmp(self.chars.data(), other.chars.data()) == 0;
        }
} // namespace Melon::String