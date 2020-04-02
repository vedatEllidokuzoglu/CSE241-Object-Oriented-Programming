#include "GTUVector.h"


namespace HW6_161044098{
	template<class T>
	GTUVector<T>::GTUVector(){}

	template<class T>
	bool GTUVector<T>::empty() const{
		if(this->len==0)	return true;
		else	return false;
	}

	template<class T>
	int GTUVector<T>::size() const{
		return this->len;
	}

	template<class T>
	int GTUVector<T>::max_size() const{
		return MAXSIZE;
	}

	template<class T>
	void GTUVector<T>::insert(const T & element) throw (exception){
		shared_ptr<Node<T> > current = this->head;
		while(current){
			if(current->getData()==element)	throw invalid_argument("Element is exist in vector");
			current=current->getNext();
		}
		shared_ptr<Node<T> > newNode(make_shared<Node<T> >(element));
		if(this->head==NULL){
			this->head=newNode;
		}
		else if(this->head->getData()>=element){
			newNode->setNext(this->head);
			(newNode->getNext())->setPrev(newNode);
			this->head=newNode;
		}
		else{
			current=this->head;
			while(current->getNext()!=NULL && (current->getNext())->getData()<element){
				current = current->getNext();
			}
			newNode->setNext(current->getNext());
			if(current->getNext()!=NULL)	(newNode->getNext())->setPrev(newNode);
			current->setNext(newNode);
			newNode->setPrev(current); 
		}
		this->len++;
	}

	template<class T>
	void GTUVector<T>::erase(const T & element){	
		if(this->len>0){
			shared_ptr<Node<T> > current = this->head;
			bool flag=false;
			while(current){
				if(current->getData()==element){
					flag = true;
					break;
				}
				current = current->getNext();
			}
			if(flag){
				if(this->head==current)	this->head=(this->head)->getNext();
				else{
					shared_ptr<Node<T> > tempprev(make_shared<Node<T> >());	
					shared_ptr<Node<T> > tempnext(make_shared<Node<T> >());
					tempprev=current->getPrev();
					tempnext=current->getNext();
					tempprev->setNext(tempnext);
					if(tempnext!=NULL)	tempnext->setPrev(tempprev);
				}
			}
			(this->len)--;
		}
	}

	template<class T>
	void GTUVector<T>::clear() noexcept{
		this->head = NULL;
		this->len = 0;
	}

	template<class T>
	T GTUVector<T>::operator [](int index) const {
		int i=0;
		shared_ptr<Node<T> > current = this->head;
		while(i<index){
			current=current->getNext();
			i++;
		}
        return current->getData();
    }
}