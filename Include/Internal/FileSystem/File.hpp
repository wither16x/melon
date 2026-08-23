#pragma once

#include "../../String.hpp"

#include <stdio.h>

namespace Melon::FileSystem
{
        class File
        {
                FILE *stream;

        public:
                File(const String::String &path, const String::String &modes);

                File(FILE *stream);

                ~File();

                bool isOpen(this const File &self);
        };
} // namespace Melon::FileSystem