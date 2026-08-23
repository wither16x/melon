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
                        FileSystem::File file(RESOURCES_PATH"/CheckRaii.txt", "rw");
                        TARWI_EXPECT(file.isOpen());
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckRaii);
                }
        };
} // namespace Melon::Test