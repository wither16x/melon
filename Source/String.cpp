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

        String String::substract(this String &self, Typing::USize chars)
        {
                String tmp = self;

                tmp.chars.popBack(); // remove null terminator
                for (Typing::USize i = 0; i < chars; i++)
                        tmp.chars.popBack();
                tmp.chars.pushBack('\0'); // add null terminator

                return tmp;
        }

        const char *String::raw(this const String &self)
        {
                return self.chars.data();
        }

        Typing::USize String::length(this const String &self)
        {
                return strlen(self.chars.data());
        }

        const char *String::begin(this const String &self)
        {
                return self.chars.begin();
        }

        const char *String::end(this const String &self)
        {
                return self.chars.end();
        }

        void String::appendChar(this String &self, char ch)
        {
                self.chars.popBack();
                self.chars.pushBack(ch);
                self.chars.pushBack('\0');
        }

        String &String::reverse(this String &self)
        {
                Typing::USize l = 0;
                Typing::USize r = self.length() - 1;
                char t;

                while (l < r) {
                        t = self[l];
                        self[l] = self[r];
                        self[r] = t;

                        ++l;
                        --r;
                }

                return self;
        }

        String &String::ltrim(this String &self, char ch)
        {
                Typing::USize i = 0;

                while (self[i] == ch)
                        self.chars.erase(i);

                return self;
        }

        String &String::rtrim(this String &self, char ch)
        {
                Typing::USize i = 0;

                while (self[i] != ch)
                        ++i;

                while (self[i] == ch)
                        self.chars.erase(i);

                return self;
        }

        String &String::trim(this String &self, char ch)
        {
                self.ltrim(ch);
                self.rtrim(ch);
                return self;
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