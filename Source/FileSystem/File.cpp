#include <Internal/FileSystem/File.hpp>
#include <Internal/Exceptions/FileNotFound.hpp>
#include <Internal/Exceptions/NullStream.hpp>
#include <String.hpp>

namespace Melon::FileSystem
{
        File::File(const String::String &path, const String::String &modes)
        {
                this->stream = fopen(path.raw(), modes.raw());
                if (not this->stream)
                        throw Exceptions::FileNotFound(path);
        }

        File::File(FILE *stream)
                : stream(stream)
        {
                if (not this->stream)
                        throw Exceptions::NullStream();
        }

        File::~File()
        {
                this->close();
        }

        void File::close(this File &self)
        {
                if (self.isOpen()) {
                        fclose(self.stream);
                        self.stream = nullptr;
                }
        }

        bool File::isOpen(this const File &self)
        {
                return self.stream != nullptr;
        }
} // namespace Melon::FileSystem