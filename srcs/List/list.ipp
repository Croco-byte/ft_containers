/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:36:07 by user42            #+#    #+#             */
/*   Updated: 2021/05/09 12:27:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

/*
** ------ PRIVATE HELPER FUNCTIONS ------
*/
template < typename T, class A >
void		ft::list<T,A>::free_list(void)
{
	if (this->empty())
		return ;
	Node * tmp = this->_first;
	delete (this->_first->prev());
	while (tmp)
	{
		Node * temp = tmp->next();
		delete (tmp);
		tmp = temp;
	}
	this->_first = 0;
}

template < typename T, class A >
void		ft::list<T,A>::copy_from_source(list const & src)
{
	this->_size = src._size;
	if (this->empty())
	{
		this->_first = 0;
		return ;
	}
	this->_first = new Node(*(src._first));
	Node * tmp = this->_first;
	Node * srcTmp = src._first->next();
	for (size_type i = 1; i < src._size; i++)
	{
		Node * new_node = new Node(*srcTmp);
		new_node->setPrev(tmp);
		tmp->setNext(new_node);
		tmp = tmp->next();
		srcTmp = srcTmp->next();
	}
	this->add_before_beginning();
	this->add_past_the_end(tmp);
}

template < typename T, class A >
void		ft::list<T,A>::add_before_beginning(void)
{
	Node * before_beginning = new Node(value_type(), 0, 0);
	before_beginning->setNext(this->_first);
	this->_first->setPrev(before_beginning);
}

template < typename T, class A >
void									ft::list<T,A>::add_past_the_end(Node * last_element)
{
	Node * past_the_end = new Node(value_type(), 0, 0);
	past_the_end->setPrev(last_element);
	last_element->setNext(past_the_end);
}

template < typename T, class A >
ft::Node<T> *							ft::list<T,A>::iterator_node(iterator position)
{
	if (this->empty())
		return (0);
	iterator offset_it(this->_first);
	int offset(0);
	while (offset_it++ != position)
		offset++;
	
	Node * pos_node = this->_first;
	for (int i = 0; i < offset; i++)
		pos_node = pos_node->next();
	return (pos_node);
}

template < typename T, class A >
void									ft::list<T,A>::extract_from_list(list & x, Node * src_first, Node * src_last)
{
	if (x.empty())
	{
		delete src_first->prev();
		delete src_last->next();
		x._first = 0;
	}
	else
	{
		src_first->prev()->setNext(src_last->next());
		src_last->next()->setPrev(src_first->prev());
	}
}

template < typename T, class A >
void									ft::list<T,A>::integrate_elements(list & x, Node * pos_node, Node * src_first, Node * src_last)
{
	if (!x.empty())
	{
		pos_node->prev()->setNext(src_first);
		src_first->setPrev(pos_node->prev());
		pos_node->setPrev(src_last);
		src_last->setNext(pos_node);
	}
	else
	{
		x._first = src_first;
		x.add_before_beginning();
		x.add_past_the_end(src_last);
	}
}

template < typename T, class A >
void									ft::list<T,A>::swap(Node * x, Node * y)
{
	value_type tmp = x->data();
	x->data() = y->data();
	y->data() = tmp;
}


/*
** ------ CONSTRUCTORS AND DESTRUCTORS ------
*/
template < typename T, class A >
ft::list<T,A>::list(): _first(0), _size(0)
{}

template < typename T, class A >
ft::list<T,A>::list(size_type n, value_type const & val)
{
	this->_size = n;
	if (this->empty())
	{
		this->_first = 0;
		return ;
	}

	this->_first = new Node(val, 0, 0);
	Node * tmp = this->_first;
	for (size_type i = 1; i < n; i++)
	{
		Node * new_node = new Node(val, 0, 0);
		new_node->setPrev(tmp);
		tmp->setNext(new_node);
		tmp = tmp->next();
	}
	this->add_before_beginning();
	this->add_past_the_end(tmp);
}

