/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:51:01 by user42            #+#    #+#             */
/*   Updated: 2021/05/07 15:48:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include "Node.hpp"
#include "../Iterators/allocator.hpp"
#include "../Iterators/iterator_tags.hpp"
#include "../Iterators/reverse_iterator.hpp"

#include <iostream>
#include <math.h>
#include <limits>

namespace ft
{

template < typename T, class A = ft::allocator<T> >
class	list
{
	public:
		/* TYPEDEFs FOR CONTAINER CHARACTERISTICS */
		typedef ft::Node<T>											Node;
		typedef A													allocator_type;
		typedef typename A::value_type								value_type;
		typedef typename A::reference								reference;
		typedef typename A::const_reference							const_reference;
		typedef typename A::difference_type							difference_type;
		typedef typename A::size_type								size_type;


		/* ITERATORS AND ITERATOR TYPEDEFs */
		#include "../Iterators/bidirectional/iterator.hpp"
		#include "../Iterators/bidirectional/const_iterator.hpp"
		typedef				ft::reverse_iterator< iterator >		reverse_iterator;
		typedef				ft::reverse_iterator< const_iterator >	const_reverse_iterator;
		typedef typename	ft::list< value_type >::iterator		InputIterator;

		/* CONSTRUCTORS / DESTRUCTOR */
		list<T,A>();
		list<T,A>(size_type n, value_type const & val = value_type());
		list<T,A>(InputIterator first, InputIterator last);
		list<T,A>(list const & src);
		~list<T,A>();

		/* OPERATOR OVERLOADS */
		list &					operator=(list const & rhs);

		/* ITERATOR FUNCTIONS */
		iterator				begin(void);
		const_iterator			begin(void)					const;
		iterator				end(void);
		const_iterator			end(void)					const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void)				const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void)					const;

		/* CAPACITY FUNCTIONS */
		size_type				size(void)					const;
		bool					empty(void)					const;
		size_type				max_size(void)				const;

		/* ELEMENT ACCESS FUNCTIONS */
		reference				front(void);
		const_reference			front(void)					const;
		reference				back(void);
		const_reference			back(void)					const;

		/* MODIFYER FUNCTIONS */
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, value_type const & val);
		void					push_front(value_type const & val);
		void					pop_front(void);
		void					push_back(value_type const & val);
		void					pop_back(void);
		iterator				insert(iterator position, value_type const & val);
		void					insert(iterator position, size_type n, value_type const & val);
		void					insert(iterator position, InputIterator first, InputIterator last);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(list & x);
		void					resize(size_type n, value_type val = value_type());
		void					clear(void);

		/* OPERATION FUNCTIONS */
		void					splice(iterator position, list & x);
		void					splice(iterator position, list & x, iterator i);
		void					splice(iterator position, list & x, iterator first, iterator last);

	private:
		/* CONTAINER ATTRIBUTES */
		Node *		_first;
		size_type	_size;

		/* SOME PRIVATE HELPER FUNCTIONS */
		void		free_list(void);
		void		copy_from_source(list const & src);
		void		add_before_beginning(void);
		void		add_past_the_end(Node * last_element);
		Node *		iterator_node(iterator position);

};

}

#include "list.ipp"

#endif

/*
 -- LIST TODO :

 ---> Member functions
 	---> Constructors
	 	> Default							OK
		> Fill								OK
		> Range								OK
		> Copy								OK
	
	---> Operators
		> Operator=							OK

	---> Iterators
		> begin()							OK
		> end()								OK
		> rbegin()							OK
		> rend()							OK
	
	---> Capacity
		> size								OK
		> max_size							OK
		> empty								OK
	
	---> Element access
		> front								OK
		> back								OK
	
	---> Modifyers
		> assign							OK
		> push_front						OK
		> pop_front							OK
		> push_back							OK
		> pop_back							OK
		> insert							OK
		> erase								OK
		> swap								OK
		> resize							OK
		> clear								OK

	---> Operations
		> splice
		> remove
		> remove_if
		> unique
		> merge
		> sort
		> reverse

 ---> Non-member functions overload
	---> Relational operators
		> Operator ==					
		> Operator !=					
		> Operator >					
		> Operator <					
		> Operator >=					
		> Operator <=					
	
	---> Other
		> swap							


=== REMARQUES ===

*/
