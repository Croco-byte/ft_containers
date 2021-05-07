/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/05/07 19:25:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	vector_tests(void);
void	list_tests(void);
#include "srcs/List/list.hpp"
#include <list>
#include <vector>

void	display_list(ft::list<int> list)
{
	if (list.empty())
		std::cout << "<empty>" << std::endl;
	else
	{
		for (ft::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}
}

int		main(void)
{
	list_tests();
	return (0);
}
