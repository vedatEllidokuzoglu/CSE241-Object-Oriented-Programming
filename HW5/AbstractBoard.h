#ifndef ABSTRACTBOARD_H_
#define ABSTRACTBOARD_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>

using namespace std;

namespace HW5_161044098{
	class AbstractBoard{
	private:
		char last_move;
		int total_move;
	public:
		virtual void print(int flag)=0;
		virtual void readFromFile(char file_name[20])=0;
		virtual void writeToFile()=0;
		virtual void reset(int flag,int size_i,int size_j)=0;
		virtual void setsize(int &size_i,int &size_j)=0;
		virtual int move(char move,int status,int flag_1)=0;
		virtual int isSolved(int flag, int status)=0;
		virtual int l(int i,int j)=0;
		virtual int operator()(int i,int j)=0;
		virtual bool operator==(const AbstractBoard &solution);
		virtual int NumberOfBoards(int size)=0;
		virtual char lastMove();
		virtual int numberOfMoves();
		void setter_last_move(char temp_last_move); 
		void setter_total_move(int temp_total_move); 
		virtual int get_size(int iORj)=0;

	};
}

#endif