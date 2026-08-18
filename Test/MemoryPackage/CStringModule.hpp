#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Internal/Memory/CString.hpp>

namespace Melon::Test
{
        TARWI_MODULE(CStringModule)
        {
                TARWI_SET_NAME("CStringModule");

                TARWI_UNIT(unitLength)
                {
                        Memory::CString str("0123456789"); // length = 10
                        TARWI_EXPECT(str.length() == 10);
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitLength);
                }
        };
} // namespace Melon::Test