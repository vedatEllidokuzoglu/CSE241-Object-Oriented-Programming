import java.io.FileNotFoundException;

public abstract class AbstractBoard {
    private static char last_move='S';
    private static int total_move=0;
    private static int numberofboards=0;

    public abstract void readFromFile() throws FileNotFoundException;
    public abstract void writeToFile();
    public abstract void reset(int flag,int size_i,int size_j);
    public abstract int setSize(int size_i,int size_j);
    public abstract int move(char move,int status,int flag_1);
    public abstract int isSolved(int flag, int status);
    public abstract int cell(int i,int j);
    public abstract boolean Equals(AbstractBoard a);
    public abstract String toString();
    public abstract int get_size(int iORj);
    public abstract void print(int flag);
    public int NumberOfBoards() {
        return numberofboards;
    }
    public char lastMove() {
        return last_move;
    }
    public int numberOfMoves() {
        return total_move;
    }
    public void setter_last_move(char temp_last_move){
        last_move=temp_last_move;
        return;
    }
    public void setter_total_move(int move){
        total_move+=move;
        return;
    }
}
