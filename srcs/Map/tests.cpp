/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:20:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/14 15:54:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <map>
#include "map.hpp"

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define CYAN		"\033[0;36m"
# define NC			"\033[0m"

template < typename T, typename T2 >
void	ftdisplay(ft::map<T,T2> const & mymap, std::ofstream & ft_outfile)
{
	if (mymap.empty())
		ft_outfile << "<empty>" << std::endl;
	else
	{
		for (typename ft::map<T,T2>::const_iterator it = mymap.begin(); it != mymap.end(); it++)
			ft_outfile << '[' << it->first << "=>" << it->second << "]	";
		ft_outfile << std::endl;
	}
}

template < typename T, typename T2 >
void	stldisplay(std::map<T,T2> const & mymap, std::ofstream & stl_outfile)
{
	if (mymap.empty())
		stl_outfile << "<empty>" << std::endl;
	else
	{
		for (typename std::map<T,T2>::const_iterator it = mymap.begin(); it != mymap.end(); it++)
			stl_outfile << '[' << it->first << "=>" << it->second << "]	";
		stl_outfile << std::endl;
	}
}

static void	check(void)
{
	std::ifstream ft,stl;
	ft.open("test_results/ft_map.out");
	stl.open("test_results/stl_map.out");

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

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

static void	constructor_operators_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > CONSTRUCTOR" << std::endl;
	ft_outfile << "	> CONSTRUCTOR" << std::endl;
	stl_outfile << "	> CONSTRUCTOR" << std::endl;

	{
		std::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::map<char,int> second (++first.begin(),--first.end());
		std::map<char,int> third (second);
		std::map<char,int> assign;
		assign = first;
		std::map<char,int,classcomp> fourth;
		stl_outfile << "[*] default	:" << std::endl;
		stldisplay(first, stl_outfile);
		stl_outfile << "[*] range	:" << std::endl;
		stldisplay(second, stl_outfile);
		stl_outfile << "[*] copy	:" << std::endl;
		stldisplay(third, stl_outfile);
		stl_outfile << "[*] compClass	:" << std::endl;
		if (fourth.empty())
			stl_outfile << "<empty>" << std::endl;
		else
		{
			for (std::map<char,int,classcomp>::const_iterator it = fourth.begin(); it != fourth.end(); it++)
				stl_outfile << '[' << it->first << "=>" << it->second << "]	";
			stl_outfile << std::endl;
		}
		stl_outfile << std::endl;
		stl_outfile << "	> OPERATORS" << std::endl;

		stl_outfile << "[*] operator=	:" << std::endl;
		stldisplay(assign, stl_outfile);
	}
	{
		ft::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		ft::map<char,int> second (++first.begin(),--first.end());
		ft::map<char,int> third (second);
		ft::map<char,int> assign;
		assign = first;
		ft::map<char,int,classcomp> fourth;
		ft_outfile << "[*] default	:" << std::endl;
		ftdisplay(first, ft_outfile);
		ft_outfile << "[*] range	:" << std::endl;
		ftdisplay(second, ft_outfile);
		ft_outfile << "[*] copy	:" << std::endl;
		ftdisplay(third, ft_outfile);
		ft_outfile << "[*] compClass	:" << std::endl;
		if (fourth.empty())
			ft_outfile << "<empty>" << std::endl;
		else
		{
			for (ft::map<char,int,classcomp>::iterator it = fourth.begin(); it != fourth.end(); it++)
				ft_outfile << '[' << it->first << "=>" << it->second << "]	";
			ft_outfile << std::endl;
		}
		ft_outfile << std::endl;
		ft_outfile << "	> OPERATORS" << std::endl;

		ft_outfile << "[*] operator=	:" << std::endl;
		ftdisplay(assign, ft_outfile);
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] default	:";
	check();
	std::cout << "[*] range	:";
	check();
	std::cout << "[*] copy	:";
	check();
	std::cout << "[*] compClass	:";
	check();

	std::cout << std::endl;
	std::cout << " > OPERATORS" << std::endl;
	std::cout << "[*] operator=	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	iterator_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > ITERATOR" << std::endl;
	ft_outfile << "	> ITERATOR" << std::endl;
	stl_outfile << "	> ITERATOR" << std::endl;

	{
		std::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
 		mymap['c'] = 300;
		 stl_outfile << "[*] begin / end :" << std::endl;
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
 		mymap['c'] = 300;
		 ft_outfile << "[*] begin / end :" << std::endl;
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] begin	:";
	check();
	std::cout << "[*]  end	:";
	check();

	{
		std::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
 		mymap['c'] = 300;
		 stl_outfile << "[*] rbegin / rend :" << std::endl;
		for (std::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
 		mymap['c'] = 300;
		 ft_outfile << "[*] rbegin / rend :" << std::endl;
		for (ft::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] rbegin	:";
	check();
	std::cout << "[*] rend	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	capacity_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > CAPACITY" << std::endl;
	ft_outfile << "	> CAPACITY" << std::endl;
	stl_outfile << "	> CAPACITY" << std::endl;

	{
		std::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		stl_outfile << "[*] empty : " << std::endl;
		while (!mymap.empty())
		{
			stl_outfile << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	{
		ft::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		ft_outfile << "[*] empty : " << std::endl;
		while (!mymap.empty())
		{
			ft_outfile << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] empty	:";
	check();

	{
		std::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;
		stl_outfile << "[*] size :" << std::endl;
		stl_outfile << "mymap.size() is " << mymap.size() << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;
		ft_outfile << "[*] size :" << std::endl;
		ft_outfile << "mymap.size() is " << mymap.size() << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] size	:";
	check();

	{
		int i;
		std::map<int,int> mymap;
		stl_outfile << "[*] max_size :" << std::endl;
		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			stl_outfile << "The map contains 1000 elements.\n";
		}
		else stl_outfile << "The map could not hold 1000 elements.\n";
	}
	{
		int i;
		ft::map<int,int> mymap;
		ft_outfile << "[*] max_size :" << std::endl;
		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			ft_outfile << "The map contains 1000 elements.\n";
		}
		else ft_outfile << "The map could not hold 1000 elements.\n";
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] max_size	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	element_access_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > ELEMENT ACCESS" << std::endl;
	ft_outfile << "	> ELEMENT ACCESS" << std::endl;
	stl_outfile << "	> ELEMENT ACCESS" << std::endl;

	{
		std::map<char,std::string> mymap;
		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];
		stl_outfile << "[*] operator[] :" << std::endl;
		stl_outfile << "mymap['a'] is " << mymap['a'] << '\n';
		stl_outfile << "mymap['b'] is " << mymap['b'] << '\n';
		stl_outfile << "mymap['c'] is " << mymap['c'] << '\n';
		stl_outfile << "mymap['d'] is " << mymap['d'] << '\n';
		stl_outfile << "mymap now contains " << mymap.size() << " elements.\n";
	}
	{
		ft::map<char,std::string> mymap;
		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];
		ft_outfile << "[*] operator[] :" << std::endl;
		ft_outfile << "mymap['a'] is " << mymap['a'] << '\n';
		ft_outfile << "mymap['b'] is " << mymap['b'] << '\n';
		ft_outfile << "mymap['c'] is " << mymap['c'] << '\n';
		ft_outfile << "mymap['d'] is " << mymap['d'] << '\n';
		ft_outfile << "mymap now contains " << mymap.size() << " elements.\n";
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] operator[]	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	modifyers_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > MODIFYERS" << std::endl;
	ft_outfile << "	> MODIFYERS" << std::endl;
	stl_outfile << "	> MODIFYERS" << std::endl;

	{
		 std::map<char,int> mymap;

		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		stl_outfile << "[*] insert :" << std::endl;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
			stl_outfile << "element 'z' already existed";
			stl_outfile << " with a value of " << ret.first->second << '\n';
		}
		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (std::pair<char,int>('b',300));
		mymap.insert (std::pair<char,int>('c',400));

		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		stl_outfile << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';

		stl_outfile << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
	}
	{
		 ft::map<char,int> mymap;

		mymap.insert ( ft::Pair<char,int>('a',100) );
		mymap.insert ( ft::Pair<char,int>('z',200) );

		ft::Pair<ft::map<char,int>::iterator,bool> ret;
		ft_outfile << "[*] insert :" << std::endl;
		ret = mymap.insert ( ft::Pair<char,int>('z',500) );
		if (ret.second==false) {
			ft_outfile << "element 'z' already existed";
			ft_outfile << " with a value of " << ret.first->second << '\n';
		}
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (ft::Pair<char,int>('b',300));
		mymap.insert (ft::Pair<char,int>('c',400));

		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		ft_outfile << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';

		ft_outfile << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] insert	:";
	check();

	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		it=mymap.find('b');
		mymap.erase (it);
		mymap.erase ('c');
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );
		stl_outfile << "[*] erase :" << std::endl;
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		it=mymap.find('b');
		mymap.erase (it);
		mymap.erase ('c');
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );
		ft_outfile << "[*] erase :" << std::endl;
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] erase	:";
	check();

	{
		std::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		foo.swap(bar);
		stl_outfile << "[*] swap :" << std::endl;
		stl_outfile << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';

		stl_outfile << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		foo.swap(bar);
		ft_outfile << "[*] swap :" << std::endl;
		ft_outfile << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';

		ft_outfile << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] swap	:";
	check();

	{
		std::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
		stl_outfile << "[*] clear :" << std::endl;
		stl_outfile << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;
		stl_outfile << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
		ft_outfile << "[*] clear :" << std::endl;
		ft_outfile << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;
		ft_outfile << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] clear	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	observers_tests(std::ofstream & stl_outfile, std::ofstream & ft_outfile)
{
	std::cout << "  > OBSERVERS" << std::endl;
	ft_outfile << "	> OBSERVERS" << std::endl;
	stl_outfile << "	> OBSERVERS" << std::endl;

	{
		std::map<char,int> mymap;
		std::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;
		stl_outfile << "[*] key_comp :" << std::endl;
		stl_outfile << "mymap contains:\n";
		char highest = mymap.rbegin()->first;
		std::map<char,int>::iterator it = mymap.begin();
		do {
			stl_outfile << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		stl_outfile << '\n';
	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;
		ft_outfile << "[*] key_comp :" << std::endl;
		ft_outfile << "mymap contains:\n";
		char highest = mymap.rbegin()->first;
		ft::map<char,int>::iterator it = mymap.begin();
		do {
			ft_outfile << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		ft_outfile << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] key_comp	:";
	check();

	{
		std::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;
		stl_outfile << "[*] value_comp :" << std::endl;
		stl_outfile << "mymap contains:\n";
		std::pair<char,int> highest = *mymap.rbegin();
		std::map<char,int>::iterator it = mymap.begin();
		do {
			stl_outfile << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	{
		ft::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;
		ft_outfile << "[*] value_comp :" << std::endl;
		ft_outfile << "mymap contains:\n";
		ft::Pair<char,int> highest = *mymap.rbegin();
		ft::map<char,int>::iterator it = mymap.begin();
		do {
			ft_outfile << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] value_comp	:";
	check();

	std::cout << std::endl;
	ft_outfile << std::endl;
	stl_outfile << std::endl;
}

static void	operations_tests(std::ofstream & ft_outfile, std::ofstream & stl_outfile)
{
	std::cout << "  > OPERATIONS" << std::endl;
	ft_outfile << "	> OPERATIONS" << std::endl;
	stl_outfile << "	> OPERATIONS" << std::endl;

	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;
		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;
		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);
		stl_outfile << "[*] find :" << std::endl;
		stl_outfile << "elements in mymap:" << '\n';
		stl_outfile << "a => " << mymap.find('a')->second << '\n';
		stl_outfile << "c => " << mymap.find('c')->second << '\n';
		stl_outfile << "d => " << mymap.find('d')->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;
		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;
		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);
		ft_outfile << "[*] find :" << std::endl;
		ft_outfile << "elements in mymap:" << '\n';
		ft_outfile << "a => " << mymap.find('a')->second << '\n';
		ft_outfile << "c => " << mymap.find('c')->second << '\n';
		ft_outfile << "d => " << mymap.find('d')->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] find	:";
	check();

	{
		std::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;
		stl_outfile << "[*] count :" << std::endl;
		for (c='a'; c<'h'; c++)
		{
			stl_outfile << c;
			if (mymap.count(c)>0)
				stl_outfile << " is an element of mymap.\n";
			else 
				stl_outfile << " is not an element of mymap.\n";
		}
	}
	{
		ft::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;
		ft_outfile << "[*] count :" << std::endl;
		for (c='a'; c<'h'; c++)
		{
			ft_outfile << c;
			if (mymap.count(c)>0)
				ft_outfile << " is an element of mymap.\n";
			else 
				ft_outfile << " is not an element of mymap.\n";
		}
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] count	:";
	check();

	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');
		itup=mymap.upper_bound ('d');
		mymap.erase(itlow,itup);
		stl_outfile << "[*] lower / upper bound :" << std::endl;
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			stl_outfile << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');
		itup=mymap.upper_bound ('d');
		mymap.erase(itlow,itup);
		ft_outfile << "[*] lower / upper bound :" << std::endl;
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ft_outfile << it->first << " => " << it->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] upper_bound	:";
	check();
	std::cout << "[*] lower_bound	:";
	check();

	{
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');
		stl_outfile << "[*] equal_range :" << std::endl;
		stl_outfile << "lower bound points to: ";
		stl_outfile << ret.first->first << " => " << ret.first->second << '\n';
		stl_outfile << "upper bound points to: ";
		stl_outfile << ret.second->first << " => " << ret.second->second << '\n';
	}
	{
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		ft::Pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');
		ft_outfile << "[*] equal_range :" << std::endl;
		ft_outfile << "lower bound points to: ";
		ft_outfile << ret.first->first << " => " << ret.first->second << '\n';
		ft_outfile << "upper bound points to: ";
		ft_outfile << ret.second->first << " => " << ret.second->second << '\n';
	}
	stl_outfile.flush();
	ft_outfile.flush();
	std::cout << "[*] equal_range	:";
	check();
}

void	map_tests(void)
{
	std::ofstream ft_outfile ("test_results/ft_map.out");
	std::ofstream stl_outfile ("test_results/stl_map.out");

	std::cout << std::endl << CYAN << "	====== MAP TESTS ======" << NC << std::endl << std::endl;

	constructor_operators_tests(ft_outfile, stl_outfile);
	iterator_tests(ft_outfile, stl_outfile);
	capacity_tests(ft_outfile, stl_outfile);
	element_access_tests(ft_outfile, stl_outfile);
	modifyers_tests(ft_outfile, stl_outfile);
	observers_tests(ft_outfile, stl_outfile);
	operations_tests(ft_outfile, stl_outfile);

	ft_outfile.close();
	stl_outfile.close();
}
