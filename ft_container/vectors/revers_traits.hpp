/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_traits.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:03:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/11/19 23:19:54 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERS_TRAITS_HPP
#define  REVERS_TRAITS_HPP

#include "iterator_traits.hpp"
// reverse_iterator
//std::reverse_iterator is an iterator adaptor that reverses the direction of a given iterator, 
//which must be at least a LegacyBidirectionalIterator or model bidirectional_iterator (since C++20). In other words, 
//when provided with a bidirectional iterator, std::reverse_iterator produces a new iterator that moves from the end to the beginning of the sequence defined by the underlying bidirectional iterator.

namespace ft
{
template< class Iterator >
class reverse_iterator
{
    public:
    typedef Iterator													iterator_type;
	// Preserves Iterator's category
	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
    //Preserves Iterator's value type
	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
	// Preservers Iterator's difference type	
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	//Preserves Iterator's pointer type
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	//Preserves Iterator's reference type
	typedef typename ft::iterator_traits<Iterator>::reference			reference;
    
    //constructor
    reverse_iterator (Iterator _src) : current(_src) { } ;
    //member operators
    //equl operator 

	reverse_iterator &operator=(reverse_iterator const &src) { _ptr = src._ptr; return (*this); };
    reverse_iterator& operator++() { --current; return *this; }
    reverse_iterator operator++(int) { reverse_iterator tmp(*this); --current; return tmp; }
    reverse_iterator& operator--() { ++current; return *this; }
    reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++current; return tmp; }
    reverse_iterator& operator+=(difference_type n) { current -= n; return *this; }
    reverse_iterator& operator-=(difference_type n) { current += n; return *this; }
    reverse_iterator operator+(difference_type n) { reverse_iterator tmp(*this); tmp += n; return tmp; }
    reverse_iterator operator-(difference_type n) { reverse_iterator tmp(*this); tmp -= n; return tmp; }
    reference operator*() { return *(current - 1); }
    pointer operator->() { return &(operator*()); }
    //member functions
    Iterator base() const { return current; }   
    //friend functions
    friend bool operator==(const reverse_iterator& lhs, const reverse_iterator& rhs) { return lhs.current == rhs.current; }             

                
    
    protected:
		Iterator current;
        
};

}




#endif // REVERS_TRAITS_HPP