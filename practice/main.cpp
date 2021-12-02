/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:11:27 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/02 11:23:22 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"


int main(void)
{
    std::vector<int> v;
    for(int i = 0; i < 10 ; i++)
        v.push_back(i);
    ft::iterator_traits<std::vector<int>::iterator>::difference_type d = v.end() - v.begin();
    std::cout << d << std::endl;
    ft::iterator_traits<std::vector<int>::reverse_iterator>::difference_type d2 = v.end() - v.begin();
    std::cout << d2 << std::endl;
    
    return (0);
}
