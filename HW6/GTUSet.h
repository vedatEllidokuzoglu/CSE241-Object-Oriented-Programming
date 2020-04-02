#ifndef GTUSET_H
#define GTUSET_H
#include "GTUContainer.h"
namespace HW6_161044098{
	template<class T>
	class GTUSet : public GTUContainer<T>{
		public:	
			typedef GTUIterator<T> Iter;
			GTUSet();
			GTUSet(const shared_ptr<GTUSet<T> > x){}
			virtual bool empty() const;
			virtual int size() const; 
			virtual int max_size() const;
			virtual void insert(const T & element) throw (exception);
			virtual void erase(const T & element);
			virtual void clear() noexcept;
			virtual Iter begin() const noexcept{return Iter(this->head);}
			virtual Iter end() const noexcept{return Iter();}	
	};
}

#endif