// This file is part of uparse library
// Copyright 2022-2024 Andrei Ilin <ortfero@gmail.com>
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
		
		
		template<typename T> std::optional<T> parse_number(char const* s) noexcept {
			if(!s)
				return std::nullopt;
			return parse_number<T>(std::string_view{s});
		}
        
    } // namespace detail
    
    
    template<typename T> std::optional<T> parse(std::string_view) noexcept = delete;
	template<typename T> std::optional<T> parse(char const*) noexcept = delete;
    
    
    template<> inline std::optional<std::int32_t>
    parse(std::string_view s) noexcept {
        return detail::parse_number<std::int32_t>(s);
    }
	
	
	template<> inline std::optional<std::int32_t>
    parse(char const* s) noexcept {
        return detail::parse_number<std::int32_t>(s);
    }
    
    
    template<> inline std::optional<std::uint32_t>
    parse(std::string_view s) noexcept {
        return detail::parse_number<std::uint32_t>(s);
    }
	
	
	template<> inline std::optional<std::uint32_t>
    parse(char const* s) noexcept {
        return detail::parse_number<std::uint32_t>(s);
    }
    
    
    template<> inline std::optional<std::int64_t>
    parse(std::string_view s) noexcept {
        return detail::parse_number<std::int64_t>(s);
    }
	
	template<> inline std::optional<std::int64_t>
    parse(char const* s) noexcept {
        return detail::parse_number<std::int64_t>(s);
    }
    
    
    template<> inline std::optional<std::uint64_t>
    parse(std::string_view s) noexcept {
        return detail::parse_number<std::uint64_t>(s);
    }
	
	
	template<> inline std::optional<std::uint64_t>
    parse(char const* s) noexcept {
        return detail::parse_number<std::uint64_t>(s);
    }
    
    
    template<> inline std::optional<double>
    parse(std::string_view s) noexcept {
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
	
	
	template<> inline std::optional<double>
    parse(char const* s) noexcept {
#ifdef _MSC_VER
        return detail::parse_number<double>(s);
#else
		if(s == nullptr)
			return std::nullopt;
		char* endptr;
        auto const value = std::strtod(s, &endptr);
        if(*endptr != '\0')
            return std::nullopt;
        return {value};
#endif
    }
    
    
} // namespace uparse
