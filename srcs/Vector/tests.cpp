/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:04:11 by user42            #+#    #+#             */
/*   Updated: 2021/05/04 16:34:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "vector.hpp"
#include <vector>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define CYAN		"\033[0;36m"
# define NC			"\033[0m"

template < typename T >
void	write_stl_vector(std::ofstream & stl_outfile, std::vector<T> const & vec, std::string const & msg)
{
	stl_outfile << msg << std::endl;
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		stl_outfile << ' ' << *it;
	stl_outfile << std::endl;
}

template < typename T >
void	write_ft_vector(std::ofstream & ft_outfile, ft::vector<T> const & vec, std::string const & msg)
{
	ft_outfile << msg << std::endl;
	for (typename ft::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		ft_outfile << ' ' << *it;
	ft_outfile << std::endl;
}

void	check(void)
{
	if (!(system("diff test_results/ft_vector.out test_results/stl_vector.out")))
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
	{
		std::cout << RED << "			KO" << NC << std::endl;
		exit(1);
	}
}



void	constructor_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > CONSTRUCTOR" << std::endl;
	ft_outfile << "	> CONSTRUCTOR" << std::endl;
	stl_outfile << "	> CONSTRUCTOR" << std::endl;


	ft::vector<int> ft_first;
	std::vector<int> stl_first;

	ft::vector<int> ft_second (4,100);
	std::vector<int> stl_second (4,100);
	
	ft::vector<int> ft_third (ft_second.begin(),ft_second.end());
	std::vector<int> stl_third (stl_second.begin(),stl_second.end());

	ft::vector<int> ft_fourth (ft_third);
	std::vector<int> stl_fourth (stl_third);

	int myints[] = {16,2,77,29};
	ft::vector<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::vector<int> stl_fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "[*] Default	:";
	write_ft_vector(ft_outfile, ft_first, "[*] Default	:");
	write_stl_vector(stl_outfile, stl_first, "[*] Default	:");
	check();

	std::cout << "[*] Fill	:";
	write_ft_vector(ft_outfile, ft_second, "[*] Fill	:");
	write_stl_vector(stl_outfile, stl_second, "[*] Fill	:");
	check();

	std::cout << "[*] Range	:";
	write_ft_vector(ft_outfile, ft_third, "[*] Range	:");
	write_stl_vector(stl_outfile, stl_third, "[*] Range	:");
	check();

	std::cout << "[*] Copy	:";
	write_ft_vector(ft_outfile, ft_fourth, "[*] Copy	:");
	write_stl_vector(stl_outfile, stl_fourth, "[*] Copy	:");
	check();

	std::cout << "[*] Array	:";
	write_ft_vector(ft_outfile, ft_fifth, "[*] Array	:");
	write_stl_vector(stl_outfile, stl_fifth, "[*] Array	:");
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void member_operators_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > MEMBER OPERATORS" << std::endl;
	ft_outfile << "	> MEMBER OPERATORS" << std::endl;
	stl_outfile << "	> MEMBER OPERATORS" << std::endl;

	std::vector<int> stl_first (10);
	std::vector<int>::size_type sz = stl_first.size();
	for (unsigned i=0; i<sz; i++) stl_first[i]=i;
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = stl_first[sz-1-i];
		stl_first[sz-1-i]=stl_first[i];
		stl_first[i]=temp;
	}

	ft::vector<int> ft_first (10);
	ft::vector<int>::size_type ft_sz = ft_first.size();
	for (unsigned i=0; i<ft_sz; i++) ft_first[i]=i;
	for (unsigned i=0; i<ft_sz/2; i++)
	{
		int temp;
		temp = ft_first[ft_sz-1-i];
		ft_first[ft_sz-1-i]=ft_first[i];
		ft_first[i]=temp;
	}

	std::cout << "[*] Operator[]	:";
	write_ft_vector(ft_outfile, ft_first, "[*] Operator[]	:");
	write_stl_vector(stl_outfile, stl_first, "[*] Operator[]	:");
	check();

	std::vector<int> stl_foo (3,0);
	std::vector<int> stl_bar (5,0);
	stl_bar = stl_foo;

	ft::vector<int> ft_foo (3,0);
	ft::vector<int> ft_bar (5,0);

	ft_bar = ft_foo;


	std::cout << "[*] Operator=	:";
	write_ft_vector(ft_outfile, ft_bar, "[*] Operator=	:");
	write_stl_vector(stl_outfile, stl_bar, "[*] Operator=	:");
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	iterator_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > ITERATOR FUNCTIONS" << std::endl;
	ft_outfile << "	> ITERATOR FUNCTIONS" << std::endl;
	stl_outfile << "	> ITERATOR FUNCTIONS" << std::endl;

	std::vector<std::string> stl_first(3, "hey!");
	stl_first.push_back("bruh");
	ft::vector<std::string> ft_first(3, "hey!");
	ft_first.push_back("bruh");

	std::cout << "[*] begin	:";
	write_ft_vector(ft_outfile, ft_first, "[*] begin	:");
	write_stl_vector(stl_outfile, stl_first, "[*] begin	:");
	check();

	std::cout << "[*]  end	:";
	write_ft_vector(ft_outfile, ft_first, "[*]  end	:");
	write_stl_vector(stl_outfile, stl_first, "[*]  end	:");
	check();

	std::cout << "[*] rbegin	:";
	stl_outfile << "[*] rbegin	:" << std::endl;
	for(std::vector<std::string>::reverse_iterator rev_it = stl_first.rbegin(); rev_it != stl_first.rend(); rev_it++)
		stl_outfile << ' ' << *rev_it;
	stl_outfile << std::endl;
	ft_outfile << "[*] rbegin	:" << std::endl;
	for(ft::vector<std::string>::reverse_iterator rev_it = ft_first.rbegin(); rev_it != ft_first.rend(); rev_it++)
		ft_outfile << ' ' << *rev_it;
	ft_outfile << std::endl;
	check();

	std::cout << "[*] rend	:";
	stl_outfile << "[*] rend	:" << std::endl;
	for(std::vector<std::string>::reverse_iterator rev_it = stl_first.rbegin(); rev_it != stl_first.rend(); rev_it++)
		stl_outfile << ' ' << *rev_it;
	stl_outfile << std::endl;
	ft_outfile << "[*] rend	:" << std::endl;
	for(ft::vector<std::string>::reverse_iterator rev_it = ft_first.rbegin(); rev_it != ft_first.rend(); rev_it++)
		ft_outfile << ' ' << *rev_it;
	ft_outfile << std::endl;
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	capacity_functions_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > CAPACITY FUNCTIONS" << std::endl;
	ft_outfile << "	> CAPACITY FUNCTIONS" << std::endl;
	stl_outfile << "	> CAPACITY FUNCTIONS" << std::endl;

	std::vector<int> myints;
	stl_outfile << "[*] size	:" << std::endl;
	stl_outfile << "0. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) myints.push_back(i);
	stl_outfile << "1. size: " << myints.size() << '\n';
	myints.insert (myints.end(),10,100);
	stl_outfile << "2. size: " << myints.size() << '\n';
	myints.pop_back();
	stl_outfile << "3. size: " << myints.size() << '\n';

	ft::vector<int> myints2;
	ft_outfile << "[*] size	:" << std::endl;
	ft_outfile << "0. size: " << myints2.size() << '\n';
	for (int i=0; i<10; i++) myints2.push_back(i);
	ft_outfile << "1. size: " << myints2.size() << '\n';
	myints2.insert (myints2.end(),10,100);
	ft_outfile << "2. size: " << myints2.size() << '\n';
	myints2.pop_back();
	ft_outfile << "3. size: " << myints2.size() << '\n';

	std::cout << "[*] size	:";
	check();

	std::vector<int> myvector;
	stl_outfile << "[*] capacity	:" << std::endl;
	for (int i=0; i<50; i++) myvector.push_back(i);
	stl_outfile << "capacity: " << myvector.capacity() << "\n";
	stl_outfile << "[*] max_size	:" << std::endl;
	stl_outfile << "max_size: " << myvector.max_size() << "\n";

	ft::vector<int> myvector2;
	ft_outfile << "[*] capacity	:" << std::endl;
	for (int i=0; i<50; i++) myvector2.push_back(i);
	ft_outfile << "capacity: " << myvector2.capacity() << "\n";
	ft_outfile << "[*] max_size	:" << std::endl;
	ft_outfile << "max_size: " << myvector2.max_size() << "\n";
	
	std::cout << "[*] capacity	:";
	check();
	std::cout << "[*] max_size	:";
	check();

	std::vector<int> stl_first;
	for (int i=1;i<10;i++) stl_first.push_back(i);
	stl_first.resize(5);
	stl_first.resize(8,100);
	stl_first.resize(12);

	ft::vector<int> ft_first;
	for (int i=1;i<10;i++) ft_first.push_back(i);
	ft_first.resize(5);
	ft_first.resize(8,100);
	ft_first.resize(12);

	std::cout << "[*] resize	:";
	write_ft_vector(ft_outfile, ft_first, "[*] resize	:");
	write_stl_vector(stl_outfile, stl_first, "[*] resize	:");
	check();

	std::vector<int> stl_second;
	int sum (0);
	for (int i=1;i<=10;i++) stl_second.push_back(i);
	while (!stl_second.empty())
	{
		sum += stl_second.back();
		stl_second.pop_back();
	}
	stl_outfile << "[*] empty	:" << std::endl << sum << std::endl;

	ft::vector<int> ft_second;
	sum = 0;
	for (int i=1;i<=10;i++) ft_second.push_back(i);
	while (!ft_second.empty())
	{
		sum += ft_second.back();
		ft_second.pop_back();
	}
	ft_outfile << "[*] empty	:" << std::endl << sum << std::endl;

	std::cout << "[*] empty	:";
	check();

	std::vector<int> stl_third(5, 42);
	ft::vector<int> ft_third(5, 42);

	stl_outfile << "[*] reserve	:" << std::endl;
	ft_outfile << "[*] reserve	:" << std::endl;
	stl_outfile << "Before reserve, capacity is : " << stl_third.capacity() << std::endl;
	ft_outfile << "Before reserve, capacity is : " << ft_third.capacity() << std::endl;
	stl_third.reserve(16);
	ft_third.reserve(16);
	stl_outfile << "After reserve, capacity is : " << stl_third.capacity() << std::endl;
	ft_outfile << "After reserve, capacity is : " << ft_third.capacity() << std::endl;

	std::cout << "[*] reserve	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}


void	element_access_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > ELEMENT ACCESS FUNCTIONS" << std::endl;
	ft_outfile << "	> ELEMENT ACCESS FUNCTIONS" << std::endl;
	stl_outfile << "	> ELEMENT ACCESS FUNCTIONS" << std::endl;

	std::vector<int> stl_first (10);
	ft::vector<int> ft_first (10);
	for (unsigned i=0; i<stl_first.size(); i++)
		stl_first.at(i)=i;
	for (unsigned i=0; i<ft_first.size(); i++)
		ft_first.at(i)=i;
	
	std::cout << "[*]   at	:";
	write_ft_vector(ft_outfile, ft_first, "[*]   at	:");
	write_stl_vector(stl_outfile, stl_first, "[*]   at	:");
	check();

	std::vector<int> stl_second;
	stl_second.push_back(78);
	stl_second.push_back(16);
	stl_second.front() -= stl_second.back();
	stl_outfile << "[*] front	:" << std::endl;
	stl_outfile << "myvector.front() is now " << stl_second.front() << '\n';

	ft::vector<int> ft_second;
	ft_second.push_back(78);
	ft_second.push_back(16);
	ft_second.front() -= ft_second.back();
	ft_outfile << "[*] front	:" << std::endl;
	ft_outfile << "myvector.front() is now " << ft_second.front() << '\n';

	std::cout << "[*] front	:";
	check();

	stl_outfile << "[*] back	:" << std::endl;
	stl_outfile << "myvector.back() is now " << stl_second.back() << '\n';
	ft_outfile << "[*] back	:" << std::endl;
	ft_outfile << "myvector.back() is now " << ft_second.back() << '\n';

	std::cout << "[*] back	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	modifyers_functions(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > MODIFYER FUNCTIONS" << std::endl;
	ft_outfile << "	> MODIFYER FUNCTIONS" << std::endl;
	stl_outfile << "	> MODIFYER FUNCTIONS" << std::endl;

	std::vector<int> stl_first;
	std::vector<int> stl_second;
	stl_first.assign (7,100);
	std::vector<int>::iterator it = stl_first.begin()+1;
	stl_second.assign (it,stl_first.end()-1);

	ft::vector<int> ft_first;
	ft::vector<int> ft_second;
	ft_first.assign (7,100);
	ft::vector<int>::iterator it2 = ft_first.begin()+1;
	ft_second.assign (it2,ft_first.end()-1);

	std::cout << "[*] assign	:";
	write_ft_vector(ft_outfile, ft_first, "[*] assign	:");
	write_ft_vector(ft_outfile, ft_second, "");
	write_stl_vector(stl_outfile, stl_first, "[*] assign	:");
	write_stl_vector(stl_outfile, stl_second, "");
	check();

	std::vector<std::string> stl_third;
	ft::vector<std::string> ft_third;

	stl_third.push_back("hi");
	stl_third.push_back("bruh");
	ft_third.push_back("hi");
	ft_third.push_back("bruh");

	std::cout << "[*] push_back	:";
	write_ft_vector(ft_outfile, ft_third, "[*] push_back	:");
	write_stl_vector(stl_outfile, stl_third, "[*] push_back	:");
	check();

	stl_third.pop_back();
	ft_third.pop_back();
	std::cout << "[*] pop_back	:";
	write_ft_vector(ft_outfile, ft_third, "[*] pop_back	:");
	write_stl_vector(stl_outfile, stl_third, "[*] pop_back	:");
	check();


	std::vector<int> stl_fourth (3,100);
	std::vector<int>::iterator stl_it;
	stl_it = stl_fourth.begin();
	stl_it = stl_fourth.insert ( stl_it , 200 );
	stl_fourth.insert (stl_it,2,300);
	stl_it = stl_fourth.begin();
	std::vector<int> anothervector (2,400);
	stl_fourth.insert (stl_it+2,anothervector.begin(),anothervector.end());
	int myarray [] = { 501,502,503 };
	stl_fourth.insert (stl_fourth.begin(), myarray, myarray+3);

	ft::vector<int> ft_fourth (3,100);
	ft::vector<int>::iterator ft_it;
	ft_it = ft_fourth.begin();
	ft_it = ft_fourth.insert ( ft_it , 200 );
	ft_fourth.insert (ft_it,2,300);
	ft_it = ft_fourth.begin();
	ft::vector<int> anothervector2 (2,400);
	ft_fourth.insert (ft_it+2,anothervector2.begin(),anothervector2.end());
	int myarray2 [] = { 501,502,503 };
	ft_fourth.insert (ft_fourth.begin(), myarray2, myarray2+3);

	std::cout << "[*] insert	:";
	write_ft_vector(ft_outfile, ft_fourth, "[*] insert	:");
	write_stl_vector(stl_outfile, stl_fourth, "[*] insert	:");
	check();

	std::vector<int> stl_six;
	for (int i=1; i<=10; i++) stl_six.push_back(i);
	stl_six.erase (stl_six.begin()+5);
	stl_six.erase (stl_six.begin(),stl_six.begin()+3);

	ft::vector<int> ft_six;
	for (int i=1; i<=10; i++) ft_six.push_back(i);
	ft_six.erase (ft_six.begin()+5);
	ft_six.erase (ft_six.begin(),ft_six.begin()+3);

	std::cout << "[*] erase	:";
	write_ft_vector(ft_outfile, ft_six, "[*] erase	:");
	write_stl_vector(stl_outfile, stl_six, "[*] erase	:");
	check();

	std::vector<int> stl_a(5,0);
	std::vector<int> stl_b(4,42);
	stl_a.swap(stl_b);

	ft::vector<int> ft_a(5,0);
	ft::vector<int> ft_b(4,42);
	ft_a.swap(ft_b);

	std::cout << "[*] swap	:";
	write_ft_vector(ft_outfile, ft_b, "[*] swap	:");
	write_stl_vector(stl_outfile, stl_b, "[*] swap	:");
	check();

	std::vector<int> stl_seven(5,4);
	ft::vector<int> ft_seven(5,4);
	stl_seven.clear();
	ft_seven.clear();

	std::cout << "[*] clear	:";
	write_ft_vector(ft_outfile, ft_seven, "[*] clear	:");
	write_stl_vector(stl_outfile, stl_seven, "[*] clear	:");
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

void	non_member_overloads(void)
{
	std::cout << "  > NON MEMBER OVERLOADS" << std::endl;

	ft::vector<int> a(1, 1);
	ft::vector<int> b(1, 1);

	std::cout << "[*] Operator==	:";
	if (a == b)
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
		std::cout << RED << "			KO" << NC << std::endl;
	
	std::cout << "[*] Operator!=	:";
	a.push_back(2);
	if (a != b)
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
		std::cout << RED << "			KO" << NC << std::endl;
	
	std::cout << "[*] Operator<	:";
	if (b < a)
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
		std::cout << RED << "			KO" << NC << std::endl;
	
	std::cout << "[*] Operator>	:";
	b.push_back(1);
	if (a > b)
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
		std::cout << RED << "			KO" << NC << std::endl;

	std::cout << "[*] Operator<=	:";
	b.pop_back();
	b.push_back(2);
	if (b >= a)
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
		std::cout << RED << "			KO" << NC << std::endl;
	
	std::cout << "[*] Operator>=	:";
	if (b >= a)
		std::cout << GREEN << "			OK" << NC << std::endl;
	else
		std::cout << RED << "			KO" << NC << std::endl;

	std::cout << std::endl;
}

void	vector_tests(void)
{
	std::ofstream ft_outfile ("test_results/ft_vector.out");
	std::ofstream stl_outfile ("test_results/stl_vector.out");

	std::cout << std::endl << CYAN << "	====== VECTOR TESTS ======" << NC << std::endl << std::endl;

	constructor_tests(ft_outfile, stl_outfile);
	member_operators_tests(ft_outfile, stl_outfile);
	iterator_tests(ft_outfile, stl_outfile);
	capacity_functions_tests(ft_outfile, stl_outfile);
	element_access_tests(ft_outfile, stl_outfile);
	modifyers_functions(ft_outfile, stl_outfile);
	non_member_overloads();

	
	ft_outfile.close();
	stl_outfile.close();
}
