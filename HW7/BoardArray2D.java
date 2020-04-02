import java.io.*;
import java.util.Scanner;

public class BoardArray2D extends AbstractBoard {
    private int size_x;
    private int size_y;
    private int [][] map;
    public BoardArray2D(){
        int max_size=3;
        int i=0,j=0,number=1;
        map= new int[max_size][max_size];
        while(i<max_size){
            while(j<max_size){
                if(number==(max_size*max_size)){
                    map[i][j]=-1;
                    break;
                }
                map[i][j]=number;
                j++;
                number++;
            }
            j=0;
            i++;
        }
        setter_last_move('S');
        setter_total_move(0);
        size_x=3;
        size_y=3;
    }

    public BoardArray2D(int size_i,int size_j){
        int max_size=size_i;
        int i=0,j=0,number=1;
        map= new int[size_i][size_j];
        while(i<size_i){
            while(j<size_j){
                if(number==(size_i*size_j)){
                    map[i][j]=-1;
                    break;
                }
                map[i][j]=number;
                j++;
                number++;
            }
            j=0;
            i++;
        }
        setter_last_move('S');
        setter_total_move(0);
        size_x=3;
        size_y=3;
    }

    public BoardArray2D(BoardArray2D board){
        int max_size=9;
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

    /**
     * Reading from file with BufferedReader
     * @throws FileNotFoundException
     *
     */
    @Override
    public void readFromFile() throws FileNotFoundException {
        int i=0,j=0,x=0,y=0;
        String name="";
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a file name for reading with .txt");
        name = sc.nextLine();
        File f=new File(String.valueOf(name));     //Creation of File Descriptor for input file
        FileReader fr=new FileReader(f);   //Creation of File Reader object
        BufferedReader br=new BufferedReader(fr);  //Creation of BufferedReader object
        int c = 0;
        while(true)         //Read char by Char
        {
            try {
                if (!((c = br.read()) != -1)) break;
            } catch (IOException e) {
                e.printStackTrace();
            }
            char character = (char) c;          //converting integer to char
            if (character!='b'&&character!=' '){
                int num = Character.getNumericValue(character);
                if (num!=-1){
                    map[i][j]=num;
                    j++;
                }
            }
            if (character=='\n'){
                i++;
                j=0;
            }
            if (character=='b'){
                map[i][j]=-1;
                j++;
                try {
                    c=br.read();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }
        size_x=i+1;
        size_y=j;
    }

    /**
     * Writing to file
     */
    @Override
    public void writeToFile() {
        int i=0,j=0;
        String s="";
        Scanner sc = new Scanner(System.in);
        StringBuilder builder = new StringBuilder();
        for( i = 0; i < size_x; i++)//for each row
        {
            for(j = 0; j < size_y; j++)//for each column
            {
                if (map[i][j]<10 && map[i][j]>0) {
                    builder.append("0"+map[i][j] + "");//append to the output string
                }
                else if(map[i][j]==-1){
                    builder.append("bb");
                }
                else
                    builder.append(map[i][j] + "");

                if(j < size_y - 1)//if this is not the last row element
                     builder.append(" ");
            }
            if (i!=size_x-1)
                builder.append("\n");//append new line at the end of the row
        }
        System.out.println("Enter a file name");
        s = sc.nextLine();
        BufferedWriter writer = null;
        try {
            writer = new BufferedWriter(new FileWriter(s));
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            writer.write(builder.toString());//save the string representation of the board
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Resets the Map
     * @param flag
     * @param size_i
     * @param size_j
     */
    @Override
    public void reset(int flag,int size_i,int size_j) {
        int max_size=9;
        int i=0,j=0,number=1;
        size_x=size_i;
        size_y=size_j;
        if(flag==0){
            map= new int[size_x][size_y];
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
            setter_last_move('S');
            setter_total_move(0);
        }
        else if(flag==1){
            while(i<size_i){
                while(j<size_j){
                    if((i*j)==(size_i-1)*(size_j-1)){
                        map[i][j]=-1;
                        break;
                    }
                    if(map[i][j]==0){
                        map[i][j]=0;
                    }
                    else{
                        map[i][j]=number;
                        number++;
                    }
                    j++;
                }
                j=0;
                i++;
            }
            i=0;
            j=0;
            number=1;
            setter_last_move('S');
            setter_total_move(0);
        }
        return;
    }

    /**
     * Sets the size of the map.
     * @param size_i
     * @param size_j
     */
    @Override
    public int setSize(int size_i,int size_j) {
        int size;
        /*Getting size from user and checking*/
        do{
            System.out.println("Please enter the problem size:");
            Scanner in = new Scanner(System.in);
            size=in.nextInt();
            if (size<3 || size>9)
            {
                System.out.println("Error. Invalid size. Try again.");
            }
        }while(size<3 || size>9);
        size_i=size;
        size_j=size;
        size_x=size;
        size_y=size;
        reset(0,size,size);
        return size;
    }

    /**
     * Moves the space which is "bb"
     * @param move can be 'L','R','U' or 'D'
     * @param status flag for another (test) situation
     * @param flag_1 controls whether or not to prints move.
     * @return
     */
    @Override
    public int move(char move,int status,int flag_1) {
        int space=-1;
        int i=0,j=0,flag_2=0,result=0,temp_total_move;
        int size_i=size_x,size_j=size_y;
        flag_1=1;
        if(status==0) System.out.println("MOVE="+String.valueOf(move));
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
                    System.out.println("Invalid move!");
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
                    System.out.println("Invalid move!");
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
                    System.out.println("Invalid move!");
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
                    System.out.println("Invalid move!");
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
    /**
     * Checks the board if it is solved or not
     * @param flag controls whether or not to prints something.
     * @param status flag for another (test) situation
     * @return
     */
    @Override
    public int isSolved(int flag, int status) {
        int max_size=9;
        BoardArray2D solution=new BoardArray2D();
        BoardArray2D current=new BoardArray2D();
        int i=0,j=0,number=1,result=1,temp_total_move;
        int size_i=size_x,size_j=size_y;
        solution.size_x=get_size(0);
        solution.size_y=get_size(1);
        current.size_x=get_size(0);
        current.size_y=get_size(1);
        solution.map=new int[size_x][size_y];
        current.map=new int[size_x][size_y];
        if(flag==0){
            while(i<size_i){
                while(j<size_i){
                    if(number==(size_i*size_j)){
                        solution.map[i][j]=-1;
                        break;
                    }
                    solution.map[i][j]=number;
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
                        solution.map[i][j]=-1;
                        break;
                    }
                    if(map[i][j]==0){
                        solution.map[i][j]=0;
                    }
                    else{
                        solution.map[i][j]=number;
                        number++;
                    }
                    j++;
                }
                j=0;
                i++;
            }
        }
        i=0;
        j=0;
        while(i<size_i){
            while(j<size_j){
                current.map[i][j]=map[i][j];
                j++;
            }
            j=0;
            i++;
        }
        if(current.Equals(solution)){
            result=0;
        }
        temp_total_move=numberOfMoves();
        if(result==0 && status!=1){
            System.out.println("Problem Solved!");
            System.out.println("");
        }
        else{
            System.out.println("Problem has not been solved");
            System.out.println("");
        }
        return result;
    }
    /**
     * Takes two indexes and returns the corresponding cell content.
     * @param i for index of i
     * @param j for index of j
     * @return
     */
    @Override
    public int cell(int i,int j) {
        int invalid=-2;
        if(i<0 || i>size_x-1 || j<0 || j>size_y-1){
            return invalid;
        }
        return map[i][j];
    }
    /**
     * Two boards are equal, if the boards are the same.
     * @param o1 other board
     * @return
     */
    @Override
    public boolean Equals(AbstractBoard o1) {
        BoardArray2D o2 =(BoardArray2D) o1;
        int i=0,j=0;
        for(i=0;i<size_x;i++){
            for(j=0;j<size_y;j++){
                if (this.map[i][j]!=o2.map[i][j])
                    return false;
            }
        }
        return true;
    }
    /**
     * Printing map
     */
    @Override
    public void print(int flag) {
        int space=-1;
        int i=0,j=0;
        int size_i=size_x,size_j=size_y;
        while(i<size_i){
            while(j<size_j){
                if(flag==0){
                    if(map[i][j]==space){
                        System.out.print("   ");
                    }
                    else{
                        if (map[i][j]<10)
                        {
                            System.out.print(" "+String.valueOf(map[i][j])+" ");
                        }
                        else{
                            System.out.print(String.valueOf(map[i][j])+" ");
                        }

                    }
                }
                else{
                    if(map[i][j]==space){
                        System.out.print("bb ");
                    }
                    else{
                        if (map[i][j]<10)
                        {
                            System.out.print("0" + String.valueOf(map[i][j]) + " ");
                        }
                        else{
                            System.out.print(String.valueOf(map[i][j]) + " ");
                        }

                    }
                }
                j++;
            }
            System.out.println();
            j=0;
            i++;
        }
        System.out.println();
        return;
    }
    /**
     * Produces the board as string
     * @return string
     */
    @Override
    public String toString() {
        int i=0,j=0;
        String arr="";
       for(i=0;i<size_x;i++){
            for (j=0;j<size_y;j++){
                if (map[i][j]==-1)
                    arr+="bb ";
                else
                    arr=arr+map[i][j]+" ";
            }
        };
        System.out.println(arr);
       return null;
    }
    /**
     * @param iORj if its equals to 0 it returns size_x, else if its equals to 1 it returns size_y of the board.
     * @return
     */
    @Override
    public int get_size(int iORj) {
        int size=0;
        if(iORj==0){
            size=size_x;
        }
        else if(iORj==1){
            size=size_y;
        }
        return size;
    }
}
