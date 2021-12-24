/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/24 18:29:59 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <new>

class RBT
{
public:
    typedef struct node
    {
        int key;
        int val;
        unsigned int height;
        bool isBlack;
        int isLeft;
        node *left;
        node *right;
        node *parent;
        int right_black_leafs;
        int left_black_leafs;
        node(int key)
        {
            parent = NULL;
            left = NULL;
            right = NULL;
            isBlack = false;
            this->key = key;
            isLeft = false;
            // isRight = false;
            height = 1;
            // count = 0;
        }

    } node;
    node *fill_node(int key, int value)
    {
        node *_node = new node(key);
        _node->val = value;
        _node->isBlack = true;
        _node->left = NULL;
        _node->right = NULL;
        _node->parent = NULL;
        return (_node);
    }
    node *root;
    node *tmp2;

    RBT()
    {
        this->root = NULL;
    }

    ~RBT()
    {
    }

    void print_tree(node *_root)
    {
        if (!_root)
            return;
        print_tree(_root->left);
        std::cout << "---> " << _root->key << "  " << _root->val << " " << _root->parent->key << std::endl;
        print_tree(_root->right);
    }

    void insert_node(node *_new)
    {
        if (root == NULL)
        {
            root = _new;
            root->isBlack = true;
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
        }
        else
        {
            node *tmp = root;
            node *tmp2 = NULL;

            while (tmp != NULL)
            {
                tmp2 = tmp;
                if (_new->key < tmp->key)
                {
                    tmp = tmp->left;
                }
                else if (_new->key > tmp->key)
                {
                    tmp = tmp->right;
                }
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
            _new->isBlack = false;
            check_balance(_new);
        }
    }

    int isRBProper(node *n)
    {
        if (n == NULL)
            return 1;
        if (n->isBlack == false && ((n->left != NULL && n->left->isBlack == false) || (n->right != NULL && n->right->isBlack == false)))
            return 0;
        return isRBProper(n->left) && isRBProper(n->right);
    }

    void rotate_right(node *n)
    {

        node *l = n->left;
        if (l == NULL)
            return;
        n->left = l->right;
        if (l->right != NULL)
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
        if (r == NULL)
            return;
        n->right = r->left;
        if (r->left != NULL)
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
                // std::cout << "parent is left\t " << _node->key << std::endl;
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
        // count number of black in sibling of right
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
        // count right of left
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
        if (x != NULL)
            x->isBlack = true;
    }

    node *search(int key)
    {
        node *tmp = root;
        while (tmp != NULL)
        {
            if (tmp->key == key)
                return tmp;
            else if (tmp->key > key)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return NULL;
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
        while (x->left != NULL)
            x = x->left;
        return (x);
    }
    void delete_node(int key)
    {
        node *_node = search(key);
        if (_node == NULL)
        {
            std::cout << "Key not found in the tree" << std::endl;
            return;
        }
        node *x;
        node *y;
        y = _node;
        bool y_original_color = y->isBlack;
        if (!_node->left)
        {
            x = _node->right;
            transplant(_node, _node->right);
        }
        else if (!_node->right)
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
        delete _node;
        if (y_original_color == true)
            delete_fix_rbt(x);
        // else
        //     delete_fix_rbt(root);
        // if (height_left(root) > height_right(root))
        // {
        //     if (root->right)
        //         rotate_left(root->right);
        //     else
        //     {
        //         rotate_left(root);
        //         rotate_right(root);
        //     }
        // }
        // else if (height_left(root) < height_right(root))
        // {
        //     if (root->left)
        //         rotate_right(root->left);
        //     else
        //     {
        //         rotate_right(root);
        //         rotate_left(root);
        //     }
        // }
        // else
        //     ;
        root->isBlack = true;
    }

    void check_print_rbt(node *n)
    {
        if (n == root)
            std::cout << "\033[0;31m <====================\t\tRoot : " << n->key << "\t\t=========================>\033[0m" << std::endl;
        if (n == NULL)
            return;
        check_print_rbt(n->left);
        std::cout << "Key: " << n->key << "\t\tColor:\t{   " << (n->isBlack == 0 ? "RED" : "BLACK") << "  }\t\tParent: \t" << (n->parent == NULL ? "\033[0;31mROOT " : std::to_string(n->parent->key)) << "\033[0m " << std::endl;
        check_print_rbt(n->right);
    }
};

int main()
{
    RBT tst;

    // segfault ==> delete 3
    // tst.insert_node(tst.fill_node(7, 7));
    // tst.insert_node(tst.fill_node(18, 18));
    // tst.insert_node(tst.fill_node(3, 3));
    // tst.insert_node(tst.fill_node(10, 10));
    // tst.insert_node(tst.fill_node(22, 22));
    // tst.insert_node(tst.fill_node(11, 11));
    // tst.insert_node(tst.fill_node(8, 8));
    // tst.insert_node(tst.fill_node(26, 26));

    // wrong output ==> to delete 11
    tst.insert_node(tst.fill_node(13, 13));
    tst.insert_node(tst.fill_node(17, 17));
    tst.insert_node(tst.fill_node(8, 8));
    tst.insert_node(tst.fill_node(25, 25));
    tst.insert_node(tst.fill_node(15, 15));
    tst.insert_node(tst.fill_node(1, 1));
    tst.insert_node(tst.fill_node(11, 11));
    tst.insert_node(tst.fill_node(6, 6));
    tst.insert_node(tst.fill_node(27, 27));
    tst.insert_node(tst.fill_node(22, 22));

    // wrong output ==> to delete 8
    // tst.insert_node(tst.fill_node(13, 13));
    // tst.insert_node(tst.fill_node(17, 17));
    // tst.insert_node(tst.fill_node(8, 8));
    // tst.insert_node(tst.fill_node(25, 25));
    // tst.insert_node(tst.fill_node(15, 15));
    // tst.insert_node(tst.fill_node(1, 1));
    // tst.insert_node(tst.fill_node(11, 11));
    // tst.insert_node(tst.fill_node(6, 6));
    // tst.insert_node(tst.fill_node(27, 27));
    // tst.insert_node(tst.fill_node(22, 22));
    // tst.insert_node(tst.fill_node(26, 26));
    // tst.insert_node(tst.fill_node(27, 27));

    tst.check_print_rbt(tst.root);
    std::cout << "*************************************************************\n";
    tst.delete_node(8);
    tst.check_print_rbt(tst.root);
    std::cout << "RBT is " << (tst.isRBProper(tst.root) ? "GOOD" : "NOOT GOOD") << "\n";
    std::cout << "*************************************************************\n";
    // tst.insert_node(tst.fill_node(2, 2));
    // tst.insert_node(tst.fill_node(5, 5));

    // std::cout << "RBT is " << (tst.isRBProper(tst.root) ? "GOOD" : "NOOT GOOD") << "\n";

    return 0;
}
