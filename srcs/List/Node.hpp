/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:15:12 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 15:09:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <iostream>

namespace ft
{

template < typename T >
class Node
{
	public:
		typedef T	value_type; 

		Node() 													{ this->_data = value_type(); this->_prev = 0; this->_next = 0; }
		Node(value_type val, Node * prev, Node * next)			{ this->_data = val; this->_prev = prev; this->_next = next; }
		Node(Node const & src)									{ this->_data = src._data; this->_prev = 0; this->_next = 0; }
		~Node()													{}

		value_type &		data(void)							{ return(this->_data); }
		Node *				prev(void)							{ return (this->_prev); }
		Node *				next(void)							{ return (this->_next); }

		void			setData(value_type const & val)			{ this->_data = val; }
		void			setPrev(Node * prev)					{ this->_prev = prev; }
		void			setNext(Node * next)					{ this->_next = next; }
	
	private:
		value_type	_data;
		Node *		_prev;
		Node *		_next;
};


}


#endif
