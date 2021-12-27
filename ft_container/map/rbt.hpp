/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:07:47 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/27 12:52:18 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP
#include "../iterators/iterator_traits.hpp"
#include "../iterators/make_pair.hpp"
#include <limits>

namespace ft
{

    template <typename Key, class T>
    struct Node
    {
        Key key;
        T val;
        unsigned int height;
        bool isBlack;
        int isLeft;
        Node *left;
        Node *right;
        Node *parent;
        int right_black_leafs;
        int left_black_leafs;
    };

    template <typename Key, class T, class Compare = std::less<Key>,
              class Alloc = std::allocator<ft::Node<Key, T> > >
    class RBT
    {
    private:
        typedef Node<Key, T> node;
        Compare comp;
        Alloc alloc;
        node *root;
        node *TNULL;
        int isRBProper(node *n)
        {
            if (n == NULL)
                return 1;
            if (n->isBlack == false && ((n->left != NULL && n->left->isBlack == false) || (n->right != NULL && n->right->isBlack == false)))
                return 0;
            return isRBProper(n->left) && isRBProper(n->right);
        }

    public:
        RBT()
        {
            TNULL = alloc.allocate(1);
            TNULL->key = std::max(std::numeric_limits<Key>::min(), std::numeric_limits<Key>::max());
            TNULL->isBlack = true;
            TNULL->left = NULL;
            TNULL->right = NULL;
            root = TNULL;
            comp = Compare();
        }

        ~RBT()
        {
        }

        void insert_node(Key key, T val)
        {
            if (root == TNULL)
            {
                root = alloc.allocate(1);
                root->isBlack = true;
                root->key = key;
                root->val = val;
                root->left = TNULL;
                root->right = TNULL;
                root->parent = NULL;
            }
            else
            {
                node *tmp = this->root;
                node *tmp2 = NULL;
                node *_new = alloc.allocate(1);
                _new->key = key;
                _new->val = val;
                _new->left = TNULL;
                _new->right = TNULL;
                _new->parent = NULL;
                _new->isBlack = false;
                while (tmp != TNULL)
                {
                    tmp2 = tmp;
                    if (comp(key, tmp->key))
                        tmp = tmp->left;
                    else if (comp(tmp->key, key))
                        tmp = tmp->right;
                    else
                        return;
                }
                _new->parent = tmp2;
                if (tmp2->key > _new->key)
                {
                    tmp2->left = _new;
                }
                else if (tmp2->key < _new->key)
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
            if (n->parent == NULL)
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
            if (n->parent == NULL)
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

        void delete_fix_rbt(node *x)
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

        node *search(Key key)
        {
            node *tmp = root;
            while (tmp != TNULL)
            {
                if (comp(key, tmp->key) > 0)
                    tmp = tmp->left;
                else if (comp(key, tmp->key) < 0)
                    tmp = tmp->right;
                else
                    return tmp;
            std::cout << "searching for " << tmp->key << std::endl;
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
            while (x->left != TNULL)
                x = x->left;
            return (x);
        }
        void delete_node(Key key)
        {
            node *_node = search(key);

            if (_node == TNULL)
            {
                std::cout << "Key not found in the tree" << std::endl;
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
            if (y_original_color == true)
                delete_fix_rbt(x);
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
                std::cout << node->key << "(" << sColor << ")" << std::endl;
                // node = node->left;
                print(node->left, indent, false);
                // node = node->right;
                print(node->right, indent, true);
            }
        }
        void check_print_rbt()
        {
            if (root)
                print(this->root, "", true);
        }

        int isRBTProper()
        {
            return this->isRBProper(root);
        }
    };
}

#endif
