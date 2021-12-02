/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:08:01 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/12/02 20:00:26 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterators.hpp"


namespace ft 
{
    template <typename T>
    class vector
    {
        public:
            typedef T value_type;
            typedef T* iterator;
            typedef const T* const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            typedef T& reference;
            typedef const T& const_reference;

    //         vector();
    //         vector(size_type n);
    //         vector(size_type n, const T& val);
    //         vector(const vector& other);
    //         vector(vector&& other);
    //         ~vector();

    //         vector& operator=(const vector& other);
    //         vector& operator=(vector&& other);

    //         iterator begin()
    //         {
    //             return _data;
    //         };
    //         const_iterator begin() const;
    //         iterator end();
    //         const_iterator end() const;
    //         reverse_iterator rbegin();
    //         const_reverse_iterator rbegin() const;
    //         reverse_iterator rend();
    //         const_reverse_iterator rend() const;

    //         size_type size() const;
    //         size_type max_size() const;
    //         size_type capacity() const;
    //         bool empty() const;

    //         reference operator[](size_type n);
    //         const_reference operator[](size_type n) const;
    //         reference at(size_type n);
    //         const_reference at(size_type n) const;
    //         reference front();
    //         const_reference front() const;
    //         reference back();
    //         const_reference back() const;

    //         void push_back(const T& val);
    //         void push_back(T&& val);
    //         void pop_back();
    //         void resize(size_type n);
    //         void resize(size_type n, const T& val);
    //         void reserve(size_type n);
    //         void shrink_to_fit();

    //         void swap(vector& other);

    //     private:
    //         T* _data;
    //         size_type _size;
    //         size_type _capacity;
    };

    // template <typename T>
    // vector<T>::vector() : _data(nullptr), _size(0), _capacity(0)
    // {
    // }
    
}



#endif