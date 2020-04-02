#include "BoardArray1D.h"

namespace HW5_161044098{
	BoardArray1D::BoardArray1D(){
		const int max_size=3;
		int i=0,j=0,number=1;
		map = new int[max_size*max_size];
		while(number<=max_size*max_size){
			if(number==((max_size)*(max_size))){
				map[j]=-1;
				break;
			}
			map[j]=number;
			number++;
			j++;
		}
		setter_last_move('S');
		setter_total_move(0);
		size_x=3;
		size_y=3;
	}

	BoardArray1D::BoardArray1D(BoardArray1D& board){
		int size_x=board.get_size(0);
		int size_y=board.get_size(1);
		int i=0;
		while(i<size_x*size_y){
			map[i]=board.map[i];
			i++;
		}
	}

	void BoardArray1D::print(int flag){
		const int space=-1;
		int i=0,j=0;
		while(j<size_x*size_y){
			if(flag==0){
				if(map[j]==space){
					cout << "   ";
				}
				else{
					if (map[j]<10)
					{
						cout << " " << map[j] << " ";
					}
					else{
						cout << map[j] << " ";
					}
					
				}	
			}
			else{
				if(map[j]==space){
					cout << "bb ";
				}
				else{
					if (map[j]<10)
					{
						cout << "0" << map[j] << " ";
					}
					else{
						cout << map[j] << " ";
					}
					
				}
			}
			j++;
			if(j%size_y==0){
				cout << endl;
			}
		}
		cout << endl;
		return;
	}
	void BoardArray1D::readFromFile(char file_name[20]){
		ifstream file;
		const int ascii_constant=48,size2=2;
		int num,flag=1,x=0,i=1,j=0;
		char c,array[2];
		file.open(file_name);
		while(file.get(c)){
			if(c!=' ' && c!='\n' && c!='b'){
				array[x]=c;
				x++;
				if(x==size2){
					num=((array[0]-ascii_constant)*10)+(array[1]-ascii_constant);
					x=0;
					j++;
				}
			}
			else if(c=='\n'){
	    		i++;
			}
			else if(c=='b'){
				file.get(c);
				j++;
			}
		}
		file.close();
		size_x=i;
		size_y=j/i;
		map=new int[size_x*size_y];
		i=0;
		j=0;
		x=0;
		file.open(file_name);
		while(file.get(c)){
			if(c!=' ' && c!='\n' && c!='b'){
				array[x]=c;
				x++;
				if(x==size2){
					num=((array[0]-ascii_constant)*10)+(array[1]-ascii_constant);
					map[j]=num;
					j++;
					x=0;
				}
			}
			else if(c=='\n'){
	    		i++;
			}
			else if(c=='b'){
				file.get(c);
				map[j]=-1;
				j++;
			}
		}
		file.close();
		return;
	}
	void BoardArray1D::writeToFile(){
		ofstream file;
		const int size=20;
		int i=0,j=0;
		char file_name[size];
		cout << "Enter a file name to save the current board to a file:";
		cin >> file_name;
		file.open(file_name);
		while(j<size_x*size_y){
			if(j%size_y==0 && j!=0){
				file << endl;
			}
			if(map[j]==-1){
				file<<"bb";
			}
			else{
				if(map[j]<10){
					file << "0" << map[j] << " ";
				}
				else{
					file << map[j] << " ";
				}
			}
			j++;
		}
		file.close();
		return;
	}
	void BoardArray1D::reset(int flag,int size_i,int size_j){
		const int max_size=9;
		int i=0,j=0,number=1;
		size_x=size_i;
		size_y=size_j;
		if(flag==0){
			delete [] map;
			map = new int[size_i*size_j];
			while(j<size_i*size_j){
				if(number==(size_i*size_j)){
					map[j]=-1;
					break;
				}
				map[j]=number;
				number++;
				j++;
			}
			setter_last_move('S');
			setter_total_move(0);
		}
		else if(flag==1){
			delete [] map;
			map = new int[size_i*size_j];
			while(j<size_i*size_j){
				if((i*j)==(size_i-1)*(size_j-1)){
					map[j]=-1;
					break;
				}
				if(map[j]==0){
					map[j]=0;
				}
				else{
					map[j]=number;
					number++;
				}
				j++;
			}
			setter_last_move('S');
			setter_total_move(0);
		}
		return;
	}
	void BoardArray1D::setsize(int &size_i,int &size_j){
		int size;
		cout << "Please enter the problem size" << endl;
		cin >> size;
		size_i=size;
		size_j=size;
		size_x=size;
		size_y=size;
		return;
	}
	int BoardArray1D::move(char move,int status,int flag_1){
		const int space=-1;
		int i=0,j=0,flag_2=0,result=0,temp_total_move;
		int size_i=size_x,size_j=size_y;
		flag_1=1;
		if(status==0) cout << "MOVE=" << move << endl;
		if(move=='L'){
			while(j<size_i*size_j && flag_2==0){
				if(map[j]==space){
					flag_2=1;
				}
				else{
					j++;
				}
			}
			if((j%size_j!=0) && map[j-1]!=0){
				map[j]=map[j-1];
				map[j-1]=space;
				if(status==0){
					print(flag_1);
				}
			}
			else{
				if(status==0){
					cout << "Invalid move!" << endl;
					temp_total_move=numberOfMoves();
					temp_total_move--;
					setter_total_move(temp_total_move);
				}
				result=-1;
			}
		}
		else if(move=='R'){
			while(j<size_i*size_j && flag_2==0){
				if(map[j]==space){
					flag_2=1;
				}
				else{
					j++;
				}
			}
			if(((j+1)%size_j!=0) && map[j+1]!=0){
				map[j]=map[j+1];
				map[j+1]=space;
				if(status==0){
					print(flag_1);
				}
			}
			else{
				if(status==0){
					cout << "Invalid move!" << endl;
					temp_total_move=numberOfMoves();
					temp_total_move--;
					setter_total_move(temp_total_move);
				}
				result=-1;
			}
		}
		else if(move=='U'){
			while(j<size_i*size_j && flag_2==0){
				if(map[j]==space){
					flag_2=1;
				}
				else{
					j++;
				}
			}
			if((j>size_j) && map[j-size_j]!=0){
				map[j]=map[j-size_j];
				map[j-size_j]=space;
				if(status==0){
					print(flag_1);
				}
			}
			else{
				if(status==0){
					cout << "Invalid move!" << endl;
					temp_total_move=numberOfMoves();
					temp_total_move--;
					setter_total_move(temp_total_move);
				}
				result=-1;
			}
		}
		else if(move=='D'){
			while(j<size_i*size_j && flag_2==0){
				if(map[j]==space){
					flag_2=1;
				}
				else{
					j++;
				}
			}
			if(((j<(size_i*size_j)-size_j) && map[j+size_j]!=0)){
				map[j]=map[j+size_j];
				map[j+size_j]=space;
				if(status==0){
					print(flag_1);
				}
			}
			else{
				if(status==0){
					cout << "Invalid move!" << endl;
					temp_total_move=numberOfMoves();
					temp_total_move--;
					setter_total_move(temp_total_move);
				}
				result=-1;
			}
		}
		temp_total_move=numberOfMoves();
		temp_total_move++;
		setter_total_move(temp_total_move);
		if(status==-5 && result!=-1){
			setter_last_move(move);
		}
		return result;
	}

