/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black-red.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:28:21 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/14 17:21:07 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

template <typename T,typename U> 
struct TreeNode
{
    T key;
    U val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *root;
    bool isBlack;
    TreeNode(T x, T y)
    {
        key = x;
        val = y;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};

// template <typename T,typename U> 
//insert 


int main()
{
    // map
    std::map<int, int> map;
    map.insert(std::pair<int, int>(1, 0));
    map.insert(std::pair<int, int>(1, 1));
    map.insert(std::pair<int, int>(20,-20));
    map.insert(std::pair<int, int>(0, 1));
    map.insert(std::pair<int, int>(5, 2));
    for (int i = 0; i < map.size(); i++)
    {
        // std::cout << "Map \n ";
        std::cout << "for i: " << i << " ==> " << map[i] << std::endl;
    }
    std::cout << "===========================" << std::endl;
    // // tree
    // TreeNode<int> *root = NULL;
    // insert(root, 0, 0);
    // insert(root, 1, 1);
    // insert(root, 2, 2);
    // insert(root, 3, 3);
    // print_tree(root);
    return 0;
}