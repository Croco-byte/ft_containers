/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:25:14 by user42            #+#    #+#             */
/*   Updated: 2021/05/14 15:55:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "../Vector/vector.hpp"
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define CYAN		"\033[0;36m"
# define NC			"\033[0m"

static void	check(void)
{
		std::ifstream ft,stl;
	ft.open("test_results/ft_stack.out");
	stl.open("test_results/stl_stack.out");

	/* Compare number of lines */
	int cft(0),cstl(0);
	std::string str;
	while (!ft.eof())
	{
		getline(ft,str);
		cft++;
	}
	ft.clear();
	ft.seekg(0,std::ios::beg);
	while (!stl.eof())
	{
		getline(stl,str);
		cstl++;
	}
	stl.clear();
	stl.seekg(0,std::ios::beg);
	if (cft != cstl)
	{
		std::cout << RED << "			KO" << NC << std::endl;
		exit(1);
	}

	/* Compare files line by line */
	std::string ftstr;
	std::string stlstr;
	
	while (!ft.eof())
	{
		getline(ft,ftstr);
		getline(stl,stlstr);
		if (ftstr != stlstr)
		{
			std::cout << RED << "			KO" << NC << std::endl;
			exit(1);
		}
	}
	std::cout << GREEN << "			OK" << NC << std::endl;
}

