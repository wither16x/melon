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
                        Memory::Buffer<char> buf(data, Memory::C::strlen(data));

                        TARWI_EXPECT(Memory::C::strcmp(buf.get(), data) == 0);
                }

                TARWI_UNIT(unitCheckCopy)
                {
                        char a_data[] = "01234";
                        char b_data[] = "abcde";

                        Memory::Buffer<char> a(a_data, Memory::C::strlen(a_data));
                        Memory::Buffer<char> b(b_data, Memory::C::strlen(b_data));

                        a.copy(b, Memory::C::strlen(a.get()));

                        TARWI_EXPECT(Memory::C::strcmp(a.get(), b.get()) == 0);
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckInit);
                        TARWI_CALL_UNIT(unitCheckCopy);
                }
        };
} // namespace Melon::Test