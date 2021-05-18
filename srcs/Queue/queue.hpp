/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:04:07 by user42            #+#    #+#             */
/*   Updated: 2021/05/15 15:59:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <iostream>
#include "../List/list.hpp"

namespace ft
{

template < typename T, class Container = list<T> >
class	queue
{
	public:
		/* TYPEDEFs FOR QUEUE CHARACTERISTICS */
		typedef T										value_type;
		typedef Container								container_type;
		typedef typename container_type::size_type		size_type;

		/* CONSTRUCTORS / DESTRUCTOR */
		queue(container_type const & c = container_type());
		queue(queue const & src);
		~queue();

		/* OPERATOR OVERLOADS */
		queue &			operator=(queue const & rhs);

		/* CAPACITY FUNCTIONS */
		size_type				size(void)					const;
		bool					empty(void)					const;

		/* ELEMENT ACCESS FUNCTIONS */
		value_type &			back(void);
		value_type const &		back(void)					const;
		value_type &			front(void);
		value_type const &		front(void)					const;

		/* MODIFYERS FUNCTIONS */
		void					push(value_type const & val);
		void					pop(void);

		/* DECLARATION OF FRIEND FUNCTIONS (NON-MEMBER FUNCTIONS OVERLOADS) */
		template < typename T2, class Container2 >
		friend bool				operator==(queue<T2,Container2> const & lhs, queue<T2,Container2> const & rhs)	{ return (lhs._c == rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator!=(queue<T2,Container2> const & lhs, queue<T2,Container2> const & rhs)	{ return (lhs._c != rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator<(queue<T2,Container2> const & lhs, queue<T2,Container2> const & rhs)	{ return (lhs._c < rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator>(queue<T2,Container2> const & lhs, queue<T2,Container2> const & rhs)	{ return (lhs._c > rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator<=(queue<T2,Container2> const & lhs, queue<T2,Container2> const & rhs)	{ return (lhs._c <= rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator>=(queue<T2,Container2> const & lhs, queue<T2,Container2> const & rhs)	{ return (lhs._c >= rhs._c); }

	private:
		container_type	_c;

};

}

#include "queue.ipp"

#endif

/*
 -- LIST TODO :

 ---> Member functions
 	---> Constructors
	 	> Default							OK
		> From_container					OK
		> Copy								OK
	
	---> Operators
		> Operator=							OK

	---> Capacity
		> size								OK
		> empty								OK
	
	---> Element access
		> back								OK
		> front								OK
	
	---> Modifyers
		> push								OK
		> pop								OK

 ---> Non-member functions overload
	---> Relational operators
		> Operator ==						OK
		> Operator !=						OK
		> Operator >						OK
		> Operator <						OK
		> Operator >=						OK
		> Operator <=						OK

=== REMARQUES ===

 ---> Le container sous-jacent par défaut qu'on va utiliser pour l'implémentation de la queue sera la "list", puisqu'on a pas implémenté les Deques (qui semblent assez complexes
 	   en termes d'implémentation, si on suit les méthodes de la STL).

*/

