#include <Conversion.hpp>

#include <utility>

namespace Melon::Conversion
{
        namespace
        {
                const char *baseStrings[] = {
                        "Binary",
                        "Octal",
                        "Decimal",
                        "Hexadecimal"
                };
        } // anonymous namespace

        const char *baseToString(Base base)
        {
                switch (base) {
                case Base::Binary:
                        return baseStrings[0];
                        break;

                case Base::Octal:
                        return baseStrings[1];
                        break;

                case Base::Decimal:
                        return baseStrings[2];
                        break;

                case Base::Hexadecimal:
                        return baseStrings[3];
                        break;
                }
        }

        String::String intToString(int value, Base base)
        {
                String::String str;

                bool is_negative = false;

                if (value < 0) {
                        is_negative = true;
                        value = -value;
                }


                if (value == 0)
                        return str;

                while (value != 0) {
                        int remaining = value % std::to_underlying(base);
                        str.appendChar(remaining + '0');
                        value = value / 10;
                }

                if (is_negative)
                        str.appendChar('-');

                return str.reverse();
        }
} // namespace Melon::Conversion