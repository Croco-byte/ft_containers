/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:14:11 by user42            #+#    #+#             */
/*   Updated: 2021/05/06 12:20:20 by user42           ###   ########.fr       */
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
#include <math.h>


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

		/* CONSTRUCTORS / DESTRUCTOR */
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
 --->	Les fonctions resize et push_back n'augmentent pas la capacit?? du vecteur de la m??me fa??on dans l'impl??mentation de la STL.
		Dans mon impl??mentation, pour le moment, elles l'augmentent de mani??re identique car resize repose sur push_back.

 --->	L'op??rateur d'acc??s [] ne check pas les "out-of-bounds" et peut crash ; la fonction at() check et throw une exception, conform??ment au comportement
		de la STL.

 --->	Sur Cplusplus, ils affirment que pop_back et resize (lorsque la taille est r??duite) acc??dent aux ??l??ments ?? supprimer, et les d??truisent.
		De mon c??t??, je ne fais que modifier la variable "_size", mais sans diff??rence r??elle dans les r??sultats. Je ne comprends d'ailleurs pas
		pourquoi et en quoi ces fonctions "acc??dent" aux ??l??ments ?? supprimer : ils sont toujours pr??sents et inchang??s en m??moire apr??s leur suppos??e "destruction".

 --->	L'impl??mentation de "insert" comporte une petite nuance. En effet, lorsqu'une r??allocation de m??moire est n??cessaire pour le vecteur (la nouvelle
 		taille est sup??rieure ?? la capacit?? actuelle du vector), les it??rateurs re??us en argument de la fonction sont invalid??s (ils pointent sur l'ancien
		tableau, qui a ??t?? free par la fonction reserve).
		On r??soud ??a en r??cup??rant l'offset de l'it??rateur de position par rapport au d??but du tableau originel (avant r??allocation), et en construisant un
		nouvel it??rateur ?? partir de cet offset, sur le nouveau tableau.
		Dans le cas de la fonction "insert" avec une range d'it??rateurs (first ---> last), il est possible que ces it??rateurs pointent sur le vector actuel,
		et qu'ils soient donc ??galement invalid??s en cas de r??allocation. C'est pourquoi on met simplement l'ensemble des valeurs contenus dans la range
		du tableau point?? par les it??rateurs avant la potentielle r??allocation, et qu'on se sert ensuite de ce tableau de valeurs "sauvegard??es".

*/
