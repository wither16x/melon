#include "Internal/Memory/CString.hpp"

namespace Melon::Memory
{
        CString::CString(const char *s)
                : data(const_cast<char *>(s))
        {}
} // namespace Melon::Memory