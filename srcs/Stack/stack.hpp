/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:50:53 by user42            #+#    #+#             */
/*   Updated: 2021/05/09 15:00:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include "../List/list.hpp"

namespace ft
{

template < typename T, class Container = list<T> >
class	stack
{
	public:
		/* TYPEDEFs FOR STACK CHARACTERISTICS */
		typedef T										value_type;
		typedef Container								container_type;
		typedef typename container_type::size_type		size_type;

		/* CONSTRUCTORS / DESTRUCTOR */
		stack(container_type const & c = container_type());
		stack(stack const & src);
		~stack();

		/* OPERATOR OVERLOADS */
		stack &			operator=(stack const & rhs);

		/* CAPACITY FUNCTIONS */
		size_type				size(void)					const;
		bool					empty(void)					const;

		/* ELEMENT ACCESS FUNCTIONS */
		value_type &			top(void);
		value_type const &		top(void)					const;

		/* MODIFYERS FUNCTIONS */
		void					push(value_type const & val);
		void					pop(void);

		/* DECLARATION OF FRIEND FUNCTIONS (NON-MEMBER FUNCTIONS OVERLOADS) */
		template < typename T2, class Container2 >
		friend bool				operator==(stack<T2,Container2> const & lhs, stack<T2,Container2> const & rhs)	{ return (lhs._c == rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator!=(stack<T2,Container2> const & lhs, stack<T2,Container2> const & rhs)	{ return (lhs._c != rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator<(stack<T2,Container2> const & lhs, stack<T2,Container2> const & rhs)	{ return (lhs._c < rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator>(stack<T2,Container2> const & lhs, stack<T2,Container2> const & rhs)	{ return (lhs._c > rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator<=(stack<T2,Container2> const & lhs, stack<T2,Container2> const & rhs)	{ return (lhs._c <= rhs._c); }
		template < typename T2, class Container2 >
		friend bool				operator>=(stack<T2,Container2> const & lhs, stack<T2,Container2> const & rhs)	{ return (lhs._c >= rhs._c); }

	private:
		container_type	_c;

};

}

#include "stack.ipp"

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
		> top								OK
	
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

 ---> Le container sous-jacent par défaut qu'on va utiliser pour l'implémentation de la stack sera la "list", puisqu'on a pas implémenté les Deques (qui semblent assez complexes
 	   en termes d'implémentation, si on suit les méthodes de la STL). La stack fonctionnera également avec notre implémentation du "vector", il faudra simplement le préciser
	   explicitement (voir les tests "constructors", qui illustrent cette possibilité).

*/
