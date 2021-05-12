/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroland <qroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/05/12 16:39:41 by qroland          ###   ########.fr       */
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
		for (ft::map<int,std::string>::const_iterator it = mymap.begin(); it != mymap.end(); it++)
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
		for (ft::map<int,std::string>::const_reverse_iterator it = mymap.rbegin(); it != mymap.rend(); it++)
			std::cout << '[' << it->first << "=>" << it->second << "]	";
		std::cout << std::endl;
	}
}


int		main(void)
{
	ft::map<int,std::string> mymap;

	mymap.insert(ft::Pair<int,std::string>(7,"bruh"));
	mymap.insert(ft::Pair<int,std::string>(14,"bjour"));
	mymap.insert(ft::Pair<int,std::string>(2,"hello there"));
	mymap.insert(ft::Pair<int,std::string>(40,"general kenobi!"));


	display(mymap);


	




	return (0);
}
