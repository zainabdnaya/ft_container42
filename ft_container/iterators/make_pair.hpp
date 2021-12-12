/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:50:11 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/12 00:57:06 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// why use ifndef befor define?
// ifndef is used to prevent multiple inclusion
// define is used to define a symbol

#ifndef MAKE_PAIR_HPP
#define MAKE_PAIR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;
        // constuctor
        pair() : first(), second(){};
        pair(const T1 &a, const T2 &b) : first(a), second(b){};
        pair(const pair &p) : first(p.first), second(p.second){};
        // Menber function operators
        // operator=(const pair &p)
        // {
        //     first = p.first;
        //     second = p.second;
        // };
        &operator=(const pair &p)
        {
            first = p.first;
            second = p.second;
        };
    };
    // non member function & operators
    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 t1, T2 t2)
    {
        return pair<T1, T2>(t1, t2);
    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first == p2.first && p1.second == p2.second);
    };

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first != p2.first || p1.second != p2.second);
    };
    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first < p2.first || p1.second < p2.second);
    };

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first > p2.first || p1.second > p2.second);
    };

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first <= p2.first || p1.second <= p2.second);
    };

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first >= p2.first || p1.second >= p2.second);
    };

    // swap function for oair
    template <class T1, class T2>
    void swap(pair<T1, T2> &p1, pair<T1, T2> &p2)
    {
        pair<T1, T2> temp = p1;
        p1 = p2;
        p2 = temp;
    };
    // get function for pair accesses an element of a pair
    template <std::size_t I, class T1, class T2>
    typename std::enable_if<I == 0, T1>::type &get(pair<T1, T2> &p)
    {
        return p.first;
    };
    // template <class T1, class T2>
    // T1 &get<0>(pair<T1, T2> &p)
    // {
    //     return p.first;
    // };
    // template <class T1, class T2>
    // T2 &get<1>(pair<T1, T2> &p)
    // {
    //     return p.second;
    // };
    //add my std::less
    template <class Arg1, class Arg2,class Result>
    struct  binary_function
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };
    
    template <class T>
    struct less : public ft::binary_function<T, T, bool>
    {
        bool operator()(const T &a, const T &b) const
        {
            return (a < b);
        };
        first_argument_type operator()(const T &a) const
        {
            return a.first;
        };
        second_argument_type operator()(const T &a) const
        {
            return a.second;
        };
        result_type operator()(const T &a, const T &b) const
        {
            return (a < b);
        };
        
    };
}
#endif