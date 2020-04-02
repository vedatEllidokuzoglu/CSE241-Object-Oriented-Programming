#ifndef GTUITERATOR_H
#define GTUITERATOR_H

#include "Node.h"

namespace HW6_161044098{

	template<class T>
	class GTUIterator
	{
	public:
		GTUIterator(){current=NULL;}
		GTUIterator(const shared_ptr<Node<T> > & initial){current=initial;}

		const T& operator*() const{return current->getData();}

		GTUIterator& operator ++(){
			current=current->getNext();
			return *this;
		}
		GTUIterator operator ++(int unusable){
			GTUIterator start(current);
			current=current->getNext();
			return start;
		}
		GTUIterator& operator --(){
			current=current->getPrev();
			return *this;
		}
		GTUIterator operator --(int unusable){	
			
			GTUIterator start(current);
			current = current->getPrev();
			return start;
		}
		bool operator == (const GTUIterator & rightSide) const
		{ return (current == rightSide.current); }

		bool operator != (const GTUIterator & rightSide) const
		{ return (current != rightSide.current); }

		GTUIterator & operator=(const GTUIterator & rightSide) 
		{
			current = rightSide.current;
			return *this;
		}
		T* operator->()
		{
			T* temp;
			temp = &(*current);
			return temp;
		}
	private:
		shared_ptr<Node<T> > current;
	};
}
#endif