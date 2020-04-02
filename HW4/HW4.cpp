/*********************************************************************************
 *       HW4_161044098_VEDAT_ELLIDOKUZOGLU.cpp                                   *
 *       CSE 241/501 - Object Oriented Programming Homework-4                    *
 *       Author: Vedat ELLIDOKUZOGLU                                             *
 *       Date: 12.11.2019                                                        *
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>

using namespace std;

class Npuzzle
{
    private:
    	class Board{
    		private:
    			vector<vector<int> > map;
    			char last_move='S';
    			int total_move=0;
    		public:
    			void print(int flag);
    			void printReport(int flag);
    			void readFromFile(char file_name[20]);
    			void writeToFile();
    			void shuffle();
    			void reset(int flag,int size_i,int size_j);
    			void setsize(int &size_i,int &size_j);
    			int calculate_manhattan_distance();
    			void moveRandom(int flag);
    			int move(char move,int status,int flag_1);
    			int isSolved(int flag,int solved);
    			char lastMove();
    			int numberOfMoves();
    			void change_lastMove(char a);
    			void change_totalMove(int count);
    			bool operator==(const Board &solution);
    			friend ostream& operator << (ostream& output,const Board& temp){
					const int space = -1;
					int i=0,j=0;
					int size_i=temp.map.size(),size_j=temp.map[i].size();
					while(i<size_i){
						while(j<size_j){
							if(temp.map[i][j]==space){
								output << "bb ";
							}
							else{
								if (temp.map[i][j]<10)
								{
									output << "0" << temp.map[i][j] << " ";
								}
								else{
									output << temp.map[i][j] << " ";
								}
								
							}
							j++;
						}
						output << endl;
						j=0;
						i++;
					}
					output << endl;
					return output;
				}
				friend istream& operator >> (istream& input,Board& temp){
					const int ascii_constant=48,size2=2;
				    vector<int> temp1;
					int num,flag=1,x=0;
					char c,array[2];
					while(input.get(c)){
						if(c!=' ' && c!='\n' && c!='b'){
							array[x]=c;
							x++;
							if(x==size2){
								num=((array[0]-ascii_constant)*10)+(array[1]-ascii_constant);
								temp1.push_back(num);
								x=0;
							}
						}
						else if(c=='\n'){
							temp.map.push_back(temp1);
				    		temp1.clear();
						}
						else if(c=='b'){
							input.get(c);
							temp1.push_back(-1);
						}
					}
				}
    			int operator()(int i,int j);
    	};
    	vector<Board> inner;
    public:
        void print(int flag);
        void printReport(int flag);
        void readFromFile(char file_name[20]);
        void writeToFile();
        void shuffle();
        void reset(int flag,int size_i,int size_j);
        void setsize(int &size_i,int &size_j);
        void moveRandom(int flag);
        int move(char move,int status,int flag);
        int isSolved(int flag,int solved);
        int solvePuzzle(int flag);
        friend ostream& operator << (ostream& output,const Npuzzle& game){
			output<< game.inner.back();
		}
		friend istream& operator >> (istream& input,Npuzzle& temp){
			input>> temp.inner.back();
		}
};

int main(int argc, char const *argv[]){
	srand(time(NULL));
	const int ascii_constant_1=90,ascii_constant_2=32;
	char file_name[20],selection;
	int status=0,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4,size_i,size_j;
	Npuzzle game;
	if(argv[1]!=NULL){
		flag_4=1;
		strcpy(file_name,argv[1]);
		game.readFromFile(file_name);
		game.print(flag_4);
	}
	else{
		flag_4=0;
		game.setsize(size_i,size_j);
		cout << "Your initial random board is" << endl;
		game.reset(flag_4,size_i,size_j);
		game.shuffle();
		game.print(flag_4);
	}
	while(true){
		if(status==flag_1 || status==flag_3){
			break;
		}
		cout << "Your move: ";
		cin >> selection;
		if(selection>ascii_constant_1){
			selection-=ascii_constant_2;
		}
		switch(selection){
			case 'V':	result=game.solvePuzzle(flag_4);
						if(result==0){
							status=flag_3;
						}
						break;

			case 'T':	game.printReport(flag_4);
						break;

			case 'E':	game.writeToFile();
						break;

			case 'O':	flag_4=1;
						cout << "Enter a file name to load a board from file:";
						cin >> file_name;
						game.readFromFile(file_name);
						game.print(flag_4);
						break;

			case 'L':	game.move(selection,flag_2,flag_4);
						result=game.isSolved(flag_4,0);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;

			case 'R':	game.move(selection,flag_2,flag_4);
						result=game.isSolved(flag_4,0);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;		
						break;

			case 'U':	game.move(selection,flag_2,flag_4);
						result=game.isSolved(flag_4,0);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;

			case 'D':	game.move(selection,flag_2,flag_4);
						result=game.isSolved(flag_4,0);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;

			case 'S':	cout << "Initial Board:" << endl;
						game.reset(flag_4,size_i,size_j);
						game.print(flag_4);
						cout << "Shuffled Board:" << endl;
						game.shuffle();
						game.print(flag_4);
						break;
		}
	}
	
	return 0;
}

void Npuzzle::print(int flag){
	inner.back().print(flag);
	return;
}

void Npuzzle::printReport(int flag){
	inner.back().printReport(flag);
	return;
}

void Npuzzle::readFromFile(char file_name[20]){
	Board a;
	inner.push_back(a);
	inner.back().readFromFile(file_name);
	return;
}

void Npuzzle::writeToFile(){
	inner.back().writeToFile();
	return;
}

void Npuzzle::shuffle(){
	inner.back().shuffle();
	return;
}

void Npuzzle::reset(int flag,int size_i,int size_j){
	inner.back().reset(flag,size_i,size_j);
	return;
}

void Npuzzle::setsize(int &size_i,int &size_j){
	Board a;
	inner.push_back(a);
	inner.back().setsize(size_i,size_j);
	return;
}

void Npuzzle::moveRandom(int flag){
	inner.back().moveRandom(flag);
	return;
}


int Npuzzle::move(char move,int status,int flag){
	int result;
	result=inner.back().move(move,status,flag);
	return result;
}

int Npuzzle::isSolved(int flag,int status){
	int result;
	result=inner.back().isSolved(flag,status);
	return result;
}

int Npuzzle::solvePuzzle(int flag){
	vector<char> moves;
	Board solution,temp_board;
	int i=0,j=0,x=0,result,result_move,number=1,move_count=0,temp1,temp2,count=0;
	char a,inverse_move;
	while(true){
		a=inner[i].lastMove();
		result_move=inner[i].move('R',-5,flag);
		if(result_move==0){
			inner.push_back(inner[i]);
			result=inner.back().isSolved(flag,1);
			inner[i].move('L',-4,flag);
			if(result==0){
				inner[i].change_lastMove(a);
				break;
			}
		}	
		result_move=inner[i].move('L',-5,flag);
		if(result_move==0){
			inner.push_back(inner[i]);
			result=inner.back().isSolved(flag,1);
			inner[i].move('R',-4,flag);
			if(result==0){
				inner[i].change_lastMove(a);
				break;
			}
		}
		result_move=inner[i].move('U',-5,flag);
		if(result_move==0){
			inner.push_back(inner[i]);
			result=inner.back().isSolved(flag,1);
			inner[i].move('D',-4,flag);
			if(result==0){
				inner[i].change_lastMove(a);
				break;
			}
		}
		result_move=inner[i].move('D',-5,flag);
		if(result_move==0){
			inner.push_back(inner[i]);
			result=inner.back().isSolved(flag,1);
			inner[i].move('U',-4,flag);
			if(result==0){
				inner[i].change_lastMove(a);
				break;
			}
		}
		inner[i].change_lastMove(a);
		i++;
	}
	i=0;
	while(!(inner[i]==inner.back())){
		a=inner[i].lastMove();
		if(a=='R') temp1=1;
		if(a=='L') temp1=2;
		if(a=='U') temp1=3;
		if(a=='D') temp1=4;
		if(a=='S') temp1=5;
		a=inner[i+1].lastMove();
		if(a=='R') temp2=1;
		if(a=='L') temp2=2;
		if(a=='U') temp2=3;
		if(a=='D') temp2=4;
		if(temp1>=temp2){
			count++;
			inner[i+1].change_totalMove(count);
		}
		else{
			inner[i+1].change_totalMove(count);
		}
		i++;
	}
	a=inner[i].lastMove();
	if(a=='R') temp1=1;
	if(a=='L') temp1=2;
	if(a=='U') temp1=3;
	if(a=='D') temp1=4;
	a=inner[i+1].lastMove();
	if(a=='R') temp2=1;
	if(a=='L') temp2=2;
	if(a=='U') temp2=3;
	if(a=='D') temp2=4;
	if(temp1>=temp2){
		inner[i+1].change_totalMove(count);
		count++;
	}
	else{
		inner[i+1].change_totalMove(count);
	}
	i=0;
	while(!(inner[i]==inner.back())){
		a=inner[i].lastMove();
		temp1=inner[i].numberOfMoves();
		//cout << "L:" << a << " T:" << temp1 << endl;
		//inner[i].print(flag);
		i++;
	}
	a=inner[i].lastMove();
	temp1=inner[i].numberOfMoves();
	//cout << "L:" << a << " T:" << temp1 << endl;
	//inner[i].print(flag);
	x=0;
	while(i>0){
		a=inner[i].lastMove();
		temp1=inner[i].numberOfMoves();
		if(a=='R')	inverse_move='L';
		if(a=='L')	inverse_move='R';
		if(a=='U')	inverse_move='D';
		if(a=='D')	inverse_move='U';
		moves.push_back(a);
		a++;
		temp_board=inner[i];
		temp_board.move(inverse_move,-4,flag);
		while(!(temp_board==inner[i])){
			i--;
		}
	}
	i=moves.size()-1;
	count=moves.size();
	while(i>=0){
		cout << "New algorithm made " << moves[i] <<" move."<< endl;
		inner[0].move(moves[i],0,flag);
		i--;
	}
	cout << "Problem Solved!" << endl;
	cout << "Total number of moves " << count << endl;
	return result;
}

void Npuzzle::Board::print(int flag){
	const int space = -1;
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
}

void Npuzzle::Board::printReport(int flag){
	int result=-1;
	cout << total_move << " moves have been done." << endl;
	result=isSolved(flag,0);
	if(result==0){
		cout << "Problem has been solved!" << endl;
	}
	else{
		cout << "Problem has not been solved" << endl;
	}
	print(flag);
	return;
}

void Npuzzle::Board::readFromFile(char file_name[20]){
	ifstream file;
	const int ascii_constant=48,size2=2;
    vector<int> temp;
	int num,flag=1,x=0;
	char c,array[2];
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
	file.close();
	return;
}

void Npuzzle::Board::writeToFile(){
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

void Npuzzle::Board::shuffle(){
	const int size=4,left_move = 0,right_move = 1,up_move = 2,down_move = 3,space = -1;
	int moves[size],count,i=0,j=0,available=0,flag=0,index;
	int size_i=map.size(),size_j=map[i].size();
	count=(size_i*size_j);
	while(count>0){
		while(i<size_i && flag==0){
			while(j<size_j && flag==0){
				if(map[i][j]==space){
					flag=1;
				}
				else{
					j++;
				}
			}
			if(flag==0){
				j=0;
				i++;
			}
		}
		if((j-1>=0) && map[i][j-1]!=0){
			moves[available]=left_move;
			available++;
		}
		if((j+1<size_j) && map[i][j+1]!=0){
			moves[available]=right_move;
			available++;
		}
		if((i-1>=0) && map[i-1][j]!=0){
			moves[available]=up_move;
			available++;
		}
		if((i+1<size_i) && map[i+1][j]!=0){
			moves[available]=down_move;
			available++;
		}
		index=(rand()%available);
		if(moves[index]==left_move){
			map[i][j]=map[i][j-1];
			map[i][j-1]=space;
		}
		else if(moves[index]==right_move){
			map[i][j]=map[i][j+1];
			map[i][j+1]=space;

		}
		else if(moves[index]==up_move){
			map[i][j]=map[i-1][j];
			map[i-1][j]=space;
		}
		else if(moves[index]==down_move){
			map[i][j]=map[i+1][j];
			map[i+1][j]=space;
		}
		i=0;
		j=0;
		available=0;
		flag=0;
		count--;
	}
	return;
}

void Npuzzle::Board::reset(int flag,int size_i,int size_j){
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
		last_move='S';
		total_move=0;
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
		last_move='S';
		total_move=0;
	}
	return;
}

void Npuzzle::Board::setsize(int &size_i,int &size_j){
	int size;
	cout << "Please enter the problem size" << endl;
	cin >> size;
	size_i=size;
	size_j=size;
	return;
}

int Npuzzle::Board::calculate_manhattan_distance(){
	const int max_size=9;
	int final_map[max_size][max_size],i=0,j=0,x=0,y=0,manhattan_distance=0,number=1,flag=0;
	int size_i=map.size(),size_j=map[i].size();
	while(i<size_i){
		while(j<size_j){
			if(i*j==(size_i-1)*(size_j-1)){
				final_map[i][j]=-1;
				break;
			}
			if(map[i][j]==0){
				final_map[i][j]=0;
			}
			else{
				final_map[i][j]=number;
				number++;
			}
			j++;
		}
		j=0;
		i++;
	}
	i=0;
	j=0;
	while(i<size_i){
		while(j<size_j){
			flag=0;
			x=0;
			y=0;
			while(x<size_i && flag==0){
				while(y<size_j && flag==0){
					if(final_map[i][j]==map[x][y] && final_map[i][j]!=0){
						if(i<=x){
							manhattan_distance+=x-i;
						}
						else if(x<i){
							manhattan_distance+=i-x;
						}
						if(j<=y){
							manhattan_distance+=y-j;
						}
						else if(y<j){
							manhattan_distance+=j-y;
						}
						x=0;
						y=0;
						flag=1;
						break;
					}
					y++;
				}
				y=0;
				x++;
			}
			x=0;
			y=0;
			j++;
		}
		j=0;
		i++;
	}
	return manhattan_distance;
}

void Npuzzle::Board::moveRandom(int flag){
	const int size=4,left_move=0,right_move=1,up_move=2,down_move = 3;
	int random_number;
	random_number=rand()%size;
	if(random_number==left_move){
		move('L',1,flag);
	}
	if(random_number==right_move){
		move('R',1,flag);
	}
	if(random_number==up_move){
		move('U',1,flag);
	}
	if(random_number==down_move){
		move('D',1,flag);
	}
	return;
}

int Npuzzle::Board::move(char move,int status,int flag_1){
	const int space=-1;
	int i=0,j=0,flag_2=0,result=0;
	int size_i=map.size(),size_j=map[i].size();
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
				total_move--;
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
				total_move--;
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
				total_move--;
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
				total_move--;
			}
			result=-1;
		}
	}
	total_move++;
	if(status==-5 && result!=-1){
		last_move=move;	
	}
	return result;
}

int Npuzzle::Board::isSolved(int flag, int status){
	const int max_size=9;
	Board solution,current;
	vector<int> temp_map;
	int i=0,j=0,number=1,result=1;
	int size_i=map.size(),size_j=map[i].size();
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
	if(result==0 && status!=1){
		cout << "Problem Solved!" << endl;
		cout << "Total number of moves " << total_move << endl;
	}
	return result;
}

bool Npuzzle::Board::operator==(const Board &solution){
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

char Npuzzle::Board::lastMove(){
	return last_move;
}

void Npuzzle::Board::change_lastMove(char a){
	last_move=a;
	return;
}

void Npuzzle::Board::change_totalMove(int count){
	total_move=count;
	return;
}

int Npuzzle::Board::numberOfMoves(){
	return total_move;
}

int Npuzzle::Board::operator()(int i,int j){
	return map[i][j];
}
