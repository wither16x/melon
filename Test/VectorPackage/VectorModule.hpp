#pragma once

#include <Tarwi.hpp>
#include <TarwiGlobals.hpp>

#include <Vector.hpp>
#include <Typing.hpp>

namespace Melon::Test
{
        TARWI_MODULE(VectorModule)
        {
                TARWI_SET_NAME("VectorModule");

                TARWI_UNIT(unitCheckRaii)
                {
                        Vector::Vector<Typing::Uint8> vec;
                        
                        TARWI_EXPECT(
                                vec.length() == 0
                                and vec.capacity() == 1
                        );
                }

                TARWI_UNIT(unitVectorOfInts)
                {
                        Vector::Vector<int> vec({1, 2, 3, 4, 5});

                        TARWI_EXPECT(
                                vec[0] == 1 and vec[1] == 2 and vec[2] == 3 and vec[3] == 4
                                and vec[4] == 5
                        );
                }

                TARWI_UNIT(unitPushBack)
                {
                        Vector::Vector<int> vec({250, 500, 750, 1000});

                        vec.pushBack(1250);
                        vec.pushBack(1500);
                        vec.pushBack(1750);
                        vec.pushBack(2000);

                        TARWI_EXPECT(
                                vec[0] == 250 and vec[1] == 500 and vec[2] == 750
                                and vec[3] == 1000 and vec[4] == 1250 and vec[5] == 1500
                                and vec[6] == 1750 and vec[7] == 2000
                        );
                }

                TARWI_UNIT(unitIsEmpty)
                {
                        Vector::Vector<int> vec_with_elems({2, 4, 6, 8, 10, 12});
                        Vector::Vector<int> empty_vec;

                        TARWI_EXPECT(
                                not vec_with_elems.isEmpty()
                                and empty_vec.isEmpty()
                        );
                }

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckRaii);
                        TARWI_CALL_UNIT(unitVectorOfInts);
                        TARWI_CALL_UNIT(unitPushBack);
                        TARWI_CALL_UNIT(unitIsEmpty);
                }
        };
} // namespace Melon::Test