#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H

#include "GTUIterator.h"
#include "GTUIteratorConst.h"
namespace HW6_161044098{
	#define MAXSIZE 100
	template<class T>
	class GTUContainer{
		public:
			typedef GTUIterator<T> Iter;
			GTUContainer(){len=0;} 
			virtual bool empty() const=0;
			virtual int size() const=0;
			virtual int max_size() const=0;
			virtual void erase(const T & element)=0;
			virtual void insert(const T & element) throw (exception)=0;
			virtual void clear() noexcept=0;
			virtual Iter begin() const noexcept=0;
			virtual Iter end() const noexcept=0;
		protected:
			shared_ptr<Node<T> > head;
			int len;	
	};
}

#endif