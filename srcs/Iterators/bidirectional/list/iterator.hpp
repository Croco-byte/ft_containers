/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroland <qroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:54:17 by user42            #+#    #+#             */
/*   Updated: 2021/05/12 13:58:20 by qroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_HPP
# define BIDIRECTIONAL_HPP

class iterator
{
	public:
		typedef typename A::difference_type		difference_type;
		typedef typename A::value_type			value_type;
		typedef typename A::pointer				pointer;
		typedef typename A::reference			reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;
	
		iterator(): _ptr(0) {}
		iterator(Node * ptr): _ptr(ptr) {}
		iterator(iterator const & src): _ptr(src._ptr) {}
		~iterator() {}

		iterator &		operator=(iterator const & rhs)					{ this->_ptr = rhs._ptr; return (*this); }
		bool			operator==(iterator const & rhs)		const	{ return (this->_ptr == rhs._ptr); }
		bool			operator!=(iterator const & rhs)		const	{ return (this->_ptr != rhs._ptr); }
		
		iterator &		operator++(void)								{ if (this->_ptr) this->_ptr = this->_ptr->next(); return (*this); }
		iterator 		operator++(int)									{ iterator result(*this); this->operator++(); return (result); }
		iterator &		operator--(void)								{ if (this->_ptr) this->_ptr = this->_ptr->prev(); return (*this); }
		iterator		operator--(int)									{ iterator result(*this); this->operator--(); return (result); }

		reference		operator*(void)							const	{ return (_ptr->data()); }
		pointer			operator->(void)						const	{ return &(_ptr->data()); }

	private:
		Node *	_ptr;

};



#endif