template < typename T, class A >
ft::list<T,A>::list(InputIterator first, InputIterator last)
{
	size_type range(0);
	for (InputIterator tmp_it = first; tmp_it != last; tmp_it++)
		range++;

	this->_size = range;
	if (this->empty())
	{
		this->_first = 0;
		return ;
	}

	this->_first = new Node(*first, 0, 0);
	Node * tmp = this->_first;
	for (size_type i = 1; i < range; i++)
	{
		Node * new_node = new Node(*(++first), tmp, 0);
		tmp->setNext(new_node);
		tmp = tmp->next();
	}
	this->add_before_beginning();
	this->add_past_the_end(tmp);
}

template < typename T, class A >
ft::list<T,A>::list(list const & src)
{ this->copy_from_source(src); }

template < typename T, class A >
ft::list<T,A>::~list()
{ this->free_list(); }


/*
** ------ OPERATOR OVERLOADS ------
*/
template < typename T, class A >
ft::list<T,A> &					ft::list<T,A>::operator=(list const & rhs)
{
	this->free_list();
	this->copy_from_source(rhs);
	return (*this);
}


/*
** ------ ITERATOR FUNCTIONS ------
*/
template < typename T, class A >
typename ft::list<T,A>::iterator					ft::list<T,A>::begin(void)
{
	iterator it(this->_first);
	return (it);
}

template < typename T, class A >
typename ft::list<T,A>::const_iterator				ft::list<T,A>::begin(void) const
{
	const_iterator it(this->_first);
	return (it);
}

template < typename T, class A >
typename ft::list<T,A>::iterator					ft::list<T,A>::end(void)
{
	Node * tmp = this->_first;
	while (tmp->next())
		tmp = tmp->next();
	iterator it(tmp);
	return (it);
}

template < typename T, class A >
typename ft::list<T,A>::const_iterator				ft::list<T,A>::end(void) const
{
	Node * tmp = this->_first;
	while (tmp->next())
		tmp = tmp->next();
	const_iterator it(tmp);
	return (it);
}

template < typename T, class A >
typename ft::list<T,A>::reverse_iterator			ft::list<T,A>::rbegin(void)
{ reverse_iterator rev_it(this->end()); return (rev_it); }

template < typename T, class A >
typename ft::list<T,A>::const_reverse_iterator		ft::list<T,A>::rbegin(void) const
{ const_reverse_iterator rev_it(this->end()); return (rev_it); }

template < typename T, class A >
typename ft::list<T,A>::reverse_iterator			ft::list<T,A>::rend(void)
{ reverse_iterator rev_it(this->begin()); return (rev_it); }

template < typename T, class A >
typename ft::list<T,A>::const_reverse_iterator		ft::list<T,A>::rend(void) const
{ const_reverse_iterator rev_it(this->begin()); return (rev_it); }


/*
** ------ CAPACITY FUNCTIONS ------
*/
template < typename T, class A >
typename ft::list<T,A>::size_type		ft::list<T,A>::size(void) const
{ return (this->_size); }

template < typename T, class A >
bool									ft::list<T,A>::empty(void) const
{ return (this->_size <= 0); }

template < typename T, class A >
typename ft::list<T,A>::size_type		ft::list<T,A>::max_size(void) const
{ return (std::numeric_limits<size_type>::max() / sizeof(Node)); }

/*
** ------ ELEMENT ACCESS FUNCTIONS ------
*/
template < typename T, class A >
typename ft::list<T,A>::reference			ft::list<T,A>::front(void)
{ return (this->_first->data()); }

template < typename T, class A >
typename ft::list<T,A>::const_reference		ft::list<T,A>::front(void) const
{ return (this->_first->data()); }

template < typename T, class A >
typename ft::list<T,A>::reference			ft::list<T,A>::back(void)
{
	Node * last = this->_first;
	while (last->next()->next())
		last = last->next();
	return (last->data());
}

template < typename T, class A >
typename ft::list<T,A>::const_reference		ft::list<T,A>::back(void) const
{
	Node * last = this->_first;
	while (last->next()->next())
		last = last->next();
	return (last->data());
}


