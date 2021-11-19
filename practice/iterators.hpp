/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:33:20 by zdnaya            #+#    #+#             */
/*   Updated: 2021/11/19 16:02:06 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>
#include <cstring>
#include <cstddef>  // this for signed integer type returned when subtracting two pointers (typedef) ptrdiff_t

/// create a class that implements the iterator traits
/// for a given container

class IteratorTraits
{
public:
    typedef std::input_iterator_tag iterator_category;
    typedef int value_type;
    typedef int difference_type;
    typedef int* pointer;
    typedef int& reference;

    // IteratorTraits(int* ptr) : ptr_(ptr) {}

    // IteratorTraits& operator++()
    // {
    //     ptr_++;
    //     return *this;
    // }
    
};

#endif