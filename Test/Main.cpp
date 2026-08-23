#include <Tarwi.hpp>

#include <MemoryPackage/Package.hpp>
#include <ExceptionsPackage/Package.hpp>
#include <VectorPackage/Package.hpp>
#include <StringPackage/Package.hpp>
#include <FileSystemPackage/Package.hpp>

int main()
{
        Melon::Test::MemoryPackage memory_package;
        TARWI_RUN_PACKAGE(memory_package);

        Melon::Test::ExceptionsPackage exceptions_package;
        TARWI_RUN_PACKAGE(exceptions_package);

        Melon::Test::VectorPackage vector_package;
        TARWI_RUN_PACKAGE(vector_package);

        Melon::Test::StringPackage string_package;
        TARWI_RUN_PACKAGE(string_package);

        Melon::Test::FileSystemPackage filesystem_package;
        TARWI_RUN_PACKAGE(filesystem_package);

        return 0;
}