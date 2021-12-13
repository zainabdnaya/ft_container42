/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black-red.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:28:21 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/13 22:30:45 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

template <typename T>
struct TreeNode
{
    T val;
    T key;
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


void  insert(TreeNode<int> *&root, int key, int val)
{
    if (root == NULL)
    {
        root = new TreeNode<int>(key, val);
        root->isBlack = false;
        return ;
    }
    if (key < root->key)
        insert(root->left, key, val);
    else if (key > root->key)
        insert(root->right, key, val);
    else
        root->val = val;
    if (root == NULL)
    {
        TreeNode<int> *node = new TreeNode<int>(key, val);
    }
}

void print_tree(TreeNode<int> *root)
{
    if (root == NULL)
        return ;
    std::cout << "for i : "  << root->key << "==> " << root->val << std::endl;
    print_tree(root->left);
    print_tree(root->right);
}
int main()
{
    // map
    std::map<int, int> map;
    map.insert(std::pair<int, int>(0, 0));
    map.insert(std::pair<int, int>(1, 1));
    map.insert(std::pair<int, int>(2, 2));
    map.insert(std::pair<int, int>(3, 3));
    for (int i = 0; i < map.size(); i++)
    {
        std::cout << "for i: " << i << " ==> " << map[i] << std::endl;
    }
    std::cout << "===========================" << std::endl;
    // tree
    TreeNode<int> *root = NULL;
    insert(root, 0, 0);
    insert(root, 1, 1);
    insert(root, 2, 2);
    insert(root, 3, 3);
    print_tree(root);
    return 0;
}