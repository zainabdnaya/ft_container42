/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:33:20 by zdnaya            #+#    #+#             */
/*   Updated: 2021/11/14 19:16:18 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <stack>
#include <vector>

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

    IteratorTraits(int* ptr) : ptr_(ptr) {}

    IteratorTraits& operator++()
    {
        ptr_++;
        return *this;
    }
    
};