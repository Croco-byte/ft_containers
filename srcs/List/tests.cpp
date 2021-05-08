/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:40:15 by user42            #+#    #+#             */
/*   Updated: 2021/05/08 16:06:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <list>
#include <cmath>

#include "list.hpp"

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define CYAN		"\033[0;36m"
# define NC			"\033[0m"

template < typename T >
void	write_stl_list(std::ofstream & stl_outfile, std::list<T> const & list, std::string const & msg)
{
	stl_outfile << msg << std::endl;
	if (list.size() == 0)
	{
		stl_outfile << "List data	: <empty>" << std::endl;
		return ;
	}
	stl_outfile << "List data	: [X]";
	for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); it++)
		stl_outfile << " <- " << *it << " -> ";
	stl_outfile << "[X]" << std::endl;
}

template < typename T >
void	write_ft_list(std::ofstream & ft_outfile, ft::list<T> const & list, std::string const & msg)
{
	ft_outfile << msg << std::endl;
	if (list.size() == 0)
	{
		ft_outfile << "List data	: <empty>" << std::endl;
		return ;
	}
	ft_outfile << "List data	: [X]";
	for (typename ft::list<T>::const_iterator it = list.begin(); it != list.end(); it++)
		ft_outfile << " <- " << *it << " -> ";
	ft_outfile << "[X]" << std::endl;
}

void	check(void)
{
	if (!(system("diff test_results/ft_list.out test_results/stl_list.out")))
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
	{
		std::cout << RED << "			KO" << NC << std::endl;
		exit(1);
	}
}


void	constructor_operators_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > CONSTRUCTOR" << std::endl;
	ft_outfile << "	> CONSTRUCTOR" << std::endl;
	stl_outfile << "	> CONSTRUCTOR" << std::endl;


	ft::list<int> ft_first;
	std::list<int> stl_first;

	ft::list<int> ft_second (4,100);
	std::list<int> stl_second (4,100);
	
	ft::list<int> ft_third (++ft_second.begin(),--ft_second.end());
	std::list<int> stl_third (++stl_second.begin(),--stl_second.end());

	ft::list<int> ft_fourth (ft_second);
	std::list<int> stl_fourth (stl_second);

	std::cout << "[*] Default	:";
	write_ft_list(ft_outfile, ft_first, "[*] Default	:");
	write_stl_list(stl_outfile, stl_first, "[*] Default	:");
	check();

	std::cout << "[*] Fill	:";
	write_ft_list(ft_outfile, ft_second, "[*] Fill	:");
	write_stl_list(stl_outfile, stl_second, "[*] Fill	:");
	check();

	std::cout << "[*] Range	:";
	write_ft_list(ft_outfile, ft_third, "[*] Range	:");
	write_stl_list(stl_outfile, stl_third, "[*] Range	:");
	check();

	std::cout << "[*] Copy	:";
	write_ft_list(ft_outfile, ft_fourth, "[*] Copy	:");
	write_stl_list(stl_outfile, stl_fourth, "[*] Copy	:");
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;

	std::cout << "  > OPERATORS" << std::endl;
	ft_outfile << "	> OPERATORS" << std::endl;
	stl_outfile << "	> OPERATORS" << std::endl;

	ft_second.push_back(4444);
	ft_second.push_back(4445);
	ft::list<int> ft_assigned(5,3);
	ft_assigned = ft_second;

	stl_second.push_back(4444);
	stl_second.push_back(4445);
	std::list<int> stl_assigned(5,3);
	stl_assigned = stl_second;

	std::cout << "[*] Operator=	:";
	write_ft_list(ft_outfile, ft_assigned, "[*] Operator=	:");
	write_stl_list(stl_outfile, stl_assigned, "[*] Operator=	:");
	check();


	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	iterator_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > ITERATORS" << std::endl;
	ft_outfile << "	> ITERATORS" << std::endl;
	stl_outfile << "	> ITERATORS" << std::endl;

	ft::list<int> ft_first;
	for(int i = 1; i < 11; i++) { ft_first.push_back(i); }
	std::list<int> stl_first;
	for(int i = 1; i < 11; i++) { stl_first.push_back(i); }

	std::cout << "[*] begin	:";
	ft_outfile << "[*] begin	: ";
	for (ft::list<int>::iterator it = ft_first.begin(); it != ft_first.end(); it++)
		ft_outfile << *it << ' ';
	ft_outfile << std::endl;
	stl_outfile << "[*] begin	: ";
	for (std::list<int>::iterator it = stl_first.begin(); it != stl_first.end(); it++)
		stl_outfile << *it << ' ';
	stl_outfile << std::endl;
	check();

	std::cout << "[*]  end	:";
	check();


	std::cout << "[*] rbegin	:";
	ft_outfile << "[*] rbegin / rend	: ";
	for (ft::list<int>::reverse_iterator it = ft_first.rbegin(); it != ft_first.rend(); it++)
		ft_outfile << *it << ' ';
	ft_outfile << std::endl;
	stl_outfile << "[*] rbegin / rend	: ";
	for (std::list<int>::reverse_iterator it = stl_first.rbegin(); it != stl_first.rend(); it++)
		stl_outfile << *it << ' ';
	stl_outfile << std::endl;
	check();

	std::cout << "[*] rend	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	capacity_functions_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > CAPACITY" << std::endl;
	ft_outfile << "	> CAPACITY" << std::endl;
	stl_outfile << "	> CAPACITY" << std::endl;

	std::list<int> myints;
	stl_outfile << "[*] size	:" << std::endl;
	stl_outfile << "0. size: " << myints.size() << std::endl;
	for (int i=0; i<10; i++) myints.push_back(i);
	stl_outfile << "1. size: " << myints.size() << std::endl;
	myints.push_back(3);
	stl_outfile << "2. size: " << myints.size() << std::endl;
	myints.pop_back();
	stl_outfile << "3. size: " << myints.size() << std::endl;

	std::list<int> myints2;
	ft_outfile << "[*] size	:" << std::endl;
	ft_outfile << "0. size: " << myints2.size() << std::endl;
	for (int i=0; i<10; i++) myints2.push_back(i);
	ft_outfile << "1. size: " << myints2.size() << std::endl;
	myints2.push_back(3);
	ft_outfile << "2. size: " << myints2.size() << std::endl;
	myints2.pop_back();
	ft_outfile << "3. size: " << myints2.size() << std::endl;

	std::cout << "[*] size	:";
	check();

	std::list<int> mylist;
	stl_outfile << "[*] max_size	:" << std::endl;
	stl_outfile << "max_size: " << mylist.max_size() << "\n";

	ft::list<int> mylist2;
	ft_outfile << "[*] max_size	:" << std::endl;
	ft_outfile << "max_size: " << mylist2.max_size() << "\n";
	
	std::cout << "[*] max_size	:";
	check();

	std::list<int> stl_second;
	int sum (0);
	for (int i=1;i<=10;i++) stl_second.push_back(i);
	while (!stl_second.empty())
	{
		sum += 1;
		stl_second.pop_back();
	}
	stl_outfile << "[*] empty	:" << std::endl << sum << std::endl;

	ft::list<int> ft_second;
	sum = 0;
	for (int i=1;i<=10;i++) ft_second.push_back(i);
	while (!ft_second.empty())
	{
		sum += 1;
		ft_second.pop_back();
	}
	ft_outfile << "[*] empty	:" << std::endl << sum << std::endl;

	std::cout << "[*] empty	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	element_access_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > ELEMENT ACCESS" << std::endl;
	ft_outfile << "	> ELEMENT ACCESS" << std::endl;
	stl_outfile << "	> ELEMENT ACCESS" << std::endl;

	std::list<int> stl_second;
	stl_second.push_back(78);
	stl_second.push_back(16);
	stl_second.front() -= stl_second.back();
	stl_outfile << "[*] front	:" << std::endl;
	stl_outfile << "mylist.front() is now " << stl_second.front() << '\n';

	ft::list<int> ft_second;
	ft_second.push_back(78);
	ft_second.push_back(16);
	ft_second.front() -= ft_second.back();
	ft_outfile << "[*] front	:" << std::endl;
	ft_outfile << "mylist.front() is now " << ft_second.front() << '\n';

	std::cout << "[*] front	:";
	check();

	stl_outfile << "[*] back	:" << std::endl;
	stl_outfile << "mylist.back() is now " << stl_second.back() << '\n';
	ft_outfile << "[*] back	:" << std::endl;
	ft_outfile << "mylist.back() is now " << ft_second.back() << '\n';

	std::cout << "[*] back	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	modifyers_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > MODIFYERS" << std::endl;
	ft_outfile << "	> MODIFYERS" << std::endl;
	stl_outfile << "	> MODIFYERS" << std::endl;

	std::list<int> stl_first(2, 3);
	std::list<int> stl_second(5, 42);
	stl_first.assign (7,100);
	stl_second.assign (++stl_first.begin(),--stl_first.end());
	write_stl_list(stl_outfile, stl_first, "[*] assign :\n");
	write_stl_list(stl_outfile, stl_second, "");

	ft::list<int> first(2, 3);
	ft::list<int> second(5, 42);
	first.assign (7,100);
	second.assign (++first.begin(),--first.end());
	write_ft_list(ft_outfile, first, "[*] assign :\n");
	write_ft_list(ft_outfile, second, "");

	std::cout << "[*] assign	:";
	check();

	std::list<int> stl_third (2,100);
	stl_third.push_front (200);
	stl_third.push_front (300);
	write_stl_list(stl_outfile, stl_third, "[*] push_front	:");

	ft::list<int> ft_third (2,100);
	ft_third.push_front (200);
	ft_third.push_front (300);
	write_ft_list(ft_outfile, ft_third, "[*] push_front	:");

	std::cout << "[*] push_front	:";
	check();

	stl_outfile << "[*] pop_front	:" << std::endl;
	std::list<int> stl_4;
	stl_4.push_back (100);
	stl_4.push_back (200);
	stl_4.push_back (300);
	stl_outfile << "Popping out the elements in list:";
	while (!stl_4.empty())
	{
		stl_outfile << ' ' << stl_4.front();
		stl_4.pop_front();
	}
	stl_outfile << "\nFinal size of list is " << stl_4.size() << std::endl;

	ft_outfile << "[*] pop_front	:" << std::endl;
	ft::list<int> ft_4;
	ft_4.push_back (100);
	ft_4.push_back (200);
	ft_4.push_back (300);
	ft_outfile << "Popping out the elements in list:";
	while (!ft_4.empty())
	{
		ft_outfile << ' ' << ft_4.front();
		ft_4.pop_front();
	}
	ft_outfile << "\nFinal size of list is " << ft_4.size() << std::endl;

	std::cout << "[*] pop_front	:";
	check();

	std::list<int> stl_5;
	stl_5.push_back(1);
	stl_5.push_back(3);
	stl_5.push_back(5);
	stl_outfile << "[*] push_back	:" << std::endl;
	for (std::list<int>::reverse_iterator it = stl_5.rbegin(); it != stl_5.rend(); it++)
		stl_outfile << *it << ' ';
	stl_outfile << std::endl;

	ft::list<int> ft_5;
	ft_5.push_back(1);
	ft_5.push_back(3);
	ft_5.push_back(5);
	ft_outfile << "[*] push_back	:" << std::endl;
	for (ft::list<int>::reverse_iterator it = ft_5.rbegin(); it != ft_5.rend(); it++)
		ft_outfile << *it << ' ';
	ft_outfile << std::endl;

	std::cout << "[*] push_back	:";
	check();

	stl_outfile << "[*] pop_back	:" << std::endl;
	std::list<int> stl_6;
	stl_6.push_back (100);
	stl_6.push_back (200);
	stl_6.push_back (300);
	stl_outfile << "Popping out the elements in list (from the back):";
	while (!stl_6.empty())
	{
		stl_outfile << ' ' << stl_6.back();
		stl_6.pop_back();
	}
	stl_outfile << "\nFinal size of list is " << stl_6.size() << std::endl;

	ft_outfile << "[*] pop_back	:" << std::endl;
	ft::list<int> ft_6;
	ft_6.push_back (100);
	ft_6.push_back (200);
	ft_6.push_back (300);
	ft_outfile << "Popping out the elements in list (from the back):";
	while (!ft_6.empty())
	{
		ft_outfile << ' ' << ft_6.back();
		ft_6.pop_back();
	}
	ft_outfile << "\nFinal size of list is " << ft_6.size() << std::endl;

	std::cout << "[*] pop_back	:";
	check();

	ft_outfile << "[*] insert	:" << std::endl;
	ft::list<int> ft_7;
	ft::list<int>::iterator ft_it;
	for (int i=1; i<=5; ++i) ft_7.push_back(i);
	ft_it = ft_7.begin();
	++ft_it;
	ft_7.insert (ft_it,10);
	ft_7.insert (ft_it,2,20);
	--ft_it;
	ft::list<int> list (2,30);
	ft_7.insert (ft_it,list.begin(),list.end());
	ft_outfile << "list contains:";
	for (ft_it=ft_7.begin(); ft_it!=ft_7.end(); ++ft_it)
		ft_outfile << ' ' << *ft_it;
	ft_outfile << std::endl;

	stl_outfile << "[*] insert	:" << std::endl;
	std::list<int> stl_7;
	std::list<int>::iterator stl_it;
	for (int i=1; i<=5; ++i) stl_7.push_back(i);
	stl_it = stl_7.begin();
	++stl_it;
	stl_7.insert (stl_it,10);
	stl_7.insert (stl_it,2,20);
	--stl_it;
	std::list<int> list2 (2,30);
	stl_7.insert (stl_it,list2.begin(),list2.end());
	stl_outfile << "list contains:";
	for (stl_it=stl_7.begin(); stl_it!=stl_7.end(); ++stl_it)
		stl_outfile << ' ' << *stl_it;
	stl_outfile << std::endl;

	std::cout << "[*] insert	:";
	check();

	std::list<int> stl_8;
	std::list<int>::iterator it8,it9;
	for (int i=1; i<10; ++i) stl_8.push_back(i*10);
	it8 = it9 = stl_8.begin();
	for (int i=0; i<6;i++) it9++;
	++it8;
	it8 = stl_8.erase (it8);
	it9 = stl_8.erase (it9);
	++it8;
	--it9;
	stl_8.erase (it8,it9);
	stl_outfile << "[*] erase :" << std::endl;
	stl_outfile << "mylist contains:";
	for (it8=stl_8.begin(); it8!=stl_8.end(); ++it8)
		stl_outfile << ' ' << *it8;
	stl_outfile << std::endl;

	ft::list<int> ft_8;
	ft::list<int>::iterator it1,it2;
	for (int i=1; i<10; ++i) ft_8.push_back(i*10);
	it1 = it2 = ft_8.begin();
	for (int i=0; i<6;i++) it2++;
	++it1;
	it1 = ft_8.erase (it1);
	it2 = ft_8.erase (it2);
	++it1;
	--it2;
	ft_8.erase (it1,it2);
	ft_outfile << "[*] erase :" << std::endl;
	ft_outfile << "mylist contains:";
	for (it1=ft_8.begin(); it1!=ft_8.end(); ++it1)
		ft_outfile << ' ' << *it1;
	ft_outfile << std::endl;

	std::cout << "[*] erase	:";
	check();

	std::list<int> stl_f (3,100);
	std::list<int> stl_s (5,200);
	stl_f.swap(stl_s);
	stl_outfile << "[*] swap :" << std::endl;
	stl_outfile << "first contains:";
	for (std::list<int>::iterator it=stl_f.begin(); it!=stl_f.end(); it++)
		stl_outfile << ' ' << *it;
	stl_outfile << std::endl;
	stl_outfile << "second contains:";
	for (std::list<int>::iterator it=stl_s.begin(); it!=stl_s.end(); it++)
		stl_outfile << ' ' << *it;
	stl_outfile << std::endl;

	std::list<int> ft_first (3,100);
	std::list<int> ft_second (5,200);
	ft_first.swap(ft_second);
	ft_outfile << "[*] swap :" << std::endl;
	ft_outfile << "first contains:";
	for (std::list<int>::iterator it=ft_first.begin(); it!=ft_first.end(); it++)
		ft_outfile << ' ' << *it;
	ft_outfile << std::endl;
	ft_outfile << "second contains:";
	for (std::list<int>::iterator it=ft_second.begin(); it!=ft_second.end(); it++)
		ft_outfile << ' ' << *it;
	ft_outfile << std::endl;

	std::cout << "[*] swap	:";
	check();

	std::list<int> stl_9;
	for (int i=1; i<10; ++i) stl_9.push_back(i);
	stl_9.resize(5);
	stl_9.resize(8,100);
	stl_9.resize(12);
	stl_outfile << "[*] resize :" << std::endl;
	stl_outfile << "mylist contains:";
	for (std::list<int>::iterator it=stl_9.begin(); it!=stl_9.end(); ++it)
		stl_outfile << ' ' << *it;
	stl_outfile << std::endl;

	ft::list<int> ft_9;
	for (int i=1; i<10; ++i) ft_9.push_back(i);
	ft_9.resize(5);
	ft_9.resize(8,100);
	ft_9.resize(12);
	ft_outfile << "[*] resize :" << std::endl;
	ft_outfile << "mylist contains:";
	for (ft::list<int>::iterator it=ft_9.begin(); it!=ft_9.end(); ++it)
		ft_outfile << ' ' << *it;
	ft_outfile << std::endl;

	std::cout << "[*] resize	:";
	check();

{
	std::list<int> mylist;
	std::list<int>::iterator it;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	stl_outfile << "[*] clear :" << std::endl;
	stl_outfile << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		stl_outfile << ' ' << *it;
	stl_outfile << std::endl;
	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);
	stl_outfile << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		stl_outfile << ' ' << *it;
	stl_outfile << std::endl;
}

{
	ft::list<int> mylist;
	ft::list<int>::iterator it;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	ft_outfile << "[*] clear :" << std::endl;
	ft_outfile << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		ft_outfile << ' ' << *it;
	ft_outfile << std::endl;
	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);
	ft_outfile << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		ft_outfile << ' ' << *it;
	ft_outfile << std::endl;
}
	std::cout << "[*] clear	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

bool single_digit (const int& value) { return (value<10); }

struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

void	operations_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > OPERATIONS" << std::endl;
	ft_outfile << "	> OPERATIONS" << std::endl;
	stl_outfile << "	> OPERATIONS" << std::endl;

	{
		stl_outfile << "[*] splice :" << std::endl;
		std::list<int> mylist1, mylist2;
		std::list<int>::iterator it;

		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);

		it = mylist1.begin();
		++it;

		mylist1.splice (it, mylist2);
		mylist2.splice (mylist2.begin(),mylist1, it);
		it = mylist1.begin();
		for (int i = 0; i < 3; i++) it++;

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());

		stl_outfile << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;

		stl_outfile << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;
	}
	{
		ft_outfile << "[*] splice :" << std::endl;
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;

		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);

		it = mylist1.begin();
		++it;

		mylist1.splice (it, mylist2);
		mylist2.splice (mylist2.begin(),mylist1, it);
		it = mylist1.begin();
		for (int i = 0; i < 3; i++) it++;

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());

		ft_outfile << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;

		ft_outfile << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;
	}

	std::cout << "[*] splice	:";
	check();

	{
		std::list<int> mylist;
		mylist.push_back(17);
		mylist.push_back(89);
		mylist.push_back(7);
		mylist.push_back(14);

		mylist.remove(89);
		stl_outfile << "[*] remove :" << std::endl;
		stl_outfile << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;
	}
	{
		ft::list<int> mylist;
		mylist.push_back(17);
		mylist.push_back(89);
		mylist.push_back(7);
		mylist.push_back(14);

		mylist.remove(89);
		ft_outfile << "[*] remove :" << std::endl;
		ft_outfile << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;
	}

	std::cout << "[*] remove	:";
	check();

	{
		ft::list<int> mylist(1, 15);
		mylist.push_back(36);
		mylist.push_back(7);
		mylist.push_back(17);
		mylist.push_back(20);
		mylist.push_back(39);
		mylist.push_back(4);
		mylist.push_back(1);

		mylist.remove_if(single_digit);
		mylist.remove_if(is_odd());
		ft_outfile << "[*] remove_if :" << std::endl;
		ft_outfile << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;
	}
	{
		std::list<int> mylist(1, 15);
		mylist.push_back(36);
		mylist.push_back(7);
		mylist.push_back(17);
		mylist.push_back(20);
		mylist.push_back(39);
		mylist.push_back(4);
		mylist.push_back(1);

		mylist.remove_if(single_digit);
		mylist.remove_if(is_odd());
		stl_outfile << "[*] remove_if :" << std::endl;
		stl_outfile << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;
	}

	std::cout << "[*] remove_if	:";
	check();

	{
		std::list<double> mylist;
		mylist.push_back(12.15);
		mylist.push_back(2.72);
		mylist.push_back(73.0);
		mylist.push_back(12.77);
		mylist.push_back(3.14);
		mylist.push_back(12.77);
		mylist.push_back(73.35);
		mylist.push_back(72.25);
		mylist.push_back(15.3);
		mylist.push_back(72.25);
		mylist.sort();
		mylist.unique();
		mylist.unique (same_integral_part);
		mylist.unique (is_near());
		stl_outfile << "[*] unique :" << std::endl;
		stl_outfile << "mylist contains:";
		for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;
	}
	{
		ft::list<double> mylist;
		mylist.push_back(12.15);
		mylist.push_back(2.72);
		mylist.push_back(73.0);
		mylist.push_back(12.77);
		mylist.push_back(3.14);
		mylist.push_back(12.77);
		mylist.push_back(73.35);
		mylist.push_back(72.25);
		mylist.push_back(15.3);
		mylist.push_back(72.25);
		mylist.sort();
		mylist.unique();
		mylist.unique (same_integral_part);
		mylist.unique (is_near());
		ft_outfile << "[*] unique :" << std::endl;
		ft_outfile << "mylist contains:";
		for (ft::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;
	}

	std::cout << "[*] unique	:";
	check();

	{
		std::list<std::string> mylist;
		std::list<std::string>::iterator it;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();
		stl_outfile << "[*] sort :" << std::endl;
		stl_outfile << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;

		mylist.sort(compare_nocase);

		stl_outfile << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;
	}
	{
		ft::list<std::string> mylist;
		ft::list<std::string>::iterator it;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();
		ft_outfile << "[*] sort :" << std::endl;
		ft_outfile << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;

		mylist.sort(compare_nocase);

		ft_outfile << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;
	}

	std::cout << "[*] sort	:";
	check();

	{
		std::list<int> mylist;
		for (int i=1; i<10; ++i) mylist.push_back(i);
		mylist.reverse();
		stl_outfile << "[*] reverse :" << std::endl;
		stl_outfile << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			stl_outfile << ' ' << *it;
		stl_outfile << std::endl;
	}
	{
		ft::list<int> mylist;
		for (int i=1; i<10; ++i) mylist.push_back(i);
		mylist.reverse();
		ft_outfile << "[*] reverse :" << std::endl;
		ft_outfile << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			ft_outfile << ' ' << *it;
		ft_outfile << std::endl;
	}

	std::cout << "[*] reverse	:";
	check();


	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}



void	list_tests(void)
{
	std::ofstream ft_outfile ("test_results/ft_list.out");
	std::ofstream stl_outfile ("test_results/stl_list.out");

	std::cout << std::endl << CYAN << "	====== LIST TESTS ======" << NC << std::endl << std::endl;

	constructor_operators_tests(ft_outfile, stl_outfile);
	iterator_tests(ft_outfile, stl_outfile);
	capacity_functions_tests(ft_outfile, stl_outfile);
	element_access_tests(ft_outfile, stl_outfile);
	modifyers_tests(ft_outfile, stl_outfile);
	operations_tests(ft_outfile, stl_outfile);


	ft_outfile.close();
	stl_outfile.close();
}