/*
** ------ MODIFYER FUNCTIONS ------
*/
template < typename T, class A >
void					ft::list<T,A>::assign(InputIterator first, InputIterator last)
{
	this->free_list();
	size_type range(0);
	for (InputIterator tmp_it = first; tmp_it != last; tmp_it++)
		range++;

	this->_size = range;
	if (this->empty())
	{
		this->_first = 0;
		return ;
	}

	this->_first = new Node(*first, 0, 0);
	Node * tmp = this->_first;
	for (size_type i = 1; i < range; i++)
	{
		Node * new_node = new Node(*(++first), tmp, 0);
		tmp->setNext(new_node);
		tmp = tmp->next();
	}
	this->add_before_beginning();
	this->add_past_the_end(tmp);
}

template < typename T, class A >
void					ft::list<T,A>::assign(size_type n, value_type const & val)
{
	this->free_list();
	this->_size = n;
	if (this->empty())
	{
		this->_first = 0;
		return ;
	}

	this->_first = new Node(val, 0, 0);
	Node * tmp = this->_first;
	for (size_type i = 1; i < n; i++)
	{
		Node * new_node = new Node(val, 0, 0);
		new_node->setPrev(tmp);
		tmp->setNext(new_node);
		tmp = tmp->next();
	}
	this->add_before_beginning();
	this->add_past_the_end(tmp);
}

template < typename T, class A >
void					ft::list<T,A>::push_front(value_type const & val)
{
	Node * new_node = new Node(val, 0, 0);
	if (this->empty())
	{
		this->_first = new_node;
		this->add_before_beginning();
		this->add_past_the_end(this->_first);
	}
	else
	{
		new_node->setPrev(this->_first->prev());
		new_node->setNext(this->_first);
		this->_first->prev()->setNext(new_node);
		this->_first->setPrev(new_node);
		this->_first = new_node;
	}
	this->_size++;
}

template < typename T, class A >
void					ft::list<T,A>::pop_front(void)
{
	if (this->empty())
		return ;
	else if (this->_size == 1)
	{
		free_list();
		this->_size--;
	}
	else
	{
		Node * tmp = this->_first->next();
		this->_first->next()->setPrev(this->_first->prev());
		this->_first->prev()->setNext(this->_first->next());
		delete (this->_first);
		this->_first = tmp;
		this->_size--;
	}
}


template < typename T, class A >
void					ft::list<T,A>::push_back(value_type const & val)
{
	Node * new_node = new Node(val, 0, 0);
	if (this->empty())
	{
		this->_first = new_node;
		this->add_before_beginning();
		this->add_past_the_end(this->_first);
	}
	else
	{
		Node * last = this->_first;
		while (last->next()->next())
			last = last->next();
		new_node->setNext(last->next());
		new_node->setPrev(last);
		last->next()->setPrev(new_node);
		last->setNext(new_node);
	}
	this->_size++;
}

template < typename T, class A >
void					ft::list<T,A>::pop_back(void)
{
	if (this->empty())
		return ;
	else if (this->_size == 1)
	{
		free_list();
		this->_size--;
	}
	else
	{
		Node * last = this->_first;
		while (last->next()->next())
			last = last->next();
		last->prev()->setNext(last->next());
		last->next()->setPrev(last->prev());
		delete (last);
		this->_size--;
	}
}

template < typename T, class A >
typename ft::list<T,A>::iterator		ft::list<T,A>::insert(iterator position, value_type const & val)
{
	if (this->empty())
	{
		this->assign(1, val);
		return (this->_first);
	}
	
	Node * pos_node = iterator_node(position);
	Node * new_node = new Node(val, 0, 0);
	new_node->setPrev(pos_node->prev());
	new_node->setNext(pos_node);
	pos_node->prev()->setNext(new_node);
	pos_node->setPrev(new_node);
	if (position == this->begin())
		this->_first = new_node;
	this->_size++;
	return (new_node);
}

