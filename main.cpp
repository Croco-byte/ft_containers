/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/05/08 17:16:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	vector_tests(void);
void	list_tests(void);
#include "srcs/List/list.hpp"
#include <list>
#include <vector>

template < typename T >
void	display_list(ft::list<T> list)
{
	if (list.empty())
		std::cout << "<empty>" << std::endl;
	else
	{
		for (typename ft::list<T>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}
}

template < typename T >
void	rev_display_list(ft::list<T> list)
{
	if (list.empty())
		std::cout << "<empty>" << std::endl;
	else
	{
		for (typename ft::list<T>::reverse_iterator it = list.rbegin(); it != list.rend(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}
}

bool mycomparison (double first, double second)
{ std::cout << "[DEBUG] comparing these two numbers : " << first << " " << second << std::endl; return ( int(first)<int(second) ); }

int		main(void)
{
	ft::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	first.merge(second);
	second.push_back (2.1);
	
	first.merge(second,mycomparison);
	
	display_list(first);
	display_list(second);

//	list_tests();

	return (0);
}
