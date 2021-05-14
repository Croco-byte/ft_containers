/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_map_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:57:19 by qroland           #+#    #+#             */
/*   Updated: 2021/05/14 11:10:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_MAP_ITERATOR_HPP
# define CONST_MAP_ITERATOR_HPP

class	const_iterator
{
	public:
		typedef typename allocator_type::difference_type				difference_type;
		typedef typename allocator_type::value_type						value_type;
		typedef typename allocator_type::const_pointer					pointer;
		typedef typename allocator_type::const_reference				reference;
		typedef ft::bidirectional_iterator_tag							iterator_category;
	
		const_iterator(): _ptr(0) {}
		const_iterator(Node * ptr): _ptr(ptr) {}
		const_iterator(const_iterator const & src): _ptr(src._ptr) {}
		~const_iterator() {}

		const_iterator &		operator=(const_iterator const & rhs)					{ this->_ptr = rhs._ptr; return (*this); }
		bool					operator==(const_iterator const & rhs)		const		{ return (this->_ptr == rhs._ptr); }
		bool					operator!=(const_iterator const & rhs)		const		{ return (this->_ptr != rhs._ptr); }
		
		const_iterator &		operator++(void)										{ if (this->_ptr) this->_ptr = next(this->_ptr); return (*this); }
		const_iterator 			operator++(int)											{ const_iterator result(*this); this->operator++(); return (result); }
		const_iterator &		operator--(void)										{ if (this->_ptr) this->_ptr = prev(this->_ptr); return (*this); }
		const_iterator			operator--(int)											{ const_iterator result(*this); this->operator--(); return (result); }

		reference				operator*(void)								const		{ return (_ptr->data); }
		pointer					operator->(void)							const		{ return &(_ptr->data); }

	private:
		Node *	_ptr;

};



#endif
