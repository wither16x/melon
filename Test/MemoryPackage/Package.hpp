#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <MemoryPackage/BufferModule.hpp>

namespace Melon::Test
{
        TARWI_PACKAGE(MemoryPackage)
        {
                TARWI_SET_NAME("MemoryPackage");

                BufferModule buffer_module;

                TARWI_PACKAGE_MAIN()
                {
                        TARWI_RUN_MODULE(buffer_module);

                        TARWI_DISPLAY_RESULTS(
                                buffer_module.successfull_tests,
                                buffer_module.failed_tests,
                                buffer_module.skipped_tests
                        );
                }
        };
} // namespace Melon::Test 