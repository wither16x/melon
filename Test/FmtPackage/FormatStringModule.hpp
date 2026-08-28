#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <String.hpp>
#include <Fmt.hpp>

namespace Melon::Test
{
        TARWI_MODULE(FormatStringModule)
        {
                TARWI_SET_NAME("FormatStringModule");

                TARWI_UNIT(unitFormatChar)
                {
                        String::String str = "The fifth letter of the alphabet is %c.";
                        str = Fmt::formatString(str, 'e');

                        TARWI_EXPECT(
                                str == "The fifth letter of the alphabet is e."
                        );
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitFormatChar);
                }
        };
} // namespace Melon::Test