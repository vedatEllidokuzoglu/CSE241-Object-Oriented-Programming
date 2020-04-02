#include "BoardArray2D.h"

namespace HW5_161044098{
	BoardArray2D::BoardArray2D(){
		const int max_size=3;
		int i=0,j=0,number=1;
		map= new int*[max_size];
		while(i<max_size){
			map[i]= new int[max_size];
			i++;
		}
		i=0;
		while(i<max_size){
			while(j<max_size){
				if(number==(max_size*max_size)){
					map[i][j]=-1;
					break;
				}
				map[i][j]=number;
				j++;
				number++;
			}
			j=0;
			i++;
		}
		setter_last_move('S');
		setter_total_move(0);
		size_x=3;
		size_y=3;
	}

	BoardArray2D::BoardArray2D(const BoardArray2D& board){
		const int max_size=9;
		int i=0,j=0;
		while(i<max_size){
			while(j<max_size){
				map[i][j]=board.map[i][j];
				j++;
			}
			j=0;
			i++;
		}
	}

	void BoardArray2D::print(int flag){
		const int space=-1;
		int i=0,j=0;
		int size_i=size_x,size_j=size_y;
		while(i<size_i){
			while(j<size_j){
				if(flag==0){
					if(map[i][j]==space){
						cout << "   ";
					}
					else{
						if (map[i][j]<10)
						{
							cout << " " << map[i][j] << " ";
						}
						else{
							cout << map[i][j] << " ";
						}
						
					}	
				}
				else{
					if(map[i][j]==space){
						cout << "bb ";
					}
					else{
						if (map[i][j]<10)
						{
							cout << "0" << map[i][j] << " ";
						}
						else{
							cout << map[i][j] << " ";
						}
						
					}
				}
				j++;
			}
			cout << endl;
			j=0;
			i++;
		}
		cout << endl;
		return;
	}
	void BoardArray2D::readFromFile(char file_name[20]){
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
					j++;
					x=0;
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
		i=0;
		map=new int*[size_x];
		while(i<size_x)
		{
			map[i]= new int[size_y];
			i++;
		}
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
					map[i][j]=num;
					j++;
					x=0;
				}
			}
			else if(c=='\n'){
	    		j=0;
	    		i++;
			}
			else if(c=='b'){
				file.get(c);
				map[i][j]=-1;
				j++;
			}
		}
		file.close();
		return;
	}
	void BoardArray2D::writeToFile(){
		ofstream file;
		const int size=20;
		int i=0,j=0;
		int size_i=size_x,size_j=size_y;
		char file_name[size];
		cout << "Enter a file name to save the current board to a file:";
		cin >> file_name;
		file.open(file_name);
		while(i<size_i){
			while(j<size_j){
				if(map[i][j]==-1){
					file<<"bb";
				}
				else{
					if(map[i][j]<10){
						file << "0" << map[i][j];
					}
					else{
						file << map[i][j];
					}
				}
				j++;
				if(j<size_j){
					file << " ";
				}
			}
			j=0;
			i++;
			if(i<size_i){
				file << "\n";
			}
		}
		file.close();
		return;
	}
	void BoardArray2D::reset(int flag,int size_i,int size_j){
		const int max_size=9;
		int i=0,j=0,number=1;
		size_x=size_i;
		size_y=size_j;
		if(flag==0){
			map= new int*[max_size];
			while(i<size_i){
				map[i]= new int[size_j];
				i++;
			}
			i=0;
			while(i<size_i){
				while(j<size_i){
					if(number==(size_i*size_j)){
						map[i][j]=-1;
						break;
					}
					map[i][j]=number;
					number++;
					j++;
				}
				j=0;
				i++;
			}
			setter_last_move('S');
			setter_total_move(0);
		}
		else if(flag==1){
			while(i<size_i){
				while(j<size_j){
					if((i*j)==(size_i-1)*(size_j-1)){
						map[i][j]=-1;
						break;
					}
					if(map[i][j]==0){
						map[i][j]=0;
					}
					else{
						map[i][j]=number;
						number++;
					}
					j++;
				}
				j=0;
				i++;
			}
			i=0;
			j=0;
			number=1;
			setter_last_move('S');
			setter_total_move(0);
		}
		return;
	}
	void BoardArray2D::setsize(int &size_i,int &size_j){
		int size;
		cout << "Please enter the problem size" << endl;
		cin >> size;
		size_i=size;
		size_j=size;
		size_x=size;
		size_y=size;
		return;
	}
	int BoardArray2D::move(char move,int status,int flag_1){
		const int space=-1;
		int i=0,j=0,flag_2=0,result=0,temp_total_move;
		int size_i=size_x,size_j=size_y;
		flag_1=1;
		if(status==0) cout << "MOVE=" << move << endl;
		if(move=='L'){
			while(i<size_i && flag_2==0){
				while(j<size_j && flag_2==0){
					if(map[i][j]==space){
						flag_2=1;
					}
					else{
						j++;
					}
				}
				if(flag_2==0){
					j=0;
					i++;
				}
			}
			if((j-1>=0) && map[i][j-1]!=0){
				map[i][j]=map[i][j-1];
				map[i][j-1]=space;
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
			while(i<size_i && flag_2==0){
				while(j<size_j && flag_2==0){
					if(map[i][j]==space){
						flag_2=1;
					}
					else{
						j++;
					}
				}
				if(flag_2==0){
					j=0;
					i++;
				}
			}
			if((j+1<size_j) && map[i][j+1]!=0){
				map[i][j]=map[i][j+1];
				map[i][j+1]=space;
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
			while(i<size_i && flag_2==0){
				while(j<size_j && flag_2==0){
					if(map[i][j]==space){
						flag_2=1;
					}
					else{
						j++;
					}
				}
				if(flag_2==0){
					j=0;
					i++;
				}
			}
			if((i-1>=0) && map[i-1][j]!=0){
				map[i][j]=map[i-1][j];
				map[i-1][j]=space;
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
			while(i<size_i && flag_2==0){
				while(j<size_j && flag_2==0){
					if(map[i][j]==space){
						flag_2=1;
					}
					else{
						j++;
					}
				}
				if(flag_2==0){
					j=0;
					i++;
				}
			}
			if((i+1<size_i && map[i+1][j]!=0)){
				map[i][j]=map[i+1][j];
				map[i+1][j]=space;
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

	int BoardArray2D::NumberOfBoards(int size){
		return size;
	}

	int BoardArray2D::isSolved(int flag, int status){
		const int max_size=9;
		BoardArray2D solution,current;
		int i=0,j=0,number=1,result=1,temp_total_move;
		int size_i=size_x,size_j=size_y;
		solution.size_x=get_size(0);
		solution.size_y=get_size(1);
		current.size_x=get_size(0);
		current.size_y=get_size(1);
		solution.map=new int*[size_x];
		current.map=new int*[size_x];
		while(i<size_x)
		{
			solution.map[i]= new int[size_y];
			current.map[i]= new int[size_y];
			i++;
		}
		i=0;
		if(flag==0){
			while(i<size_i){
				while(j<size_i){
					if(number==(size_i*size_j)){
						solution.map[i][j]=-1;
						break;
					}
					solution.map[i][j]=number;
					number++;
					j++;
				}
				j=0;
				i++;
			}
		}
		else if(flag==1){
			while(i<size_i){
				while(j<size_j){
					if((i*j)==(size_i-1)*(size_j-1)){
						solution.map[i][j]=-1;
						break;
					}
					if(map[i][j]==0){
						solution.map[i][j]=0;
					}
					else{
						solution.map[i][j]=number;
						number++;
					}
					j++;
				}
				j=0;
				i++;
			}
		}
		i=0;
		j=0;
		while(i<size_i){
			while(j<size_j){
				current.map[i][j]=map[i][j];
				j++;
			}
			j=0;
			i++;
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

	int BoardArray2D::l(int i,int j){
		int invalid=-2;
		if(i<0 || i>size_x-1 || j<0 || j>size_y-1){
			return invalid;
		}
		return map[i][j];
	}

	int BoardArray2D::operator()(int i,int j){
		int invalid=-2;
		int size_i=get_size(0);
		int size_j=get_size(1);
		if(i<0 || i>size_i-1 || j<0 || j>size_j-1){
			return invalid;
		}
		return map[i][j];
	}
	BoardArray2D& BoardArray2D::operator=(BoardArray2D& solution){
		int i=0,j=0;
		size_x=solution.get_size(0);
		size_y=solution.get_size(1);
		while(i<size_x){
        	delete[] map[i];
        	i++;
    	}
    	i=0;
		delete [] map;
		map=new int*[size_x];
		while(i<size_x){
			map[i]=new int[size_y];
			i++;
		}
		i=0;
		while(i<size_x){
			while(j<size_y){
				map[i][j]=solution.map[i][j];
				j++;
			}
			j=0;
			i++;
		}
		return *this;
	}

	bool BoardArray2D::operator==(const BoardArray2D &solution){
		int i=0,j=0,size_i=size_x,size_j=size_y;
		bool result=true;
		while(i<size_i){
			while(j<size_j){
				if(map[i][j]==solution.map[i][j]){
					j++;
				}
				else{
					result=false;
					break;
				}
			}
			j=0;
			i++;
		}
		return result;
	}
	int BoardArray2D::get_size(int iORj){
		int size;
		if(iORj==0){
			size=size_x;
		}
		else if(iORj==1){
			size=size_y;
		}
		return size;
	}


	BoardArray2D::~BoardArray2D(){
		int i=0,size_i,size_j;
		size_j=get_size(0);
		while(i<size_i) 
		{
        	delete [] map[i];
    		i++;
    	}
		delete [] map;
	}
}