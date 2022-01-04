/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:44:45 by zainabdnaya       #+#    #+#             */
/*   Updated: 2022/01/04 11:04:07 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "stack.hpp"


int main()
{
    ft::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);
    
    std::cout << stack.top() << std::endl;
    std::cout << stack.size() << std::endl;
    std::cout << stack.empty() << std::endl;
    stack.pop();
    for (size_t i = 0; i < stack.size(); i++)
    {
        std::cout << stack.top() << std::endl;
        stack.pop();        
    }
    std::cout << stack.size() << std::endl;
    std::cout << stack.empty() << std::endl;
    return 0;
    
}
