#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Internal/FileSystem/File.hpp>
#include <Internal/FileSystem/StdStreams.hpp>

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

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckRaii);
                        TARWI_CALL_UNIT(unitOpenClose);
                }
        };
} // namespace Melon::Test