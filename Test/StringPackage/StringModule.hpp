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

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckInit);
                }
        };
} // namespace Melon::Test