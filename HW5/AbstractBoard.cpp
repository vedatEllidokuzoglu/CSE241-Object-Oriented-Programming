#include "AbstractBoard.h"

namespace HW5_161044098{
	char AbstractBoard::lastMove(){
		return last_move;
	}
	int AbstractBoard::numberOfMoves(){
		return total_move;
	}
	void AbstractBoard::setter_last_move(char temp_last_move){
		last_move=temp_last_move;
		return;
	}
	void AbstractBoard::setter_total_move(int temp_total_move){
		total_move=temp_total_move;
		return;
	}
	bool AbstractBoard::operator==(const AbstractBoard &solution){}
}