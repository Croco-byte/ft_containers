/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/05/13 16:50:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	vector_tests(void);
//void	list_tests(void);
//void	stack_tests(void);
//void	queue_tests(void);

#include <iostream>
#include <map>
#include "srcs/Map/map.hpp"


template < typename T, typename T2 >
void	display(ft::map<T,T2> const & mymap)
{
	if (mymap.empty())
		std::cout << "<empty>" << std::endl;
	else
	{
		for (typename ft::map<T,T2>::const_iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '[' << it->first << "=>" << it->second << "]	";
		std::cout << std::endl;
	}
}

template < typename T, typename T2 >
void	rev_display(ft::map<T,T2> const & mymap)
{
	if (mymap.empty())
		std::cout << "<empty>" << std::endl;
	else
	{
		for (typename ft::map<T,T2>::const_reverse_iterator it = mymap.rbegin(); it != mymap.rend(); it++)
			std::cout << '[' << it->first << "=>" << it->second << "]	";
		std::cout << std::endl;
	}
}


int		main(void)
{
	    ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['e']=30;

  ft::Pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('c');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

	return (0);
}
