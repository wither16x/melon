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

                TARWI_UNIT(unitGetByIndex)
                {
                        Memory::CString str("Hello");
                        TARWI_EXPECT(
                                str[0] == 'H' and str[1] == 'e' and str[2] == 'l'
                                and str[3] == 'l' and str[4] == 'o'
                        );
                }

                TARWI_UNIT(unitOperatorEqual)
                {
                        Memory::CString str1("Foo");
                        Memory::CString str2("Foo");

                        TARWI_EXPECT(str1 == str2);
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitLength);
                        TARWI_CALL_UNIT(unitGetByIndex);
                        TARWI_CALL_UNIT(unitOperatorEqual);
                }
        };
} // namespace Melon::Test