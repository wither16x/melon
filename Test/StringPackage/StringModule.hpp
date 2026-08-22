#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <String.hpp>

#include <string.h>

namespace Melon::Test
{
        TARWI_MODULE(StringModule)
        {
                TARWI_SET_NAME("StringModule");

                TARWI_UNIT(unitCheckInit)
                {
                        String::String str("Hello, world!");

                        TARWI_EXPECT(strcmp(str.raw(), "Hello, world!") == 0);
                }

                TARWI_UNIT(unitGetByIndex)
                {
                        String::String str("abcde");

                        TARWI_EXPECT(
                                str[0] == 'a' and str[1] == 'b' and str[2] == 'c'
                                and str[3] == 'd' and str[4] == 'e'
                        );
                }

                TARWI_UNIT(unitSetByIndex)
                {
                        String::String str("banana");

                        str[1] = 'o';
                        str[3] = 'o';
                        str[5] = 'o';

                        TARWI_EXPECT(strcmp(str.raw(), "bonono") == 0);
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckInit);
                        TARWI_CALL_UNIT(unitGetByIndex);
                        TARWI_CALL_UNIT(unitSetByIndex);
                }
        };
} // namespace Melon::Test