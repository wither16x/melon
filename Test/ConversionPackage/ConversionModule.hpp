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

                TARWI_UNIT(unitBaseToString)
                {
                        String::String bin = Conversion::baseToString(Conversion::Base::Binary);
                        String::String oct = Conversion::baseToString(Conversion::Base::Octal);
                        String::String dec = Conversion::baseToString(Conversion::Base::Decimal);
                        String::String hex = Conversion::baseToString(Conversion::Base::Hexadecimal);

                        TARWI_EXPECT(
                                bin == "Binary" and
                                oct == "Octal" and
                                dec == "Decimal" and
                                hex == "Hexadecimal"
                        );
                }

                TARWI_UNIT(unitUintToString)
                {
                        String::String str = Conversion::uintToString(15, Conversion::Base::Hexadecimal);
                        TARWI_EXPECT(str == "f");
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitIntToString);
                        TARWI_CALL_UNIT(unitBaseToString);
                        TARWI_CALL_UNIT(unitUintToString);
                }
        };
} // namespace Melon::Test