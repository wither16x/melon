#include <Tarwi.hpp>
#include <MemoryPackage/Package.hpp>
#include <ExceptionsPackage/Package.hpp>

int main()
{
        Melon::Test::MemoryPackage memory_package;
        TARWI_RUN_PACKAGE(memory_package);

        Melon::Test::ExceptionsPackage exceptions_package;
        TARWI_RUN_PACKAGE(exceptions_package);

        return 0;
}