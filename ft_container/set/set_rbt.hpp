/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set__set.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:59:39 by zainabdnaya       #+#    #+#             */
/*   Updated: 2022/01/03 19:01:00 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _set_HPP
#define _set_HPP

#include "../tools/iterator_traits.hpp"
#include "../tools/reverse_iterators.hpp"
#include "../tools/make_pair.hpp"
#include "../tools/is_integral.hpp"
#include <limits>

namespace ft
{
    template <class T>
    struct Node
    {
        bool isBlack;
        unsigned int height;
        T data;
        Node *left;
        Node *right;
        Node *parent;
    };
    template <class tree, class Iter, class T>
    class _set_iterator : public std::iterator<std::bidirectional_iterator_tag,
                                               typename iterator_traits<T>::value_type>
    {
    public:
        typedef Iter iterator_type;
        typedef tree _set;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef std::bidirectional_iterator_tag iterator_category;
        // const pointer operator->() const { return &(this->_ptr->data); }
        typedef std::ptrdiff_t difference_type;

        iterator_type *it;
        _set _set_;

    public:
        _set_iterator() : it(), _set_()
        {
        }

        _set_iterator(iterator_type *_x, _set _tr) : it(_x), _set_(_tr)
        {
        }

        template <class OthTree, class OthIter, class U>
        _set_iterator(const _set_iterator<OthTree, OthIter, U> &_other) : it(_other.it), _set_(_other._set_)
        {
        }

        template <class OthTree, class OthIter, class U>
        _set_iterator &operator=(const _set_iterator<OthTree, OthIter, U> &_other)
        {
            this->it = _other.base();
            this->_set_ = _other.get__set();
            return (*this);
        }

        reference operator*()
        {
            return it->data;
        }

        pointer operator->()
        {
            return &(operator*());
        }

        _set_iterator &operator++()
        {
            it = _set_->successor(it);
            return *this;
        }

        _set_iterator operator++(int)
        {
            _set_iterator tmp(*this);
            it = _set_->successor(it);
            return tmp;
        }

        _set_iterator &operator--()
        {
            it = _set_->predecessor(it);
            return *this;
        }

        _set_iterator operator--(int)
        {
            _set_iterator tmp(*this);
            it = _set_->predecessor(it);
            return tmp;
        }

        bool operator==(const _set_iterator &_set_iter) const
        {
            return it == _set_iter.it;
        }

        bool operator!=(const _set_iterator &_set_iter) const
        {
            return it != _set_iter.it;
        }

        iterator_type get_iterator() const
        {
            return it;
        }

        _set get__set() const
        {
            return _set_;
        }
    };

    template <class T, class Compare,
              class Alloc>
    class _set
    {
    public:
        // typedef Key  key_type;
        typedef T value_type; // pair<key_type, val> --> T
        typedef struct Node<value_type> node;
        typedef typename Alloc::template rebind<node>::other allocator_type;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename Alloc::const_pointer const_node_pointer;
        typedef typename Alloc::reference node_reference;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::difference_type difference_type;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::const_reference const_node_reference;
        typedef struct Node<value_type> *NodePtr;
        typedef _set *self;
        typedef ft::_set_iterator<self, node, pointer> iterator;
        typedef ft::_set_iterator<self, node, pointer> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename Alloc::size_type size_type;
        Compare comp;
        size_type _size;
        allocator_type alloc;
        node *root;
        node *TNULL;
        node *Tend;

        int isRBProper(node *n)
        {
            if (n == NULL)
                return 1;
            if (n->isBlack == false && ((n->left != NULL && n->left->isBlack == false) || (n->right != NULL && n->right->isBlack == false)))
                return 0;
            return isRBProper(n->left) && isRBProper(n->right);
        }

        _set()
        {
            TNULL = alloc.allocate(1);
            Tend = alloc.allocate(1);
            Tend->right = TNULL;
            TNULL->isBlack = true;
            TNULL->left = NULL;
            TNULL->right = NULL;
            root = TNULL;
            Tend->left = root;
            Tend->parent = Tend;
            comp = Compare();
            _size = 0;
        }

        ~_set()
        {
            int i = -1;
            if (TNULL->right != Tend)
            {
                this->clear();
                alloc.destroy(TNULL);
                alloc.deallocate(TNULL, 1);
                TNULL->right = Tend;
                i = 1;
            }
            if (Tend->right != Tend)
            {
                if (i == -1)
                    this->clear();
                alloc.destroy(Tend);
                alloc.deallocate(Tend, 1);
                Tend->right = Tend;
            }
        }

        void insert_node(T data)
        {
            if (root == TNULL)
            {
                root = alloc.allocate(1);
                root->isBlack = true;
                root->data = data;
                root->left = TNULL;
                root->right = TNULL;
                root->parent = Tend;
                _size++;
            }
            else
            {
                node *tmp = this->root;
                node *tmp2 = TNULL;
                node *_new = alloc.allocate(1);
                _size++;
                _new->data = data;
                _new->left = TNULL;
                _new->right = TNULL;
                _new->parent = Tend;
                _new->isBlack = false;
                while (tmp != TNULL)
                {
                    tmp2 = tmp;
                    if (comp(data, tmp->data))
                        tmp = tmp->left;
                    else if (comp(tmp->data, data))
                        tmp = tmp->right;
                    else
                        return;
                }
                _new->parent = tmp2;
                if (tmp2->data > _new->data)
                {
                    tmp2->left = _new;
                }
                else if (tmp2->data < _new->data)
                {
                    tmp2->right = _new;
                }
                check_balance(_new);
            }
        }

        void rotate_right(node *n)
        {

            node *l = n->left;
            n->left = l->right;
            if (l->right != TNULL)
                l->right->parent = n;
            l->parent = n->parent;
            if (n->parent == TNULL || n->parent == Tend)
                root = l;
            else if (n == n->parent->left)
                n->parent->left = l;
            else
                n->parent->right = l;
            l->right = n;
            n->parent = l;
        }

        void rotate_left(node *n)
        {
            node *r = n->right;
            n->right = r->left;
            if (r->left != TNULL)
                r->left->parent = n;
            r->parent = n->parent;
            if (n->parent == TNULL || n->parent == Tend)
                root = r;
            else if (n == n->parent->left)
                n->parent->left = r;
            else
                n->parent->right = r;
            r->left = n;
            n->parent = r;
        }

        void check_balance(node *_node)
        {
            node *tmp;
            while (_node->parent->isBlack == false)
            {
                if (_node->parent == _node->parent->parent->right)
                {
                    tmp = _node->parent->parent->left;
                    if (tmp && tmp->isBlack == false)
                    {
                        tmp->isBlack = true;
                        _node->parent->isBlack = true;
                        _node->parent->parent->isBlack = false;
                        _node = _node->parent->parent;
                    }
                    else
                    {
                        if (_node == _node->parent->left)
                        {
                            _node = _node->parent;
                            rotate_right(_node);
                        }
                        _node->parent->isBlack = true;
                        _node->parent->parent->isBlack = false;
                        rotate_left(_node->parent->parent);
                    }
                }
                else
                {
                    tmp = _node->parent->parent->right;
                    if (tmp && tmp->isBlack == false)
                    {
                        tmp->isBlack = true;
                        _node->parent->isBlack = true;
                        _node->parent->parent->isBlack = false;
                        _node = _node->parent->parent;
                    }
                    else
                    {
                        if (_node == _node->parent->right)
                        {
                            _node = _node->parent;
                            rotate_left(_node);
                        }
                        _node->parent->isBlack = true;
                        _node->parent->parent->isBlack = false;
                        rotate_right(_node->parent->parent);
                    }
                }
                if (_node == root)
                    break;
            }
            root->isBlack = true; // root is always black
            root->parent = Tend;
            // root->isLeft = -1;
        }

        int height_right(node *_node)
        {
            node *tmp = _node->right;
            int h = 0;
            while (tmp != NULL)
            {
                if (tmp->isBlack == true)
                    h++;
                tmp = tmp->right;
            }
            tmp = _node->right;
            while (tmp != NULL)
            {
                node *tmp2 = tmp->left;
                while (tmp2 != NULL)
                {
                    if (tmp2->isBlack == true)
                        h++;
                    tmp2 = tmp2->left;
                }
                tmp = tmp->right;
            }
            return h;
        }

        int height_left(node *_node)
        {
            node *tmp = _node->left;
            int h = 0;
            while (tmp != NULL)
            {
                if (tmp->isBlack == true)
                    h++;
                tmp = tmp->left;
            }

            tmp = _node->left;
            while (tmp != NULL)
            {
                node *tmp2 = tmp->right;
                while (tmp2 != NULL)
                {
                    if (tmp2->isBlack == true)
                        h++;
                    tmp2 = tmp2->right;
                }
                tmp = tmp->left;
            }

            return h;
        }

        void delete_fix__set(node *x)
        {
            node *tmp;

            while (x && x != root && x->isBlack == true)
            {
                if (x == x->parent->left)
                {
                    tmp = x->parent->right;
                    if (tmp->isBlack == false)
                    {
                        tmp->isBlack = true;
                        x->parent->isBlack = false;
                        rotate_left(x->parent);
                        tmp = x->parent->right;
                    }
                    if ((tmp && (tmp->left->isBlack == true && tmp->right->isBlack == true)) || (tmp->left == NULL && tmp->right == NULL))
                    {
                        tmp->isBlack = false;
                        x = x->parent;
                    }
                    else
                    {
                        if (tmp->right->isBlack == true)
                        {
                            tmp->left->isBlack = true;
                            tmp->isBlack = false;
                            rotate_right(tmp);
                            tmp = x->parent->right;
                        }
                        tmp->isBlack = x->parent->isBlack;
                        x->parent->isBlack = true;
                        tmp->right->isBlack = true;
                        rotate_left(x->parent);
                        x = root;
                    }
                }
                else
                {
                    tmp = x->parent->left;
                    if (tmp->isBlack == false)
                    {
                        tmp->isBlack = true;
                        x->parent->isBlack = false;
                        rotate_right(x->parent);
                        tmp = x->parent->left;
                    }
                    if ((tmp && (tmp->left->isBlack == true && tmp->right->isBlack == true)) || (tmp->left == NULL && tmp->right == NULL))
                    {
                        tmp->isBlack = false;
                        x = x->parent;
                    }
                    else
                    {
                        if (tmp->left->isBlack == true)
                        {
                            tmp->right->isBlack = true;
                            tmp->isBlack = false;
                            rotate_left(tmp);
                            tmp = x->parent->left;
                        }
                        tmp->isBlack = x->parent->isBlack;
                        x->parent->isBlack = true;
                        tmp->left->isBlack = true;
                        rotate_right(x->parent);
                        x = root;
                    }
                }
            }
            x->isBlack = true;
        }

        node *search(value_type key)
        {
            node *tmp = root;
            // std::cout << "here I m " << (tmp == Tend ? "Tend" : "TNULL") << key << std::endl;
            while (tmp != Tend && tmp != TNULL)
            {
                if (comp(key, tmp->data))
                    tmp = tmp->left;
                else if (comp(tmp->data, key))
                    tmp = tmp->right;
                else
                    return tmp;
            }
            return TNULL;
        }

        node *const_search(const value_type key) const
        {
            node *tmp = root;
            while (tmp != TNULL && tmp != Tend)
            {
                if (comp(key, tmp->data))
                    tmp = tmp->left;
                else if (comp(tmp->data, key))
                    tmp = tmp->right;
                else
                    return tmp;
            }
            return TNULL;
        }
        void transplant(node *u, node *v)
        {
            if (!u->parent)
                root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            if (v)
                v->parent = u->parent;
        }

        node *tree_minimum(node *x)
        {

            while (x && x->left != TNULL)
                x = x->left;
            return (x);
        }

        void delete_node(T data)
        {
            node *_node = search(data);

            if (_node == TNULL)
            {
                std::cout << "Key not found in the tree " << data << std::endl;
                return;
            }

            node *x = TNULL;
            node *y = TNULL;
            y = _node;
            bool y_original_color = y->isBlack;

            if (_node->left == TNULL)
            {
                x = _node->right;
                transplant(_node, _node->right);
            }
            else if (_node->right == TNULL)
            {
                x = _node->left;
                transplant(_node, _node->left);
            }
            else
            {
                y = tree_minimum(_node->right);
                y_original_color = y->isBlack;
                x = y->right;
                if (x && y->parent == _node)
                {
                    x->parent = y;
                }
                else
                {
                    transplant(y, y->right);
                    y->right = _node->right;
                    if (y->right)
                        y->right->parent = y;
                }
                transplant(_node, y);
                y->left = _node->left;
                y->left->parent = y;
                y->isBlack = _node->isBlack;
            }
            alloc.destroy(_node);
            alloc.deallocate(_node, 1);
            _size--;
            if (y_original_color == true)
                delete_fix__set(x);
            if (root != TNULL && root)
                root->isBlack = true;
        }

        void print(node *node, std::string indent, bool last)
        {
            if (node != TNULL)
            {
                std::cout << indent;
                if (last)
                {
                    std::cout << "R----";
                    indent += "   ";
                }
                else
                {
                    std::cout << "L----";
                    indent += "|  ";
                }

                std::string sColor = node->isBlack == false ? "RED" : "BLACK";
                std::cout << node->data << "(" << sColor << ")" << std::endl;
                // node = node->left;
                print(node->left, indent, false);
                // node = node->right;
                print(node->right, indent, true);
            }
        }
        void check_print__set()
        {
            if (root)
                print(this->root, "", true);
        }

        int is_setProper()
        {
            return this->isRBProper(root);
        }

        node *successor(node *n)
        {
            if (n && n->right != TNULL)
                return tree_minimum(n->right);
            // std::cout << "here" << std::endl;
            node *tmp = n->parent;
            while (tmp != TNULL && tmp != Tend && n == tmp->right)
            {
                n = tmp;
                tmp = tmp->parent;
            }
            return (tmp);
        }

        node *treeMaximum(node *n)
        {
            while (n->right != TNULL)
                n = n->right;
            return n;
        }

        node *predecessor(node *n)
        {
            if (n->left != TNULL && n->left != Tend)
                return treeMaximum(n->left);
            node *tmp = n->parent;
            while (tmp != Tend && n == tmp->left)
            {
                n = tmp;
                tmp = tmp->parent;
            }
            if (tmp == Tend)
                return treeMaximum(root);
            return (tmp);
        }
        /// add begin()
        iterator begin()
        {
            // check_print__set();

            return iterator(tree_minimum(root), this);
        }
        //
        const_iterator cbegin()
        {
            return const_iterator(tree_minimum(root), this);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator crbegin()
        {
            return const_reverse_iterator(cend());
        }
        /// add end()
        iterator end()
        {
            return iterator(Tend, this);
        }

        const_iterator cend()
        {
            return const_iterator(Tend, this);
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator crend()
        {
            return const_reverse_iterator(cbegin());
        }

        // add empty
        bool empty() const
        {
            if (root == TNULL)
                return true;
            return false;
        }
        // add size
        size_type size() const
        {
            return this->_size;
        }

        // max size
        size_type max_size() const
        {
            return std::numeric_limits<difference_type>::max();
        }

        // erase
        void erase(iterator it)
        {
            // node *tmp = ;
            delete_node(_search(it));
        }
        // erase
        void erase(iterator first, iterator last)
        {
            while (first != last)
            {
                // std::cout << "erase " << first.it->data << std::endl;
                erase(first);
                ++first;
            }
        }
        // erase
        size_type erase(const T &data)
        {

            node *_node = search(data);

            if (_node == TNULL)
                return 0;
            delete_node(data);
            return 1;
        }

        // swap
        void swap(_set &other)
        {

            root = other.root;
            _size = other._size;
            Tend = other.Tend;
            TNULL = other.TNULL;
        }
        // find
        iterator find(const T &data)
        {

            node *_node = search(data);
            if (_node == TNULL)
                return iterator(Tend, this);

            return iterator(_node, this);
        }
        // find
        const_iterator find(const T &data) const
        {

            node *_node = const_search(data);
            if (const_search(data) == TNULL)
                return const_iterator(Tend, this);
            return const_iterator(_node, this);
        }
        // count
        size_type count(const T &data) const
        {
            node *_node = const_search(data);
            if (_node == TNULL)
                return 0;
            return 1;
        }
        // lowe nee
        //  lower_bound
        iterator lower_bound(const T &data)
        {
            iterator _from = this->begin();
            iterator _to = this->end();

            while (_from != _to)
            {
                if (!comp((*_from), data))
                    return _from;
                _from++;
            }
            return _from;
        }

        const_iterator lower_bound(const T &data) const
        {
            return const_iterator(lower_bound(data));
        }
        // upper_bound
        iterator upper_bound(const T &data)
        {
            iterator _from = this->begin();
            iterator _to = this->end();

            while (_from != _to)
            {
                if (comp(data, (*_from)))
                    return _from;
                _from++;
            }
            return _from;
        }
        // upper_bound
        const_iterator upper_bound(const T &data) const
        {
            return const_iterator(upper_bound(data));
        }
        // equal_range
        ft::pair<iterator, iterator> equal_range(const T &data)
        {
            return ft::make_pair(lower_bound(data), upper_bound(data));
        }
        // equal_range
        ft::pair<const_iterator, const_iterator> equal_range(const T &data) const
        {
            return ft::make_pair(lower_bound(data), upper_bound(data));
        }
        // clear_tree
        void clear_tree(node *n)
        {
            if (n && n != TNULL && n != Tend)
            {
                clear_tree(n->left);
                clear_tree(n->right);
                if (n->left != Tend && n->right != Tend)
                {
                    alloc.destroy(n);
                    alloc.deallocate(n, 1);
                }
                n->left = Tend;
                n->right = Tend;
            }
            else
                return;
        }
        // clear
        void clear()
        {
            clear_tree(root);
        }
        // searsh by iterator

        T _search(iterator it)
        {
            node *_node = root;
            while (_node && _node != TNULL && _node != Tend)
            {
                if (_node->data > *it)
                    _node = _node->left;
                else if (*it > _node->data)
                    _node = _node->right;
                else
                    return _node->data;
            }
            if (_node == Tend)
                return _node->data;
            else
                return TNULL->data;
        }
        allocator_type get_allocator() const
        {
            return alloc;
        }
    };
}

#endif
