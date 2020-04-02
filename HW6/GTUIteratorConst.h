#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include "Node.h"

namespace HW6_161044098{

	template<class T>
	class GTUIteratorConst
	{
	public:
		GTUIteratorConst(){current=NULL;}
		GTUIteratorConst(const shared_ptr<Node<T> > & initial){current=initial;}

		const T& operator*() const{return current->getData();}

		GTUIteratorConst& operator ++()
		{
			current = current->getNext();
			return *this;
		}
		GTUIteratorConst operator ++(int unusable)
		{
			GTUIteratorConst start(current);
			current = current->getNext();
			return start;
		}
		GTUIteratorConst& operator --()
		{
			current = current->getPrev();
			return *this;
		}
		GTUIteratorConst operator --(int unusable)
		{	
			
			GTUIteratorConst start(current);
			current = current->getPrev();
			return start;
		}
		bool operator == (const GTUIteratorConst & rightSide) const
		{ return (current == rightSide.current); }

		bool operator != (const GTUIteratorConst & rightSide) const
		{ return (current != rightSide.current); }

		GTUIteratorConst & operator=(const GTUIteratorConst & rightSide) 
		{
			current = rightSide.current;
			return *this;
		}
		const T* operator->()
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