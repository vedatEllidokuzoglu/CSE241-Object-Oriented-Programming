#include "GTUSet.h"

namespace HW6_161044098{
	template<class T>
	GTUSet<T>::GTUSet(){}
	
	template<class T>
	bool GTUSet<T>::empty() const{
		if(this->len==0)	return true;
		else return false;
	}

	template<class T>
	int GTUSet<T>::size() const{
		return this->len;
	}
	
	template<class T>
	int GTUSet<T>::max_size() const{
		return MAXSIZE;
	}

	template<class T>
	void GTUSet<T>::insert(const T & element) throw (exception){
		shared_ptr<Node<T> > current = this->head;
		while(current){
			if (current->getData()==element)	throw invalid_argument("Element is exist in set");
			current = current->getNext();
		}
		shared_ptr<Node<T> > newNode(make_shared<Node<T> >(element));
		if(this->head==NULL){
			this->head=newNode;
		}
		else if(this->head->getData() >= element){
			newNode->setNext(this->head);
			(newNode->getNext())->setPrev(newNode);
			this->head=newNode;
		}
		else{
			current=this->head;
			while(current->getNext()!=NULL && (current->getNext())->getData()<element)
				current = current->getNext();
				newNode->setNext(current->getNext());
			if (current->getNext() != NULL)	(newNode->getNext())->setPrev(newNode);
			current->setNext(newNode);
			newNode->setPrev(current); 
		}
		this->len++;
	}

	template<class T>
	void GTUSet<T>::erase(const T & element){	
		bool flag=false;
		if(this->len>0){
			shared_ptr<Node<T> > current=this->head;
			while (current){
				if(current->getData()==element){
					flag = true;
					break;
				}
				current=current->getNext();
			}
			if(flag){
				if(this->head == current)	this->head=(this->head)->getNext();
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
	void GTUSet<T>::clear() noexcept{
		this->head = NULL;
		this->len = 0;
	}
}