#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
using namespace std;

namespace HW6_161044098{

	template<class T>
	class Node{
	public:	
		Node(){
			next=NULL;
			prev=NULL;
		}
		Node(const T & temp_data){
			data=temp_data;
			next=NULL;
			prev=NULL;
		}
		Node(const T& temp_data, shared_ptr<Node<T> >  temp_prev, shared_ptr<Node<T> >  temp_next){
			data=temp_data;
			next=temp_prev;
			prev=temp_next;
		}
		shared_ptr<Node<T> > getNext() const{return next;}
		shared_ptr<Node<T> > getPrev() const{return prev;}
		void setData(const T & temp_data) {data=temp_data;}
		void setNext(shared_ptr<Node<T> >  temp_next) {next=temp_next;}
		void setPrev(shared_ptr<Node<T> >  temp_prev) {prev=temp_prev;}
		const T& getData() const {return data;}
	private:
		shared_ptr<Node<T> >  next;
		shared_ptr<Node<T> >  prev;
		T data;
	};
}
#endif