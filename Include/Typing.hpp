#pragma once

#include <stdint.h>
#include <stddef.h>

namespace Melon::Typing
{
        // signed types
        using Int8              = int8_t;
        using Int16             = int16_t;
        using Int32             = int32_t;
        using Int64             = int64_t;
        using IntPointer        = intptr_t;

        // unsigned types
        using Uint8             = uint8_t;
        using Uint16            = uint16_t;
        using Uint32            = uint32_t;
        using Uint64            = uint64_t;
        using UPointer          = uintptr_t;
        using Size              = size_t;
} // namespace Melon::Typing