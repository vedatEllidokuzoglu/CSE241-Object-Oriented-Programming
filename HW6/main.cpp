#include <iostream>
#include <string>
#include "GTUContainer.h"
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUVector.h"
#include "GTUVector.cpp"
#include "Node.h"
using namespace std;
using namespace HW6_161044098;

template<class Iter, class T>
Iter find(Iter first, Iter last, const T& element){
  while (first!=last) {
    if (*first==element) return first;
    ++first;
  }
  return last;
}

template<class InputIter, class UnaryPredicate>
InputIter find_if(InputIter first,InputIter last,UnaryPredicate pred){
	while(first!=last){
    	if(pred(*first)) return first;
   		first++;
  	}
  	return last;
}
template<class InputIter, class Function>
Function for_each(InputIter first, InputIter last, Function fn){
  while(first!=last){
    fn(*first);
    first++;
  }
  return fn;
}

bool first_letter_M(string instructor){ /*For find_if funtion testing*/
  return (instructor[0]=='M');
}

bool divisible_nine(int number){ /*For find_if funtion testing*/
  bool status;
  if(number%9==0){status=true;}
  else status=false;
  return status;
}

void make_first_latter_A(string& instructor){ /*For for_each function testing*/
  instructor[0]='A';
  return;
}

void increase_num(int index){ /*For for_each function testing*/
  index++;
  return;
}

