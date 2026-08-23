#include <Internal/Exceptions/FileNotFound.hpp>

#include <stdio.h>

namespace Melon::Exceptions
{
        FileNotFound::FileNotFound(const String::String &path)
                : path(path)
        {}

        const char *FileNotFound::what() const noexcept
        {
                static char message[256];
                
                snprintf(message, sizeof(message),
                        "file not found: %s",
                        this->path.raw()
                );

                return message;
        }
} // namespace Melon::Exceptions