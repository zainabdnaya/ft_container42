/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:47:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/28 16:15:32 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <new>
// #include "map.hpp"
#include "rbt.hpp"


// 

int main()
{
    ft::RBT<ft::pair<int,int>, std::less <int> > rbt;
    // ft::RBT<int, int> rbt;
    // ft::iterator_traits<std::bidirectional_iterator_tag>::iterator it;
    // segfault ==> delete 3
    // tst.insert_node(tst.fill_node(7, 7));
    // tst.insert_node(tst.fill_node(18, 18));
    // tst.insert_node(tst.fill_node(3, 3));
    // tst.insert_node(tst.fill_node(10, 10));
    // tst.insert_node(tst.fill_node(22, 22));
    // tst.insert_node(tst.fill_node(11, 11));
    // tst.insert_node(tst.fill_node(8, 8));
    // tst.insert_node(tst.fill_node(26, 26));

    // wrong output ==> to delete 11
    // rbt.insert_node(10,10);
    // rbt.insert_node(17,17);
    // rbt.insert_node(8,8);
    // rbt.insert_node(25,25);
    // rbt.insert_node(15,15);
    // rbt.insert_node(1,1);
    // rbt.insert_node(11,11);
    // rbt.insert_node(6,6);
    // rbt.insert_node(27,27);
    // rbt.insert_node(22,22);

 

    // wrong output ==> to delete 1
    rbt.insert_node(ft::make_pair(2,10));
    rbt.insert_node(ft::make_pair(1,10));
    rbt.insert_node(ft::make_pair(3,10));
    rbt.insert_node(ft::make_pair(5,10));
    rbt.insert_node(ft::make_pair(4,10));
    rbt.insert_node(ft::make_pair(7,10));
    rbt.insert_node(ft::make_pair(6,10));

rbt.check_print_rbt();
    std::cout << "*************************************************************\n";
    rbt.delete_node(ft::make_pair(1,10));
    std::cout << "*************************************************************\n";
    rbt.check_print_rbt();
    // // tst.insert_node(tst.fill_node(2, 2));
    // // tst.insert_node(tst.fill_node(5, 5));

    // std::cout << "RBT is " << (rbt.isRBTProper() ? "GOOD" : "NOOT GOOD") << "\n";

    return 0;
}
