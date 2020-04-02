#include "AbstractBoard.h"
#include "BoardArray1D.h"
#include "BoardArray2D.h"
#include "BoardVector.h"

using namespace std;
using namespace HW5_161044098;

bool global_function(AbstractBoard *Board[],int size){
	int i=0,x=0,y=0,space_flag=1,space=-1,size_x=Board[i]->get_size(0),size_y=Board[i]->get_size(1);
	bool status=true;
	while(i<size){
		Board[i]->print(1);
		i++;
	}
	i=0;
	while(i<size-1 && status==true){
		while(x<size_x && space_flag==1){
			while(y<size_y && space_flag==1){
				if(Board[i]->l(x,y)==space){
					space_flag=0;
					break;
				}
				y++;
			}
			if(space_flag==1){
				y=0;
				x++;
			}
		}
		space_flag=1;
		if(Board[i+1]->l(x+1,y)==space || Board[i+1]->l(x,y+1)==space || Board[i+1]->l(x-1,y)==space || Board[i+1]->l(x,y-1)==space){
			i++;
		}
		else{
			status=false;
			break;
		}
	}
	
	return status;
}

void test_1D(){
	int i=0,j=0,status=0,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4,size_i,size_j;
	char file_name[20];
	BoardArray1D a,b;
	flag_4=0;
	a.setsize(size_i,size_j);
	a.reset(0,size_i,size_j);
	b.reset(0,size_i,size_j);
	cout<<"INITIAL BOARD:" << endl;
	a.print(1);
	cout << "MOVE TEST:" << endl << endl;
	a.move('R',0,0);
	a.move('L',0,0);
	a.move('U',0,0);
	a.move('D',0,0);
	cout << "isSolved TEST:" << endl<< "----------------" << endl;
	result=a.isSolved(flag_4,0);
	a.move('R',0,0);
	result=a.isSolved(flag_4,0);
	a.move('L',1,0);
	cout << "OPERATOR == TEST:" << endl<< "----------------" << endl;
	cout << "FIRST BOARD" << endl;
	a.print(1);
	cout << "SECOND BOARD" << endl;
	b.print(1);
	if(a==b)cout << "Return=TRUE" << endl<< "----------------" << endl;
	else cout << "Return=FALSE" << endl<< "----------------" << endl;
	a=b;
	cout << "FIRST BOARD" << endl;
	a.print(1);
	cout << "SECOND BOARD" << endl;
	b.print(1);
	if(a==b)cout << "Return=TRUE" << endl << "----------------" << endl;
	else cout << "Return=FALSE" << endl<< "----------------" << endl;
	cout << endl << "OPERATOR () TEST:" << endl<< "----------------" << endl;
	a.print(1);
	cout << "for x=0 y=0" << endl;
	cout << a(0,0) << endl << "----------------" << endl;
	cout << endl << "READ-WRITE TEST:" << endl<< "----------------" << endl;
	a.writeToFile();
	cout << "Board has been written successfully to text file." << endl;
	cout << "Enter a file name to load a board from file:";
	cin >> file_name;
	a.readFromFile(file_name);
	cout << "Board has been read successfully from text file." << endl;
	a.print(1);
	cout << "----------------" << endl << endl;
	return;
}

void test_2D(){
	int i=0,j=0,status=0,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4,size_i,size_j;
	char file_name[20];
	BoardArray2D a,b;
	flag_4=0;
	a.setsize(size_i,size_j);
	a.reset(0,size_i,size_j);
	b.reset(0,size_i,size_j);
	cout<<"INITIAL BOARD:" << endl;
	a.print(1);
	cout << "MOVE TEST:" << endl << endl;
	a.move('R',0,0);
	a.move('L',0,0);
	a.move('U',0,0);
	a.move('D',0,0);
	cout << "isSolved TEST:" << endl<< "----------------" << endl;
	result=a.isSolved(flag_4,0);
	a.move('R',0,0);
	result=a.isSolved(flag_4,0);
	a.move('L',1,0);
	cout << "OPERATOR == TEST:" << endl<< "----------------" << endl;
	cout << "FIRST BOARD" << endl;
	a.print(1);
	cout << "SECOND BOARD" << endl;
	b.print(1);
	if(a==b)cout << "Return=TRUE" << endl<< "----------------" << endl;
	else cout << "Return=FALSE" << endl<< "----------------" << endl;
	a=b;
	cout << "FIRST BOARD" << endl;
	a.print(1);
	cout << "SECOND BOARD" << endl;
	b.print(1);
	if(a==b)cout << "Return=TRUE" << endl << "----------------" << endl;
	else cout << "Return=FALSE" << endl<< "----------------" << endl;
	cout << endl << "OPERATOR () TEST:" << endl<< "----------------" << endl;
	a.print(1);
	cout << "for x=0 y=0" << endl;
	cout << a(0,0) << endl << "----------------" << endl;
	cout << endl << "READ-WRITE TEST:" << endl<< "----------------" << endl;
	a.writeToFile();
	cout << "Board has been written successfully to text file." << endl;
	cout << "Enter a file name to load a board from file:";
	cin >> file_name;
	a.readFromFile(file_name);
	cout << "Board has been read successfully from text file." << endl;
	a.print(1);
	cout << "----------------" << endl << endl;
	return;
}

