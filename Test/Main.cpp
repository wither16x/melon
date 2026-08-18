#include <Tarwi.hpp>
#include <MemoryPackage/Package.hpp>
#include <ExceptionsPackage/Package.hpp>
#include <VectorPackage/Package.hpp>

int main()
{
        Melon::Test::MemoryPackage memory_package;
        TARWI_RUN_PACKAGE(memory_package);

        Melon::Test::ExceptionsPackage exceptions_package;
        TARWI_RUN_PACKAGE(exceptions_package);

        Melon::Test::VectorPackage vector_package;
        TARWI_RUN_PACKAGE(vector_package);

        return 0;
}