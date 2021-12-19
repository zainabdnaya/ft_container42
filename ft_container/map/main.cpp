/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/19 02:28:05 by zdnaya           ###   ########.fr       */
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
    // void rotate_left(node *node);
    // void rotate_right(node *node);
    // void rotae_left_right(node *node);
    // void rotae_right_left(node *node);
    void check_balance(node *node);
    void check_print_rbt(node *root);
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

void RBT::insert_node(struct node *_new)
{
    if (root == NULL)
    {
        root = _new;
        root->isBlack = true;
        root->left = NULL;
        root->right = NULL;
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
        // std::cout << _new->key << "----" << _new->parent->key <<"\n";
        _new->isBlack = false;
        _new->left = NULL;
        _new->right = NULL;
        check_balance(_new);
    }
}

void RBT::check_balance(node *node)
{
    // if (node->isBlack == false && node->parent->isBlack == false && node->parent->isLeft == true)
    // {
    //     if (node->isLeft == true)
    //         std::cout << "here I m in Left Left  \t" << node->key << " " << node->parent->key << "\n";
    //     else
    //         std::cout << "here I m in Left Right \t" << node->key << " " << node->parent->key << "\n";
    // }
    // else 
    // if (node->isBlack == false && node->parent->isBlack == false && node->parent->isLeft == false)
    // {
    //     if (node->isLeft == false)
    //         std::cout << "here I m in Right Right \t" << node->key << " " << node->parent->key << "\n";
    // }

    if (node->isBlack == false && node->parent->isBlack == false && node->parent->isLeft == true)
    {
        if (node->isLeft == true)
        {
            std::cout << "he\n";
        }
        else
        {
            std::cout << "her\n";
        }
    }
    else if (node->isBlack == false && node->parent->isBlack == false && node->parent->isLeft == false)
    {
        if (node->isLeft == true)
        {
            std::cout << "h\n";
        }
        else
        {
            if ( node->parent->parent->left == NULL || node->parent->parent->left->isBlack == true)
            {
                // rotale left
                // RBT::node *tmp  = node->parent;
                // RBT::node *tmp2 = node->parent->parent;
                // RBT::node  *tmp3 = node->parent->parent->parent;
                
                // node->parent->parent = tmp;
                // node->parent = node;
                // node->parent->left = tmp2;
                // node->parent->left->isLeft = true;
                // node->parent->parent->parent = tmp3;
                // std::cout << "node->parent->parent :  " << node->parent->left->key << "\n";
                // node = NULL;
            }
            else
            {
                // // color
                node->parent->parent->left->isBlack = !node->parent->parent->left->isBlack;
                node->parent->parent->isBlack = !node->parent->parent->isBlack;
                node->parent->isBlack = !node->parent->isBlack;
                // std::cout << "here1\n";
            }
        }
    //     // std::cout << node->parent->parent->key << " == " << root->key << "\n";
    }
    if (root->isBlack == false)
        root->isBlack = true;
    // std::cout << root->left->key << "\n";
    //     // if (node->parent->parent->left != NULL)
    //     //     std::cout << node->parent->parent->left->key << "\n";
    //     // if (node->parent->parent->right != NULL)
    //     //     std::cout << node->parent->parent->left->key << "\n";
}

void RBT::check_print_rbt(node *root)
{
    std::cout << "root -> |" << root->key << "|  is it black ?  =>  " << root->isBlack << "\n";
    node *tmp = root;
    while (root->right != NULL)
    {
        root = root->right;
        // std::cout << "root->right  |" << root->key << "| is it black ? =>  " << root->isBlack << "\n";
        if (root->isLeft == true)
        {
            // root = root->left;
            std::cout << "here I m in right Left  \t" << root->key << " " << root->parent->key << "\n";
            // root = root->parent;
        }
        else
            std::cout << "here I m in right Right \t" << root->key << " " << root->parent->key << "\n";
    }
    while (tmp->left != NULL)
    {
        tmp = tmp->left;
        std::cout << "root->left |" << tmp->key << "|  is it black ? =>  " << tmp->isBlack << "\n";
    }
}

int main()
{
    RBT tst;

    tst.insert_node(tst.fill_node(2, 2));
    tst.insert_node(tst.fill_node(1, 1));
    tst.insert_node(tst.fill_node(3, 3));
    tst.insert_node(tst.fill_node(4, 4));
    tst.insert_node(tst.fill_node(5, 5));
    tst.check_print_rbt(tst.root);

    return 0;
}
