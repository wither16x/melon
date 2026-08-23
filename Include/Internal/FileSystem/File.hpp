#pragma once

#include "../../String.hpp"

#include <stdio.h>

namespace Melon::FileSystem
{
        /// @brief Representation of a file stream.
        class File
        {
                FILE *stream;

        public:
                /// @brief Open constructor.
                /// @param path path to the file
                /// @param modes open modes
                File(const String::String &path, const String::String &modes);

                /// @brief Constructs the object from an existing stream.
                /// @param stream base stream
                File(FILE *stream);

                /// @brief Destructor.
                ~File();

                /// @brief Close the file if it is open.
                void close(this File &self);

                /// @brief Checks if the file is open.
                ///
                /// If the stream is not null, then it is considered as open.
                /// @return boolean
                bool isOpen(this const File &self);
        };
} // namespace Melon::FileSystem