/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:45:33 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/08 14:49:29 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"


int main()
{
    //test ft::vector

    ft::vector<int> first;                                // empty vector of ints
    ft::vector<int> second (4,100);                       // four ints with value 100
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    ft::vector<int> fourth (third);                       // a copy of third
    
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator  it = fifth.begin(); it != fifth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    
    return 0;
}