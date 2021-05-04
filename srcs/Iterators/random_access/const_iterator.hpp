/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:02:41 by user42            #+#    #+#             */
/*   Updated: 2021/05/02 13:06:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

class const_iterator
{
	public:
		typedef typename A::difference_type		difference_type;
		typedef typename A::value_type			value_type;
		typedef typename A::const_pointer		pointer;
		typedef typename A::const_reference		reference;
		typedef ft::random_access_iterator_tag	iterator_category;

	private:
		value_type *	_ptr;

	public:
		const_iterator(): _ptr(0) {}
		const_iterator(value_type * p): _ptr(p) {}
		const_iterator(const_iterator const & src): _ptr(src._ptr) {}
		~const_iterator() {}

		const_iterator&		operator=(const_iterator const & rhs)			{ this->_ptr = rhs._ptr; return (*this); }
		bool			operator==(const_iterator const & rhs)		const	{ return (this->_ptr == rhs._ptr); }
		bool			operator!=(const_iterator const & rhs)		const	{ return (this->_ptr != rhs._ptr); }
		bool			operator>(const_iterator const & rhs)		const	{ return (this->_ptr > rhs._ptr); }
		bool			operator<(const_iterator const & rhs)		const	{ return (this->_ptr < rhs._ptr); }
		bool			operator>=(const_iterator const & rhs)		const	{ return (this->_ptr >= rhs._ptr); }
		bool			operator<=(const_iterator const & rhs)		const	{ return (this->_ptr <= rhs._ptr); }

		const_iterator&		operator++(void)								{ this->_ptr++; return (*this); }										// Implements ++it (canonical implementation returns reference)
		const_iterator		operator++(int)									{ const_iterator result(*this); this->operator++(); return (result); }	// Implements it++ (canonical implementation returns value)
		const_iterator&		operator--(void)								{ this->_ptr--; return (*this); }
		const_iterator		operator--(int)									{ const_iterator result(*this); this->operator--(); return (result); }
		const_iterator		operator+(size_type n)					const	{ const_iterator result(*this); result._ptr += n; return (result); }
		const_iterator		operator-(size_type n)					const	{ const_iterator result(*this); result._ptr -= n; return (result); }
		difference_type		operator-(const_iterator const & rhs)	const	{ return (this->_ptr - rhs._ptr); }
		const_iterator&		operator+=(size_type n)							{ this->_ptr += n; return (*this); }
		const_iterator&		operator-=(size_type n)							{ this->_ptr -= n; return (*this); }

		reference		operator*()								const	{ return (*(this->_ptr)); }
		pointer			operator->()							const	{ return (this->_ptr); }
		reference		operator[](size_type n)					const	{ return (*(this->_ptr + n)); }
};

#endif
