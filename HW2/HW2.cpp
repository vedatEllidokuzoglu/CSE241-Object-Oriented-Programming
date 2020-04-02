/*********************************************************************************
 *       HW2_161044098_VEDAT_ELLIDOKUZOGLU.cpp                                   *
 *       CSE 241/501 - Object Oriented Programming Homework-2                    *
 *       Author: Vedat ELLIDOKUZOGLU                                             *
 *       Date: 22.10.2019                                                        *
 *-------------------------------------------------------------------------------*
 * It is an extension C++ N-Puzzle game program problem that programmed at HW1.  *
 * See descriptions from the Homework PDF to see the new extensions.             *
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int space = -1;
const int size1 = 9;
const int size2 = 2;
const int size3 = 4;
const int size4 = 20;
const int max_size = 9;
const int left_move = 0;
const int right_move = 1;
const int up_move = 2;
const int down_move = 3;
const int ascii_constant_1 = 90;
const int ascii_constant_2 = 32;
const int ascii_constant_3 = 48;

int move_left(int map[max_size][max_size],int size_i,int size_j,int status,int flag);
int move_right(int map[max_size][max_size],int size_i,int size_j,int status,int flag);
int move_up(int map[max_size][max_size],int size_i,int size_j,int status,int flag);
int move_down(int map[max_size][max_size],int size_i,int size_j,int status,int flag);
int move_intelligent(int map[max_size][max_size],int size_i,int size_j,int last_move);
int calculate_manhattan_distance(int map[max_size][max_size],int size_i,int size_j);
void fill_initial(int map[max_size][max_size],int size_i,int size_j);
void fill_initial_file(int map[max_size][max_size],int size_i,int size_j);
void print_map(int map[max_size][max_size],int size_i,int size_j,int flag);
void shuffle(int map[max_size][max_size],int size_i,int size_j);
void save(int map[max_size][max_size],int size_i,int size_j);
void load(int map[max_size][max_size],int value[size2]);
int final_check(int map[max_size][max_size],int size_i,int size_j);
int final_check_file(int map[max_size][max_size],int size_i,int size_j);

int move_left(int map[max_size][max_size],int size_i,int size_j,int status,int flag){
	int i=0,j=0,flag_2=0,result=0;
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
			print_map(map,size_i,size_j,flag);
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
int move_right(int map[max_size][max_size],int size_i,int size_j,int status,int flag){
	int i=0,j=0,flag_2=0,result=0;
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
			print_map(map,size_i,size_j,flag);
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
int move_up(int map[max_size][max_size],int size_i,int size_j,int status,int flag){
	int i=0,j=0,flag_2=0,result=0;
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
			print_map(map,size_i,size_j,flag);
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
int move_down(int map[max_size][max_size],int size_i,int size_j,int status,int flag){
	int i=0,j=0,flag_2=0,result=0;
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
			print_map(map,size_i,size_j,flag);
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

int move_intelligent(int map[max_size][max_size],int size_i,int size_j,int flag,int last_move){
	int distances[size3]={-1,-1,-1,-1},i=0,flag_2=1,distance,status,move=0,min,not_available=0;
	if(last_move%2==0 && last_move!=-1){
		last_move++;
	}
	else if(last_move%2==1 && last_move!=-1){
		last_move--;
	}
	status=move_left(map,size_i,size_j,flag_2,flag);
	distance=calculate_manhattan_distance(map,size_i,size_j);
	if(status!=-1){
		move_right(map,size_i,size_j,flag_2,flag);
		distances[left_move]=distance;
	}
	
	status=move_right(map,size_i,size_j,flag_2,flag);
	distance=calculate_manhattan_distance(map,size_i,size_j);
	if(status!=-1){
		move_left(map,size_i,size_j,flag_2,flag);
		distances[right_move]=distance;
	}
	
	status=move_up(map,size_i,size_j,flag_2,flag);
	distance=calculate_manhattan_distance(map,size_i,size_j);
	if(status!=-1){
		move_down(map,size_i,size_j,flag_2,flag);
		distances[up_move]=distance;
	}

	status=move_down(map,size_i,size_j,flag_2,flag);
	distance=calculate_manhattan_distance(map,size_i,size_j);
	if(status!=-1){
		move_up(map,size_i,size_j,flag_2,flag);
		distances[down_move]=distance;
	}
	i=0;
	while(i<size3){
		if (distances[i]==-1){
			not_available++;
		}
		i++;
	}
	if(not_available>=size3-1){
		i=0;
		while(i<size3){
			if(distances[i]!=-1){
				move=i;
				break;
			}
			i++;
		}
		i=0;
	}
	else{
		i=0;
		while(i<size3){
			if(distances[i]!=-1){
				min=distances[i];
				break;
			}
			i++;
		}
		i=0;
	    while(i<size3){
	    	if(i==last_move && i==down_move){
	    		break;
	    	}
	    	else if(i==last_move){
	    		i++;
	    	}
	    	if((min>distances[i] && distances[i]!=-1) || (min==distances[i] && distances[i-1]==-1)){
	    		min=distances[i];
	    		move=i;
	    	}
	    	i++;
	    }
    }

	flag_2=0;
	i=0;
	while(i<4){
		i++;
	}

	if(distances[move]==-1){
		i=0;
		while(distances[i]==-1){
			i++;
		}
		move=i;
	}
	if(move==left_move){
		cout << "Intelligent move chooses L" << endl;
		move_left(map,size_i,size_j,flag_2,flag);
		last_move=left_move;
	}
	if(move==right_move){
		cout << "Intelligent move chooses R" << endl;
		move_right(map,size_i,size_j,flag_2,flag);
		last_move=right_move;
	}
	
	if(move==up_move){
		cout << "Intelligent move chooses U" << endl;
		move_up(map,size_i,size_j,flag_2,flag);
		last_move=up_move;
	}

	if(move==down_move){
		cout << "Intelligent move chooses D" << endl;
		move_down(map,size_i,size_j,flag_2,flag);
		last_move=down_move;
	}
	return last_move;
}

int calculate_manhattan_distance(int map[max_size][max_size],int size_i,int size_j){
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

void fill_initial(int map[max_size][max_size],int size_i,int size_j){
	int i=0,j=0,number=1;
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
	return;
}

void fill_initial_file(int map[max_size][max_size],int size_i,int size_j){
	int temp_map[max_size][max_size],i=0,j=0,number=1;
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
	return;
}

void print_map(int map[max_size][max_size],int size_i,int size_j,int flag){
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
	return;
}

void shuffle(int map[max_size][max_size],int size_i,int size_j){
	int moves[size3],count=(size_i*size_j),i=0,j=0,available=0,flag=0,index;
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

int final_check(int map[max_size][max_size],int size_i,int size_j){
	int i=0,j=0,number=1,result=1;
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
	return result;
}

int final_check_file(int map[max_size][max_size],int size_i,int size_j){
	int temp_map[max_size][max_size],i=0,j=0,number=1,result=1;
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
	return result;
}

void save(int map[max_size][max_size],int size_i,int size_j){
	ofstream file;
	char file_name[size4];
	int i=0,j=0;
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

void load(int map[max_size][max_size],int value[size2]){
	int i=0,j=0,x=0,size_i=0,size_j=0,num;
	ifstream file;
	char file_name[size4],array[size1],c;
	cout << "Enter a file name to load a board from file:";
	cin >> file_name;
	file.open(file_name);
	while(file.get(c)){
		if(c=='\n'){
			size_j++;
			break;
		}
		if(c==' ')
		{
			size_j++;
		}
	}
	file.close();
	file.open(file_name);
	while(file.get(c)){
		if(c==' '){
			size_i++;
		}
	}
	size_i=size_i/(size_j-1);
	file.close();
	file.open(file_name);
	while(file.get(c)){
		if(c!=' ' && c!='\n' && c!='b'){
			array[x]=c;
			x++;
			if(x==size2){
				num=((array[0]-ascii_constant_3)*10)+(array[1]-ascii_constant_3);
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
	value[0]=size_i;
	value[1]=size_j;
	file.close();
	return;
}

int main(int argc, char const *argv[]){
	srand(time(NULL));
	ifstream file;
	int map[size1][size1],value[size2],num,i=0,j=0,x=0,size_i=0,size_j=0,size,status=0,flag_1=1,flag_2=0,flag_3=2,flag_4,total_move=0,result,last_move=-1,distance,random_number,t;
	char array[size1],c,move;
	if(argv[1]==NULL){
		flag_4=0;
		cout << "Please enter the problem size" << endl;
		cin >> size;
		size_i=size;
		size_j=size;
		fill_initial(map,size_i,size_j);
		cout << "Your initial random board is" << endl;
		shuffle(map,size_i,size_j);
		print_map(map,size_i,size_j,flag_4);
	}
	else{
		flag_4=1;
		file.open(argv[1]);
		while(file.get(c)){
			if(c=='\n'){
				size_j++;
				break;
			}
			if(c==' ')
			{
				size_j++;
			}
		}
		file.close();
		file.open(argv[1]);
		while(file.get(c)){
			if(c==' '){
				size_i++;
			}
		}
		size_i=size_i/(size_j-1);
		file.close();
		file.open(argv[1]);
		while(file.get(c)){
			if(c!=' ' && c!='\n' && c!='b'){
				array[x]=c;
				x++;
				if(x==size2){
					num=((array[0]-ascii_constant_3)*10)+(array[1]-ascii_constant_3);
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

		i=0;j=0;
		print_map(map,size_i,size_j,flag_4);
		file.close();	
	}
	while(true){
		if(status==flag_1 || status==flag_3){
			break;
		}
		cout << "Your move: ";
		cin >> move;
		if(move>ascii_constant_1){
			move-=ascii_constant_2;
		}
		switch(move){
			case 'L':	result=move_left(map,size_i,size_j,flag_2,flag_4);
						if(result==0){
							total_move++;
						}
						if(flag_4==1){
							result=final_check_file(map,size_i,size_j);
						}
						else{
							result=final_check(map,size_i,size_j);
						}
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;
			case 'R':	result=move_right(map,size_i,size_j,flag_2,flag_4);
						if(result==0){
							total_move++;
						}
						if(flag_4==1){
							result=final_check_file(map,size_i,size_j);
						}
						else{
							result=final_check(map,size_i,size_j);
						}
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;
			case 'U':	result=move_up(map,size_i,size_j,flag_2,flag_4);
						if(result==0){
							total_move++;
						}
						if(flag_4==1){
							result=final_check_file(map,size_i,size_j);
						}
						else{
							result=final_check(map,size_i,size_j);
						}
						if(result==0){
							status=flag_3;
						}
						last_move=-1;
						break;
			case 'D':	result=move_down(map,size_i,size_j,flag_2,flag_4);
						if(result==0){
							total_move++;
						}
						if(flag_4==1){
							result=final_check_file(map,size_i,size_j);
						}
						else{
							result=final_check(map,size_i,size_j);
						}
						if(result==0){
							status=flag_3;
							break;
						}
						last_move=-1;
						break;
			case 'I':	last_move=move_intelligent(map,size_i,size_j,flag_4,last_move);
						total_move++;
						if(flag_4==1){
							result=final_check_file(map,size_i,size_j);
						}
						else{
							result=final_check(map,size_i,size_j);
						}
						if(result==0){
							status=flag_3;
						}
						break;
			case 'S':	cout << "Initial Board:" << endl;
						if(flag_4==1){
							fill_initial_file(map,size_i,size_j);
							print_map(map,size_i,size_j,flag_4);
							shuffle(map,size_i,size_j);
						}
						else{
								fill_initial(map,size_i,size_j);
								print_map(map,size_i,size_j,flag_4);
								shuffle(map,size_i,size_j);
						}
						cout << "Shuffled Board:" << endl;
						print_map(map,size_i,size_j,flag_4);
						result=1;
						break;
			case 'Q':	cout << "You quitted the game!" << endl;
						status=flag_1;
						break;
			
			case 'V':	i=1;
						while(true){
							total_move++;
							last_move=move_intelligent(map,size_i,size_j,flag_4,last_move);
							distance=calculate_manhattan_distance(map,size_i,size_j);
							if(i%20==0){
								t=distance/size_j/2;
								cout <<"t: " << t << "distance: " << distance << endl;
								while(t>0){
									total_move++;
									random_number=rand()%size3;
									if(random_number==left_move){
										move_left(map,size_i,size_j,1,flag_4);
										if(flag_4==1){
											result=final_check_file(map,size_i,size_j);
										}
										else{
											result=final_check(map,size_i,size_j);
										}
										if(result==0){
											status=flag_3;
											break;
										}
									}
									if(random_number==right_move){
										move_right(map,size_i,size_j,1,flag_4);
										if(flag_4==1){
											result=final_check_file(map,size_i,size_j);
										}
										else{
											result=final_check(map,size_i,size_j);
										}
										if(result==0){
											status=flag_3;
											break;
										}
									}
									if(random_number==up_move){
										move_up(map,size_i,size_j,1,flag_4);
										if(flag_4==1){
											result=final_check_file(map,size_i,size_j);
										}
										else{
											result=final_check(map,size_i,size_j);
										}
										if(result==0){
											status=flag_3;
											break;
										}
									}
									if(random_number==down_move){
										move_down(map,size_i,size_j,1,flag_4);
										if(flag_4==1){
											result=final_check_file(map,size_i,size_j);
										}
										else{
											result=final_check(map,size_i,size_j);
										}
										if(result==0){
											status=flag_3;
											break;
										}
									}
									t--;
								}
							}
							if(flag_4==1){
								result=final_check_file(map,size_i,size_j);
							}
							else{
								result=final_check(map,size_i,size_j);
							}
							if(result==0){
								status=flag_3;
								break;
							}
							i++;
						}
						break;
			case 'T':	cout << total_move << " moves have been done." << endl;
						result=final_check(map,size_i,size_j);
						if(result==0){
							cout << "Problem has been solved!" << endl;
							break;
						}
						else{
							cout << "Problem has not been solved" << endl;
						}
						print_map(map,size_i,size_j,flag_4);
						break;
			case 'E':	save(map,size_i,size_j);
						total_move++;
						break;
			case 'Y':	load(map,value);
						size_i=value[0];
						size_j=value[1];
						flag_4=1;
						print_map(map,size_i,size_j,flag_4);
						total_move++;
						break;
			
		}
	}
	if(status==flag_3){
		cout << "Problem Solved!" << endl;
		cout << "Total number of moves " << total_move << endl;
	}
	
	return 0;
}
