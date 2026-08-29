#pragma once

#include "String.hpp"
#include "Conversion.hpp"

#include <type_traits>

#define IF_TYPE_EQ(T1, T2) if constexpr (std::is_same<std::remove_cvref_t<T1>, T2>::value)

namespace Melon::Fmt
{
        /// @brief All characters used by formatArgs().
        enum class FormatChar : char
        {
                Percent         = '%',
                Char            = 'c',
                String          = 's',
                SignedInt       = 'd'
        };

        /// @brief Format a string.
        /// @param out output string
        /// @param fmt string to format
        /// @param idx index in the string
        /// @param arg argument
        /// @param args arguments
        template<typename T, typename... ARGS>
        void formatArgs(String::String &out, const String::String &fmt, Typing::USize &idx, T &&arg, ARGS &&...args)
        {
                char buf[65];

                for (; idx < fmt.length(); ++idx) {
                        if (fmt[idx] != '%') {
                                out.appendChar(fmt[idx]);
                                continue;
                        }

                        ++idx;
                        if (idx >= fmt.length())
                                return;

                        switch (static_cast<FormatChar>(fmt[idx])) {
                        case FormatChar::Percent:
                                out.appendChar('%');
                                break;

                        case FormatChar::Char:
                                IF_TYPE_EQ(T, char)
                                        out.appendChar(arg);
                                break;

                        case FormatChar::String:
                                IF_TYPE_EQ(T, String::String)
                                        out += arg;
                                break;

                        case FormatChar::SignedInt:
                                IF_TYPE_EQ(T, int)
                                        out += Conversion::intToString(arg, Conversion::Base::Decimal);
                                break;

                        default:
                                break;
                        }

                        if constexpr (sizeof...(ARGS) > 0) {
                                ++idx;
                                formatArgs(out, fmt, idx, static_cast<ARGS &&>(args)...);
                                return;
                        }
                }
        }

        /// @brief Format a string.
        ///
        /// This function uses a printf-like formatting syntax.
        /// @param str string to format
        /// @param args values
        template<typename... ARGS>
        String::String formatString(const String::String &str, ARGS &&... args)
        {
                String::String new_str;
                Typing::USize idx = 0;

                if constexpr (sizeof...(ARGS) > 0) {
                        formatArgs(new_str, str, idx, static_cast<ARGS &&>(args)...);
                } else {
                        for (; idx < str.length(); idx++)
                                new_str.appendChar(str[idx]);
                }

                return new_str;
        }
} // namespace Melon::Fmt