template < typename T, class A >
void									ft::list<T,A>::insert(iterator position, size_type n, value_type const & val)
{
	if (this->empty())
		this->assign(n, val);
	
	Node * pos_node = iterator_node(position);
	for (size_type i = 0; i < n; i++)
	{
		Node * new_node = new Node(val, 0, 0);
		new_node->setPrev(pos_node->prev());
		new_node->setNext(pos_node);
		pos_node->prev()->setNext(new_node);
		pos_node->setPrev(new_node);
		pos_node = pos_node->prev();
	}
	if (position == this->begin())
		this->_first = pos_node;
	this->_size += n;
}

template < typename T, class A >
void									ft::list<T,A>::insert(iterator position, InputIterator first, InputIterator last)
{
	if (this->empty())
		this->assign(first, last);
	
	size_type range(0);
	for (InputIterator tmp_it = first; tmp_it != last; tmp_it++)
		range++;
	
	Node * pos_node = iterator_node(position);
	for (size_type i = 0; i < range; i++)
	{
		Node * new_node = new Node(*(first), 0, 0);
		new_node->setPrev(pos_node->prev());
		new_node->setNext(pos_node);
		pos_node->prev()->setNext(new_node);
		pos_node->setPrev(new_node);
		pos_node = pos_node->prev();
		first++;
	}
	if (position == this->begin())
		this->_first = pos_node;
	this->_size += range;
}

template < typename T, class A >
typename ft::list<T,A>::iterator		ft::list<T,A>::erase(iterator position)
{
	if (this->_size == 1)
	{
		this->free_list();
		this->_size--;
		return (0);
	}
	
	Node * pos_node = iterator_node(position);
	Node * result = pos_node->next();
	pos_node->prev()->setNext(pos_node->next());
	pos_node->next()->setPrev(pos_node->prev());
	if (position == this->begin())
		this->_first = pos_node->next();
	delete (pos_node);
	this->_size--;
	return (result);
}

template < typename T, class A >
typename ft::list<T,A>::iterator		ft::list<T,A>::erase(iterator first, iterator last)
{
	size_type range(0);
	for (iterator tmp_it = first; tmp_it != last; tmp_it++)
		range++;
	
	if (this->_size <= range)
	{
		free_list();
		this->_size -= range;
		return (0);
	}

	Node * first_node = this->iterator_node(first);
	Node * last_node = this->iterator_node(last);
	first_node->prev()->setNext(last_node);
	last_node->setPrev(first_node->prev());

	if (first == this->begin())
		this->_first = last_node;

	for (size_type i = 0; i < range; i++)
	{
		Node * tmp = first_node->next();
		delete (first_node);
		first_node = tmp;
	}
	this->_size -= range;
	return (last_node);
}

template < typename T, class A >
void									ft::list<T,A>::swap(list & x)
{
	Node *	tmpFirst = this->_first;
	size_type	tmpSize = this->_size;

	this->_first = x._first;
	this->_size = x._size;

	x._first = tmpFirst;
	x._size = tmpSize;
}

template < typename T, class A >
void									ft::list<T,A>::resize(size_type n, value_type val)
{
	if (n < this->_size)
	{
		Node * tmp = this->_first;
		for (size_type i = 0; i < n; i++)
			tmp = tmp->next();
		this->erase(tmp, this->end());
	}
	else if (n > this->_size)
		this->insert(this->end(), n - this->_size, val);
}

template < typename T, class A >
void									ft::list<T,A>::clear(void)
{
	this->free_list();
	this->_size = 0;
}


/*
** ------ OPERATION FUNCTIONS ------
*/
template < typename T, class A >
void									ft::list<T,A>::splice(iterator position, list & x)
{
	if (x.empty())
		return ;
	size_type range = x._size;
	Node * pos_node = iterator_node(position);
	Node * src_first = x._first;
	Node * src_last = x.iterator_node(--x.end());

	x._size = 0;
	extract_from_list(x, src_first, src_last);

	if (position == this->begin())
		this->_first = src_first;

	integrate_elements(*this, pos_node, src_first, src_last);

	this->_size += range;
}

