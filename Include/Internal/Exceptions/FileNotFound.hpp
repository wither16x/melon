#pragma once

#include "../../String.hpp"

#include <exception>

/// @brief Contains custom exceptions.
///
/// This namespace contains a bunch of useful exceptions to handle most errors
/// as possible.
namespace Melon::Exceptions
{
        class FileNotFound: public std::exception
        {
                const String::String &path;

        public:
                FileNotFound(const String::String &path);

                const char *what() const noexcept;
        };
} // namespace Melon::Exceptions