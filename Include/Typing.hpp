#pragma once

namespace Melon::C
{
        #include <stdint.h>
        #include <stddef.h>
} // namespace Melon::C

namespace Melon::Typing
{
        // signed types
        using Int8              = C::int8_t;
        using Int16             = C::int16_t;
        using Int32             = C::int32_t;
        using Int64             = C::int64_t;
        using IntPointer        = C::intptr_t;

        // unsigned types
        using Uint8             = C::uint8_t;
        using Uint16            = C::uint16_t;
        using Uint32            = C::uint32_t;
        using Uint64            = C::uint64_t;
        using UPointer          = C::uintptr_t;
        using Size              = C::size_t;
} // namespace Melon::Typing