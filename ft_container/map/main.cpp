/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/22 06:42:57 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <new>

// this is a red black tree simple implementation

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
        // bool isRight;
        node *left;
        node *right;
        node *parent;
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
        }

    } node;
    node *fill_node(int key, int value)
    {
        node *_node = new node(key);
        _node->val = value;
        return (_node);
    }
    RBT();
    ~RBT();
    node *root;
    node *tmp;
    node *tmp2;
    void print_tree(node *_root);
    void insert_node(node *_new);
    // void color_fix(RBT *node);
    void rotate_left(node *node);
    void rotate_right(node *node);
    // void rotae_left_right(node *node);
    // void rotae_right_left(node *node);
    void check_balance(node *node);
    void check_print_rbt(node *root);
    int isRBProper(node *n);
};

RBT::RBT()
{
    this->root = NULL;
}

RBT::~RBT()
{
}

void RBT::print_tree(node *_root)
{
    //  && !root->right )
    //     return;
    if (!_root)
        return;
    print_tree(_root->left);
    std::cout << "---> " << _root->key << "  " << _root->val << " " << _root->parent->key << std::endl;
    print_tree(_root->right);
}

void RBT::insert_node(node *_new)
{
    if (root == NULL)
    {
        root = _new;
        root->isBlack = true;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        root->isLeft = -1;
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
                break;
        }
        _new->parent = tmp2;
        if (tmp2->key > _new->key)
        {
            tmp2->left = _new;
            _new->isLeft = true;
        }
        else if (tmp2->key < _new->key)
        {
            tmp2->right = _new;
            _new->isLeft = false;
        }
        else
            return;
        // std::cout << _new->key << "----" << _new->parent->key <<"\n";
        _new->isBlack = false;
        _new->left = NULL;
        _new->right = NULL;
        check_balance(_new);
    }
}

int RBT::isRBProper(node *n)
{
    if (n == NULL)
        return 1;
    if (n->isBlack == false && ((n->left != NULL && n->left->isBlack == false) || (n->right != NULL && n->right->isBlack == false)))
        return 0;
    return isRBProper(n->left) && isRBProper(n->right);
}