template < typename T, class A >
void									ft::list<T,A>::splice(iterator position, list & x, iterator i)
{
	if (x.empty())
		return ;

	Node * pos_node = iterator_node(position);
	Node * i_node = x.iterator_node(i);

	x._size--;
	extract_from_list(x, i_node, i_node);

	if (i == x.begin())
		x._first = i_node->next();
	if (!this->empty() && position == this->begin())
		this->_first = i_node;

	integrate_elements(*this, pos_node, i_node, i_node);
	
	this->_size++;
}

template < typename T, class A >
void									ft::list<T,A>::splice(iterator position, list & x, iterator first, iterator last)
{
	if (x.empty())
		return ;

	size_type range(0);
	for (iterator tmp_it = first; tmp_it != last; tmp_it++)
		range++;

	Node * pos_node = iterator_node(position);
	Node * src_first = x.iterator_node(first);
	Node * src_last = x.iterator_node(--last);

	x._size -= range;
	extract_from_list(x, src_first, src_last);

	if (first == x.begin())
		x._first = src_last->next();	
	if (!this->empty() && position == this->begin())
		this->_first = src_first;
	
	integrate_elements(*this, pos_node, src_first, src_last);

	this->_size += range;
}

template < typename T, class A >
void									ft::list<T,A>::remove(value_type const & val)
{
	if (this->empty())
		return ;
	Node * tmp = this->_first;
	while (!this->empty() && tmp && tmp->next())
	{
		Node * save = tmp->next();
		if (tmp->data() == val)
			erase(tmp);
		tmp = save;
	}
}

template < typename T, class A >
template < class Predicate >
void									ft::list<T,A>::remove_if(Predicate pred)
{
		if (this->empty())
		return ;
	Node * tmp = this->_first;
	while (!this->empty() && tmp && tmp->next())
	{
		Node * save = tmp->next();
		if (pred(tmp->data()))
			erase(tmp);
		tmp = save;
	}
}

template < typename T, class A >
void									ft::list<T,A>::unique(void)
{
	if (this->empty() || this->_size == 1)
		return ;
	Node * tmp = this->_first->next();
	while (tmp->next())
	{
		Node * save = tmp->next();
		if (tmp->data() == tmp->prev()->data())
			erase(tmp);
		tmp = save;
	}
}

template < typename T, class A >
template < class BinaryPredicate >
void									ft::list<T,A>::unique(BinaryPredicate binary_pred)
{
	if (this->empty() || this->_size == 1)
		return ;
	Node * tmp = this->_first->next();
	while (tmp->next())
	{
		Node * save = tmp->next();
		if (binary_pred(tmp->data(), tmp->prev()->data()))
			erase(tmp);
		tmp = save;
	}
}

template < typename T, class A >
void									ft::list<T,A>::sort(void)
{
	if (this->empty() || this->_size == 1)
		return ;
	int swapped(1);
	Node * ptr1;

	while (swapped)
	{
		swapped = 0;
		ptr1 = this->_first;
		while (ptr1->next()->next() != 0)
		{
			if (ptr1->data() > ptr1->next()->data())
			{
				swap(ptr1, ptr1->next());
				swapped = 1;
			}
			ptr1 = ptr1->next();
		}
	}
}

template < typename T, class A >
template < class Compare >
void									ft::list<T,A>::sort(Compare compare)
{
	if (this->empty() || this->_size == 1)
		return ;
	int swapped(1);
	Node * ptr1;

	while (swapped)
	{
		swapped = 0;
		ptr1 = this->_first;
		while (ptr1->next()->next() != 0)
		{
			if (compare(ptr1->next()->data(), ptr1->data()))
			{
				swap(ptr1, ptr1->next());
				swapped = 1;
			}
			ptr1 = ptr1->next();
		}
	}
}

template < typename T, class A >
void									ft::list<T,A>::reverse(void)
{
	if (this->empty() || this->_size <= 1)
		return ;
	size_type i		= 0;
	Node * first	= this->_first;
	Node * last		= iterator_node(--this->end());

	while (i < this->_size / 2)
	{
		swap(first, last);
		first = first->next();
		last = last->prev();
		i++;
	}
}

