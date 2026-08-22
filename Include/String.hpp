#pragma once

#include "Vector.hpp"

namespace Melon::String
{
        /// @brief A dynamic string.
        class String
        {
                Vector::Vector<char> chars;

        public:
                /// @brief Constructs the string from a raw char pointer.
                /// @param s raw char pointer
                String(const char *s);

                /// @brief Gets a raw buffer which contains the string characters.
                /// @return constant char pointer
                const char *raw(this const String &self);
        };
} // namespace Melon::String