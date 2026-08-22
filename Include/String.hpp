#pragma once

#include "Vector.hpp"
#include "Typing.hpp"

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

                /// @brief Gets a character from its index.
                /// @param index position of the character
                /// @return character
                char &operator [](this String &self, Typing::USize index);
        };
} // namespace Melon::String