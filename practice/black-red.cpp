/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black-red.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:28:21 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/16 19:47:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

// template <typename T, typename U>
// class black_red
// {
// protected:
//     /* data */
// public:
    // struct Node
    // {
    //     T key;
    //     U val;
    //     Node *left;
    //     Node *right;
    //     Node *root;
    //     unsigned int height;
    // };
    // black_red(/* args */);
    // black_red(Node *initiale)
    // {
    //     this->initiale.root = NULL;
    //     this->initiale.left = NULL;
    //     this->initiale.right = NULL;
    //     this->initiale.height = 1;
    // }
    // ~black_red()
    // {
    //     //
    // };
    
    // void insert(T key, U val);
    // {
    //     Node *newNode = new Node(key, val);
    //     if (this->initiale.root == NULL)
    //     {
    //         this->initiale.root = newNode;
    //         this->initiale.root->root = this->initiale.root;
    //         this->initiale.root->left = NULL;
    //         this->initiale.root->right = NULL;
    //         this->initiale.root->height = 1;
    //         this->initiale.root->isBlack = true;
    //     }
    //     else
    //     {
    //         Node *current = this->initiale.root;
    //         Node *parent = NULL;
    //         while (current != NULL)
    //         {
    //             parent = current;
    //             if (key < current->key)
    //                 current = current->left;
    //             else
    //                 current = current->right;
    //         }
    //         if (key < parent->key)
    //         {
    //             parent->left = newNode;
    //             newNode->root = parent;
    //             newNode->left = NULL;
    //             newNode->right = NULL;
    //             newNode->height = 1;
    //             newNode->isBlack = false;
    //         }
    //         else
    //         {
    //             parent->right = newNode;
    //             newNode->root = parent;
    //             newNode->left = NULL;
    //             newNode->right = NULL;
    //             newNode->height = 1;
    //             newNode->isBlack = false;
    //         }
    //         this->fix_insert(newNode);
    //     }
    // };
    // void fix_insert(Node *newNode)
    // {
    //     Node *parent = newNode->root;
    //     Node *grandparent = parent->root;
    //     while (parent->isBlack == false)
    //     {
    //         if (parent == grandparent->left)
    //         {
    //             Node *uncle = grandparent->right;
    //             if (uncle->isBlack == false)
    //             {
    //                 parent->isBlack = true;
    //                 uncle->isBlack = true;
    //                 grandparent->isBlack = false;
    //                 newNode = grandparent;
    //                 parent = newNode->root;
    //                 grandparent = parent->root;
    //             }
    //             else
    //             {
    //                 if (newNode == parent->right)
    //                 {
    //                     newNode = parent;
    //                     left_rotate(newNode);
    //                     parent = newNode->root;
    //                 }
    //                 parent->isBlack = true;
    //                 grandparent->isBlack = false;
    //                 right_rotate(grandparent);
    //             }
    //         }
    //         else
    //         {
    //             Node *uncle = grandparent->left;
    //             if (uncle->isBlack == false)
    //             {
    //                 parent->isBlack = true;
    //                 uncle->isBlack = true;
    //                 grandparent->isBlack = false;
    //                 newNode = grandparent;
    //                 parent = newNode->root;
    //                 grandparent = parent->root;
    //             }
    //             else
    //             {
    //                 if (newNode == parent->left)
    //                 {
    //                     newNode = parent;
    //                     right_rotate(newNode);
    //                     parent = newNode->root;
    //                 }
    //                 parent->isBlack = true;
    //                 grandparent->isBlack = false;
    //                 left_rotate(grandparent);
    //             }
    //         }
    //     }
    //     this->initiale.root->isBlack = true;
    // };
    // int size()
    // {
        
    // };
// };

// int main()
// {
//     // map
//     // std::map<int, int> map;
//     // map.insert(std::pair<int, int>(1, 0));
//     // map.insert(std::pair<int, int>(1, 1));
//     // map.insert(std::pair<int, int>(20,-20));
//     // map.insert(std::pair<int, int>(0, 1));
//     // map.insert(std::pair<int, int>(5, 2));
//     // for (int i = 0; i < map.size(); i++)
//     // {
//     //     // std::cout << "Map \n ";
//     //     std::cout << "for i: " << i << " ==> " << map[i] << std::endl;
//     // }
//     std::cout << "===========================" << std::endl;
//     // // tree
//     black_red<int, int> _tree;
//     _tree.insert(1, 0);
//     _tree.insert(1, 1);
//     _tree.insert(20, -20);
//     _tree.insert(0, 1);
//     _tree.insert(5, 2);
//     for(int i = 0; i < _tree.size(); i++)
//     {
//         std::cout << "for i: " << i << " ==> " << _tree[i] << std::endl;
//     }
    
//     return 0;
// }