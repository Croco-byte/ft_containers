/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:18:35 by user42            #+#    #+#             */
/*   Updated: 2021/05/04 16:21:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <math.h>

/*
** ------ CONSTRUCTORS AND DESTRUCTORS ------
*/

template < typename T, class A >
ft::vector<T,A>::vector()
{
	this->_size = 0;
	this->_max_size = std::numeric_limits<size_type>::max() / sizeof(value_type);
	this->_capacity = 0;
	this->_array = new T[0];
}

template < typename T, class A >
ft::vector<T,A>::vector(size_type n, value_type const & val)
{
	this->_size = n;
	this->_max_size = std::numeric_limits<size_type>::max() / sizeof(value_type);
	this->_capacity = n;
	this->_array = new T[n];
	for (size_type i = 0; i < n; i++)
		this->_array[i] = val;
}

template < typename T, class A >
ft::vector<T,A>::vector(vector<T> const & src)
{
	this->_size = src.size();
	this->_max_size = std::numeric_limits<size_type>::max() / sizeof(value_type);
	this->_capacity = src.capacity();
	this->_array = new T[this->_size];
	for (size_type i = 0; i < this->_size; i++)
		this->_array[i] = src[i];
}

template < typename T, class A >
ft::vector<T,A>::vector(InputIterator first, InputIterator last)
{
	difference_type diff = std::abs(first - last);
	
	this->_size = diff;
	this->_max_size = std::numeric_limits<size_type>::max() / sizeof(value_type);
	this->_capacity = diff;

	this->_array = new T[diff];
	for (difference_type i = 0; i < diff; i++)
		this->_array[i] = *(first + i);
}

template < typename T, class A >
ft::vector<T,A>::~vector()
{
	delete [] this->_array;
}


/*
** ------ OPERATORS OVERLOADS ------
*/

template < typename T, class A >
ft::vector<T,A> &						ft::vector<T,A>::operator=(ft::vector<T,A> const & rhs)
{
	delete [] this->_array;
	this->_size = rhs._size;
	this->_max_size = rhs._max_size;
	this->_capacity = rhs._capacity;
	this->_array = new T[this->_capacity];
	for (size_type i = 0; i < this->_size; i++)
		this->_array[i] = rhs[i];
	return (*this);
}

template < typename T, class A >
typename ft::vector<T,A>::value_type &	ft::vector<T,A>::operator[](ft::vector<T,A>::size_type index) const
{ return (this->_array[index]); }

/*
** ------ ITERATOR FUNCTIONS ------
*/
template < typename T, class A >
typename ft::vector<T,A>::iterator					ft::vector<T,A>::begin(void)
{
	iterator it(this->_array);
	return (it);
}

template < typename T, class A >
typename ft::vector<T,A>::const_iterator			ft::vector<T,A>::begin(void) const
{
	const_iterator it(this->_array);
	return (it);
}

template < typename T, class A >
typename ft::vector<T,A>::iterator					ft::vector<T,A>::end(void)
{
	iterator it(this->_array + this->_size);
	return (it);
}

template < typename T, class A >
typename ft::vector<T,A>::const_iterator			ft::vector<T,A>::end(void) const
{
	const_iterator it(this->_array + this->_size);
	return (it);
}

template < typename T, class A >
typename ft::vector<T,A>::reverse_iterator			ft::vector<T,A>::rbegin(void)
{
	reverse_iterator rev_it(this->end());
	return (rev_it);
}

template < typename T, class A >
typename ft::vector<T,A>::const_reverse_iterator	ft::vector<T,A>::rbegin(void) const
{
	const_reverse_iterator rev_it(this->end());
	return (rev_it);
}

template < typename T, class A >
typename ft::vector<T,A>::reverse_iterator			ft::vector<T,A>::rend(void)
{
	reverse_iterator rev_it(this->begin());
	return (rev_it);
}

template < typename T, class A >
typename ft::vector<T,A>::const_reverse_iterator	ft::vector<T,A>::rend(void) const
{
	const_reverse_iterator rev_it(this->begin());
	return (rev_it);
}




/*
** ------ CAPACITY FUNCTIONS ------
*/
template < typename T, class A >
typename ft::vector<T,A>::size_type	ft::vector<T,A>::size(void) const
{ return (this->_size); }

template < typename T, class A >
typename ft::vector<T,A>::size_type	ft::vector<T,A>::max_size(void) const
{ return (this->_max_size); }

template < typename T, class A >
typename ft::vector<T,A>::size_type	ft::vector<T,A>::capacity(void) const
{ return (this->_capacity); }

template < typename T, class A >
bool								ft::vector<T,A>::empty(void) const
{ return (this->_size == 0); }

template < typename T, class A >
void								ft::vector<T,A>::reserve(size_type n)
{
	if (n > this->_max_size)
		throw std::length_error("vector:: _M_capacity_check: capacity exceeds max_size");
	if (n > this->_capacity)
	{
		T *	new_array = new T[n];
		for (size_type i = 0; i < this->_size; i++)
			new_array[i] = this->_array[i];
		delete [] this->_array;
		this->_array = new_array;
		this->_capacity = n;
	}
}

template < typename T, class A >
void								ft::vector<T,A>::resize(size_type n, value_type val)
{
	if (n < this->_size)
		this->_size = n;
	else if (n > this->_size)
	{
		while (this->_size < n)
			this->push_back(val);
	}
	
}

