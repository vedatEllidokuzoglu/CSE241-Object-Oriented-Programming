/*********************************************************************************
 *       HW3_161044098_VEDAT_ELLIDOKUZOGLU.cpp                                   *
 *       CSE 241/501 - Object Oriented Programming Homework-3                    *
 *       Author: Vedat ELLIDOKUZOGLU                                             *
 *       Date: 04.11.2019                                                        *
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

class Npuzzle
{
    private:
    	class Board{
    		private:
    			int map[9][9];
    			int size_i;
    			int size_j;
    			int total_move=0;
    		public:
    			void print(int flag);
    			void printReport(int flag);
    			void readFromFile(char file_name[20]);
    			void writeToFile();
    			void shuffle();
    			void reset(int flag);
    			void setsize();
    			int calculate_manhattan_distance();
    			void moveRandom(int flag);
    			int moveIntelligent(int flag,int last_move);
    			int move(char move,int status,int flag_1);
    			int isSolved(int flag);
    			int solvePuzzle(int flag,int last_move);
    	};
    	Board inner;
    public:
        void print(int flag);
        void printReport(int flag);
        void readFromFile(char file_name[20]);
        void writeToFile();
        void shuffle();
        void reset(int flag);
        void setsize();
        void moveRandom(int flag);
        int moveIntelligent(int flag,int last_move);
        int move(char move,int status,int flag);
        int isSolved(int flag);
        int solvePuzzle(int flag,int last_move);
};

int main(int argc, char const *argv[]){
	srand(time(NULL));
	const int ascii_constant_1=90,ascii_constant_2=32;
	char file_name[20],selection;
	int status=0,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4;
	Npuzzle game;
	if(argv[1]!=NULL){
		flag_4=1;
		strcpy(file_name,argv[1]);
		game.readFromFile(file_name);
		game.print(flag_4);
	}
	else{
		flag_4=0;
		game.setsize();
		cout << "Your initial random board is" << endl;
		game.reset(flag_4);
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
			case 'V':	result=game.solvePuzzle(flag_4,last_move);
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
						result=game.isSolved(flag_4);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;

			case 'R':	game.move(selection,flag_2,flag_4);
						result=game.isSolved(flag_4);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;		
						break;

			case 'U':	game.move(selection,flag_2,flag_4);
						result=game.isSolved(flag_4);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;

			case 'D':	game.move(selection,flag_2,flag_4);
						result=game.isSolved(flag_4);
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;

			case 'I':	last_move=game.moveIntelligent(flag_4,last_move);
						result=game.isSolved(flag_4);
						if(result==0){
							status=flag_3;
						}
						break;

			case 'S':	cout << "Initial Board:" << endl;
						game.reset(flag_4);
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
	inner.print(flag);
	return;
}

void Npuzzle::printReport(int flag){
	inner.printReport(flag);
	return;
}

void Npuzzle::readFromFile(char file_name[20]){
	inner.readFromFile(file_name);
	return;
}

void Npuzzle::writeToFile(){
	inner.writeToFile();
	return;
}

void Npuzzle::shuffle(){
	inner.shuffle();
	return;
}

void Npuzzle::reset(int flag){
	inner.reset(flag);
	return;
}

void Npuzzle::setsize(){
	inner.setsize();
	return;
}

void Npuzzle::moveRandom(int flag){
	inner.moveRandom(flag);
	return;
}

int Npuzzle::moveIntelligent(int flag,int last_move){
	last_move=inner.moveIntelligent(flag,last_move);
	return last_move;
}

int Npuzzle::move(char move,int status,int flag){
	int result;
	result=inner.move(move,status,flag);
	return result;
}

int Npuzzle::isSolved(int flag){
	int result;
	result=inner.isSolved(flag);
	return result;
}

int Npuzzle::solvePuzzle(int flag,int last_move){
	int result;
	result=inner.solvePuzzle(flag,last_move);
	return result;
}

void Npuzzle::Board::print(int flag){
	const int space = -1;
	int i=0,j=0;
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
	result=isSolved(flag);
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
	int num,flag=1,i=0,j=0,x=0;
	char c,array[2];
	file.open(file_name);
	while(file.get(c)){
		if(c=='\n'){
			j++;
			break;
		}
		if(c==' ')
		{
			j++;
		}
	}
	file.close();
	file.open(file_name);
	while(file.get(c)){
		if(c==' '){
			i++;
		}
	}
	i=i/(j-1);
	file.close();
	size_i=i;
	size_j=j;
	i=0;
	j=0;
	file.open(file_name);
	while(file.get(c)){
		if(c!=' ' && c!='\n' && c!='b'){
			array[x]=c;
			x++;
			if(x==size2){
				num=((array[0]-ascii_constant)*10)+(array[1]-ascii_constant);
				map[i][j]=num;
				x=0;
			}
		}
		else if(c==' '){
			j++;
		}
		else if(c=='\n'){
			j=0;
			i++;
		}
		else if(c=='b'){
			file.get(c);
			map[i][j]=-1;
		}
	}
	file.close();
	return;
}

void Npuzzle::Board::writeToFile(){
	ofstream file;
	const int size=20;
	int i=0,j=0;
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
	int moves[size],count=(size_i*size_j),i=0,j=0,available=0,flag=0,index;
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

void Npuzzle::Board::reset(int flag){
	const int max_size=9;
	int temp_map[max_size][max_size],i=0,j=0,number=1;
	if(flag==0){
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
	}
	else if(flag==1){
		while(i<size_i){
			while(j<size_j){
				if((i*j)==(size_i-1)*(size_j-1)){
					temp_map[i][j]=-1;
					break;
				}
				if(map[i][j]==0){
					temp_map[i][j]=0;
				}
				else{
					temp_map[i][j]=number;
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
				map[i][j]=temp_map[i][j];
				j++;
			}
			j=0;
			i++;
		}	
	}
	return;
}

void Npuzzle::Board::setsize(){
	int size;
	cout << "Please enter the problem size" << endl;
	cin >> size;
	size_i=size;
	size_j=size;
	return;
}

int Npuzzle::Board::moveIntelligent(int flag,int last_move){
	const int size=4,left_move=0,right_move=1,up_move=2,down_move = 3;
	int distances[size]={-1,-1,-1,-1},i=0,flag_2=1,distance,status,move_1=0,min,not_available=0;
	if(last_move%2==0 && last_move!=-1){
		last_move++;
	}
	else if(last_move%2==1 && last_move!=-1){
		last_move--;
	}
	status=move('L',flag_2,flag);
	total_move--;
	distance=calculate_manhattan_distance();
	if(status!=-1){
		move('R',flag_2,flag);
		total_move--;
		distances[left_move]=distance;
	}

	status=move('R',flag_2,flag);
	total_move--;
	distance=calculate_manhattan_distance();
	if(status!=-1){
		move('L',flag_2,flag);
		total_move--;
		distances[right_move]=distance;
	}
	
	status=move('U',flag_2,flag);
	total_move--;
	distance=calculate_manhattan_distance();
	if(status!=-1){
		move('D',flag_2,flag);
		total_move--;
		distances[up_move]=distance;
	}

	status=move('D',flag_2,flag);
	total_move--;
	distance=calculate_manhattan_distance();
	if(status!=-1){
		move('U',flag_2,flag);
		total_move--;
		distances[down_move]=distance;
	}
	i=0;
	while(i<size){
		if (distances[i]==-1){
			not_available++;
		}
		i++;
	}
	if(not_available>=size-1){
		i=0;
		while(i<size){
			if(distances[i]!=-1){
				move_1=i;
				break;
			}
			i++;
		}
		i=0;
	}
	else{
		i=0;
		while(i<size){
			if(distances[i]!=-1){
				min=distances[i];
				break;
			}
			i++;
		}
		i=0;
	    while(i<size){
	    	if(i==last_move && i==down_move){
	    		break;
	    	}
	    	else if(i==last_move){
	    		i++;
	    	}
	    	if((min>distances[i] && distances[i]!=-1) || (min==distances[i] && distances[i-1]==-1)){
	    		min=distances[i];
	    		move_1=i;
	    	}
	    	i++;
	    }
    }

	flag_2=0;
	i=0;
	while(i<4){
		i++;
	}

	if(distances[move_1]==-1){
		i=0;
		while(distances[i]==-1){
			i++;
		}
		move_1=i;
	}
	if(move_1==left_move){
		cout << "Intelligent move chooses L" << endl;
		move('L',flag_2,flag);
		last_move=left_move;
	}
	if(move_1==right_move){
		cout << "Intelligent move chooses R" << endl;
		move('R',flag_2,flag);
		last_move=right_move;
	}
	
	if(move_1==up_move){
		cout << "Intelligent move chooses U" << endl;
		move('U',flag_2,flag);
		last_move=up_move;
	}

	if(move_1==down_move){
		cout << "Intelligent move chooses D" << endl;
		move('D',flag_2,flag);
		last_move=down_move;
	}
	return last_move;
}

int Npuzzle::Board::calculate_manhattan_distance(){
	const int max_size=9;
	int final_map[max_size][max_size],i=0,j=0,x=0,y=0,manhattan_distance=0,number=1,flag=0;
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
	return result;
}

int Npuzzle::Board::isSolved(int flag){
	const int max_size=9;
	int temp_map[max_size][max_size],i=0,j=0,number=1,result=1;
	if(flag==0){
		while(i<size_i){
			if (result==0 || result==-1){
				break;
			}
			while(j<size_j){
				if(number==((size_i*size_j)-1) && number==map[i][j]){
					result=0;
					break;
				}
				if(number==map[i][j]){
					j++;
					number++;
				}
				else{
					result=-1;
					break;
				}
			}
			j=0;
			i++;
		}
	}
	else if(flag==1){
		while(i<size_i){
			while(j<size_j){
				if((i*j)==(size_i-1)*(size_j-1)){
					temp_map[i][j]=-1;
					break;
				}
				if(map[i][j]==0){
					temp_map[i][j]=0;
				}
				else{
					temp_map[i][j]=number;
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
				if(i*j==((size_i-1)*(size_j-1)) && map[i][j]==-1){
					result=0;
					break;
				}
				if(map[i][j]==temp_map[i][j]){
					j++;
				}
				else{
					result-1;
					break;
				}
			}
			j=0;
			i++;
		}
	}
	if(result==0){
		cout << "Problem Solved!" << endl;
		cout << "Total number of moves " << total_move << endl;
	}
	return result;
}

int Npuzzle::Board::solvePuzzle(int flag,int last_move){
	int i=1,x,size=4,distance,result;
	while(true){
		last_move=moveIntelligent(flag,last_move);
		distance=calculate_manhattan_distance();
		if(i%20==0){
			x=distance/size_j/2;
			while(x>0){
				moveRandom(flag);
				result=isSolved(flag);
				if(result==0){
					return result;
				}
				x--;
			}
		}
		result=isSolved(flag);
		if(result==0){
			break;
		}
		i++;
	}
	return result;
}
