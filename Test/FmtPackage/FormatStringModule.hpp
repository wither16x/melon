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

                TARWI_UNIT(unitFormatString)
                {
                        String::String firstname = "John";
                        String::String lastname = "Doe";
                        String::String hello = Fmt::formatString(
                                "Hello! My name is %s %s!",
                                firstname, lastname
                        );

                        TARWI_EXPECT(hello == "Hello! My name is John Doe!");
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitFormatChar);
                        TARWI_CALL_UNIT(unitFormatString);
                }
        };
} // namespace Melon::Test