/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:51:01 by user42            #+#    #+#             */
/*   Updated: 2021/05/14 16:02:27 by user42           ###   ########.fr       */
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
		#include "../Iterators/bidirectional/list/iterator.hpp"
		#include "../Iterators/bidirectional/list/const_iterator.hpp"
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
		void					remove(value_type const & val);
		template < class Predicate >
		void					remove_if (Predicate pred);
		void					unique(void);
		template < class BinaryPredicate >
		void					unique(BinaryPredicate binary_pred);
		void					sort(void);
		template < class Compare >
		void					sort(Compare comp);
		void					reverse(void);
		void					merge(list & x);
		template < class Compare >
		void					merge(list & x, Compare comp);


		/* DECLARATION OF FRIEND FUNCTIONS (NON-MEMBER FUNCTIONS OVERLOADS) */
		template < typename T2, class A2 >
		friend bool				operator==(list<T2,A2> const & lhs, list<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator!=(list<T2,A2> const & lhs, list<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator<(list<T2,A2> const & lhs, list<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator>(list<T2,A2> const & lhs, list<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator<=(list<T2,A2> const & lhs, list<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator>=(list<T2,A2> const & lhs, list<T2,A2> const & rhs);


	private:
		/* CONTAINER ATTRIBUTES */
		Node *		_first;
		size_type	_size;

		/* SOME PRIVATE HELPER FUNCTIONS */
		void			free_list(void);
		void			copy_from_source(list const & src);
		void			add_before_beginning(void);
		void			add_past_the_end(Node * last_element);
		Node *			iterator_node(iterator position);
		static void		extract_from_list(list & x, Node * src_first, Node * src_last);
		static void		integrate_elements(list & x, Node * pos_node, Node * src_first, Node * src_last);
		static void		swap(Node * x, Node * y);

};

#include "non_member_overloads.ipp"

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
		> splice							OK
		> remove							OK
		> remove_if							OK
		> unique							OK
		> merge
		> sort								OK
		> reverse							OK

 ---> Non-member functions overload
	---> Relational operators
		> Operator ==						OK
		> Operator !=						OK
		> Operator >						OK
		> Operator <						OK
		> Operator >=						OK
		> Operator <=						OK
	
	---> Other
		> swap								OK


=== REMARQUES ===

 --> Dans le cadre de l'impl??mentation des listes, j'ai d??cid?? de proc??der de la mani??re suivante :
		- Lorsqu'une liste est vide (size == 0), elle n'a aucun ??l??ment. Le premier ??l??ment pointe sur 0, il n'y a pas de before_begining ni de past_the_end.
		- Lorsque j'ajoute le premier ??l??ment d'une liste, j'ajoute un ??l??ment before_beginning et past_the_end.
	Ce qui a pour cons??quence un crash du programme lorsqu'on tente de d??r??f??rencer un it??rateur sur une liste vide. La STL pr??cise en effet qu'il ne faut pas
	tenter de d??r??f??rencer ce genre d'it??rateurs, mais ne crash pas, car je pense qu'elle ajoute un ??l??ment before_beginning et past_the_end, m??me sur des listes
	vides. Le comportement reste quand m??me globalement coh??rent avec la STL.

	Mon impl??mentation a l'avantage de la simplicit?? "conceptuelle", mais rend l??g??rement plus complexe l'impl??mentation des fonctions qui modifient la taille d'une,
	ou de plusieurs listes (insert, push_back, splice...). En effet, il faut alors s'occuper des cas particuliers d'une op??ration qui vide enti??rement une liste, ou
	d'une op??ration qui ajoute un premier ??l??ment ?? une liste.

 --> L'impl??mentation des it??rateurs de listes ici rend impossible l'initialisation d'une liste ?? partir d'un array (comme c'est le cas dans la STL, et dans mon
 	 impl??mentation des vectors). En effet, les it??rateurs de listes reposent sur des Node *. Peut-??tre ?? am??liorer, et avoir un constructeur pour les it??rateurs de
	 listes qui repose sur des arrays (en les transformant en liste cha??n??e donc), pour coller au maximum ?? la STL.

*/