/*
** ------ ELEMENT ACCESS ------
*/
template < typename T, class A >
typename ft::vector<T,A>::reference				ft::vector<T,A>::at(size_type n)
{ 
	if (n >= this->_size)
		throw std::out_of_range("vector::_M_range_check: requested element is ouf of range");
	return (this->_array[n]);
}

template < typename T, class A >
typename ft::vector<T,A>::const_reference		ft::vector<T,A>::at(size_type n) const
{ 
	if (n >= this->_size)
		throw std::out_of_range("vector::_M_range_check: requested element is ouf of range");
	return (this->_array[n]);
}

template < typename T, class A >
typename ft::vector<T,A>::reference				ft::vector<T,A>::front(void)
{ return *(this->_array); }

template < typename T, class A >
typename ft::vector<T,A>::const_reference		ft::vector<T,A>::front(void) const
{ return *(this->_array); }

template < typename T, class A >
typename ft::vector<T,A>::reference				ft::vector<T,A>::back(void)
{ return *(this->_array + (this->_size - 1)); }

template < typename T, class A >
typename ft::vector<T,A>::const_reference		ft::vector<T,A>::back(void) const
{ return *(this->_array + (this->_size - 1)); }



/*
** ------ MODIFYERS ------
*/

template < typename T, class A >
void			ft::vector<T,A>::assign(InputIterator first, InputIterator last)
{
	size_type new_size = std::abs(first - last);

	this->clear();
	if (new_size > this->_capacity)
		this->reserve(new_size);

	this->_size = new_size;
	for (size_type i = 0; i < this->_size; i++)
		this->_array[i] = *(first + i);
}

template < typename T, class A >
void			ft::vector<T,A>::assign(size_type n, value_type const & val)
{
	this->clear();
	if (n > this->_capacity)
		this->reserve(n);
	
	this->_size = n;
	for (size_type i = 0; i < this->_size; i++)
		this->_array[i] = val;
}

template < typename T, class A >
void			ft::vector<T,A>::push_back(value_type const & val)
{
	if (this->_size == this->_capacity)
		(this->_capacity == 0) ? this->reserve(1) : this->reserve(this->_capacity * 2);
	this->_size++;
	this->_array[this->_size - 1] = val;
}

template < typename T, class A >
void			ft::vector<T,A>::pop_back(void)
{
	if (this->_size > 0)
		this->_size--;
}

template < typename T, class A >
typename ft::vector<T,A>::iterator	ft::vector<T,A>::insert(iterator position, value_type const & val)
{
	size_type iterator_offset = std::abs(position - this->begin());

	if (this->_size + 1 > this->_capacity)
		this->reserve(this->_size + 1);
	
	this->_size = this->_size + 1;
	iterator insert_pos(this->begin() + iterator_offset);
	for (iterator it = this->end() - 1; it != insert_pos; it--)
		*it = *(it - 1);
	*insert_pos = val;

	return (insert_pos);
}

template < typename T, class A >
void			ft::vector<T,A>::insert(iterator position, size_type n, value_type const & val)
{
	size_type iterator_offset = std::abs(position - this->begin());

	if (this->_size + n > this->_capacity)
		this->reserve(this->_size + n);

	this->_size = this->_size + n;

	iterator fill_begin(this->begin() + iterator_offset);
	iterator fill_end(this->begin() + iterator_offset + n);

	for (iterator it = this->end() - 1; it != fill_end - 1; it--)
		*it = *(it - n);
	for (; fill_begin != fill_end; fill_begin++)
		*fill_begin = val;
}

template < typename T, class A >
void			ft::vector<T,A>::insert(iterator position, InputIterator first, InputIterator last)
{
	size_type iterator_offset = std::abs(position - this->begin());

	size_type range = std::abs(first - last);
	value_type * elements = new T[range];
	for (size_type i = 0; i < range; i++)
		elements[i] = *(first + i);

	if (this->_size + range > this->_capacity)
		this->reserve(this->_size + range);

	this->_size = this->_size + range;

	iterator range_begin(this->begin() + iterator_offset);
	iterator range_end(this->begin() + iterator_offset + range);
	for (iterator it = this->end() - 1; it != range_end - 1; it--)
		*it = *(it - range);

	int i = 0;
	for (; range_begin != range_end; range_begin++)
		*range_begin = elements[i++];

	delete [] elements;
}

template < typename T, class A >
typename ft::vector<T,A>::iterator	ft::vector<T,A>::erase(iterator position)
{
	iterator tmp(position);
	for (; tmp != this->end() - 1; tmp++)
		*tmp = *(tmp + 1);
	this->_size = this->_size - 1;

	return (position);
}

template < typename T, class A >
typename ft::vector<T,A>::iterator	ft::vector<T,A>::erase(iterator first, iterator last)
{
	size_type diff = std::abs(first - last);
	iterator tmp(first);
	for (; tmp != this->end() - 1; tmp++)
		*tmp = *(tmp + diff);
	this->_size = this->_size - diff;

	return (first);
}

template < typename T, class A >
void								ft::vector<T,A>::swap(vector & x)
{
	value_type *	tmpArray = this->_array;
	size_type		tmpSize = this->_size;
	size_type		tmpMax = this->_max_size;
	size_type		tmpCapacity = this->_capacity;

	this->_array = x._array;
	this->_size = x._size;
	this->_max_size = x._max_size;
	this->_capacity = x._capacity;

	x._array = tmpArray;
	x._size = tmpSize;
	x._max_size = tmpMax;
	x._capacity = tmpCapacity;
}




template < typename T, class A >
void			ft::vector<T,A>::clear(void)
{ this->_size = 0; }
