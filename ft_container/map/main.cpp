#include <iostream>
#include <map>
#include <new>
// #include "map.hpp"
#include "rbt.hpp"

//

int main()
{
    ft::RBT<ft::pair<int, int>, std::less<int> > rbt;
    rbt.insert_node(ft::make_pair(3, 10));
    rbt.insert_node(ft::make_pair(1, 10));
    rbt.insert_node(ft::make_pair(2, 10));
    rbt.insert_node(ft::make_pair(5, 10));

    ft::RBT<ft::pair<int, int>, std::less<int> >::iterator it = rbt.rbegin();
    ft::RBT<ft::pair<int, int>, std::less<int> >::iterator it2 = rbt.rend();

    // it = rbt.end();
    // it2 = rbt.begin();

    // --it;
    // while (it != it2)
    // {
    //     std::cout << it->first << " ----- " << it->second << std::endl;
    //     --it;
    // }
    
    // std::cout << it->first << " ----- " << it->second << std::endl;

    return 0;
}
