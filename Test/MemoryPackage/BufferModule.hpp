#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Memory.hpp>

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

                TARWI_UNIT(unitCheckCopy)
                {
                        char a_data[] = "01234";
                        char b_data[] = "abcde";

                        Memory::Buffer<char> a(a_data, strlen(a_data));
                        Memory::Buffer<char> b(b_data, strlen(b_data));

                        a.copy(b, strlen(a.get()));

                        TARWI_EXPECT(strcmp(a.get(), b.get()) == 0);
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckInit);
                        TARWI_CALL_UNIT(unitCheckCopy);
                }
        };
} // namespace Melon::Test