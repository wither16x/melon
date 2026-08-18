#pragma once

#include "Typing.hpp"

#include <exception>

/// @brief Contains custom exceptions.
///
/// This namespace contains a bunch of useful exceptions to handle most errors
/// as possible.
namespace Melon::Exceptions
{
        /// @brief Thrown when a buffer overflows.
        class BufferOverflow : public std::exception
        {
                Typing::USize requested_size;
                Typing::USize buffer_size;

        public:
                /// @brief Main constructor for class BufferOverflow
                /// @param requested_size size requested by the user
                /// @param buffer_size size of the buffer
                BufferOverflow(Typing::USize requested_size, Typing::USize buffer_size);

                /// @return a formatted message describing the error
                const char *what() const noexcept;
        };

        /// @brief Thrown when an index is out of range.
        class OutOfRange : public std::exception
        {
                Typing::USize index;
                Typing::USize highest_index;

        public:
                /// @brief Main constructor for class OutOfRange.
                /// @param index index out of range
                /// @param highest_index limit of the array
                OutOfRange(Typing::USize index, Typing::USize highest_index);

                /// @return a formatted message describing the error
                const char *what() const noexcept;
        };
} // namespace Melon::Exceptions