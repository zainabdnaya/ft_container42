/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:42:09 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/12/29 14:13:16 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <map>
#include <new>
// #include "map.hpp"
#include "rbt.hpp"
// #include "map.hpp"

//

int main()
{
    ft::RBT<ft::pair<int, int>, std::less<int> > rbt;
    rbt.insert_node(ft::make_pair(3, 10));
    rbt.insert_node(ft::make_pair(1, 10));
    rbt.insert_node(ft::make_pair(2, 10));
    rbt.insert_node(ft::make_pair(5, 10));

    ft::RBT<ft::pair<int, int>, std::less<int> >::iterator it = rbt.begin();
    ft::RBT<ft::pair<int, int>, std::less<int> >::iterator it2 = rbt.end();

    // --it;
    while (it != it2)
    {
        std::cout << it->first << " ----- " << it->second << std::endl;
        ++it;
    }
    std::cout << "==========================================================" << std::endl;
    std::map<int, int> m;

    m.insert(std::make_pair(3, 10));
    m.insert(std::make_pair(1, 10));
    m.insert(std::make_pair(2, 10));
    m.insert(std::make_pair(5, 10));
    std::map<int, int>::reverse_iterator it3 = m.rbegin();
    std::map<int, int>::reverse_iterator it4 = m.rend();
    
    // --it3;
    while (it3 != it4)
    {
        // std::cout << "I m here";
        std::cout << it3->first << " ----- " << it3->second << std::endl;
        ++it3;
    }
    // std::cout << it->first << " ----- " << it->second << std::endl;

    return 0;
}
