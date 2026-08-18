#include "Internal/Memory/CString.hpp"
#include "Exceptions.hpp"
#include "Typing.hpp"

#include <string.h>

namespace Melon::Memory
{
        CString::CString(const char *s)
        {
                this->data = new char[strlen(s) + 1];
                strncpy(data, s, strlen(s) + 1);
        }

        CString::~CString()
        {
                if (this->data)
                        delete[] this->data;
        }

        CString &CString::copy(this const CString &self, CString &dest, Typing::USize chars)
        {
                strncpy(dest.data, self.data, chars);
                return dest;
        }

        Typing::USize CString::length(this const CString &self)
        {
                return strlen(self.data);
        }

        const char *CString::get(this const CString &self)
        {
                return self.data;
        }

        bool CString::operator ==(this const CString &self, const CString &other)
        {
                return strcmp(self.data, other.data) == 0;
        }

        bool CString::operator !=(this const CString &self, const CString &other)
        {
                return strcmp(self.data, other.data) != 0;
        }

        bool CString::operator <(this const CString &self, const CString &other)
        {
                return strcmp(self.data, other.data) < 0;
        }

        bool CString::operator >(this const CString &self, const CString &other)
        {
                return strcmp(self.data, other.data) > 0;
        }

        bool CString::operator <=(this const CString &self, const CString &other)
        {
                return self < other or self == other;
        }

        bool CString::operator >=(this const CString &self, const CString &other)
        {
                return self > other or self == other;
        }

        char &CString::operator [](this CString &self, Typing::USize index)
        {
                Typing::USize length = strlen(self.data);
                if (index >= length)
                        throw Exceptions::OutOfRange(index, length);

                return self.data[index];
        }
} // namespace Melon::Memory