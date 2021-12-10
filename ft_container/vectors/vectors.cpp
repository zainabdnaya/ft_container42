/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:45:33 by zdnaya            #+#    #+#             */
/*   Updated: 2021/12/10 11:26:08 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <vector>

int main()
{
  // test ft::vector
  /*** test : push_back ***++++++++++**/
   //Create a vector containing integers
  // ft::vector<int> v;
  // for (int i = 0; i < 20; i += 2)
  // {

  //   v.push_back(i);
  // }

  // v.push_back(42);
  // v.push_back(13);
  //   std::cout <<  v.size() << " ft::v = { ";
  //  for (int n = 0; n < v.size() ; n++)
  // {
  //   std::cout <<   v[n] << ", ";
  // }
  // std::cout << "}; \n";
/********************++++++++++++********/
///  test cnstructors
  // ft::vector<int> first;                                // empty vector of ints
  // ft::vector<int> second (4,100);                       // four ints with value 100
  // ft::vector<int> third (second.begin(),second.end());  // iterating through second
  // ft::vector<int> fourth (third);                       // a copy of third

  // // the iterator constructor can also be used to construct from arrays:
  // int myints[] = {16,2,77,29};
  // ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  // std::cout << "The contents of fifth are:";
  // for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';

/***********************  +++++++++++++++********/
//:vector::operator=
  // ft::vector<int> foo (3,0);
  // ft::vector<int> bar (5,0);

  // bar = foo;
  // foo = ft::vector<int>();

  // std::cout << "Size of foo: " << int(foo.size()) << '\n';
  // std::cout << "Size of bar: " << int(bar.size()) << '\n';
/***********************  +++++++++++++++********/
//vector begin()
  // ft::vector<int> myvector;
  // for (int i=1; i<=5; i++) myvector.push_back(i);

  // std::cout << "myvector contains:";
  // for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';
  /***********************  +++++++++++++++********/
  // vector end
  // ft::vector<int> myvector;
  // for (int i=1; i<=5; i++) myvector.push_back(i);

  // std::cout << "myvector contains:";
  // for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';
  /***********************  +++++++++++++++********/
    // rbegin
  // rend

  // ft::vector<int> myvector (5);  // 5 default-constructed ints
  // int i = 0;
  // ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  // for (; rit!= myvector.rend(); ++rit)
  //   *rit = ++i;

  // std::cout << "myvector contains:";
  // for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';
  /***********************  +++++++++++++++********/
  //size 
  // ft::vector<int> myints;
  // std::cout << "0. size: " << myints.size() << '\n';

  // for (int i=0; i<10; i++) myints.push_back(i);
  // std::cout << "1. size: " << myints.size() << '\n';

  // myints.insert (myints.end(),10,100);
  // std::cout << "2. size: " << myints.size() << '\n';

  // myints.pop_back();
  // std::cout << "3. size: " << myints.size() << '\n';
    /***********************  +++++++++++++++********/
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  // it = myvector.begin();

  // ft::vector<int> anothervector (2,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);
/***************************************************  +++++++++++++++******+++++++++++++++******+++****/

  // std::vector<int> myvector (3,100);
  // std::vector<int>::iterator it;

  // it = myvector.begin();
  // it = myvector.insert ( it , 200 );

  // myvector.insert (it,2,300);

  // // // "it" no longer valid, get a new one:
  // // it = myvector.begin();

  // // std::vector<int> anothervector (2,400);
  // // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // // int myarray [] = { 501,502,503 };
  // // myvector.insert (myvector.begin(), myarray, myarray+3);
/***************************************************  +++++++++++++++******+++++++++++++++******+++****/

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

//myvector.insert ( it , 200 ); ==>  200 100 100 100

//myvector.insert (it,2,300); => myvector contains: 300 300 200 100 100 100

  return 0;
}
