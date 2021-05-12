/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:33:19 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 12:48:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template < typename T1, typename T2 >
class Pair
{
	public:
		/* PUBLIC MEMBER TYPES */
		typedef T1				first_type;
		typedef T2				second_type;

		/* PUBLIC MEMBER VARIABLES */
		first_type				first;
		second_type				second;

		/* CONSTRUCTORS / DESTRUCTORS */
		Pair()												: first(), second()						{}
		Pair(first_type const & a, second_type const & b)	: first(a), second(b)					{}
		Pair(Pair const & src)								: first(src.first), second(src.second)	{}
		~Pair()																						{}

		/* OPERATOR OVERLOADS */
		Pair &				operator=(Pair const & rhs)												{ this->first = rhs.first; this->second = rhs.second; return (*this); }

		/* STATIC HELPER FUNCTIONS */
		static Pair<T1,T2>	make_pair(T1 x, T2 y)													{ return (Pair<T1,T2>(x,y)); }

};

	/* NON-MEMBER OPERATOR OVERLOADS */
	template < typename T1, typename T2 >
	bool		operator==(Pair<T1,T2> const & lhs, Pair<T1,T2> const & rhs)
	{ return lhs.first == rhs.first && lhs.second == rhs.second; }

	template < typename T1, typename T2 >
	bool		operator!=(Pair<T1,T2> const & lhs, Pair<T1,T2> const & rhs)
	{ return !(lhs == rhs); }

	template < typename T1, typename T2 >
	bool		operator<(Pair<T1,T2> const & lhs, Pair<T1,T2> const & rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template < typename T1, typename T2 >
	bool		operator<=(Pair<T1,T2> const & lhs, Pair<T1,T2> const & rhs)
	{ return !(rhs < lhs); }

	template < typename T1, typename T2 >
	bool		operator>(Pair<T1,T2> const & lhs, Pair<T1,T2> const & rhs)
	{ return rhs < lhs; }

	template < typename T1, typename T2 >
	bool		operator>=(Pair<T1,T2> const & lhs, Pair<T1,T2> const & rhs)
	{ return !(lhs<rhs); }

}

#endif
