#pragma once

#include "String.hpp"

namespace Melon::Conversion
{
        /// @brief All conversion functions that take integers should support these bases.
        enum class Base
        {
                Binary          = 2,
                Octal           = 8,
                Decimal         = 10,
                Hexadecimal     = 16
        };

        /// @brief Convert a base to a raw string.
        /// @param base base to convert
        /// @return corresponding string
        const char *baseToString(Base base);

        /// @brief Convert an integer to a String::String.
        /// @param value integer to convert
        /// @param base base
        /// @return new string
        String::String intToString(int value, Base base);

        /// @brief Convert an unsigned integer to a String::String.
        /// @param value unsigned integer to convert
        /// @return corresponding string
        String::String uintToString(unsigned int value, Base base);
} // namespace Melon::Conversion