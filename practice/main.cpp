/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:11:27 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/17 21:07:09 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include <map>
#include <string>

int main(void)
{
    // std::vector<int> v;
    // for(int i = 0; i < 10 ; i++)
    //     v.push_back(i);
    // ft::iterator_traits<std::vector<int>::iterator>::difference_type d = v.end() - v.begin();
    // std::cout << d << std::endl;
    // ft::iterator_traits<std::vector<int>::reverse_iterator>::difference_type d2 = v.end() - v.begin();
    // std::cout << d2 << std::endl;
    std::map<int, int> m;
    m.insert(std::pair<int, int>(1, 1));
    m.insert(std::pair<int, int>(4, 3));
    m.insert(std::pair<int, int>(3, 2));
    m.insert(std::pair<int, int>(20, 1));
    m.insert(std::pair<int, int>(2, 1));
    std::map<int,int>::iterator it = m.begin();      
    for ( it = m.begin(); it != m.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    return (0);
}
