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
                        Memory::Buffer<char> buf = file.readLine(0);
                        TARWI_EXPECT(strcmp(buf.get(), "Hello! I am a file!") == 0);
                }

                TARWI_UNIT(unitRead)
                {
                        FileSystem::File file(RESOURCES_PATH"/Message.txt", "r");
                        Memory::Buffer<char> content = file.read(512);
                        TARWI_EXPECT(strcmp(content.get(),
                        "Hey!\n"
                        "\n"
                        "If you read this, know that...\n"
                        "Uh...\n"
                        "I don't know T-T\n") == 0
                        );
                }

                TARWI_UNIT(unitReadSeveralLines)
                {
                        FileSystem::File file(RESOURCES_PATH"/Lines.txt", "r");

                        auto line0 = file.readLine(0);
                        auto line4 = file.readLine(4);
                        auto line2 = file.readLine(2);
                        auto line1 = file.readLine(1);
                        auto line3 = file.readLine(3);

                        TARWI_EXPECT(
                                strcmp(line0.get(), "First line.") == 0 and
                                strcmp(line1.get(), "Second line.") ==0 and
                                strcmp(line2.get(), "Third line.") == 0 and
                                strcmp(line3.get(), "Fourth line.") == 0 and
                                strcmp(line4.get(), "Fifth line.") == 0
                        );
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckRaii);
                        TARWI_CALL_UNIT(unitOpenClose);
                        TARWI_CALL_UNIT(unitFileNotFound);
                        TARWI_CALL_UNIT(unitNullStream);
                        TARWI_CALL_UNIT(unitReadLine);
                        TARWI_CALL_UNIT(unitRead);
                        TARWI_CALL_UNIT(unitReadSeveralLines);
                }
        };
} // namespace Melon::Test