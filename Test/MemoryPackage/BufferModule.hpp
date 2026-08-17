#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Memory.hpp>
#include <Exceptions.hpp>

namespace Melon::Test
{
        TARWI_MODULE(BufferModule)
        {
                TARWI_SET_NAME("BufferModule");

                TARWI_UNIT(unitCheckInit)
                {
                        char data[] = "abcdefg";
                        Memory::Buffer<char> buf(data, strlen(data));

                        TARWI_EXPECT(strcmp(buf.get(), data) == 0);
                }

                TARWI_UNIT(unitCheckCopy)
                {
                        char a_data[] = "01234";
                        char b_data[] = "abcde";

                        Memory::Buffer<char> a(a_data, strlen(a_data));
                        Memory::Buffer<char> b(b_data, strlen(b_data));

                        a.copy(b, strlen(a.get()));

                        TARWI_EXPECT(strcmp(a.get(), b.get()) == 0);
                }

                TARWI_UNIT(unitCopyOverflow)
                {
                        char a_data[] = "01234";
                        char b_data[] = "abcde";

                        Memory::Buffer<char> a(a_data, strlen(a_data));
                        Memory::Buffer<char> b(b_data, strlen(b_data));

                        try {
                                a.copy(b, strlen(a.get()) + 2);
                        } catch (const Exceptions::BufferOverflow &e) {
                                TARWI_OUTPUT("buffer copy failed: %s\n", e.what());
                        }

                        TARWI_EXPECT(strcmp(a.get(), b.get()) != 0);
                }

                TARWI_UNIT(unitCheckSet)
                {
                        Typing::Uint8 data[5];
                        Memory::Buffer<Typing::Uint8> buf(data, sizeof(data));

                        buf.set(12, sizeof(data));

                        TARWI_EXPECT(
                                data[0] == 12 and data[1] == 12 and data[2] == 12 and
                                data[3] == 12 and data[4] == 12
                        );
                }

                TARWI_UNIT(unitCheckMove)
                {
                        char a_data[] = "01234";
                        char b_data[] = "abcde";

                        Memory::Buffer<char> a(a_data, strlen(a_data));
                        Memory::Buffer<char> b(b_data, strlen(b_data));

                        a.move(b, strlen(a.get()));

                        TARWI_EXPECT(strcmp(a.get(), b.get()) == 0);
                }

                TARWI_UNIT(unitCheckComparison)
                {
                        char small_data[] = "Apple";
                        char enormous_data[] = "Banana bunch";
                        char equal_data0[] = "Equal";
                        char equal_data1[] = "Equal";

                        Typing::USize size1 = strlen(small_data) < strlen(enormous_data) ? strlen(small_data) : strlen(enormous_data);
                        
                        Memory::Buffer<char> small(small_data, strlen(small_data));
                        Memory::Buffer<char> enormous(enormous_data, strlen(enormous_data));
                        Memory::Buffer<char> equal0(equal_data0, strlen(equal_data0));
                        Memory::Buffer<char> equal1(equal_data1, strlen(equal_data1));

                        int is_smaller = small.compare(enormous, size1);
                        int is_bigger = enormous.compare(small, size1);
                        int is_equal = equal0.compare(equal1, strlen(equal0.get()));

                        TARWI_EXPECT(
                                is_smaller < 0
                                and is_bigger > 0
                                and is_equal == 0
                        );
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckInit);
                        TARWI_CALL_UNIT(unitCheckCopy);
                        TARWI_CALL_UNIT(unitCopyOverflow);
                        TARWI_CALL_UNIT(unitCheckSet);
                        TARWI_CALL_UNIT(unitCheckMove);
                        TARWI_CALL_UNIT(unitCheckComparison);
                }
        };
} // namespace Melon::Test