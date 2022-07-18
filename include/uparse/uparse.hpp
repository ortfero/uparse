// This file is part of uparse library
// Copyright 2022 Andrei Ilin <ortfero@gmail.com>
// SPDX-License-Identifier: MIT


#pragma once


#include <charconv>
#include <cstdint>
#include <cstdlib>
#include <optional>
#include <string_view>


namespace uparse {
    
    namespace detail {
    
        template<typename T> std::optional<T> parse_number(std::string_view s) noexcept {
            T value;
            auto const parsed = std::from_chars(s.data(), s.data() + s.size(), value);
            if(parsed.ec != std::errc{})
                return std::nullopt;
            return {value};
        }
        
    } // namespace detail
    
    
    template<typename T> std::optional<T> parse(std::string_view) noexcept = delete;
    
    
    template<> std::optional<std::int32_t> parse(std::string_view s) noexcept {
        return detail::parse_number<std::int32_t>(s);
    }
    
    
    template<> std::optional<std::uint32_t> parse(std::string_view s) noexcept {
        return detail::parse_number<std::uint32_t>(s);
    }
    
    
    template<> std::optional<std::int64_t> parse(std::string_view s) noexcept {
        return detail::parse_number<std::int64_t>(s);
    }
    
    
    template<> std::optional<std::uint64_t> parse(std::string_view s) noexcept {
        return detail::parse_number<std::uint64_t>(s);
    }
    
    
    template<> std::optional<double> parse(std::string_view s) noexcept {
#ifdef _MSC_VER
        return detail::parse_number<double>(s);
#else
        char* endptr;
        auto const value = std::strtod(s.data(), &endptr);
        if(endptr != s.data() + s.size())
            return std::nullopt;
        return {value};
#endif
    }
    
    
} // namespace uparse
