/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:27:40 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 15:29:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
# define LESS_HPP

namespace ft
{

template < class T >
class less
{
	public:
		bool	operator()(T const & x, T const & y)	const	{ return x<y; }

};

}

#endif
