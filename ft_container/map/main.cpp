/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/16 21:19:08 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <new>


// this is a red black tree simple implementation   


struct Node
{
    int key;
    int  val;
    Node *left;
    Node *right;
    Node *root;
    unsigned int height;
    unsigned int size;
    bool isBlack;
    //initial value is true
};

Node *initinale_node()
{
    Node  *node = new Node();
    node->root = NULL;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->isBlack = true;
    return(node);
}

void insert_node(int key , int value)
{
    
}


void print_node(Node *node)
{
    if (node == NULL)
        return ;
    std::cout << "map[" << node->key << "] == " << node->val << std::endl;
    print_node(node->left);
    print_node(node->right);
}



int main()
{
    Node *node = initinale_node();
    // insert_node(1, 1);
    // insert_node(3, 3);
    // insert_node(4, 4);
    // insert_node(10, 10);
    // insert_node(14, 14);
    // insert_node(9, 9);
    // insert_node(15, 15);
    // insert_node(8, 8);
   
}