#pragma once

#include "String.hpp"

namespace Melon::Conversion
{
        /// @brief All conversion functions that take integers should support these bases.
        ///
        /// If a base is not supported, the function should throw an exception.
        /// TODO: add Exceptions::UnsupportedBase
        enum class Base
        {
                Binary          = 2,
                Octal           = 8,
                Decimal         = 10,
                Hexadecimal     = 16
        };

        /// @brief Convert an integer to a String::String.
        /// @param value integer to convert
        /// @param base base
        /// @return new string
        String::String intToString(int value, Base base);
} // namespace Melon::Conversion