/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:50:43 by user42            #+#    #+#             */
/*   Updated: 2021/05/09 15:03:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

/*
** ------ CONSTRUCTORS / DESTRUCTOR ------
*/
template < typename T, class Container >
ft::stack<T,Container>::stack(container_type const & c) : _c(c)
{}

template < typename T, class Container >
ft::stack<T,Container>::stack(stack const & src)
{
	this->_c = src._c;
}

template < typename T, class Container >
ft::stack<T,Container>::~stack()
{}


/*
** ------ OPERATOR OVERLOADS ------
*/
template < typename T, class Container >
ft::stack<T,Container> &						ft::stack<T,Container>::operator=(stack const & rhs)
{
	this->_c = rhs._c;
}


/*
** ------ OPERATOR OVERLOADS ------
*/
template < typename T, class Container >
typename ft::stack<T,Container>::size_type				ft::stack<T,Container>::size(void) const
{ return (this->_c.size()); }

template < typename T, class Container >
bool													ft::stack<T,Container>::empty() const
{ return (this->_c.empty()); }


/*
** ------ ELEMENT ACCESS FUNCTIONS ------
*/
template < typename T, class Container >
typename ft::stack<T,Container>::value_type &			ft::stack<T,Container>::top(void)
{ return (this->_c.back()); }

template < typename T, class Container >
typename ft::stack<T,Container>::value_type const &		ft::stack<T,Container>::top(void) const
{ return (this->_c.back()); }


/*
** ------ MODIFYERS FUNCTIONS ------
*/
template < typename T, class Container >
void													ft::stack<T,Container>::push(value_type const & val)
{ this->_c.push_back(val); }

template < typename T, class Container >
void													ft::stack<T,Container>::pop(void)
{ this->_c.pop_back(); }