void test_vector(){
	int i=0,j=0,status=0,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4,size_i,size_j;
	char file_name[20];
	BoardVector a,b;
	flag_4=0;
	a.setsize(size_i,size_j);
	a.reset(0,size_i,size_j);
	b.reset(0,size_i,size_j);
	cout<<"INITIAL BOARD:" << endl;
	a.print(1);
	cout << "MOVE TEST:" << endl << endl;
	a.move('R',0,0);
	a.move('L',0,0);
	a.move('U',0,0);
	a.move('D',0,0);
	cout << "isSolved TEST:" << endl<< "----------------" << endl;
	result=a.isSolved(flag_4,0);
	a.move('R',0,0);
	result=a.isSolved(flag_4,0);
	a.move('L',1,0);
	cout << "OPERATOR == TEST:" << endl<< "----------------" << endl;
	cout << "FIRST BOARD" << endl;
	a.print(1);
	cout << "SECOND BOARD" << endl;
	b.print(1);
	if(a==b)cout << "Return=TRUE" << endl<< "----------------" << endl;
	else cout << "Return=FALSE" << endl<< "----------------" << endl;
	a=b;
	cout << "FIRST BOARD" << endl;
	a.print(1);
	cout << "SECOND BOARD" << endl;
	b.print(1);
	if(a==b)cout << "Return=TRUE" << endl << "----------------" << endl;
	else cout << "Return=FALSE" << endl<< "----------------" << endl;
	cout << endl << "OPERATOR () TEST:" << endl<< "----------------" << endl;
	a.print(1);
	cout << "for x=0 y=0" << endl;
	cout << a(0,0) << endl << "----------------" << endl;
	cout << endl << "READ-WRITE TEST:" << endl<< "----------------" << endl;
	a.writeToFile();
	cout << "Board has been written successfully to text file." << endl;
	cout << "Enter a file name to load a board from file:";
	cin >> file_name;
	a.readFromFile(file_name);
	cout << "Board has been read successfully from text file." << endl;
	a.print(1);
	cout << "----------------" << endl << endl;
	return;
}
int main(int argc, char const *argv[]){
	int i=0,j=0;
	char file_name[20];
	int selection=0,status=0,glb,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4,size_i,size_j;
	bool validty;
	AbstractBoard *Board[3];
	BoardArray1D a,b,c;
	BoardArray2D x,y,z;
	BoardVector k,l,m;
	while(selection!=5){
		cout << "Please Select a Test:" << endl;
		cout << "1) BoardArray1D" << endl;
		cout << "2) BoardArray2D" << endl;
		cout << "3) BoardVector" << endl;
		cout << "4) Global Function" << endl;
		cout << "5) Exit" << endl;
		cin >> selection;
		switch(selection){
			case 1:{		
				test_1D();
				break;
				}
			case 2:{	
				test_2D();
				break;
				}
			case 3:{	
				test_vector();
				break;
				}
			case 4:{
				cout << "Select for Global Function:" << endl;
				cout << "1) BoardArray1D" << endl;
				cout << "2) BoardArray2D" << endl;
				cout << "3) BoardVector" << endl;
				cin>>glb;
				switch(glb){
					case 1:{
						c=a;
						a.move('L',1,0);
						b=a;
						a.move('U',1,0);
						Board[0]=&a;
						Board[1]=&b;
						Board[2]=&c;
						validty=global_function(Board,3);
						if(validty==true){
							cout << "GLOBAL FUNTION: True"<<endl<<endl;
						}
						else if(validty==false){
							cout << "GLOBAL FUNTION: False"<<endl<<endl;
						}
						a.move('U',1,0);
						validty=global_function(Board,3);
						if(validty==true){
							cout << "GLOBAL FUNTION: True"<<endl<<endl;
						}
						else if(validty==false){
							cout << "GLOBAL FUNTION: False"<<endl<<endl;
						}
						break;
						}
					case 2:{
						z=x;
						x.move('L',1,0);
						y=x;
						x.move('U',1,0);
						Board[0]=&x;
						Board[1]=&y;
						Board[2]=&z;
						validty=global_function(Board,3);
						if(validty==true){
							cout << "GLOBAL FUNTION: True"<<endl<<endl;
						}
						else if(validty==false){
							cout << "GLOBAL FUNTION: False"<<endl<<endl;
						}
						x.move('U',1,0);
						validty=global_function(Board,3);
						if(validty==true){
							cout << "GLOBAL FUNTION: True"<<endl<<endl;
						}
						else if(validty==false){
							cout << "GLOBAL FUNTION: False"<<endl<<endl;
						}
						break;
						}
					case 3:{		
						m=k;
						k.move('L',1,0);
						l=k;
						k.move('U',1,0);
						Board[0]=&k;
						Board[1]=&l;
						Board[2]=&m;
						validty=global_function(Board,3);
						if(validty==true){
							cout << "GLOBAL FUNTION: True"<<endl<<endl;
						}
						else if(validty==false){
							cout << "GLOBAL FUNTION: False"<<endl<<endl;
						}
						k.move('U',1,0);
						validty=global_function(Board,3);
						if(validty==true){
							cout << "GLOBAL FUNTION: True"<<endl<<endl;
						}
						else if(validty==false){
							cout << "GLOBAL FUNTION: False"<<endl<<endl;
						}
						break;
						}
				}
				
				break;
				}
			case 5:{
				
				break;
				}
		}
	}
	return 0;
}