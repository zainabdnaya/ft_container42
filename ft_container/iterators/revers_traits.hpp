/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_traits.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:03:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/11/20 16:20:42 by zainabdnaya      ###   ########.fr       */
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
    explicit	reverse_iterator (iterator_type it) {
		current = --it;
		return ;}
    // (3) copy / type-cast constructor ==> template <class Iter> reverse_iterator (const reverse_iterator<Iterator>& rev_it);
    // Constructs a reverse iterator from some other reverse iterator. The constructed object keeps the same sense of iteration as rev_it.
	template <class Iter>
			reverse_iterator (const reverse_iterator<Iterator>& rev) {
				current = rev.base();}
    //menber  operators
    // (4) dereference operator ==> reference operator* ();
    // Returns a reference to the element pointed to by the iterator.
    // equal operator ==> bool operator== (const reverse_iterator& x) const;
    reference	operator*() const {return (*current);}
   reverse_iterator &operator=(reverse_iterator const &src) { current  = src._ptr; return (*this); };
    // (5) pre-increment operator ==> reverse_iterator& operator++ ();  
    reverse_iterator&	operator--() { ++current;return *this;};  
    reverse_iterator &operator++() {--current;  return (*this);};
 	reverse_iterator&	operator-= (difference_type n) {current += n;return (*this);};
    reverse_iterator	operator++(int) { reverse_iterator tmp = *this; current--; return (tmp);};
    //A pointer to the element pointed by the iterator
    pointer		operator->() const {return &(operator*());};
    reverse_iterator	operator+ (difference_type n) const {return (reverse_iterator(current - n + 1));};
    reverse_iterator&	operator+= (difference_type n) {current -= n;return (*this);};
	reverse_iterator	operator- (difference_type n) const {return (reverse_iterator(current + (n + 1)));};
    reverse_iterator	operator--(int) {reverse_iterator tmp = *this;++current;return (tmp);};
    reference			operator[] (difference_type n) const {return (current[n]);};
   
};
// mon member operators 
  //Performs the appropriate comparison operation between the reverse_iterator objects
	 // lefths and righths
	 // Internally, the function compares directly the base iterators using the reflexively
	 // equivalent relational operators
	 // These operators are overloaded in header <iterator>
	 // @tparam Iterator
	 // @param lefths, righths reverse_iterator objects (to the left- and right-hand size of the operator,
	 // respectively), having both the same template parameter (Iterator).
	 // @return true if the condition holds, and false otherwise
	template <class Iterator>
		bool operator== (const reverse_iterator<Iterator>& lefths,
				const reverse_iterator<Iterator>& righths) {
			return (lefths.base() == righths.base());
		}
	template <class Iterator>
		bool operator!= (const reverse_iterator<Iterator>& lefths,
				const reverse_iterator<Iterator>& righths) {
			return (lefths.base() != righths.base());
		}
	template <class Iterator>
		bool operator< (const reverse_iterator<Iterator>& lefths,
				const reverse_iterator<Iterator>& righths) {
			return (lefths.base() > righths.base());
		}
	template <class Iterator>
		bool operator<= (const reverse_iterator<Iterator>& lefths,
				const reverse_iterator<Iterator>& righths) {
			return (lefths.base() >= righths.base());
		}
	template <class Iterator>
		bool operator> (const reverse_iterator<Iterator>& lefths,
				const reverse_iterator<Iterator>& righths) {
			return (lefths.base() < righths.base());
		}
	template <class Iterator>
		bool operator>= (const reverse_iterator<Iterator>& lefths,
				const reverse_iterator<Iterator>& righths) {
			return (lefths.base() <= righths.base());
		}

	//brief Addition operator
	// Returns a reverse iterator pointing to the element located n positions away from the element
	// pointed to by rev_it.
	// The function returns the same as: rev_it+n.
	// This operator is also overloaded as a member function to return a reverse iterator offset by -n
	// element positions.
	// @tparam Iterator
	// @param n Number of elements to offset.
	// @param rev_it  Reverse iterator.
	// @return An iterator pointing to the element n positions away from rev_it.
	///
	template <class Iterator>
		reverse_iterator<Iterator> operator+ (
					typename	reverse_iterator<Iterator>::difference_type n,
					const		reverse_iterator<Iterator>& rev_it
				) {
			return (rev_it + n);
		}

	/** @brief Subtraction operator
	 * Returns the distance between lefths and righths.
	 *
	 * The function returns the same as subtracting lefths's base iterator from righths's base iterator.
	 *
	 * @tparam Iterator
	 * @param lefths, righths reverse_iterator objects (to the left- and right- hand side of the operator
	 * , respectively), having both the same template parameter (Iterator).
	 * @return The number of elements between lefths and righths.
	 */
	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator- (
				const reverse_iterator<Iterator>& lefths,
				const reverse_iterator<Iterator>& righths) {
			return (righths.base() - lefths.base());
		}
}




#endif // REVERS_TRAITS_HPP