int main(){
  GTUSet<string> set;
  GTUSet<string>::Iter ptr,ptr_begin,ptr_end;
  GTUVector<int> test_vector;
  GTUVector<int>::Iter ptr_v,ptr_begin_v,ptr_end_v;
  int temp;
  try{
    cout << "----------SET TEST----------" << endl<< endl;
    cout << "-----EMPTY TEST:-----" << endl;
  	if(set.empty()==true)  cout << "SET is empty." << endl<< endl;
    else cout << "SET is not empty." << endl<< endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "SET SIZE = " << set.size() << endl<< endl;
    cout << "-----MAX SIZE TEST:-----" << endl;
    cout << "SET MAX SIZE = " << set.max_size() << endl << endl;
    cout << "Inserting the names of the instructors to SET:" << endl;
    set.insert("Muhammet Ali");
    set.insert("Yusuf Sinan");
    set.insert("Erdoğan");
    set.insert("Yakup");
    set.insert("Erkan");
    set.insert("Zafeirakis");
    set.insert("Burcu");
    set.insert("Mehmet Burak");
    set.insert("Rasih");
    set.insert("Samet");
    set.insert("Gökhan");
    cout << "After adding elements to SET:" << endl << endl;
    cout << "-----INSERT & BEGIN & END TEST:-----" << endl;
    cout << "SET Elements:"<<endl;
    ptr = set.begin();
    while(ptr!=set.end()){
      cout << *ptr << endl;
      ptr++;
    }
    cout << endl;
    cout << "-----EMPTY TEST:-----" << endl;
    if(set.empty()==true)  cout << "SET is empty." << endl<< endl;
    else cout << "SET is not empty." << endl<< endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "SET SIZE = " << set.size() << endl << endl;
    cout << "-----ERASE TEST:-----" << endl;
    cout << "Erasing names of Burcu & Yusuf Sinan from the SET:" << endl;
    set.erase("Burcu");
    set.erase("Yusuf Sinan");
    cout << "SET Elements:"<<endl;
    ptr=set.begin();
    while(ptr!=set.end()){
      cout << *ptr << endl;
      ptr++;
    }
    cout << endl;
    cout << "-----find TEST:-----" << endl;
    cout << "Finding the instructor Muhammet Ali" << endl;
    ptr_begin=set.begin();
    ptr_end=set.end();
    ptr = find(ptr_begin,ptr_end,"Muhammet Ali");
    cout<<"find Function Returns: "<<*ptr << endl << endl;


    cout << "-----find_if TEST:-----" << endl;
    cout << "First instructor in the set with first letter M" << endl;
    ptr_begin=set.begin();
    ptr_end=set.end();
    ptr = find_if(ptr_begin,ptr_end,first_letter_M);
    cout<<"find_if Function Returns: "<<*ptr << endl << endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "SET SIZE = " << set.size() << endl << endl;
    cout << "-----CLEAR TEST:-----" << endl;
    cout << "Clearing all elements of SET" << endl;
    cout << "SET Elements:"<<endl;
    set.clear();
    ptr=set.begin();
    while(ptr!=set.end()){
      cout << *ptr << endl;
      ptr++;
    }
    cout << endl;
    cout << "-----EMPTY TEST:-----" << endl;
    if(set.empty()==true)  cout << "SET is empty." << endl<< endl;
    else cout << "SET is not empty." << endl<< endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "SET SIZE = " << set.size() << endl << endl;
    cout << "-----MAX SIZE TEST:-----" << endl;
    cout << "SET MAX SIZE= " << set.max_size() << endl << endl;
    cout << "----------------------------------------------------------------------------------------------------"<< endl << endl;

    cout << "----------VECTOR TEST----------" << endl<< endl;
    cout << "-----EMPTY TEST:-----" << endl;
    if(test_vector.empty()==true)  cout << "VECTOR is empty." << endl<< endl;
    else cout << "VECTOR is not empty." << endl << endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "VECTOR SIZE = " << test_vector.size() << endl<< endl;
    cout << "-----MAX SIZE TEST:-----" << endl;
    cout << "VECTOR MAX SIZE = " << test_vector.max_size() << endl << endl;
    cout << "Inserting integers (10,20,30,40,50,2,8,3,9,0,5) to VECTOR:" << endl;
    test_vector.insert(10);
    test_vector.insert(20);
    test_vector.insert(30);
    test_vector.insert(40);
    test_vector.insert(50);
    test_vector.insert(2);
    test_vector.insert(8);
    test_vector.insert(3);
    test_vector.insert(9);
    test_vector.insert(0);
    test_vector.insert(5);
    cout << "After adding elements to VECTOR:" << endl << endl;
    cout << "-----INSERT & BEGIN & END TEST:-----" << endl;
    cout << "VECTOR Elements:"<<endl;
    ptr_v = test_vector.begin();
    while(ptr_v!=test_vector.end()){
      cout << *ptr_v << endl;
      ptr_v++;
    }
    cout << endl;
    cout << "-----EMPTY TEST:-----" << endl;
    if(test_vector.empty()==true)  cout << "VECTOR is empty." << endl<< endl;
    else cout << "VECTOR is not empty." << endl<< endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "VECTOR SIZE = " << test_vector.size() << endl << endl;
    cout << "-----ERASE TEST:-----" << endl;
    cout << "Erasing numbers of 10 & 0 from the VECTOR:" << endl;
    test_vector.erase(10);
    test_vector.erase(0);
    cout << "VECTOR Elements:"<<endl;
    ptr_v=test_vector.begin();
    while(ptr_v!=test_vector.end()){
      cout << *ptr_v << endl;
      ptr_v++;
    }
    cout << endl;
    cout << "-----find TEST:-----" << endl;
    cout << "Finding the number of 50" << endl;
    ptr_begin_v=test_vector.begin();
    ptr_end_v=test_vector.end();
    ptr_v = find(ptr_begin_v,ptr_end_v,50);
    cout<<"find Function Returns: "<<*ptr_v << endl << endl;


    cout << "-----find_if TEST:-----" << endl;
    cout << "Divisible to 9 without residue" << endl;
    ptr_begin_v=test_vector.begin();
    ptr_end_v=test_vector.end();
    ptr_v = find_if(ptr_begin_v,ptr_end_v,divisible_nine);
    cout<<"find_if Function Returns: "<< *ptr_v << endl << endl;
    cout << "-----for_each TEST:-----" << endl;
    cout << "Increase all numbers by 1 (+1)" << endl << endl;
    ptr_begin_v=test_vector.begin();
    ptr_end_v=test_vector.end();
    for_each(ptr_begin_v,ptr_end_v,[](int index){index++;});
    cout << "VECTOR ELEMENTS:"<<endl;
    ptr_v=test_vector.begin();
    while(ptr_v!=test_vector.end()){
      temp=*ptr_v;
      cout << ++temp << endl;
      ptr_v++;
    }
    cout << endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "VECTOR SIZE = " << test_vector.size() << endl << endl;
    cout << "-----CLEAR TEST:-----" << endl;
    cout << "Clearing all elements of VECTOR" << endl;
    cout << "VECTOR Elements:"<<endl;
    test_vector.clear();
    ptr_v=test_vector.begin();
    while(ptr_v!=test_vector.end()){
      cout << *ptr_v << endl;
      ptr_v++;
    }
    cout << endl;
    cout << "-----EMPTY TEST:-----" << endl;
    if(test_vector.empty()==true)  cout << "VECTOR is empty." << endl<< endl;
    else cout << "VECTOR is not empty." << endl<< endl;
    cout << "-----SIZE TEST:-----" << endl;
    cout << "VECTOR SIZE = " << test_vector.size() << endl << endl;
    cout << "-----MAX SIZE TEST:-----" << endl;
    cout << "VECTOR MAX SIZE= " << test_vector.max_size() << endl << endl;
  }
  catch (exception e) {
  	cout << e.what() << endl;
  }
  return 0;
}
