#pragma once

#include "String.hpp"

#include <type_traits>

namespace Melon::Fmt
{
        /// @brief Format a string.
        /// @param out output string
        /// @param fmt string to format
        /// @param idx index in the string
        /// @param arg argument
        /// @param args arguments
        template<typename T, typename... ARGS>
        void formatArgs(String::String &out, String::String &fmt, Typing::USize &idx, T &&arg, ARGS &&...args)
        {
                for (; idx < fmt.length(); ++idx) {
                        if (fmt[idx] != '%') {
                                out.appendChar(fmt[idx]);
                                continue;
                        }

                        ++idx;
                        if (idx >= fmt.length())
                                return;

                        switch (fmt[idx]) {
                        case '%':
                                out.appendChar('%');
                                break;

                        case 'c':
                                if constexpr (std::is_same<std::remove_cvref_t<T>, char>::value)
                                        out.appendChar(arg);
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
        String::String formatString(String::String &str, ARGS &&... args)
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