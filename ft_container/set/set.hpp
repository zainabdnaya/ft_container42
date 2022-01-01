/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:06:02 by zdnaya            #+#    #+#             */
/*   Updated: 2022/01/01 10:52:16 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "../tools/iterator_traits.hpp"
#include "../tools/rbt.hpp"
#include "../tools/make_pair.hpp"
#include <limits>
#include "../tools/is_integral.hpp"

// The set stores the elements in sorted order.
// All the elements in a set have unique values.
// The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
// this set follows a red balck impelementation.
// The values in a set are unindexed.

class RBT;

namespace ft
{
    // creat set library
    template <class T, class Compare = std::less<T>,
              class Alloc = std::allocator<T> >
    class set
    {
    public:
        typedef Alloc _alloc_type;
        typedef T key_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef ft::RBT<value_type, value_compare, Alloc> tree;
        typedef typename tree::iterator iterator;
        typedef typename tree::const_iterator const_iterator;
        typedef typename tree::reverse_iterator reverse_iterator;
        typedef typename tree::const_reverse_iterator const_reverse_iterator;
        typedef typename tree::size_type size_type;
        typedef typename tree::difference_type difference_type;
        typedef typename tree::node_allocator allocator_type;
        typedef typename tree::reference reference;
        typedef typename tree::pointer pointer;

    public:
        explicit set(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc), _comp(comp), _tree()
        {
        }
        template <class InputIterator>
        set(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc), _comp(comp), _tree()
        {
            this->insert(first, last);
        }

        set(const set &_m) : _size(0), _alloc(_m._alloc), _comp(_m._comp), _tree(_m._tree)
        {
        }

        set &operator=(const set &_m)
        {
            this->_tree = _m._tree;
            this->_alloc = _m._alloc;
            this->_comp = _m._comp;
            this->_size = _m._size;
            return *this;
        }

        ~set() {}

        // begin
        iterator begin()
        {
            return this->_tree.begin();
        }

        // begin
        const_iterator cbegin() const
        {
            return this->_tree.begin();
        }

        // end
        iterator end()
        {
            return this->_tree.end();
        }

        // end
        const_iterator cend() const
        {
            return this->_tree.end();
        }
        // rbegin
        reverse_iterator rbegin()
        {
            return this->_tree.rbegin();
        }

        // rbegin
        const_reverse_iterator crbegin() const
        {
            return this->_tree.rbegin();
        }

        // rend
        reverse_iterator rend()
        {
            return this->_tree.rend();
        }

        // rend
        const_reverse_iterator crend() const
        {
            return this->_tree.rend();
        }

        iterator insert(iterator position, const value_type &val)
        {
            // std::cout << "insert" << std::endl;
            this->_tree.insert_node(val);
            iterator it = this->find(val);
            return (it);
        }

        ft::pair<iterator, bool> insert(const value_type &_v)
        {

            if (this->_tree.find(_v) != this->_tree.end())
                return (ft::pair<iterator, bool>(_tree.find(_v), false));

            this->_tree.insert_node(_v);
            return (ft::pair<iterator, bool>(_tree.find(_v), true));
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            for (InputIterator it = first; it != last; ++it)
                this->insert(*it);
        }

        // erase
        void erase(iterator position)
        {
            this->_tree.delete_node(_tree._search(position));
        }

        // erase
        size_type erase(const key_type &_k)
        {
            this->_tree.delete_node(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            return (1);
        }

        void erase(iterator first, iterator last)
        {
            this->_tree.erase(first, last);
        }

        // clear
        void clear()
        {
            this->_tree.clear();
            this->_size = 0;
        }

        // swap
        void swap(set &_m)
        {
            ft::swap(this->_size, _m._size);
            ft::swap(this->_alloc, _m._alloc);
            ft::swap(this->_comp, _m._comp);
            this->_tree.swap(_m._tree);
        }
        // empty
        bool empty() const
        {
            return (this->_tree.empty());
        }
        // size
        size_type size() const
        {
            return (this->_tree.size());
        }
        // max_size
        size_t max_size() const
        {
            return this->_tree.max_size();
        }
        // find
        iterator find(const key_type &_k)
        {
            iterator it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            return (it);
        }
        const_iterator find(const key_type &_k) const
        {
            const_iterator it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            return (it);
        }
        // count
        size_type count(const key_type &_k) const
        {
            return (this->_tree.count(ft::pair<const key_type, mapped_type>(_k, mapped_type())));
        }
        // lower_bound
        iterator lower_bound(const key_type &_k)
        {
            return (this->_tree.lower_bound(ft::pair<const key_type, mapped_type>(_k, mapped_type())));
        }
        const_iterator lower_bound(const key_type &_k) const
        {
            return (this->lower_bound(_k));
        }

        // upper_bound
        iterator upper_bound(const key_type &_k)
        {
            return (this->_tree.upper_bound(ft::pair<const key_type, mapped_type>(_k, mapped_type())));
        }

        const_iterator upper_bound(const key_type &_k) const
        {
            const_iterator it = this->_tree.upper_bound(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            return (it);
        }
        // equal_range
        ft::pair<iterator, iterator> equal_range(const key_type &_k)
        {
            ft::pair<iterator, iterator> it = this->_tree.equal_range(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            return (it);
        }
        ft::pair<const_iterator, const_iterator> equal_range(const key_type &_k) const
        {
            ft::pair<const_iterator, const_iterator> it = this->_tree.equal_range(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            return (it);
        }
        // key_comp
        key_compare key_comp() const
        {
            return (this->_comp);
        }
        // value_comp
        value_compare value_comp() const
        {
            return (this->_comp);
        }
        // operator[]
        mapped_type &operator[](const key_type &_k)
        {
            iterator it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            if (it == this->end())
            {
                this->_tree.insert_node(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
                it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
            }
            return (it->second);
        }
        // get_allocator
        allocator_type get_allocator() const
        {
            return (this->_alloc);
        }

    private:
        key_compare _comp;
        allocator_type _alloc;
        size_type _size;
        tree _tree;
    };
}
#endif