	int BoardArray1D::NumberOfBoards(int size){
		return size;
	}

	int BoardArray1D::isSolved(int flag, int status){
		const int max_size=9;
		BoardArray1D solution,current;
		int i=0,j=0,number=1,result=1,temp_total_move;
		int size_i=size_x,size_j=size_y;
		solution.size_x=size_x;
		solution.size_y=size_y;
		current.size_x=size_x;
		current.size_y=size_y;
		delete [] solution.map;
		delete [] current.map;
		solution.map = new int[size_x*size_y];
		current.map = new int[size_x*size_y];
		if(flag==0){
			while(j<size_i*size_j){
				if(number==(size_i*size_j)){
					solution.map[j]=-1;
					break;
				}
				solution.map[j]=number;
				number++;
				j++;
			}
		}
		else if(flag==1){
			while(j<size_i*size_j){
				if((number)==(size_i)*(size_j)){
					solution.map[j]=-1;
					break;
				}
				if(map[j]==0){
					solution.map[j]=0;
				}
				else{
					solution.map[j]=number;
					number++;
				}
				j++;
			}
		}
		i=0;
		j=0;
		while(j<size_i*size_j){
			current.map[j]=map[j];
			j++;
		}
		if(current==solution){
			result=0;
		}
		temp_total_move=numberOfMoves();
		if(result==0 && status!=1){
			cout << "Problem Solved!" << endl;
			cout << "Total number of moves " << temp_total_move << endl<< endl;
		}
		else{
			cout << "Problem has not been solved" << endl << endl;
		}
		return result;
	}

	int BoardArray1D::l(int i,int j){
		int size_i=get_size(0);
		int size_j=get_size(1);
		int invalid=-2;
		if(i<0 || i>size_i-1 || j<0 || j>size_j-1){
			return invalid;
		}
		return map[(i*size_i)+j];
	}

	int BoardArray1D::operator()(int i,int j){
		int size_i=get_size(0);
		int size_j=get_size(1);
		int invalid=-2;
		if(i<0 || i>size_i-1 || j<0 || j>size_j-1){
			return invalid;
		}
		return map[(i*size_i)+j];
	}

	BoardArray1D& BoardArray1D::operator=(const BoardArray1D& solution){
		int i=0;
		delete [] map;
		size_x=solution.size_x;
		size_y=solution.size_y;
		map=new int[size_x*size_y];
		while(i<size_x*size_y){
			map[i]=solution.map[i];
			i++;
		}	
		return *this;
	}

	bool BoardArray1D::operator==(const BoardArray1D &solution){
		int i=0,j=0,size_i=size_x,size_j=size_y;
		bool result=true;
		while(j<size_i*size_j){
			if(map[j]==solution.map[j]){
				j++;
			}
			else{
				result=false;
				break;
			}
		}
		return result;
	}
	int BoardArray1D::get_size(int iORj){
		int size;
		if(iORj==0){
			size=size_x;
		}
		else if(iORj==1){
			size=size_y;
		}
		return size;
	}

	BoardArray1D::~BoardArray1D(){
		delete [] map;
	}
}