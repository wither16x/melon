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

                /// @brief Gets the length of the string.
                /// @return internal vector length
                Typing::USize length(this const String &self);

                /// @brief Gets a character from its index.
                /// @param index position of the character
                /// @return character
                char &operator [](this String &self, Typing::USize index);

                /// @brief Checks if both strings are the same.
                /// @param other string to compare
                /// @return boolean
                bool operator ==(this const String &self, const String &other);

                /// @brief Checks if both strings are different.
                /// @param other string to compare
                /// @return boolean
                bool operator !=(this const String &self, const String &other);

                /// @brief Checks if this string is smaller than another.
                /// @param other string to compare
                /// @return boolean
                bool operator <(this const String &self, const String &other);

                /// @brief Checks if this string is bigger than another.
                /// @param other string to compare
                /// @return boolean
                bool operator >(this const String &self, const String &other);

                /// @brief Checks if this string is smaller than another or if both have the same size.
                /// @param other string to compare
                /// @return boolean
                bool operator <=(this const String &self, const String &other);

                /// @brief Checks if this string is bigger than another or if both have the same size.
                /// @param other string to compare
                /// @return boolean
                bool operator >=(this const String &self, const String &other);
        };
} // namespace Melon::String