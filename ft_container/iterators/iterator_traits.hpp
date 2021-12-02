/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:59:50 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/12/02 11:26:34 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>
#include <cstring>
#include <cstddef> // this for signed integer type returned when subtracting two pointers (typedef) ptrdiff_t

namespace ft
{
    // Create  Iterator base class
    // This is a base class template that can be used to derive iterator classes from it. It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
    template <
        class Category,
        class T,
        class Distance = ptrdiff_t,
        class Pointer = T *,
        class Reference = T &>
    struct iterator
    {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };
    // iterators_traits are  used to access the iterator's members
    // iterator_traits : template< class Iter > struct iterator_traits;
    template <class Iterator>
    struct iterator_traits
    {
        // Member typedefs
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };
    // typedef is defining a new type for use in your code, like a shorthand.
    // typedef typename _MyBase::value_type value_type;
    // value_type v;
    // //use v
    // typename here is letting the compiler know that value_type is a type and not a static member of _MyBase.
    // the :: is the scope of the type. It is kind of like "is in" so value_type "is in" _MyBase. or can also be thought of as contains.
    // iterator_traits : template< class T > struct iterator_traits<T*>;
    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type; // ptrdiff_t is a signed integer type returned when subtracting two pointers (typedef) ptrdiff_t
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    // iterator_traits : template< class T > struct iterator_traits<const T*>;
    template <class T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    // iterator_traits : template< class T > struct iterator_traits<T&>;
    template <class T>
    struct iterator_traits<T &>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    // iterator_traits : template< class T > struct iterator_traits<const T&>;
    template <class T>
    struct iterator_traits<const T &>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    // iterator_traits : template< class T > struct iterator_traits<T*const>;
    template <class T>
    struct iterator_traits<T *const>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *const pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    // iterator_traits : template< class T > struct iterator_traits<const T*const>;
    template <class T>
    struct iterator_traits<const T *const>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *const pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

}

// Templete Parameters:
// Category:
// An iterator category type. This is a typedef of one of the standard iterator categories such as input_iterator, output_iterator, forward_iterator, bidirectional_iterator, random_access_iterator, and the default iterator category.
// T:
// The value type of the iterator.
// Distance:
// A signed integer type. This is the type of the result of subtracting two iterators.
// Pointer:
// A pointer type. This is the type of the result of applying the -> operator to an iterator.
// Reference:
// A reference type. This is the type of the result of applying the * operator to an iterator.

#endif