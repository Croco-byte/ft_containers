/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:03:58 by user42            #+#    #+#             */
/*   Updated: 2021/05/15 15:59:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"

/*
** ------ CONSTRUCTORS / DESTRUCTOR ------
*/
template < typename T, class Container >
ft::queue<T,Container>::queue(container_type const & c) : _c(c)
{}

template < typename T, class Container >
ft::queue<T,Container>::queue(queue const & src)
{
	this->_c = src._c;
}

template < typename T, class Container >
ft::queue<T,Container>::~queue()
{}


/*
** ------ OPERATOR OVERLOADS ------
*/
template < typename T, class Container >
ft::queue<T,Container> &						ft::queue<T,Container>::operator=(queue const & rhs)
{
	this->_c = rhs._c;
}


/*
** ------ OPERATOR OVERLOADS ------
*/
template < typename T, class Container >
typename ft::queue<T,Container>::size_type				ft::queue<T,Container>::size(void) const
{ return (this->_c.size()); }

template < typename T, class Container >
bool													ft::queue<T,Container>::empty() const
{ return (this->_c.empty()); }


/*
** ------ ELEMENT ACCESS FUNCTIONS ------
*/
template < typename T, class Container >
typename ft::queue<T,Container>::value_type &			ft::queue<T,Container>::back(void)
{ return (this->_c.back()); }

template < typename T, class Container >
typename ft::queue<T,Container>::value_type const &		ft::queue<T,Container>::back(void) const
{ return (this->_c.back()); }

template < typename T, class Container >
typename ft::queue<T,Container>::value_type &			ft::queue<T,Container>::front(void)
{ return (this->_c.front()); }

template < typename T, class Container >
typename ft::queue<T,Container>::value_type const &		ft::queue<T,Container>::front(void) const
{ return (this->_c.front()); }

/*
** ------ MODIFYERS FUNCTIONS ------
*/
template < typename T, class Container >
void													ft::queue<T,Container>::push(value_type const & val)
{ this->_c.push_back(val); }

template < typename T, class Container >
void													ft::queue<T,Container>::pop(void)
{ this->_c.pop_front(); }
