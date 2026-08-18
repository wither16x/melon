#include "Internal/Memory/CString.hpp"
#include "Exceptions.hpp"

#include <string.h>

namespace Melon::Memory
{
        CString::CString(const char *s)
                : data(const_cast<char *>(s))
        {}

        Typing::USize CString::length(this const CString &self)
        {
                return strlen(self.data);
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

        char CString::operator [](this const CString &self, Typing::USize index)
        {
                Typing::USize length = strlen(self.data);
                if (index >= length)
                        throw Exceptions::OutOfRange(index, length);

                return self.data[index];
        }
} // namespace Melon::Memory