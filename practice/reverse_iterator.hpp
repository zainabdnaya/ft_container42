/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:03:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/12/02 11:26:33 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_TRAITS_HPP
#define REVERSE_TRAITS_HPP

#include "iterator_traits.hpp"
// reverse_iterator
// std::reverse_iterator is an iterator adaptor that reverses the direction of a given iterator,
// which must be at least a LegacyBidirectionalIterator or model bidirectional_iterator (since C++20). In other words,
// when provided with a bidirectional iterator, std::reverse_iterator produces a new iterator that moves from the end to the beginning of the sequence defined by the underlying bidirectional iterator.
namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        // Preserves Iterator's category
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        // Preserves Iterator's value type
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        // Preservers Iterator's difference type
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        // Preserves Iterator's pointer type
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        // Preserves Iterator's reference type
        typedef typename ft::iterator_traits<Iterator>::reference reference;
        // constructor
        //  Constructs reverse_iterator object
    protected:
        iterator_type current;
        // (1) default constructor ==> reverse_iterator();
        // Constructs a reverse iterator that points to no object.
        // The internal base iterator is value-initialized.
        reverse_iterator() { return; };
        // std::reverse_iterator::base iterator_type base() const;
        // Return base iterator
        // Returns a copy of the base iterator.
        // The base iterator is an iterator of the same type as the one used to construct
        // the reverse_iterator, but pointing to the element next to the one the reverse_iterator
        // is currently pointing to (a reverse_iterator has always as offset of -1 with respect to it's
        // base iterator).
        iterator_type base() const
        {
            iterator_type tmp = current;
            return (++tmp);
        };
        // (2) initalization constructor ==>  explicit reverse_iterator (iterator_type it);
        // Constructs a reverse iterator from some original iterator it. The behavior of the constructed object replicates the original,
        // except that it iterates through its pointed elements in the reverse order.
        explicit reverse_iterator(iterator_type it) : current(it){};
        // (3) copy constructor ==> reverse_iterator (const reverse_iterator& it);
        // Constructs a reverse iterator from another reverse_iterator it.
        reverse_iterator(const reverse_iterator &it) : current(it.current){};
        // (4) assignment operator ==> reverse_iterator& operator= (const reverse_iterator& it);
        // Assigns the value of the reverse_iterator it to the reverse_iterator *this.
        reverse_iterator &operator=(const reverse_iterator &it)
        {
            current = it.current;
            return *this;
        };
        // (5) dereference operator ==> reference operator* ();
        // Returns a reference to the element pointed to by the iterator.
        reference operator*()
        {
            iterator_type tmp = current;
            return *(--tmp);
        };
        // constexpr reference operator*() const;
        //  Returns a const reference to the element pointed to by the iterator.
        // constexpr reference operator*() const
        // {
        //     iterator_type tmp = current;
        //     return *(--tmp);
        // };
        // (6) dereference operator ==> pointer operator-> ();
        // Returns a pointer to the element pointed to by the iterator.
        pointer operator->()
        {
            iterator_type tmp = current;
            return &(*(--tmp));
        };
        // constexpr pointer operator->() const;
        //  Returns a const pointer to the element pointed to by the iterator.
        // constexpr pointer operator->() const
        // {
        //     iterator_type tmp = current;
        //     return &(*(--tmp));
        // };
        // re
        //  (7) prefix increment operator ==> reverse_iterator& operator++ ();
        //  Pre-increment operator.
        reverse_iterator &operator++()
        {
            --current;
            return *this;
        };
        // (8) postfix increment operator ==> reverse_iterator operator++ (int);
        // Post-increment operator.
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --current;
            return tmp;
        };
        // constexpr reverse_iterator operator++(int) const
        // {
        //     reverse_iterator tmp = *this;
        //     --current;
        //     return tmp;
        // };
        // (9) prefix decrement operator ==> reverse_iterator& operator-- ();
        // Pre-decrement operator.
        reverse_iterator &operator--()
        {
            ++current;
            return *this;
        };
        // constexpr reverse_iterator operator--(int)
        // {
        //     reverse_iterator tmp = *this;
        //     ++current;
        //     return tmp;
        // };
        // (10) postfix decrement operator ==> reverse_iterator operator-- (int);
        // Post-decrement operator.
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++current;
            return tmp;
        };
        // (11) addition operator ==> reverse_iterator operator+ (difference_type n);
        // Returns a reverse_iterator that points to the element n positions forward from the element the iterator is pointing to.
        reverse_iterator operator+(difference_type n)
        {
            reverse_iterator tmp = *this;
            return tmp += n;
        };
        // (12) addition assignment operator ==> reverse_iterator& operator+= (difference_type n);
        // Adds n to the iterator, and returns a reference to the iterator.
        reverse_iterator &operator+=(difference_type n)
        {
            current -= n;
            return *this;
        };
        // (13) subtraction operator ==> reverse_iterator operator- (difference_type n);
        // Returns a reverse_iterator that points to the element n positions backward from the element the iterator is pointing to.
        reverse_iterator operator-(difference_type n)
        {
            reverse_iterator tmp = *this;
            return tmp -= n;
        };
        // (14) subtraction assignment operator ==> reverse_iterator& operator-= (difference_type n);
        // Subtracts n from the iterator, and returns a reference to the iterator.
        reverse_iterator &operator-=(difference_type n)
        {
            current += n;
            return *this;
        };
        // (15) difference operator ==> difference_type operator- (const reverse_iterator& it) const;
        // Returns the distance between two iterators.
        difference_type operator-(const reverse_iterator &it) const
        {
            return (current - it.current);
        };
        // (16) equality operator ==> bool operator== (const reverse_iterator& it) const;
        // Returns true if the iterators are equal, false otherwise.
        bool operator==(const reverse_iterator &it) const
        {
            return (current == it.current);
        };
        // (17) inequality operator ==> bool operator!= (const reverse_iterator& it) const;
        // Returns true if the iterators are not equal, false otherwise.
        bool operator!=(const reverse_iterator &it) const
        {
            return (current != it.current);
        };
        // (18) less than operator ==> bool operator< (const reverse_iterator& it) const;
        // Returns true if the iterator is less than the iterator it, false otherwise.
        bool operator<(const reverse_iterator &it) const
        {
            return (current > it.current);
        };
        // (19) greater than operator ==> bool operator> (const reverse_iterator& it) const;
        // Returns true if the iterator is greater than the iterator it, false otherwise.
        bool operator>(const reverse_iterator &it) const
        {
            return (current < it.current);
        };
        // (20) less than or equal operator ==> bool operator<= (const reverse_iterator& it) const;
        // Returns true if the iterator is less than or equal to the iterator it, false otherwise.
        bool operator<=(const reverse_iterator &it) const
        {
            return (current >= it.current);
        };
        // (21) greater than or equal operator ==> bool operator>= (const reverse_iterator& it) const;
        // Returns true if the iterator is greater than or equal to the iterator it, false otherwise.
        bool operator>=(const reverse_iterator &it) const
        {
            return (current <= it.current);
        };
        // (22) dereference operator ==> reference operator[] (difference_type n);
        // Returns a reference to the element n positions forward from the element the iterator is pointing to.
        reference operator[](difference_type n)
        {
            iterator_type tmp = current;
            return *(--(tmp += n));
        };
        // constexpr reference operator[] (difference_type n) const;
        //  Returns a const reference to the element n positions forward from the element the iterator is pointing to.
        // constexpr reference operator[](difference_type n) const
        // {
        //     iterator_type tmp = current;
        //     return *(--(tmp += n));
        // };
        // (23) dereference operator ==> reference operator[] (difference_type n);
        // Returns a reference to the element n positions backward from the element the iterator is pointing to.
        reference operator[](difference_type n) const
        {
            iterator_type tmp = current;
            return *(--(tmp -= n));
        };
        // constexpr reference operator<=> (const reverse_iterator& it) const;
        //  Returns true if the iterators are equal, false otherwise.
        // constexpr bool operator<=>(const reverse_iterator &it) const
        // {
        //     return (current <= > it.current);
        // };
        // (24) swap function ==> void swap (reverse_iterator& it);
        // Swaps the iterators.
        void swap(reverse_iterator &it)
        {
            std::swap(current, it.current);
        };
        // (25) swap function ==>   friend constexpr void iter_swap(reverse_iterator &it1, reverse_iterator &it2);
        // Swaps the iterators.
        // friend constexpr void iter_swap(reverse_iterator &it1, reverse_iterator &it2)
        // {
        //     std::swap(current, it2.current);
        // };
        // (26) move function ==> reverse_iterator move (reverse_iterator it);
        // Moves the iterator it to the current iterator.
        reverse_iterator move(reverse_iterator it)
        {
            current = it.current;
            return *this;
        };
        // (27) move function ==> reverse_iterator move (reverse_iterator it);
        // Moves the iterator it to the current iterator.
        reverse_iterator move(reverse_iterator it) const
        {
            current = it.current;
            return *this;
        };
        // (28) make_reverse_iterator function ==> reverse_iterator make_reverse_iterator (iterator_type it);
        // Returns a reverse_iterator that points to the same element as the iterator it.
        static reverse_iterator make_reverse_iterator(iterator_type it)
        {
            return reverse_iterator(it);
        };
        // static reverse_iterator make_reverse_iterator(iterator_type it) const
        // {
        //     return reverse_iterator(it);
        // };
        // constexpr reverse_iterator make_reverse_iterator (iterator_type it);
        // Returns a constexpr reverse_iterator that points to the same element as the iterator it.
        // constexpr reverse_iterator make_reverse_iterator(iterator_type it) const
        // {
        //     return reverse_iterator(it);
        // };
    };
} // namespace ft

#endif // REVERS_TRAITS_HPP