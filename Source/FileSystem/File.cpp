#include <Internal/FileSystem/File.hpp>
#include <Internal/Exceptions/FileNotFound.hpp>
#include <Internal/Exceptions/NullStream.hpp>
#include <String.hpp>

#include <stdio.h>
#include <unistd.h>

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

        Memory::Buffer<char> File::read(this File &self, Typing::USize bytes)
        {
                char *p = new char[bytes];
                ::read(fileno(self.stream), p, bytes);
                Memory::Buffer<char> buf(p, bytes);
                delete[] p;
                return buf;
        }

        Memory::Buffer<char> File::readLine(this File &self, Typing::USize lineno)
        {
                int ch = '\0';
                Typing::USize lf_count = 0;
                Memory::Buffer<char> buf;

                fseek(self.stream, 0, SEEK_SET);

                while (lf_count < lineno) {
                        ch = fgetc(self.stream);

                        if (ch == EOF)
                                return buf;

                        if (ch == '\n')
                                ++lf_count;
                }

                while ((ch = fgetc(self.stream)) != EOF and ch != '\n') {
                        buf.resize(buf.size() + 1);
                        buf[buf.size() - 1] = static_cast<char>(ch);
                }

                return buf;
        }

        bool File::isOpen(this const File &self)
        {
                return self.stream != nullptr;
        }
} // namespace Melon::FileSystem