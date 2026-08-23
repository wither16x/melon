#include <Internal/FileSystem/File.hpp>
#include <Internal/Exceptions/FileNotFound.hpp>
#include <String.hpp>

namespace Melon::FileSystem
{
        File::File(const String::String &path, const String::String &modes)
        {
                this->stream = fopen(path.raw(), modes.raw());

                if (not this->stream)
                        throw Exceptions::FileNotFound(path.raw());
        }

        File::File(FILE *stream)
                : stream(stream)
        {}

        File::~File()
        {
                fclose(this->stream);
        }

        bool File::isOpen(this const File &self)
        {
                return self.stream != nullptr;
        }
} // namespace Melon::FileSystem