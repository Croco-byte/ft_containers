/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:14:11 by user42            #+#    #+#             */
/*   Updated: 2021/05/04 16:10:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../Iterators/allocator.hpp"
#include "../Iterators/iterator_tags.hpp"
#include "../Iterators/reverse_iterator.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>

namespace ft
{

template < typename T, class A = ft::allocator<T> >
class	vector
{
	public:
		/* TYPEDEFs FOR CONTAINER CHARACTERISTICS */
		typedef A												allocator_type;
		typedef typename A::value_type							value_type;
		typedef typename A::reference							reference;
		typedef typename A::const_reference						const_reference;
		typedef typename A::difference_type						difference_type;
		typedef typename A::size_type							size_type;

		/* ITERATORS AND ITERATOR TYPEDEFs */
		#include "../Iterators/random_access/iterator.hpp"
		#include "../Iterators/random_access/const_iterator.hpp"
		typedef ft::reverse_iterator< iterator >				reverse_iterator;
		typedef ft::reverse_iterator< const_iterator >			const_reverse_iterator;
		typedef typename ft::vector< value_type >::iterator		InputIterator;

		/* CONSTRUCTORS / DESTRUCTORS */
		vector<T, A>();
		vector<T, A>(size_type n, value_type const & val = value_type());
		vector<T, A>(vector<T> const & src);
		vector<T, A>(InputIterator first, InputIterator last);
		~vector<T, A>();

		/* OPERATOR OVERLOADS */
		vector<T,A> &			operator=(vector<T,A> const & rhs);
		value_type &			operator[](size_type index)							const;

		/* ITERATOR FUNCTIONS */
		iterator				begin(void);
		const_iterator			begin(void)											const;
		iterator				end(void);
		const_iterator			end(void)											const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void)										const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void)											const;

		/* CAPACITY FUNCTIONS */
		size_type				size(void) 											const;
		size_type				max_size(void)										const;
		void					resize(size_type n, value_type val = value_type());
		size_type				capacity(void) 										const;
		bool					empty(void)											const;
		void					reserve(size_type n);

		/* ELEMENT ACCESS FUNCTIONS */
		reference				at(size_type n);
		const_reference			at(size_type n)										const;
		reference				front(void);
		const_reference			front(void)											const;
		reference				back(void);
		const_reference			back(void)											const;

		/* MODIFYERS FUNCTIONS */
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, value_type const & val);
		void					push_back(value_type const & val);
		void					pop_back(void);
		iterator				insert(iterator position, value_type const & val);
		void					insert(iterator position, size_type n, value_type const & val);
		void					insert(iterator position, InputIterator first, InputIterator last);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(vector & x);
		void					clear(void);

		/* DECLARATION OF FRIEND FUNCTIONS (NON-MEMBER FUNCTIONS OVERLOADS) */
		template < typename T2, class A2 >
		friend bool				operator==(vector<T2,A2> const & lhs, vector<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator!=(vector<T2,A2> const & lhs, vector<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator<(vector<T2,A2> const & lhs, vector<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator>(vector<T2,A2> const & lhs, vector<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator<=(vector<T2,A2> const & lhs, vector<T2,A2> const & rhs);
		template < typename T2, class A2 >
		friend bool				operator>=(vector<T2,A2> const & lhs, vector<T2,A2> const & rhs);

	private:
		value_type *	_array;
		size_type		_size;
		size_type		_max_size;
		size_type		_capacity;
};

#include "non_member_overloads.ipp"

}

#include "vector.ipp"

#endif



/*
 -- VECTOR TODO :

 ---> Member functions
 	---> Constructors
	 	> Default							OK
		> Fill								OK
		> Range								OK
		> Copy								OK
	
	---> Operators
		> Operator[]						OK
		> Operator=							OK

	---> Iterators
		> begin()							OK
		> end()								OK
		> rbegin()							OK
		> rend()							OK
	
	---> Capacity
		> size								OK
		> max_size							OK
		> resize							OK
		> capacity							OK
		> empty								OK
		> reserve							OK
	
	---> Element access
		> at								OK
		> front								OK
		> back								OK
	
	---> Modifyers
		> assign							OK
		> push_back							OK
		> pop_back							OK
		> insert							OK
		> erase								OK
		> swap								OK
		> clear								OK

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
 --->	Les fonctions resize et push_back n'augmentent pas la capacité du vecteur de la même façon dans l'implémentation de la STL.
		Dans mon implémentation, pour le moment, elles l'augmentent de manière identique car resize repose sur push_back.

 --->	L'opérateur d'accès [] ne check pas les "out-of-bounds" et peut crash ; la fonction at() check et throw une exception, conformément au comportement
		de la STL.

 --->	Sur Cplusplus, ils affirment que pop_back et resize (lorsque la taille est réduite) accèdent aux éléments à supprimer, et les détruisent.
		De mon côté, je ne fais que modifier la variable "_size", mais sans différence réelle dans les résultats. Je ne comprends d'ailleurs pas
		pourquoi et en quoi ces fonctions "accèdent" aux éléments à supprimer : ils sont toujours présents et inchangés en mémoire après leur supposée "destruction".

 --->	L'implémentation de "insert" comporte une petite nuance. En effet, lorsqu'une réallocation de mémoire est nécessaire pour le vecteur (la nouvelle
 		taille est supérieure à la capacité actuelle du vector), les itérateurs reçus en argument de la fonction sont invalidés (ils pointent sur l'ancien
		tableau, qui a été free par la fonction reserve).
		On résoud ça en récupérant l'offset de l'itérateur de position par rapport au début du tableau originel (avant réallocation), et en construisant un
		nouvel itérateur à partir de cet offset, sur le nouveau tableau.
		Dans le cas de la fonction "insert" avec une range d'itérateurs (first ---> last), il est possible que ces itérateurs pointent sur le vector actuel,
		et qu'ils soient donc également invalidés en cas de réallocation. C'est pourquoi on met simplement l'ensemble des valeurs contenus dans la range
		du tableau pointé par les itérateurs avant la potentielle réallocation, et qu'on se sert ensuite de ce tableau de valeurs "sauvegardées".

*/
