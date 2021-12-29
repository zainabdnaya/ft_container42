/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:06:02 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/29 21:01:59 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../iterators/iterator_traits.hpp"
#include "./rbt.hpp"

class RBT;

namespace ft
{
    // creat map library
    template <typename Key, class T, class Compare = std::less<Key>,
              class Alloc = std::allocator<ft::pair<Key, T> > >
    class map
    {
    public:
       typedef Key key_type;
		typedef T mapped_type;
		typedef typename ft::pair<key_type, mapped_type> value_type;
		typedef Compare key_compare;
		class value_compare
		{
			friend class map;
		protected:
			Compare _comp;
			value_compare(Compare _c) : _comp(_c) {}
		public:
			typedef bool result_type;
			typedef value_type first_type;
			typedef value_type second_type;
			result_type operator()(const value_type& _x,  const value_type& _y) const
			{
				return (_comp(_x.first, _y.first));
			}
		};
        typedef ft::RBT<value_type,key_compare,Alloc> tree;
		typedef typename tree::iterator iterator;
		typedef typename tree::const_iterator const_iterator;
		typedef typename tree::reverse_iterator reverse_iterator;
		typedef typename tree::const_reverse_iterator const_reverse_iterator;
		typedef typename tree::size_type size_type;
		typedef typename tree::difference_type difference_type;
		typedef typename tree::node_allocator allocator_type;
		typedef typename tree::reference reference;
		// typedef typename tree::const_reference const_reference;
		typedef typename tree::pointer pointer;
		// typedef typename tree::const_pointer const_pointer;
		
        public:
		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) :  _size(0), _alloc(alloc), _comp(comp)
		{
		}
		template <class InputIterator>
  		map (InputIterator first, InputIterator last,
       		const key_compare& comp = key_compare(),
       		const allocator_type& alloc = allocator_type()):  _size(0), _alloc(alloc), _comp(comp)
		{
			for (InputIterator it = first; it != last; ++it)
				this->insert(*it);
		}
		
		map (const map& _m) : _tree(value_compare(_m._comp)), _size(0), _alloc(_m._alloc), _comp(_m._comp)
		{
			*this = _m;
		}

		map& operator=(const map& _m)
		{
			if (this != &_m)
			{
				this->clear();
				this->_alloc = _m._alloc;
				this->_comp = _m._comp;
				this->insert(_m.begin(), _m.end());
				this->_size = _m._size;
			}
			return *this;
		}


		~map(){}
        

		//begin
		iterator begin()
		{
			return this->_tree.begin();
		}

		//begin
		const_iterator begin() const
		{
			return this->_tree.begin();
		}

		//end
		iterator end()
		{
			return this->_tree.end();
		}

		//end
		// const_iterator end() const
		// {
		// 	return this->_tree.end();
		// }
		// inser
		iterator insert (iterator position, const value_type& val)
		{
			std::cout << "insert" << std::endl;
			this->_tree.insert_node(val);
			iterator it = this->find(val);
			return (it);
		}


		ft::pair<iterator, bool> insert(const value_type& _v)
		{
			
			if (this->_tree.find(_v) != this->_tree.end())
				return (ft::pair<iterator, bool>(_tree.find(_v), false));
				
			this->_tree.insert_node(_v);
			return (ft::pair<iterator, bool>(_tree.find(_v), true));	
		}
		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last)
		{
			std::cout << "insert" << std::endl;

			_tree.insert_node(ft::pair<const key_type, mapped_type>(first, last));		  
		}

		// erase
		void erase (iterator position)
		{
			this->_tree.delete_node(ft::pair<const key_type, mapped_type>(position.node));
		}
		
		// erase
		size_type erase (const key_type& _k)
		{
			iterator it = _tree->find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			if (it == this->end())
				return (0);
			this->delete_node(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (1);
		}
		
		void erase (iterator first, iterator last)
		{
			for (iterator it = first; it != last; ++it)
				this->erase(it);
		}
		
		// clear
		void clear()
		{
			this->_tree.clear();
			this->_size = 0;
		}

		//swap
		void swap (map& _m)
		{
			this->_tree.swap(_m._tree);
			ft::swap(this->_size, _m._size);
			ft::swap(this->_alloc, _m._alloc);
			ft::swap(this->_comp, _m._comp);
		}		
		//empty
		bool empty() const
		{
			return (this->_tree.empty());
		}
		//size
		size_type size() const
		{
			return (this->_size);
		}
		//max_size
		size_type max_size() const
		{
			return (this->_tree.max_size());
		}
		//find
		iterator find (const key_type& _k)
		{
			iterator it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);
		}
		const_iterator find (const key_type& _k) const
		{
			const_iterator it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);
		}
		//count
		size_type count (const key_type& _k) const
		{
			return (this->_tree.count(ft::pair<const key_type, mapped_type>(_k, mapped_type())));
		}
		//lower_bound
		iterator lower_bound (const key_type& _k)
		{
			iterator it = this->_tree.lower_bound(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);
		}
		const_iterator lower_bound (const key_type& _k) const
		{
			const_iterator it = this->_tree.lower_bound(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);

		}

		//upper_bound
		iterator upper_bound (const key_type& _k)
		{
			iterator it = this->_tree.upper_bound(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);
		}

		const_iterator upper_bound (const key_type& _k) const
		{
			const_iterator it = this->_tree.upper_bound(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);
		}
		//equal_range
		ft::pair<iterator, iterator> equal_range (const key_type& _k)
		{
			ft::pair<iterator, iterator> it = this->_tree.equal_range(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);
		}
		ft::pair<const_iterator, const_iterator> equal_range (const key_type& _k) const
		{
			ft::pair<const_iterator, const_iterator> it = this->_tree.equal_range(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			return (it);
		}
		//key_comp
		key_compare key_comp() const
		{
			return (this->_comp);
		}
		//value_comp
		value_compare value_comp() const
		{
			return (this->_comp);
		}
		//operator[]
		mapped_type& operator[] (const key_type& _k)
		{
			iterator it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
			if (it == this->end())
			{
				this->_tree.insert_node(ft::pair<const key_type, mapped_type>(_k, mapped_type()));
				it = this->_tree.find(ft::pair<const key_type, mapped_type>(_k, mapped_type()));	
			}
			return (it->second);
		}
		//get_allocator
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
