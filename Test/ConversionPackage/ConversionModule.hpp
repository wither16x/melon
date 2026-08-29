#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Conversion.hpp>

namespace Melon::Test
{
        TARWI_MODULE(ConversionModule)
        {
                TARWI_SET_NAME("ConversionModule");

                TARWI_UNIT(unitIntToString)
                {
                        String::String str = Conversion::intToString(42, Conversion::Base::Decimal);
                        TARWI_EXPECT(str == "42");
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitIntToString);
                }
        };
} // namespace Melon::Test