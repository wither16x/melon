#pragma once

#include "../../Typing.hpp"

#include <string.h>

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
                Typing::USize length(this const CString &self)
                {
                        return strlen(self.data);
                }
        };
} // namespace Melon::Memory