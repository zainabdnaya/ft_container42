/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:06:02 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/27 12:07:27 by zdnaya           ###   ########.fr       */
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
        typedef Key key_type;
        typedef T data_type;
        typedef pair<const Key, T> value_type;

        typedef Compare key_compare;
        typedef Alloc allocator_type;

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;

        typedef typename ft::tree::iterator_category iterator;
        typedef typename ft::iterator_traits::iterator_category const_iterator;

        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename size_type size_type;

        class valaue_compare : public binary_function<value_type, value_type, bool>
        {
        protected:
            Compare comp;
            key_compare(Compare c) : comp(c) {}

        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };
        

        // constructors
        // Constructs an empty container, with no elements.
        explicit map(const Compare &comp = Compare(), const Alloc &alloc = Alloc());
        // range constructor
        // Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range.
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Alloc &alloc = Alloc())
        {
            _comp = comp;
            _alloc = alloc;
            for (; first != last; ++first)
                insert(*first);
        }
        // copy constructor
        map(const map &other);
        {
            _comp = other._comp;
            _alloc = other._alloc;
            _map = other._map;
            _size = other._size;
            _key = other._key;
            _data = other._data;
        }
        // destructor
        ~map()
        {
            for (auto it = _map.begin(); it != _map.end(); ++it)
                _alloc.destroy(&*it);
            _alloc.deallocate(_map.begin(), _map.size());
        }
        // assignment operator
        map &operator=(const map &other);
        {
            _comp = other._comp;
            _alloc = other._alloc;
            _map = other._map;
        }
        // iterators
        // begin: Returns an iterator referring to the first element in the map container.
        iterator begin()
        {
            return _map.root;
        }
        // end: Returns an iterator referring to the past-the-end element in the map container.
        iterator end()
        {
            return NULL;
        }

    private:
        const Compare &_comp;
        const Alloc &_alloc;
        Node *_map;
        // key_type _key;
        // data_type _data;
        // size_type _size;
    };
}
#endif