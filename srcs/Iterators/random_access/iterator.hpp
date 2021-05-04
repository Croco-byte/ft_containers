/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:29:30 by user42            #+#    #+#             */
/*   Updated: 2021/05/01 16:19:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

class iterator
{
	public:
		typedef typename A::difference_type		difference_type;
		typedef typename A::value_type			value_type;
		typedef typename A::pointer				pointer;
		typedef typename A::reference			reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	
	private:
		pointer	_ptr;
	
	public:
		iterator(): _ptr(0) {}
		iterator(pointer p): _ptr(p) {}
		iterator(iterator const & src): _ptr(src._ptr) {}
		~iterator() {}

		iterator&		operator=(iterator const & rhs)				{ this->_ptr = rhs._ptr; return (*this); }
		bool			operator==(iterator const & rhs)	const	{ return (this->_ptr == rhs._ptr); }
		bool			operator!=(iterator const & rhs)	const	{ return (this->_ptr != rhs._ptr); }
		bool			operator>(iterator const & rhs)		const	{ return (this->_ptr > rhs._ptr); }
		bool			operator<(iterator const & rhs)		const	{ return (this->_ptr < rhs._ptr); }
		bool			operator>=(iterator const & rhs)	const	{ return (this->_ptr >= rhs._ptr); }
		bool			operator<=(iterator const & rhs)	const	{ return (this->_ptr <= rhs._ptr); }

		iterator&		operator++(void)							{ this->_ptr++; return (*this); }									// Implements ++it (canonical implementation returns reference)
		iterator		operator++(int)								{ iterator result(*this); this->operator++(); return (result); }	// Implements it++ (canonical implementation returns value)
		iterator&		operator--(void)							{ this->_ptr--; return (*this); }
		iterator		operator--(int)								{ iterator result(*this); this->operator--(); return (result); }
		iterator		operator+(size_type n)				const	{ iterator result(*this); result._ptr += n; return (result); }
		iterator		operator-(size_type n)				const	{ iterator result(*this); result._ptr -= n; return (result); }
		difference_type	operator-(iterator const & rhs)		const	{ return (this->_ptr - rhs._ptr); }
		iterator&		operator+=(size_type n)						{ this->_ptr += n; return (*this); }
		iterator&		operator-=(size_type n)						{ this->_ptr -= n; return (*this); }

		reference		operator*()							const	{ return (*(this->_ptr)); }
		pointer			operator->()						const	{ return (this->_ptr); }
		reference		operator[](size_type n)				const	{ return (*(this->_ptr + n)); }
};

#endif
