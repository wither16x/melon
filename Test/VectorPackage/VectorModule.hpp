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

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckRaii);
                        TARWI_CALL_UNIT(unitVectorOfInts);
                }
        };
} // namespace Melon::Test