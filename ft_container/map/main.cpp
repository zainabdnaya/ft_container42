/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/22 09:52:01 by zdnaya           ###   ########.fr       */
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
        // number of leafs in the subtree
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
            count = 0;
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
    void balance_tree(node *_node);
    int isRBProper(node *n);
    void delete_node(int key);
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
    node *r = n->right;
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

void RBT::check_balance(node *_node)
{

    while (_node && _node != root && _node->parent->isBlack == false && _node->parent->parent != NULL )
    {
        if (_node->parent->left == _node)
        {
            if (_node->parent->parent->right != NULL && _node->parent->parent->right->isBlack == false)
            {
                _node->parent->parent->right->isBlack = true;
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
        else
        {
            if (_node->parent->parent->left != NULL && _node->parent->parent->left->isBlack == false)
            {
                _node->parent->parent->left->isBlack = true;
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
    }
    root->isBlack = true; // root is always black
    root->isLeft = -1;
}

void RBT::delete_node(int key)
{
    node *tmp = root;
    node *tmp2 = NULL;
    while (tmp != NULL)
    {
        tmp2 = tmp;
        if (key < tmp->key)
        {
            tmp = tmp->left;
        }
        else if (key > tmp->key)
        {
            tmp = tmp->right;
        }
        else
            break;
    }
    if (tmp == NULL)
        return;
    if (tmp->left == NULL && tmp->right == NULL)
    {
        if (tmp->parent->left == tmp)
            tmp->parent->left = NULL;
        else
            tmp->parent->right = NULL;
        delete tmp;
    }
    else if (tmp->left == NULL || tmp->right == NULL)
    {
        if (tmp->left == NULL)
        {
            if (tmp->parent->left == tmp)
                tmp->parent->left = tmp->right;
            else
                tmp->parent->right = tmp->right;
            tmp->right->parent = tmp->parent;
            delete tmp;
        }
        else
        {
            if (tmp->parent->left == tmp)
                tmp->parent->left = tmp->left;
            else
                tmp->parent->right = tmp->left;
            tmp->left->parent = tmp->parent;
            delete tmp;
        }
    }
    else
    {
        node *tmp3 = tmp->right;
        while (tmp3->left != NULL)
        {
            tmp3 = tmp3->left;
        }
        tmp->key = tmp3->key;
        tmp->val = tmp3->val;
        if (tmp3->parent->left == tmp3)
            tmp3->parent->left = tmp3->right;
        else
            tmp3->parent->right = tmp3->right;
        if (tmp3->right != NULL)
            tmp3->right->parent = tmp3->parent;
        delete tmp3;
    }
}

void RBT::check_print_rbt(node *n)
{
    if (n == NULL)
        return;
    check_print_rbt(n->left);
    std::cout << "Key: " << n->key << " Color: " << (n->isBlack == 0 ? "RED" : "BLACK") << " Parent: \t\t" << (n->parent == NULL ? "\033[0;31mROOT " : std::to_string(n->parent->key)) << "\033[0m " << std::endl;
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
    tst.insert_node(tst.fill_node(7, 7));
    tst.insert_node(tst.fill_node(9, 9));
    
    tst.check_print_rbt(tst.root);
    std::cout << "RBT is " << (tst.isRBProper(tst.root) ? "GOOD" : "NOOT GOOD") << "\n";
    std::cout << "*************************************************************\n";
    tst.delete_node(1);
    tst.check_print_rbt(tst.root);
    std::cout << "RBT is " << (tst.isRBProper(tst.root) ? "GOOD" : "NOOT GOOD") << "\n";

    return 0;
}
