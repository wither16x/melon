#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <String.hpp>
#include <Fmt.hpp>
#include <climits>

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

                TARWI_UNIT(unitFormatSignedInt)
                {
                        String::String name = "John Doe";
                        int age = 42;

                        String::String hello = Fmt::formatString(
                                "Hello! My name is %s and I am %d years old!",
                                name, age
                        );

                        TARWI_EXPECT(hello == "Hello! My name is John Doe and I am 42 years old!");
                }

                TARWI_UNIT(unitFormatUnsignedInt)
                {
                        unsigned int age = 65;
                        String::String hello = Fmt::formatString(
                                "I'm very old because I'm %u years old.",
                                age
                        );

                        TARWI_EXPECT(hello == "I'm very old because I'm 65 years old.");
                }

                TARWI_UNIT(unitBinaryOctalHexadecimal)
                {
                        unsigned int x = 35;

                        String::String bin = Fmt::formatString("x = 0b%b", x);
                        String::String oct = Fmt::formatString("x = 0o%o", x);
                        String::String hex = Fmt::formatString("x = 0x%x", x);

                        TARWI_EXPECT(bin == "x = 0b100011" and oct == "x = 0o43" and hex == "x = 0x23");
                }

                TARWI_UNIT(unitLongTypes)
                {
                        String::String hello = Fmt::formatString("%d", LONG_LONG_MAX);
                        TARWI_EXPECT(hello == "9223372036854775807");
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitFormatChar);
                        TARWI_CALL_UNIT(unitFormatString);
                        TARWI_CALL_UNIT(unitFormatSignedInt);
                        TARWI_CALL_UNIT(unitFormatUnsignedInt);
                        TARWI_CALL_UNIT(unitBinaryOctalHexadecimal);
                        TARWI_CALL_UNIT(unitLongTypes);
                }
        };
} // namespace Melon::Test