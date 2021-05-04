/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:42:22 by user42            #+#    #+#             */
/*   Updated: 2021/05/02 15:28:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

template < class Iterator >
class	reverse_iterator
{
	public:
		typedef	Iterator								iterator_type;
		typedef	typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;

	private:
		iterator_type	_it;
	
	public:
		reverse_iterator(): _it() {}
		reverse_iterator(iterator_type it): _it(it - 1) {}
		reverse_iterator(reverse_iterator< iterator_type > const & src): _it(src._it) {}

		iterator_type		base(void)									const	{ return (this->_it); }
		reverse_iterator&	operator++(void)									{ (this->_it)--; return (*this); }
		reverse_iterator	operator++(int)										{ reverse_iterator result(*this); this->operator++(); return (result); }
		reverse_iterator&	operator--(void)									{ (this->_it)++; return (*this); }
		reverse_iterator	operator--(int)										{ reverse_iterator result(*this); this->operator--(); return (result); }
		reverse_iterator	operator+(difference_type n)				const	{ return (reverse_iterator(this->_it - n)); }
		reverse_iterator	operator-(difference_type n)				const	{ return (reverse_iterator(this->_it + n)); }
		reverse_iterator&	operator+=(difference_type n)						{ (this->_it) -= n; return (*this); }
		reverse_iterator&	operator-=(difference_type n)						{ (this->_it) += n; return (*this); }

		bool				operator==(reverse_iterator const & rhs)	const	{ return (this->_it == rhs._it); }
		bool				operator!=(reverse_iterator const & rhs)	const	{ return (this->_it != rhs._it); }

		reference			operator*(void)								const	{ return (*(this->_it)); }
		pointer				operator->(void)							const	{ return (&(this->operator*())); }
		reference			operator[](difference_type n)				const	{ return *(this->_it - n); }

};



}


#endif
