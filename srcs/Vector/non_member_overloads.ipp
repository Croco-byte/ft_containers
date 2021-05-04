/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_overloads.ipp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:52:13 by user42            #+#    #+#             */
/*   Updated: 2021/05/03 17:56:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

/* VECTOR NON-MEMBER FUNCTIONS OVERLOAD IMPLEMENTATION */
template < typename T, class A >
bool	operator==(vector<T,A> const & lhs, vector<T,A> const & rhs)
{
	if (lhs._size != rhs._size)
		return (false);
	for (typename ft::vector<T,A>::size_type i = 0; i < lhs._size; i++)
	{
		if (lhs._array[i] != rhs._array[i])
			return (false);
	}

	return (true);
}

template < typename T, class A >
bool	operator!=(vector<T,A> const & lhs, vector<T,A> const & rhs)
{
	if (lhs == rhs)
		return (false);
	return (true);
}

template < typename T, class A >
bool	operator<(vector<T,A> const & lhs, vector<T,A> const & rhs)
{
	typename ft::vector<T,A>::size_type min_size = std::min(lhs._size, rhs._size);
	for (typename ft::vector<T,A>::size_type i = 0; i < min_size; i++)
	{
		if (lhs._array[i] < rhs._array[i])
			return (true);
		if (rhs._array[i] < lhs._array[i])
			return (false);
	}
	if (lhs._size >= rhs._size)
		return (false);
	return (true);
}

template < typename T, class A >
bool	operator>(vector<T,A> const & lhs, vector<T,A> const & rhs)
{
	if (rhs < lhs)
		return (true);
	return (false);
}

template < typename T, class A >
bool	operator<=(vector<T,A> const & lhs, vector<T,A> const & rhs)
{
	if (!(lhs > rhs))
		return (true);
	return (false);
}

template < typename T, class A >
bool	operator>=(vector<T,A> const & lhs, vector<T,A> const & rhs)
{
	if (!(lhs < rhs))
		return (true);
	return (false);
}

template < typename T, class A >
void	swap(vector<T,A> &x, vector<T,A> &y)
{ x.swap(y); }
