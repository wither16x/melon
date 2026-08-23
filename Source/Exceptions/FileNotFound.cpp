#include <Internal/Exceptions/FileNotFound.hpp>

#include <stdio.h>

namespace Melon::Exceptions
{
        FileNotFound::FileNotFound(const String::String &path)
        {
                this->path = new char[path.length()];
                strcpy(this->path, path.raw());
        }

        const char *FileNotFound::what() const noexcept
        {
                static char message[256];
                
                snprintf(message, sizeof(message),
                        "file not found: %s",
                        this->path
                );

                return message;
        }
} // namespace Melon::Exceptions