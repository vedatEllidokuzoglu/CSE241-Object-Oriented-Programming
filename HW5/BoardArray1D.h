#ifndef BOARDARRAY1D_H_
#define BOARDARRAY1D_H_

#include "AbstractBoard.h"

namespace HW5_161044098{
	class BoardArray1D : public AbstractBoard{
	private:
		int size_x;
		int size_y;
		int *map;
	public:
		BoardArray1D();
		BoardArray1D(BoardArray1D& board);
		void print(int flag);
		void readFromFile(char file_name[20]);
		void writeToFile();
		void reset(int flag,int size_i,int size_j);
		void setsize(int &size_i,int &size_j);
		int move(char move,int status,int flag_1);
		int isSolved(int flag, int status);
		int l(int i,int j);
		int operator()(int i,int j);
		BoardArray1D& operator=(const BoardArray1D& solution);
		bool operator==(const BoardArray1D &solution);
		int NumberOfBoards(int size);
		int get_size(int iORj);
		~BoardArray1D();
	};
}

#endif