#pragma once

#include "../../Typing.hpp"

namespace Melon::Memory
{
        /// @brief A null-terminated string.
        class CString
        {
                char *data;

        public:
                /// @brief Constructs the object from a given null-terminated string.
                /// @param s null-terminated string
                CString(const char *s);

                /// @brief Computes the length of this string.
                ///
                /// The null-terminating character is not treated as a part of the string.
                /// @return string length
                Typing::USize length(this const CString &self);

                /// @brief Checks if a string is the same than this one.
                /// @param other string to compare
                /// @return boolean
                bool operator ==(this const CString &self, const CString &other);

                /// @brief Gets a character by its index in the string.
                /// @param index character position
                /// @return character at given position
                char operator [](this const CString &self, Typing::USize index);
        };
} // namespace Melon::Memory