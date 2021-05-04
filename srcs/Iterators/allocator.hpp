/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:46:52 by user42            #+#    #+#             */
/*   Updated: 2021/05/01 13:51:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP

#include <cstddef>

namespace ft
{

template < class T >
class	allocator
{
	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef const T *	const_pointer;
		typedef const T &	const_reference;
		typedef size_t		size_type;
		typedef	ptrdiff_t	difference_type;
};


}

#endif
