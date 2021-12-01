/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_traits.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:03:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/11/30 16:16:23 by zdnaya           ###   ########.fr       */
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
    // Constructs reverse_iterator object
    protected:
		iterator_type	current;
    // (1) default constructor ==> reverse_iterator();
        // Constructs a reverse iterator that points to no object.
        // The internal base iterator is value-initialized.
    reverse_iterator() {return;}
        //std::reverse_iterator::base iterator_type base() const;
        //Return base iterator
        //Returns a copy of the base iterator.
        //The base iterator is an iterator of the same type as the one used to construct
		//the reverse_iterator, but pointing to the element next to the one the reverse_iterator
		//is currently pointing to (a reverse_iterator has always as offset of -1 with respect to it's
		//base iterator).
    iterator_type	base() const {
		iterator_type tmp = current;
		return (++tmp);
	}
    // (2) initalization constructor ==>  explicit reverse_iterator (iterator_type it);
    // Constructs a reverse iterator from some original iterator it. The behavior of the constructed object replicates the original, except that it iterates through its pointed elements in the reverse order.
  
}




#endif // REVERS_TRAITS_HPP