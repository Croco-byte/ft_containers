/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/05/14 15:46:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	vector_tests(void);
void	list_tests(void);
void	stack_tests(void);
void	queue_tests(void);
void	map_tests(void);

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : ./container [vector / list / stack / queue / map / all]" << std::endl;
		return (1);
	}
	std::string arg(argv[1]);
	if (arg == "vector")
		vector_tests();
	if (arg == "list")
		list_tests();
	if (arg == "stack")
		stack_tests();
	if (arg == "queue")
		queue_tests();
	if (arg == "map")
		map_tests();
	if (arg == "all")
	{
		vector_tests();
		std::cout << std::endl;
		list_tests();
		std::cout << std::endl;
		stack_tests();
		std::cout << std::endl;
		queue_tests();
		std::cout << std::endl;
		map_tests();
		std::cout << std::endl;
	}

	return (0);
}
