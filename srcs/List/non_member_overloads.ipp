/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_overloads.ipp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:12:21 by user42            #+#    #+#             */
/*   Updated: 2021/05/09 11:19:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

/* LIST NON-MEMBER FUNCTIONS OVERLOAD IMPLEMENTATION */
template < typename T, class A >
bool	operator==(list<T,A> const & lhs, list<T,A> const & rhs)
{
	if (lhs._size != rhs._size)
		return (false);
	typename ft::list<T,A>::const_iterator comp = rhs.begin();
	for (typename ft::list<T,A>::const_iterator it = lhs.begin(); it != lhs.end(); it++)
	{
		if (*comp != *it)
			return (false);
		comp++;
	}
	return (true);
}

template < typename T, class A >
bool	operator!=(list<T,A> const & lhs, list<T,A> const & rhs)
{
	if (lhs == rhs)
		return (false);
	return (true);
}

template < typename T, class A >
bool	operator<(list<T,A> const & lhs, list<T,A> const & rhs)
{
	typename ft::list<T,A>::const_iterator comp = rhs.begin();
	for (typename ft::list<T,A>::const_iterator it = lhs.begin(); it != lhs.end(); it++)
	{
		if (*it < *comp)
			return (true);
		if (*comp < *it)
			return (false);
	}
	if (lhs._size >= rhs._size)
		return (false);
	return (true);
}

template < typename T, class A >
bool	operator>(list<T,A> const & lhs, list<T,A> const & rhs)
{
	if (rhs < lhs)
		return (true);
	return (false);
}

template < typename T, class A >
bool	operator<=(list<T,A> const & lhs, list<T,A> const & rhs)
{
	if (!(lhs > rhs))
		return (true);
	return (false);
}

template < typename T, class A >
bool	operator>=(list<T,A> const & lhs, list<T,A> const & rhs)
{
	if (!(lhs < rhs))
		return (true);
	return (false);
}

template < typename T, class A >
void	swap(list<T,A> &x, list<T,A> &y)
{ x.swap(y); }
