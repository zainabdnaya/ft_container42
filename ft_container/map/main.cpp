/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/18 05:02:44 by zdnaya           ###   ########.fr       */
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
        // bool isLeft;
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
            this->key =key;
            // isLeft = false;
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
    void print_tree(node *_root);
    void insert_node( node *_new);
    // void color_fix(RBT *node);
    // void rotate_left(node *node);
    // void rotate_right(node *node);
    // void rotae_left_right(node *node);
    // void rotae_right_left(node *node);
    // void check_balance(RBT *node);
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
        if(!_root)
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
        }
        else if (tmp2->key < _new->key)
        {
            tmp2->right = _new;
        }
        std::cout << _new->key << "----" << _new->parent->key <<"\n";

    }
    
    // if(root->parent->parent->left == root->parent)
    // {
    //     std::cout<< "fuck u " << std::endl;
    // }
}

int main()
{
    RBT tst;

    tst.insert_node(tst.fill_node(2, 2));
    tst.insert_node(tst.fill_node(1, 1));
    tst.insert_node(tst.fill_node(3, 3));
    tst.insert_node(tst.fill_node(4, 4));
    tst.insert_node(tst.fill_node(5, 5));



    return 0;
}
