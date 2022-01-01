/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:43:21 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/09 17:19:58 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <iostream>
#include <type_traits>

namespace ft
{
    template <class T>
    struct is_integral
    {
        // Enumeration is a user defined datatype in C/C++ language. It is used to assign names to the integral constants which makes a program easy to read and maintain. The keyword “enum” is used to declare an enumeration.
        enum
        {
            value = false
        };
    };

    template <>
    struct is_integral<bool>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<char>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<signed char>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<unsigned char>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<wchar_t>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<char16_t>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<char32_t>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<short>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<unsigned short>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<int>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<unsigned int>
    {
        enum
        {
            value = true
        };
    };

    template <>
    struct is_integral<long>
    {
        enum
        {
            value = true
        };
    };
    template <class T>
    void swap(T &a, T &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }
}

#endif
