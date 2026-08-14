#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Memory.hpp>

#include <string.h>

namespace Melon::Test
{
        TARWI_MODULE(BufferModule)
        {
                TARWI_SET_NAME("BufferModule");

                TARWI_UNIT(unitCheckInit)
                {
                        char data[] = "abcdefg";
                        Memory::Buffer<char> buf(data, strlen(data));

                        TARWI_EXPECT(strcmp(buf.get(), data) == 0);
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckInit);
                }
        };
} // namespace Melon::Test