#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Internal/FileSystem/File.hpp>
#include <Internal/FileSystem/StdStreams.hpp>
#include <Internal/Exceptions/FileNotFound.hpp>
#include <Internal/Exceptions/NullStream.hpp>

#define RESOURCES_PATH   "Test/FileSystemPackage/Resources"

namespace Melon::Test
{
        TARWI_MODULE(FileModule)
        {
                TARWI_SET_NAME("FileModule");

                TARWI_UNIT(unitCheckRaii)
                {
                        FileSystem::File file(RESOURCES_PATH"/Empty.txt", "rw");
                        TARWI_EXPECT(file.isOpen());
                }

                TARWI_UNIT(unitOpenClose)
                {
                        FileSystem::File file(RESOURCES_PATH"/Empty.txt", "rw");
                        bool is_open_before_close = file.isOpen();
                        file.close();
                        bool is_open_after_close = file.isOpen();
                        TARWI_EXPECT(is_open_before_close and not is_open_after_close);
                }

                TARWI_UNIT(unitFileNotFound)
                {
                        bool caught = false;

                        try {
                                FileSystem::File file(RESOURCES_PATH"/Invisible.txt", "rw");
                        } catch (const Exceptions::FileNotFound &e) {
                                TARWI_OUTPUT("caught exception: %s\n", e.what());
                                caught = true;
                        }

                        TARWI_EXPECT(caught);
                }

                TARWI_UNIT(unitNullStream)
                {
                        bool caught = false;

                        FILE *stream = nullptr;

                        try {
                                FileSystem::File file(stream);
                        } catch (const Exceptions::NullStream &e) {
                                TARWI_OUTPUT("caught exception: %s\n", e.what());
                                caught = true;
                        }

                        TARWI_EXPECT(caught);
                }

                TARWI_UNIT(unitReadLine)
                {
                        FileSystem::File file(RESOURCES_PATH"/Line.txt", "r");
                        Memory::Buffer<char> buf = file.readLine(255);
                        TARWI_EXPECT(strcmp(buf.get(), "Hello! I am a file!\n") == 0);
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckRaii);
                        TARWI_CALL_UNIT(unitOpenClose);
                        TARWI_CALL_UNIT(unitFileNotFound);
                        TARWI_CALL_UNIT(unitNullStream);
                        TARWI_CALL_UNIT(unitReadLine);
                }
        };
} // namespace Melon::Test