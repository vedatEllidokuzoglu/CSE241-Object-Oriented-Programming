#ifndef GTUVECTOR_H
#define GTUVECTOR_H
#include "GTUContainer.h"
namespace HW6_161044098{

	template <class T>
	class GTUVector : public GTUContainer<T>{
		public:	
			typedef GTUIterator<T> Iterator;
			GTUVector();
			GTUVector(const shared_ptr<GTUVector<T> > x){}
			virtual bool empty() const;
			virtual int size() const; 
			virtual int max_size() const;
			virtual void insert(const T & element) throw (exception);
			virtual void erase(const T & element);
			virtual void clear() noexcept;
			virtual Iterator begin() const noexcept {return Iterator(this->head);}
			virtual Iterator end() const noexcept {return Iterator();}	
			T operator[] (int index)const;
	};
}

#endif