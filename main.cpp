/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/05/11 19:26:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	vector_tests(void);
//void	list_tests(void);
//void	stack_tests(void);
//void	queue_tests(void);

#include <iostream>
#include "srcs/Map/map.hpp"

int		main(void)
{
	ft::map<int,std::string> mymap(15,"hey");

	for (ft::map<int,std::string>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << '[' << it->first << "=>" << it->second << "]	";
	std::cout << std::endl;
	
	ft::map<int,std::string>::iterator it = mymap.begin();
	ft::map<int,std::string>::iterator it2 = mymap.begin();
	it++;
	it++;
	for (int i = 0; i < 4; i++)
		it2++;

	

	ft::map<int,std::string> range(it, it2);

	for (ft::map<int,std::string>::iterator it = range.begin(); it != range.end(); it++)
		std::cout << '[' << it->first << "=>" << it->second << "]	";
	std::cout << std::endl;

//	range.printInorder();

	return (0);
}
