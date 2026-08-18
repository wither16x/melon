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

                TARWI_MODULE_MAIN()
                {
                        TARWI_CALL_UNIT(unitCheckRaii);
                }
        };
} // namespace Melon::Test