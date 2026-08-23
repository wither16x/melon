#pragma once

#include <exception>

/// @brief Contains custom exceptions.
///
/// This namespace contains a bunch of useful exceptions to handle most errors
/// as possible.
namespace Melon::Exceptions
{
        class FileNotFound: public std::exception
        {
                const char *path;

        public:
                FileNotFound(const char *path);

                const char *what() const noexcept;
        };
} // namespace Melon::Exceptions