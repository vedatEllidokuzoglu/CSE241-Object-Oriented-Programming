#ifndef BOARDVECTOR_H_
#define BOARDVECTOR_H_

#include "AbstractBoard.h"

namespace HW5_161044098{
	class BoardVector : public AbstractBoard{
	private:
		vector<vector<int>> map;
	public:
		BoardVector();
		BoardVector(int size_i, int size_j);
		BoardVector(const BoardVector& board);
		void print(int flag);
		void readFromFile(char file_name[20]);
		void writeToFile();
		void reset(int flag,int size_i,int size_j);
		void setsize(int &size_i,int &size_j);
		int move(char move,int status,int flag_1);
		int isSolved(int flag, int status);
		int l(int i,int j);
		int operator()(int i,int j);
		bool operator==(const BoardVector &solution);
		int NumberOfBoards(int size);
		int get_size(int iORj);

	};
}

#endif