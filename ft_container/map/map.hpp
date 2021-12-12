/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:06:02 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/12 15:51:50 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../iterators/iterator_traits.hpp"
#include "../iterators/make_pair.hpp"

namespace ft
{
    // creat map library
    template <typename Key, class T, class Compare = ft::less<Key>,
              class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                                 key_type;
            typedef T                                                   data_type;
            typedef std::pair<const Key, T>                            value_type;
            typedef Compare                                             key_compare;
            typedef Alloc                                               allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;   
            typedef typename allocator_type::size_type                  size_type;
            typedef typename allocator_type::difference_type            difference_type;
            typedef typename allocator_type::value_type                 value_type;
            typedef typename allocator_type::pointer                    iterator;
            typedef typename allocator_type::const_pointer              const_iterator;
            typedef typename allocator_type::pointer                    reverse_iterator;
            typedef typename allocator_type::const_pointer              const_reverse_iterator;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename size_type                                  size_type;
            

            // constructors
            
            
    };
}

#endif