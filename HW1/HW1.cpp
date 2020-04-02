/*********************************************************************************
 *       HW1_161044098_VEDAT_ELLIDOKUZOGLU.cpp                                   *
 *       CSE 241/501 - Object Oriented Programming Homework-1                    *
 *       Author: Vedat ELLIDOKUZOGLU                                             *
 *       Date: 12.10.2019                                                        *
 *-------------------------------------------------------------------------------*
 * It is a C++ program that helps the user to solve the N-Puzzle problem.        *
 * See descriptions from the Homework PDF to understand the problem and the rules*
 ********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_SIZE 9
#define SIZE_1 4
#define LEFT_MOVE 0
#define RIGHT_MOVE 1
#define UP_MOVE 2
#define DOWN_MOVE 3
#define ASCII_CONSTANT_1 90
#define ASCII_CONSTANT_2 32

int move_left(int map[MAX_SIZE][MAX_SIZE],int size,int status);
int move_right(int map[MAX_SIZE][MAX_SIZE],int size,int status);
int move_up(int map[MAX_SIZE][MAX_SIZE],int size,int status);
int move_down(int map[MAX_SIZE][MAX_SIZE],int size,int status);
void move_intelligent(int map[MAX_SIZE][MAX_SIZE],int size);
int calculate_manhattan_distance(int map[MAX_SIZE][MAX_SIZE],int size);
void fill_initial(int map[MAX_SIZE][MAX_SIZE], int size);
void print_map(int map[MAX_SIZE][MAX_SIZE],int size);
void shuffle(int map[MAX_SIZE][MAX_SIZE],int size);
int final_check(int map[MAX_SIZE][MAX_SIZE],int size);

int main(){
	srand(time(NULL));
	int map[MAX_SIZE][MAX_SIZE],i=0,j=0,size,status=0,flag_1=1,flag_2=0,flag_3=2,total_move=0,result;
	char move;
	cout << "Please enter the problem size" << endl;
	cin >> size;
	fill_initial(map,size);
	cout << "Your initial random board is" << endl;
	shuffle(map,size);
	print_map(map,size);
	while(true){
		if(status==flag_1 || status==flag_3){
			break;
		}
		cout << "Your move: ";
		cin >> move;
		if(move>ASCII_CONSTANT_1){
			move-=ASCII_CONSTANT_2;
		}
		switch(move){
			case 'L':	result=move_left(map,size,flag_2);
					if(result==0){
						total_move++;
					}
					result=final_check(map,size);
					if(result==0){
						status=flag_3;
					}
					break;
					
			case 'R':	result=move_right(map,size,flag_2);
					if(result==0){
						total_move++;
					}
					result=final_check(map,size);
					if(result==0){
						status=flag_3;
					}
					break;
					
			case 'U':	result=move_up(map,size,flag_2);
					if(result==0){
						total_move++;
					}
					result=final_check(map,size);
					if(result==0){
						status=flag_3;
					}
					break;
					
			case 'D':	result=move_down(map,size,flag_2);
					if(result==0){
						total_move++;
					}
					result=final_check(map,size);
					if(result==0){
						status=flag_3;
					}
					break;
					
			case 'I':	move_intelligent(map,size);
					total_move++;
					result=final_check(map,size);
					if(result==0){
						status=flag_3;
					}
					break;
					
			case 'S':	while(result!=-1){
						fill_initial(map,size);
						shuffle(map,size);
						result=final_check(map,size);
					}
					print_map(map,size);
					break;
					
			case 'Q':	cout << "You quitted the game!" << endl;
					status=flag_1;
					break;
					
		}
	}
	
	if(status==flag_3){
		cout << "Problem Solved!" << endl;
		cout << "Total number of moves " << total_move << endl;
	}
	
	return 0;
}

int move_left(int map[MAX_SIZE][MAX_SIZE],int size,int status){
	int i=0,j=0,flag=0,result=0;
	while(i<size && flag==0){
		while(j<size && flag==0){
			if(map[i][j]==0){
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
	if((j-1>=0) && map[i][j-1]!=-1){
		map[i][j]=map[i][j-1];
		map[i][j-1]=0;
		if(status==0){
			print_map(map,size);
		}
	}
	else{
		if(status==0){
			cout << "Invalid move!" << endl;
		}
		result=-1;
	}
	return result;
}

int move_right(int map[MAX_SIZE][MAX_SIZE],int size,int status){
	int i=0,j=0,flag=0,result=0;
	while(i<size && flag==0){
		while(j<size && flag==0){
			if(map[i][j]==0){
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
	
	if((j+1<size) && map[i][j+1]!=-1){
		map[i][j]=map[i][j+1];
		map[i][j+1]=0;
		if(status==0){
			print_map(map,size);
		}
	}
	
	else{
		if(status==0){
			cout << "Invalid move!" << endl;
		}
		result=-1;
	}
	
	return result;
}

int move_up(int map[MAX_SIZE][MAX_SIZE],int size,int status){
	int i=0,j=0,flag=0,result=0;
	while(i<size && flag==0){
		while(j<size && flag==0){
			if(map[i][j]==0){
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
	
	if((i-1>=0) && map[i-1][j]!=-1){
		map[i][j]=map[i-1][j];
		map[i-1][j]=0;
		if(status==0){
			print_map(map,size);
		}
	}
	else{
		if(status==0){
			cout << "Invalid move!" << endl;
		}
		result=-1;
	}
	
	return result;
}

int move_down(int map[MAX_SIZE][MAX_SIZE],int size,int status){
	int i=0,j=0,flag=0,result=0;
	while(i<size && flag==0){
		while(j<size && flag==0){
			if(map[i][j]==0){
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
	
	if((i+1<size) && map[i+1][j]!=-1){
		map[i][j]=map[i+1][j];
		map[i+1][j]=0;
		if(status==0){
			print_map(map,size);
		}
	}
	else{
		if(status==0){
			cout << "Invalid move!" << endl;
		}
		result=-1;
	}
	
	return result;
}

void move_intelligent(int map[MAX_SIZE][MAX_SIZE],int size){
	int distances[SIZE_1]={-1,-1,-1,-1},i=0,flag=1,distance,status,move=0,min;
	status=move_left(map,size,flag);
	distance=calculate_manhattan_distance(map,size);
	if(status!=-1){
		move_right(map,size,flag);
		distances[LEFT_MOVE]=distance;
	}
	
	status=move_right(map,size,flag);
	distance=calculate_manhattan_distance(map,size);
	
	if(status!=-1){
		move_left(map,size,flag);
		distances[RIGHT_MOVE]=distance;
	}
	
	status=move_up(map,size,flag);
	distance=calculate_manhattan_distance(map,size);
	
	if(status!=-1){
		move_down(map,size,flag);
		distances[UP_MOVE]=distance;
	}

	status=move_down(map,size,flag);
	distance=calculate_manhattan_distance(map,size);
	
	if(status!=-1){
		move_up(map,size,flag);
		distances[DOWN_MOVE]=distance;
	}

	while(i<SIZE_1){
		if(distances[i]!=-1){
			min=distances[i];
			break;
		}
		i++;
	}
	i=0;
	
    while(i<SIZE_1){
    	if((min>distances[i] && distances[i]!=-1) || (min==distances[i] && distances[i-1]==-1)){
    		min=distances[i];
    		move=i;
    	}
    	i++;
    }
	
	flag=0;
	
	if(move==LEFT_MOVE){
		cout << "Intelligent move chooses L" << endl;
		move_left(map,size,flag);
	}
	
	if(move==RIGHT_MOVE){
		cout << "Intelligent move chooses R" << endl;
		move_right(map,size,flag);
	}
	
	if(move==UP_MOVE){
		cout << "Intelligent move chooses U" << endl;
		move_up(map,size,flag);
	}

	if(move==DOWN_MOVE){
		cout << "Intelligent move chooses D" << endl;
		move_down(map,size,flag);
	}
	
	return;
	
}

int calculate_manhattan_distance(int map[MAX_SIZE][MAX_SIZE],int size){
	int final_map[MAX_SIZE][MAX_SIZE],i=0,j=0,x=0,y=0,manhattan_distance=0,number=1,flag=0;
	while(i<size){
		while(j<size){
			if(number==(size*size)){
				final_map[i][j]=0;
				break;
			}
			final_map[i][j]=number;
			number++;
			j++;
		}
		j=0;
		i++;
	}
	i=0;
	j=0;
	while(i<size){
		while(j<size){
			flag=0;
			x=0;
			y=0;
			while(x<size && flag==0){
				while(y<size && flag==0){
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

void fill_initial(int map[MAX_SIZE][MAX_SIZE], int size){
	int i=0,j=0,number=1;
	
	while(i<MAX_SIZE){
		while(j<MAX_SIZE){
			map[i][j]=-1;
			j++;
		}
		j=0;
		i++;
	}
	i=0;
	j=0;
	
	while(i<size){
		while(j<size){
			if(number==(size*size)){
				map[i][j]=0;
				break;
			}
			map[i][j]=number;
			number++;
			j++;
		}
		j=0;
		i++;
	}
	
	return;
}

void print_map(int map[MAX_SIZE][MAX_SIZE],int size){
	int i=0,j=0;
	while(i<size){
		while(j<size){
			if(map[i][j]==0){
				cout << "   ";
			}
			else{
				if (map[i][j]<10)
				{
					cout << map[i][j] << "  ";
				}
				else{
					cout << map[i][j] << " ";
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

void shuffle(int map[MAX_SIZE][MAX_SIZE],int size){
	int moves[SIZE_1],count=(size*size),i=0,j=0,available=0,flag=0,index;
	while(count>0){
		while(i<size && flag==0){
			while(j<size && flag==0){
				if(map[i][j]==0){
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
		
		if((j-1>=0) && map[i][j-1]!=-1){
			moves[available]=LEFT_MOVE;
			available++;
		}
		
		if((j+1<size) && map[i][j+1]!=-1){
			moves[available]=RIGHT_MOVE;
			available++;
		}
		
		if((i-1>=0) && map[i-1][j]!=-1){
			moves[available]=UP_MOVE;
			available++;
		}
		
		if((i+1<size) && map[i+1][j]!=-1){
			moves[available]=DOWN_MOVE;
			available++;
		}
		
		index=(rand()%available);
		if(moves[index]==LEFT_MOVE){
			map[i][j]=map[i][j-1];
			map[i][j-1]=0;
		}
		
		else if(moves[index]==RIGHT_MOVE){
			map[i][j]=map[i][j+1];
			map[i][j+1]=0;

		}
		
		else if(moves[index]==UP_MOVE){
			map[i][j]=map[i-1][j];
			map[i-1][j]=0;
		}
		
		else if(moves[index]==DOWN_MOVE){
			map[i][j]=map[i+1][j];
			map[i+1][j]=0;
		}
		i=0;
		j=0;
		available=0;
		flag=0;
		count--;
	}
	return;
}

int final_check(int map[MAX_SIZE][MAX_SIZE],int size){
	int i=0,j=0,number=1,result=1;
	while(i<size){
		if (result==0 || result==-1){
			break;
		}
		while(j<size){
			if(number==((size*size)-1) && number==map[i][j]){
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
	return result;
}