template < typename T, class A >
void									ft::list<T,A>::merge(list & x)
{
	Node * dest_pos;
	Node * src_pos	= x._first;

	while (!x.empty())
	{
		
		dest_pos = this->_first;
		while (dest_pos->next() && dest_pos->data() < src_pos->data())
			dest_pos = dest_pos->next();
		this->splice(dest_pos, x, src_pos);
		src_pos = x._first;
	}
}

template < typename T, class A >
template < class Compare >
void									ft::list<T,A>::merge(list & x, Compare comp)
{
	Node * dest_pos;
	Node * src_pos	= x._first;

	while (!x.empty())
	{
		dest_pos = this->iterator_node(--this->end());
		while (dest_pos->prev() && comp(src_pos->data(), dest_pos->prev()->data()))
			dest_pos = dest_pos->prev();
		this->splice(dest_pos, x, src_pos);
		src_pos = x._first;
	}
}

























/* PREVIOUS VERSIONS OF SPLICE FUNCTIONS


template < typename T, class A >
void									ft::list<T,A>::splice(iterator position, list & x)
{
	if (x.empty())
		return ;

	Node * pos_node = iterator_node(position);
	Node * src_first = x._first;
	Node * src_last = x.iterator_node(--x.end());

	delete src_first->prev();
	delete src_last->next();

	if (!this->empty())
	{
		pos_node->prev()->setNext(src_first);
		src_first->setPrev(pos_node->prev());
		pos_node->setPrev(src_last);
		src_last->setNext(pos_node);
	}
	else
	{
		this->_first = src_first;
		this->add_before_beginning();
		this->add_past_the_end(src_last);
	}

	if (position == this->begin())
		this->_first = src_first;

	this->_size += x._size;
	x._size = 0;
	x._first = 0;
}

template < typename T, class A >
void									ft::list<T,A>::splice(iterator position, list & x, iterator i)
{
	if (x.empty())
		return ;

	Node * pos_node = iterator_node(position);
	Node * i_node = x.iterator_node(i);

	x._size--;
	if (x.empty())
	{
		delete i_node->prev();
		delete i_node->next();
		x._first = 0;
	}
	else
	{
		i_node->prev()->setNext(i_node->next());
		i_node->next()->setPrev(i_node->prev());
	}

	if (i == x.begin())
		x._first = i_node->next();
	if (!this->empty() && position == this->begin())
		this->_first = i_node;

	if (!this->empty())
	{
		pos_node->prev()->setNext(i_node);
		i_node->setPrev(pos_node->prev());
		pos_node->setPrev(i_node);
		i_node->setNext(pos_node);
	}
	else
	{
		this->_first = i_node;
		this->add_before_beginning();
		this->add_past_the_end(i_node);
	}
	this->_size++;
}

template < typename T, class A >
void									ft::list<T,A>::splice(iterator position, list & x, iterator first, iterator last)
{
	if (x.empty())
		return ;

	size_type range(0);
	for (iterator tmp_it = first; tmp_it != last; tmp_it++)
		range++;

	Node * pos_node = iterator_node(position);
	Node * src_first = x.iterator_node(first);
	Node * src_last = x.iterator_node(--last);

	x._size -= range;
	if (x.empty())
	{
		delete src_first->prev();
		delete src_last->next();
		x._first = 0;
	}
	else
	{
		src_first->prev()->setNext(src_last->next());
		src_last->next()->setPrev(src_first->prev());
	}

	if (first == x.begin())
		x._first = src_last->next();
	if (!this->empty() && position == this->begin())
		this->_first = src_first;

	if (!this->empty())
	{
		pos_node->prev()->setNext(src_first);
		src_first->setPrev(pos_node->prev());
		pos_node->setPrev(src_last);
		src_last->setNext(pos_node);
	}
	else
	{
		this->_first = src_first;
		this->add_before_beginning();
		this->add_past_the_end(src_last);
	}
	this->_size += range;

}



*/
