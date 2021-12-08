/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:08:01 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/12/08 19:13:57 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterators.hpp"

class reverse_iterator;

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class vector 
    {

    public:
        typedef   T *iterator;
        typedef  T value_type;
        typedef  Alloc::allocator_type;
        typedef  Alloc<T &> reference;
        typedef  Alloc<const T &> const_reference;
        typedef  Alloc<T *> pointer;
        typedef  Alloc<const T *> const_pointer;
        typedef const T *const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        // constructors
            explicit vector(const Alloc& alloc = Alloc()))
            : _data(nullptr), _size(0), _capacity(0), _alloc(Alloc)
            {
            };
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
            ~vector()
            {
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(&_data[i]);
                _alloc.deallocate(_data, _capacity);
            };
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
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            };
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            };
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
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
            size_type max_size() const
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
            // push_back Inserts a new element at the end of the vector, after its current last element. This new element is constructed in place using args as the arguments for its construction.
            void push_back(const T &val)
            {
                if (_size == _capacity)
                {
                    _capacity *= 2; // why double the capacity ?  because we want to have a bigger capacity than the size of the vector to avoid reallocation of memory when we add elements to the vector  .
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
            // pop_back Removes the last element in the vector, effectively reducing the container size by one.
            void pop_back()
            {
                _alloc.destroy(&_data[_size - 1]);
                _size--;
            };
            // insert Inserts a new element at position n in the vector, shifting the element at position n and those after it to the right.
            iterator insert(const_iterator position, const T &val)
            {
                if (_size == _capacity)
                {
                    _capacity *= 2;
                    T *new_data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.construct(&new_data[i], _data[i]);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                }
                for (size_type i = _size; i > position - begin(); i--)
                    _alloc.construct(&_data[i], _data[i - 1]);
                _alloc.construct(&_data[position - begin()], val);
                _size++;
                return iterator(position);
            };

            // insert fill
            void insert(iterator position, size_type n, const T &val)
            {
                if (_size + n > _capacity)
                {
                    _capacity = _size + n;
                    T *new_data = _alloc.allocate(_capacity);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.construct(&new_data[i], _data[i]);
                    for (size_type i = 0; i < _capacity; i++)
                        _alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = new_data;
                }
                for (size_type i = _size; i > position - begin(); i--)
                    _alloc.construct(&_data[i], _data[i - 1]);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(&_data[position - begin() + i], val);
                _size += n;
            };
            // erase Erases the element at position n in the vector, shifting the elements at and after position n to the left.
            iterator erase(const_iterator position)
            {
                for (size_type i = position - begin(); i < _size - 1; i++)
                    _alloc.destroy(&_data[i]);
                _alloc.destroy(&_data[_size - 1]);
                _size--;
                return iterator(position);
            };
            // erase Erases the elements in the range [first, last), shifting the elements at and after last to the left.
            iterator erase(const_iterator first, const_iterator last)
            {
                for (size_type i = first - begin(); i < _size - 1; i++)
                    _alloc.destroy(&_data[i]);
                _alloc.destroy(&_data[_size - 1]);
                _size -= last - first;
                return iterator(first);
            };
            // swap Exchanges the contents of the container by those of x.
            void swap(vector &x)
            {
                ft::swap(_data, x._data);
                ft::swap(_size, x._size);
                ft::swap(_capacity, x._capacity);
            };
            // clear Removes all elements from the vector container, leaving the container with a size of 0.
            void clear()
            {
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(&_data[i]);
                _size = 0;
            };
            // get_allocator Returns a copy of the allocator object associated with the vector.
            allocator_type get_allocator() const
            {
                return _alloc;
            };

        private:
            T *_data;
            size_type _size;
            size_type _capacity;
            allocator_type _alloc;
    };
    // relational operators
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
    {
        if (x.size() != y.size())
            return false;
        for (size_t i = 0; i < x.size(); i++)
            if (x[i] != y[i])
                return false;
        return true;
    };
    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
    {
        return !(x == y);
    };
    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
    {
        if (x.size() < y.size())
            return true;
        else if (x.size() > y.size())
            return false;
        for (size_t i = 0; i < x.size(); i++)
            if (x[i] < y[i])
                return true;
            else if (x[i] > y[i])
                return false;
        return false;
    };
    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
    {
        return y < x;
    };
    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
    {
        return !(x > y);
    };
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
    {
        return !(x < y);
    };
    // swap
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    };

    // template sprcialization ==> vector<bool>
    template <class Alloc>
    class vector<bool, Alloc>
    {
    private:
        typedef bool value_type;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef bool &reference;
        typedef const bool &const_reference;
        typedef bool *pointer;
        typedef const bool *const_pointer;
        typedef bool *iterator;
        typedef const bool *const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    public:
        // vector<bool>::reference is a reference to bool
        // vector<bool>::const_reference is a const reference to bool
        vector<bool>::reference
        {
            friend class vector;
            reference(); // no public constructor
        public:
            ~reference();
            operator bool() const;                    // convert to bool
            reference &operator=(const bool x);       // assign from bool
            reference &operator=(const reference &x); // assign from bit
            void flip();                              // flip bit value.
        };
        // membr functions
        // flip all bits: Flips all values in the container: All instances of true become false, and all instances of false become true.
        void flip()
        {
            for (size_type i = 0; i < _size; i++)
                _data[i] = !_data[i];
        };
        // swap containers
        void swap(vector &x)
        {
            ft::swap(_data, x._data);
            ft::swap(_size, x._size);
            ft::swap(_capacity, x._capacity);
        };
        // swap elelements A static signature to swap individual elements (bits) is added on vector<bool>.
        static void swap(reference x, reference y)
        {
            bool temp = x;
            x = y;
            y = temp;
        };
    };

}

#endif