#pragma once

#include "Vector.hpp"

namespace Melon::String
{
        class String
        {
                Vector::Vector<char> chars;

        public:
                String(const char *s);
        };
} // namespace Melon::String