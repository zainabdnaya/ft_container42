/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/21 20:46:28 by zdnaya           ###   ########.fr       */
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
        bool isLeft;
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

void RBT::rotate_right(node *_node)
{
    node *parent_ = _node->parent->parent;
    node *new_parent = parent_->left;
    if (parent_->parent)
    {
        new_parent->parent = parent_->parent;
        root->left = new_parent;
    }
    else
    {
        root = new_parent;
        root->parent = NULL;
    }
    // new_parent->parent = parent_->parent;
    parent_->right = parent_;
    parent_->right->isLeft = true;
    parent_->right->left = NULL;
    parent_->right->right = NULL;
    parent_->parent = new_parent;
    new_parent->right = parent_;
    // root->left = new_parent;
    new_parent->right->isBlack = false;
    new_parent->left->isBlack = false;
    new_parent->isBlack = true;
}

void RBT::rotate_left(node *_node)
{
    node *parent_ = _node->parent->parent;
    node *new_parent = parent_->right;
    if (parent_->parent)
    {
        new_parent->parent = parent_->parent;
        root->right = new_parent;
    }
    else
    {
        root = new_parent;
        root->parent = NULL;
    }
    new_parent->left = parent_;
    new_parent->left->isLeft = true;
    new_parent->left->right = NULL;
    new_parent->left->left = NULL;
    parent_->parent = new_parent;
    new_parent->right = _node;
    // std::cout << "===> |"  <<   new_parent->key<< "|\n";
    new_parent->left->isBlack = false;
    new_parent->right->isBlack = false;
    new_parent->isBlack = true;
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
                    // std::cout << "helooo \n";
                    // rotate right
                    RBT::rotate_right(_node);
                }
                else
                {
                    // std::cout << "he\n";
                    // std::cout << "here I m in Left Right \n";
                    _node->parent->parent->right->isBlack = !_node->parent->parent->right->isBlack;
                    _node->parent->isBlack = !_node->parent->isBlack;
                    _node->parent->parent->isBlack = !_node->parent->parent->isBlack;
                    _node = _node->parent->parent;
                }
            }
            else
            {
                std::cout << "her\n";
                exit(0);
            }
        }
        else if (_node->parent->isLeft == false)
        {
            if (_node->isLeft == true)
            {
                std::cout << "h\n";
                exit(0);
            }
            else
            {
                if (_node->parent->parent->left == NULL || _node->parent->parent->left->isBlack == true)
                {
                    // std::cout << "===> \n";
                    // rotale left
                    RBT::rotate_left(_node);
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
            root->isBlack = true;
    }
}

void RBT::check_print_rbt(node *n)
{
    // print tree with details
    if (n == NULL)
        return;
    check_print_rbt(n->left);
    std::cout << "Key: " << n->key << " Color: " << (n->isBlack == 0 ? "RED" : "BLACK") << " Parent: " << (n->parent == NULL ? "\033[0;31mROOT " : std::to_string(n->parent->key)) << "\033[0m Left: " << n->left << " Right: " << n->right << std::endl;
    check_print_rbt(n->right);
}
int main()
{
    RBT tst;

    tst.insert_node(tst.fill_node(2, 2));
    tst.insert_node(tst.fill_node(1, 1));
    tst.insert_node(tst.fill_node(5, 5));
    tst.insert_node(tst.fill_node(4, 4));
    tst.insert_node(tst.fill_node(3, 3));
    // tst.insert_node(tst.fill_node(7, 7));

    // int i = 0;
    // while (i < 100)
    // {
    //     tst.insert_node(tst.fill_node(i, i));
    //     i++;
    // }
    tst.check_print_rbt(tst.root);

    std::cout << "RBT is " << (tst.isRBProper(tst.root) ? "GOOD" : "NOOT GOOD") << "\n";
    return 0;
}
