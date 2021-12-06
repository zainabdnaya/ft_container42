/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:08:01 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/12/06 19:44:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterators.hpp"

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc<T> allocator_type;
        typedef Alloc<T &> reference;
        typedef Alloc<const T &> const_reference;
        typedef Alloc<T *> pointer;
        typedef Alloc<const T *> const_pointer;
        typedef T *iterator;
        typedef const T *const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

        // constructors
            explicit vector(const Alloc& alloc = Alloc()));
            explicit vector(size_type n, const T &value, const Alloc &alloc = Alloc())
            {
                _alloc = alloc;
                _size = n;
                _capacity = n;
                _data = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(&_data[i], value);
            };
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const Alloc &alloc = Alloc())
            {
                _alloc = alloc;
                _size = 0;
                _capacity = 0;
                _data = nullptr;
                for (; first != last; first++)
                    push_back(*first);
            };
            vector(const vector &other)
            {
                _alloc = other._alloc;
                _size = other._size;
                _capacity = other._capacity;
                _data = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(&_data[i], other._data[i]);
            };
            // destructors
            ~vector();
            // oprator=
            vector &operator=(const vector &other)
            {
                if (this != &other)
                {
                    _alloc = other._alloc;
                    _size = other._size;
                    _capacity = other._capacity;
                    _data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.construct(&_data[i], other._data[i]);
                }
                return *this;
            };
            // iterarors

            iterator begin()
            {
                return _data;
            };
            const_iterator begin() const
            {
                return _data;
            };
            iterator end()
            {
                return _data + _size;
            };
            const_iterator end() const
            {
                return _data + _size;
            };
            ft::reverse_iterator rbegin()
            {
                return ft::reverse_iterator(end());
            };
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            };
            ft::reverse_iterator rend()
            {
                return ft::reverse_iterator(begin());
            };
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(begin());
            };
            // capacity
            size_type size() const
            {
                return _size;
            };
            max_size size() const
            {
                return _alloc.max_size();
            };
            // Change size or Resizes the container so that it contains n elements.
            void resize(size_type n)
            {
                // If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
                if (n > _capacity)
                {
                    _capacity = n;
                    T *new_data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.construct(&new_data[i], _data[i]);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                }
                // If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
                else if (n < _size)
                {
                    for (size_type i = n; i < _size; i++)
                        _alloc.destroy(&_data[i]);
                    _size = n;
                }
                // If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
                else if (n > _size)
                {
                    for (size_type i = _size; i < n; i++)
                        _alloc.construct(&_data[i], T());
                    _size = n;
                }
                else if (n == _size)
                    return;
            };
            // capacity if a vector
            size_type capacity() const
            {
                return _capacity;
            };
            // cheque if a vector is empty

            bool empty() const
            {
                if (_size == 0)
                    return true;
                else
                    return false;
            };
            // resere the capacity of a vector meanse request a change in capacity
            void reserve(size_type n)
            {
                // If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
                if (n > _capacity)
                {
                    _capacity = n;
                    T *new_data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.construct(&new_data[i], _data[i]);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                }
            };
            // shrink to fit request to reduce the capacity fo fit it's size
            void shrink_to_fit()
            {
                if (_size < _capacity)
                {
                    T *new_data = _alloc.allocate(_size);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.construct(&new_data[i], _data[i]);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                    _capacity = _size;
                }
            };
            // element access
            //  operator[] Returns a reference to the element at position n in the vector container.
            reference operator[](size_type n)
            {
                return _data[n];
            };
            const_reference operator[](size_type n) const
            {
                return _data[n];
            };
            // at Returns a reference to the element at position n in the vector container.
            reference at(size_type n)
            {
                if (n >= _size)
                    throw std::out_of_range("out of range");
                return _data[n];
            };
            const_reference at(size_type n) const
            {
                if (n >= _size)
                    throw std::out_of_range("out of range");
                return _data[n];
            };
            // front Returns a reference to the first element in the vector container.
            reference front()
            {
                return _data[0];
            };
            const_reference front() const
            {
                return _data[0];
            };
            // back Returns a reference to the last element in the vector container.
            reference back()
            {
                return _data[_size - 1];
            };
            const_reference back() const
            {
                return _data[_size - 1];
            };
            // This in c11+ data Returns a pointer to the first element in the vector container. This is the only way to obtain a pointer to the underlying array.
            //  value_type* data()
            //  {
            //      return _data;
            //  };
            //  const value_type* data() const
            //  {
            //      return _data;
            //  };
            // Modifiers
            // to fill assign Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
            void assign(size_type n, const T &val)
            {
                if (n > _capacity)
                {
                    _capacity = n;
                    T *new_data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.construct(&new_data[i], val);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                }
                else if (n < _size)
                {
                    for (size_type i = n; i < _size; i++)
                        _alloc.destroy(&_data[i]);
                    _size = n;
                }
                else if (n > _size)
                {
                    for (size_type i = _size; i < n; i++)
                        _alloc.construct(&_data[i], val);
                    _size = n;
                }
                else if (n == _size)
                    return;
            };
            // range elements
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last) 
            {
                size_type n = last - first;
                if (n > _capacity)
                {
                    _capacity = n;
                    T *new_data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.construct(&new_data[i], *(first + i));
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                }
                else if (n < _capacity)
                {
                    for (size_type i = n; i < _size; i++)
                        _alloc.destroy(&_data[i]);
                    _size = n;
                }
                else if (n == _size)
                    return;
            };
            //push_back Inserts a new element at the end of the vector, after its current last element. This new element is constructed in place using args as the arguments for its construction.
            void push_back(const T &val)
            {
                if (_size == _capacity)
                {
                    _capacity *= 2;//why double the capacity ?  because we want to have a bigger capacity than the size of the vector to avoid reallocation of memory when we add elements to the vector  .
                    T *new_data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.construct(&new_data[i], _data[i]);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                }
                _alloc.construct(&_data[_size], val);
                _size++;
            };

        private:
            T *_data;
            size_type _size;
            size_type _capacity;
            allocator_type _alloc;
    };

    // template <typename T>
    // vector<T>::vector() : _data(nullptr), _size(0), _capacity(0)
    // {
    // }

}

#endif