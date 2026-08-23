#include <String.hpp>
#include <Typing.hpp>

namespace Melon::String
{
        String::String()
        {
                this->chars.pushBack('\0');
        }

        String::String(const char *s)
        {
                while (*s)
                        this->chars.pushBack(*s++);
                this->chars.pushBack('\0');
        }

        String::String(const String &other)
        {
                this->chars = other.chars;
        }

        String::String(String &&other)
        {
                this->chars = other.chars;
                other.chars.clear();
        }

        const char *String::raw(this const String &self)
        {
                return self.chars.data();
        }

        Typing::USize String::length(this const String &self)
        {
                return strlen(self.chars.data());
        }

        char &String::operator [](this String &self, Typing::USize index)
        {
                return self.chars[index];
        }

        const char &String::operator [](this const String &self, Typing::USize index)
        {
                return self.chars[index];
        }

        bool String::operator ==(this const String &self, const String &other)
        {
                return strcmp(self.chars.data(), other.chars.data()) == 0;
        }

        bool String::operator !=(this const String &self, const String &other)
        {
                return strcmp(self.chars.data(), other.chars.data()) != 0;
        }

        bool String::operator <(this const String &self, const String &other)
        {
                return strcmp(self.chars.data(), other.chars.data()) < 0;
        }

        bool String::operator >(this const String &self, const String &other)
        {
                return strcmp(self.chars.data(), other.chars.data()) > 0;
        }

        bool String::operator <=(this const String &self, const String &other)
        {
                return strcmp(self.chars.data(), other.chars.data()) <= 0;
        }

        bool String::operator >=(this const String &self, const String &other)
        {
                return strcmp(self.chars.data(), other.chars.data()) >= 0;
        }

        String String::operator +(this const String &self, const String &other)
        {
                String tmp = self;

                tmp.chars.popBack(); // remove null terminator
                for (Typing::USize i = 0; i < other.length(); ++i)
                        tmp.chars.pushBack(other.chars[i]);
                tmp.chars.pushBack('\0');

                return tmp;
        }

        String &String::operator =(this String &self, const String &other)
        {
                if (self != other)
                        self.chars = other.chars;

                return self;
        }

        String &String::operator =(this String &self, String &&other)
        {
                if (self != other) {
                        self.chars = other.chars;
                        other.chars.clear();
                }

                return self;
        }

        String &String::operator +=(this String &self, const String &other)
        {
                self = self + other;
                return self;
        }
} // namespace Melon::String