static void	constructor_operator_tests(std::ofstream & stl_outfile, std::ofstream & ft_outfile)
{
	std::cout << "  > CONSTRUCTORS / OPERATORS" << std::endl;
	ft_outfile << "	> CONSTRUCTORS / OPERATORS" << std::endl;
	stl_outfile << "	> CONSTRUCTORS / OPERATORS" << std::endl;

	{
		std::list<int> mylist (3,100);
		std::vector<int> myvector (2,200);

		std::stack<int> first;
		std::stack<int, std::list<int> > second (mylist);

		std::stack<int,std::vector<int> > third;
		std::stack<int,std::vector<int> > fourth (myvector);
		std::stack<int,std::vector<int> > fifth = fourth;

		stl_outfile << "[*] Constructors / Operators :" << std::endl;
		stl_outfile << "size of first: " << first.size() << std::endl;
		stl_outfile << "size of second: " << second.size() << std::endl;
		stl_outfile << "size of third: " << third.size() << std::endl;
		stl_outfile << "size of fourth: " << fourth.size() << std::endl;
		stl_outfile << "size of fifth: " << fourth.size() << std::endl;
	}
	{
		ft::list<int> mylist (3,100);
		ft::vector<int> myvector (2,200);

		ft::stack<int> first;
		ft::stack<int> second (mylist);

		ft::stack<int,ft::vector<int> > third;
		ft::stack<int,ft::vector<int> > fourth (myvector);
		ft::stack<int,ft::vector<int> > fifth = fourth;

		ft_outfile << "[*] Constructors / Operators :" << std::endl;
		ft_outfile << "size of first: " << first.size() << std::endl;
		ft_outfile << "size of second: " << second.size() << std::endl;
		ft_outfile << "size of third: " << third.size() << std::endl;
		ft_outfile << "size of fourth: " << fourth.size() << std::endl;
		ft_outfile << "size of fifth: " << fourth.size() << std::endl;
	}

	std::cout << "[*] Default	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] From_c	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] Copy	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] Operator=	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	capacity_functions(std::ofstream & stl_outfile, std::ofstream & ft_outfile)
{
	std::cout << "  > CONSTRUCTORS / OPERATORS" << std::endl;
	ft_outfile << "	> CONSTRUCTORS / OPERATORS" << std::endl;
	stl_outfile << "	> CONSTRUCTORS / OPERATORS" << std::endl;

	{
		std::stack<int> myints;
		stl_outfile << "[*] size / empty :" << std::endl;
		stl_outfile << "0. size: " << myints.size() << '\n';
		for (int i=0; i<5; i++) myints.push(i);
		stl_outfile << "1. size: " << myints.size() << '\n';
		myints.pop();
		stl_outfile << "2. size: " << myints.size() << '\n';
		myints.pop();
		myints.pop();
		myints.pop();
		myints.pop();
		if (myints.empty())
			stl_outfile << "myints is now EMPTY" << std::endl;
	}
	{
		ft::stack<int> myints;
		ft_outfile << "[*] size / empty :" << std::endl;
		ft_outfile << "0. size: " << myints.size() << '\n';
		for (int i=0; i<5; i++) myints.push(i);
		ft_outfile << "1. size: " << myints.size() << '\n';
		myints.pop();
		ft_outfile << "2. size: " << myints.size() << '\n';
		myints.pop();
		myints.pop();
		myints.pop();
		myints.pop();
		if (myints.empty())
			ft_outfile << "myints is now EMPTY" << std::endl;
	}

	std::cout << "[*] size	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] empty	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	element_access_modifyers(std::ofstream & stl_outfile, std::ofstream & ft_outfile)
{
	std::cout << "  > ELEMENT ACCESS" << std::endl;
	ft_outfile << "	> ELEMENT ACCESS" << std::endl;
	stl_outfile << "	> ELEMENT ACCESS" << std::endl;

	{
		std::stack<int> mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
		stl_outfile << "[*] top :" << std::endl;
		stl_outfile << "mystack.top() is now " << mystack.top() << '\n';
	}
	{
		ft::stack<int> mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
		ft_outfile << "[*] top :" << std::endl;
		ft_outfile << "mystack.top() is now " << mystack.top() << '\n';
	}
	std::cout << "[*]  top	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;

	std::cout << "  > MODIFYERS" << std::endl;
	ft_outfile << "	> MODIFYERS" << std::endl;
	stl_outfile << "	> MODIFYERS" << std::endl;

	{
		std::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		stl_outfile << "[*] push / pop :" << std::endl;
		stl_outfile << "Popping out elements...";
		while (!mystack.empty())
		{
			stl_outfile << ' ' << mystack.top();
			mystack.pop();
		}
		stl_outfile << std::endl;
	}
	{
		ft::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		ft_outfile << "[*] push / pop :" << std::endl;
		ft_outfile << "Popping out elements...";
		while (!mystack.empty())
		{
			ft_outfile << ' ' << mystack.top();
			mystack.pop();
		}
		ft_outfile << std::endl;
	}

	std::cout << "[*] push	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*]  pop	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	non_member_overloads(std::ofstream & stl_outfile, std::ofstream & ft_outfile)
{
	std::cout << "  > ELEMENT ACCESS" << std::endl;
	ft_outfile << "	> ELEMENT ACCESS" << std::endl;
	stl_outfile << "	> ELEMENT ACCESS" << std::endl;

	{
		std::stack<int> a;
		a.push(10);
		a.push(20);
		a.push(30);
		std::stack<int> b;
		b.push(10);
		b.push(20);
		b.push(30);
		std::stack<int> c;
		c.push(30);
		c.push(20);
		c.push(10);
		stl_outfile << "[*] Non-member overloads :" << std::endl;
		if (a==b) stl_outfile << "a and b are equal\n";
		if (b!=c) stl_outfile << "b and c are not equal\n";
		if (b<c) stl_outfile << "b is less than c\n";
		if (c>b) stl_outfile << "c is greater than b\n";
		if (a<=b) stl_outfile << "a is less than or equal to b\n";
		if (a>=b) stl_outfile << "a is greater than or equal to b\n";
	}
	{
		ft::stack<int> a;
		a.push(10);
		a.push(20);
		a.push(30);
		ft::stack<int> b;
		b.push(10);
		b.push(20);
		b.push(30);
		ft::stack<int> c;
		c.push(30);
		c.push(20);
		c.push(10);
		ft_outfile << "[*] Non-member overloads :" << std::endl;
		if (a==b) ft_outfile << "a and b are equal\n";
		if (b!=c) ft_outfile << "b and c are not equal\n";
		if (b<c) ft_outfile << "b is less than c\n";
		if (c>b) ft_outfile << "c is greater than b\n";
		if (a<=b) ft_outfile << "a is less than or equal to b\n";
		if (a>=b) ft_outfile << "a is greater than or equal to b\n";
	}

	std::cout << "[*] Operator==	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] Operator!=	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] Operator<	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] Operator<=	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] Operator>	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
	std::cout << "[*] Operator>=	:";
	stl_outfile.flush();
	ft_outfile.flush();
	check();
}

void	stack_tests(void)
{
	std::ofstream ft_outfile ("test_results/ft_stack.out");
	std::ofstream stl_outfile ("test_results/stl_stack.out");

	std::cout << std::endl << CYAN << "	====== STACK TESTS ======" << NC << std::endl << std::endl;

	constructor_operator_tests(stl_outfile, ft_outfile);
	capacity_functions(stl_outfile, ft_outfile);
	element_access_modifyers(stl_outfile, ft_outfile);
	non_member_overloads(stl_outfile, ft_outfile);
	
	ft_outfile.close();
	stl_outfile.close();
}
