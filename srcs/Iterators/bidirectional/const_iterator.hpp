/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:02:02 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 10:45:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_BIDIRECTIONAL_HPP
# define CONST_BIDIRECTIONAL_HPP

class const_iterator
{
	public:
		typedef typename A::difference_type		difference_type;
		typedef typename A::value_type			value_type;
		typedef typename A::const_pointer		pointer;
		typedef typename A::const_reference		reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;

	private:
		Node *	_ptr;

	public:
		const_iterator(): _ptr(0) {}
		const_iterator(Node * ptr): _ptr(ptr) {}
		const_iterator(const_iterator const & src): _ptr(src._ptr) {}
		~const_iterator() {}

		const_iterator &		operator=(const_iterator const & rhs)				{ this->_ptr = rhs._ptr; return (*this); }
		bool					operator==(const_iterator const & rhs)		const	{ return (this->_ptr == rhs._ptr); }
		bool					operator!=(const_iterator const & rhs)		const	{ return (this->_ptr != rhs._ptr); }
		
		const_iterator &		operator++(void)									{ this->_ptr = this->_ptr->next(); return (*this); }
		const_iterator 			operator++(int)										{ const_iterator result(*this); this->operator++(); return (result); }
		const_iterator &		operator--(void)									{ this->_ptr = this->_ptr->prev(); return (*this); }
		const_iterator			operator--(int)										{ const_iterator result(*this); this->operator--(); return (result); }

		reference		operator*(void)												const	{ return (_ptr->data()); }
		pointer			operator->(void)											const	{ return (&(_ptr->data())); }
};

#endif