void RBT::rotate_right(node *n)
{
    node *l = n->left;
    //    std::cout << l->key;
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

void RBT::rotate_left(node *n)
{
}

void RBT::check_balance(node *_node)
{

    while (_node && _node != root && _node->parent->isBlack == false)
    {
        if (_node->parent->isLeft == true)
        {
            if (_node->isLeft == true)
            {
                if (_node->parent->parent->right == NULL || _node->parent->parent->right->isBlack == true)
                {
                    std::cout << "1  im in left I m gonna rotate right\n";
                    RBT::rotate_right(_node->parent->parent);
                }
                else
                {
                    _node->parent->parent->right->isBlack = !_node->parent->parent->right->isBlack;
                    _node->parent->isBlack = !_node->parent->isBlack;
                    _node->parent->parent->isBlack = !_node->parent->parent->isBlack;
                }
            }
            else
            {
                // rotate left
                if (_node->parent->parent->right == NULL || _node->parent->parent->right->isBlack == true)
                {
                    std::cout << " 2 im in left  right I m gonna rotate right than left\n";

                    node *tmp = _node->parent->parent;
                    node *tmp1 = _node->parent;
                    tmp1->right = NULL;
                    _node->parent = _node;
                    _node->parent->left = tmp1;
                    _node->parent->right = NULL;
                    _node->parent->left->parent = _node;
                    tmp->left = _node;
                    _node->parent = tmp;
                    _node->parent->parent = NULL;
                    _node->isLeft = true;
                    /********************************---------------***********************/
                    // rotate right
                    if (tmp->parent == NULL)
                    {
                        _node->parent = NULL;
                        root = _node;
                        root->isLeft = -1;
                    }
                    else
                        _node->parent = tmp->parent;
                    tmp->parent = _node;
                    _node->right = tmp;
                    _node->right->left = NULL;
                    _node->right->isLeft = false;
                    _node->right->isBlack = false;
                }
                else
                {
                    _node->parent->parent->right->isBlack = !_node->parent->parent->right->isBlack;
                    _node->parent->isBlack = !_node->parent->isBlack;
                    _node->parent->parent->isBlack = !_node->parent->parent->isBlack;
                }
            }
        }
        else if (_node->parent->isLeft == false)
        {
            if (_node->isLeft == true)
            {

                // std::cout<<  _node->key <<  " I m here\n";
                if (_node->parent->parent->left == NULL || _node->parent->parent->left->isBlack == true)
                {
                    node *tmp = _node->parent->parent;
                    node *tmp1 = _node->parent;
                    tmp1->left = NULL;
                    _node->parent = _node;
                    _node->parent->right = tmp1;
                    _node->parent->left = NULL;
                    _node->parent->right->parent = _node;
                    tmp->right = _node;
                    _node->parent = tmp;
                    _node->parent->parent = NULL;
                    _node->isLeft = false;

                    if (tmp->parent == NULL)
                    {
                        _node->parent = NULL;
                        root = _node;
                        root->isLeft = -1;
                    }
                    else
                        _node->parent = tmp->parent;
                    tmp->parent = _node;
                    _node->left = tmp;
                    _node->left->right = NULL;
                    _node->left->isLeft = true;
                    _node->left->isBlack = false;
                    std::cout << " 3 im in right left  I m gonna rotate  left than right \n";
                }
                else
                {
                    _node->parent->parent->left->isBlack = !_node->parent->parent->left->isBlack;
                    _node->parent->parent->isBlack = !_node->parent->parent->isBlack;
                    _node->parent->isBlack = !_node->parent->isBlack;
                }
            }
            else
            {

                if (_node->parent->parent->left == NULL || _node->parent->parent->left->isBlack == true)
                {
                    node *n = _node->parent->parent;

                    /////////////////
                    _node->parent->isBlack = true;
                    _node->parent->left->isBlack = false;
                    _node->parent->left->isLeft = true;
                    _node->parent->right->isBlack = false;
                    _node->parent->right->isLeft = false;
                    // break;
                }
                else
                {
                    // color fix
                    _node->parent->parent->left->isBlack = !_node->parent->parent->left->isBlack;
                    _node->parent->parent->isBlack = !_node->parent->parent->isBlack;
                    _node->parent->isBlack = !_node->parent->isBlack;
                }
            }
        }
        if (root->isBlack == false)
        {
            root->isBlack = true;
        }
        root->isLeft = -1;
    }
}

void RBT::check_print_rbt(node *n)
{
    // print tree with details
    if (n == NULL)
        return;
    check_print_rbt(n->left);
    std::cout << "Key: " << n->key << "\t left : " << n->isLeft << " Color: " << (n->isBlack == 0 ? "RED" : "BLACK") << " Parent: " << (n->parent == NULL ? "\033[0;31mROOT " : std::to_string(n->parent->key)) << "\033[0m Left: " << n->left << " Right: " << n->right << std::endl;
    check_print_rbt(n->right);
}

int main()
{
    RBT tst;

    tst.insert_node(tst.fill_node(2, 2));
    tst.insert_node(tst.fill_node(3, 3));
    tst.insert_node(tst.fill_node(1, 1));
    tst.insert_node(tst.fill_node(4, 4));
    tst.insert_node(tst.fill_node(5, 5));
    // // tst.insert_node(tst.fill_node(7, 7));
    // // tst.insert_node(tst.fill_node(9, 9));
    // // tst.insert_node(tst.fill_node(10, 10));
    // char *number = 10;

    // char *numberbeta = number;

    // numberbeta = NULL;

    // // int i = 0;
    // // while (i < 100)
    // // {
    // //     tst.insert_node(tst.fill_node(i, i));
    // //     i++;
    // // }
    tst.check_print_rbt(tst.root);

    std::cout << "RBT is " << (tst.isRBProper(tst.root) ? "GOOD" : "NOOT GOOD") << "\n";
    return 0;
}
