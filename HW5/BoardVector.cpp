#include "BoardVector.h"

namespace HW5_161044098{
	BoardVector::BoardVector(){
		const int max_size=3;
		int i=0,j=0,number=1;
		vector<int> temp_map;
		while(i<max_size){
			while(j<max_size){
				if(number==((max_size)*(max_size))){
					temp_map.push_back(-1);
					break;
				}
				temp_map.push_back(number);
				j++;
				number++;
			}
			map.push_back(temp_map);
			temp_map.clear();
			j=0;
			i++;
		}
		setter_last_move('S');
		setter_total_move(0);
	}
	BoardVector::BoardVector(int size_i, int size_j){
		int i=0,j=0;
		vector<int> temp_map;
		while(i<size_i){
			while(j<size_j){
				if(i*j==((size_i-1)*(size_j-1))){
					temp_map.push_back(-1);
					break;
				}
				temp_map.push_back(1);
				j++;
			}
			map.push_back(temp_map);
			temp_map.clear();
			j=0;
			i++;
		}
		setter_last_move('S');
		setter_total_move(0);
		//AbstractBoard::inc_boardNum();
	}

	BoardVector::BoardVector(const BoardVector& board){
		const int max_size=board.map.size();
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

	void BoardVector::print(int flag){
		const int space=-1;
		int i=0,j=0;
		int size_i=map.size(),size_j=map[i].size();
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

	void BoardVector::readFromFile(char file_name[20]){
		ifstream file;
		const int ascii_constant=48,size2=2;
	    vector<int> temp;
		int num,flag=1,x=0;
		char c,array[2];
		map.clear();
		file.open(file_name);
		while(file.get(c)){
			if(c!=' ' && c!='\n' && c!='b'){
				array[x]=c;
				x++;
				if(x==size2){
					num=((array[0]-ascii_constant)*10)+(array[1]-ascii_constant);
					temp.push_back(num);
					x=0;
				}
			}
			else if(c=='\n'){
				map.push_back(temp);
	    		temp.clear();
			}
			else if(c=='b'){
				file.get(c);
				temp.push_back(-1);
			}
		}
		map.push_back(temp);
		file.close();
		return;
	}

	void BoardVector::writeToFile(){
		ofstream file;
		const int size=20;
		int i=0,j=0;
		int size_i=map.size(),size_j=map[i].size();
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
	void BoardVector::reset(int flag,int size_i,int size_j){
		const int max_size=9;
		vector<int> temp_map;
		vector<vector<int> > board_map;
		int i=0,j=0,number=1;
		if(flag==1){
			size_i=map.size();
			size_j=map[i].size();
		}
		if(flag==0){
			map.clear();
			while(i<size_i){
				while(j<size_i){
					if(number==(size_i*size_j)){
						temp_map.push_back(-1);
						break;
					}
					temp_map.push_back(number);
					number++;
					j++;
				}
				map.push_back(temp_map);
				temp_map.clear();
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
						temp_map.push_back(-1);
						break;
					}
					if(map[i][j]==0){
						temp_map.push_back(0);
					}
					else{
						temp_map.push_back(number);
						number++;
					}
					j++;
				}
				j=0;
				i++;
				board_map.push_back(temp_map);
				temp_map.clear();
			}
			i=0;
			j=0;
			number=1;
			map.clear();
			while(i<size_i){
				map.push_back(board_map[i]);
				i++;
			}
			setter_last_move('S');
			setter_total_move(0);
		}
		return;
	}
	void BoardVector::setsize(int &size_i,int &size_j){
		int size;
		cout << "Please enter the problem size" << endl;
		cin >> size;
		size_i=size;
		size_j=size;
		return;
	}
	int BoardVector::move(char move,int status,int flag_1){
		const int space=-1;
		int i=0,j=0,flag_2=0,result=0,temp_total_move;
		int size_i=map.size(),size_j=map[i].size();
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
					cout << "Invalid move!" << endl<< endl;
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
					cout << "Invalid move!" << endl<< endl;
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
					cout << "Invalid move!" << endl<< endl;
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
					cout << "Invalid move!" << endl<< endl;
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


	int BoardVector::NumberOfBoards(int size){
		return size;
	}

	int BoardVector::isSolved(int flag, int status){
		const int max_size=9;
		int i=0,j=0,number=1,result=1,temp_total_move;
		int size_i=map.size(),size_j=map[i].size();
		BoardVector solution(size_i,size_j),current(size_i,size_j);
		solution.map.clear();
		current.map.clear();
		vector<int> temp_map;
		if(flag==0){
			while(i<size_i){
				while(j<size_i){
					if(number==(size_i*size_j)){
						temp_map.push_back(-1);
						break;
					}
					temp_map.push_back(number);
					number++;
					j++;
				}
				solution.map.push_back(temp_map);
				temp_map.clear();
				j=0;
				i++;
			}
		}
		else if(flag==1){
			while(i<size_i){
				while(j<size_j){
					if((number)==(size_i)*(size_j)){
						temp_map.push_back(-1);
						break;
					}
					if(map[i][j]==0){
						temp_map.push_back(0);
					}
					else{
						temp_map.push_back(number);
						number++;
					}
					j++;
				}
				j=0;
				i++;
				solution.map.push_back(temp_map);
				temp_map.clear();
			}
		}
		i=0;
		while(i<size_i){
			current.map.push_back(map[i]);
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
	int BoardVector::l(int i,int j){
		int invalid=-2;
		if(i<0 || i>map.size()-1 || j<0 || j>map[0].size()-1){
			return invalid;
		}
		return map[i][j];
	}

	int BoardVector::operator()(int i,int j){
		return map[i][j];
	}
	bool BoardVector::operator==(const BoardVector &solution){
		int i=0,j=0,size_i=map.size(),size_j=map[i].size();
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

	int BoardVector::get_size(int iORj){
		int size;
		if(iORj==0){
			size=map.size();
		}
		else if(iORj==1){
			size=map[0].size();
		}
		return size;
	}
}