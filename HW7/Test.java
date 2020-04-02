import java.io.FileNotFoundException;
import java.util.Scanner;

public class Test{
    public static void test_1D(){
        int i=0,j=0,status=0,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4=0,size_i=0,size_j=0;
        AbstractBoard a= new BoardArray1D();
        AbstractBoard b= new BoardArray1D();
        System.out.println("BoardArray1D TEST");
        size_i=a.setSize(size_i,size_j);
        size_j=size_i;
        a.reset(0,size_i,size_j);
        b.reset(0,size_i,size_j);
        System.out.println("INITIAL BOARD:");
        a.print(1);
        System.out.println("MOVE TEST:");
        a.move('R',0,0);
        a.move('L',0,0);
        a.move('U',0,0);
        a.move('D',0,0);
        System.out.println("isSolved TEST:");
        System.out.println("----------------");
        result=a.isSolved(flag_4,0);
        a.move('R',0,0);
        result=a.isSolved(flag_4,0);
        a.move('L',1,0);
        System.out.println("EQUALS FUNC. TEST:");
        System.out.println("----------------");
        System.out.println("FIRST BOARD");
        a.print(1);
        System.out.println("SECOND BOARD");
        b.print(1);
        if(a.Equals(b)){
            System.out.println("Return=TRUE");
            System.out.println("----------------");
        }
        else{
            System.out.println("Return=FALSE");
            System.out.println("----------------");
        }
        a=b;
        System.out.println("FIRST BOARD");
        a.print(1);
        System.out.println("SECOND BOARD");
        b.print(1);
        if(a.Equals(b)){
            System.out.println("Return=TRUE");
            System.out.println("----------------");
        }
        else{
            System.out.println("Return=FALSE");
            System.out.println("----------------");
        }
        System.out.println("CELL FUNC. TEST:");
        System.out.println("----------------");
        a.print(1);
        System.out.println("for x=0 y=0");
        System.out.println(String.valueOf(a.cell(0,0)));
        System.out.println("----------------");
        System.out.println("WRITE TEST:");
        System.out.println("----------------");
        a.writeToFile();
        System.out.println("Board has been written successfully to text file.");
        System.out.println("----------------");
    }


    public static void test_2D(){
        int i=0,j=0,status=0,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4=0,size_i=0,size_j=0;
        AbstractBoard a= new BoardArray2D();
        AbstractBoard b= new BoardArray2D();
        System.out.println("BoardArray2D TEST");
        size_i=a.setSize(size_i,size_j);
        size_j=size_i;
        a.reset(0,size_i,size_j);
        b.reset(0,size_i,size_j);
        System.out.println("INITIAL BOARD:");
        a.print(1);
        System.out.println("MOVE TEST:");
        a.move('R',0,0);
        a.move('L',0,0);
        a.move('U',0,0);
        a.move('D',0,0);
        System.out.println("isSolved TEST:");
        System.out.println("----------------");
        result=a.isSolved(flag_4,0);
        a.move('R',0,0);
        result=a.isSolved(flag_4,0);
        a.move('L',1,0);
        System.out.println("EQUALS FUNC. TEST:");
        System.out.println("----------------");
        System.out.println("FIRST BOARD");
        a.print(1);
        System.out.println("SECOND BOARD");
        b.print(1);
        if(a.Equals(b)){
            System.out.println("Return=TRUE");
            System.out.println("----------------");
        }
        else{
            System.out.println("Return=FALSE");
            System.out.println("----------------");
        }
        a=b;
        System.out.println("FIRST BOARD");
        a.print(1);
        System.out.println("SECOND BOARD");
        b.print(1);
        if(a.Equals(b)){
            System.out.println("Return=TRUE");
            System.out.println("----------------");
        }
        else{
            System.out.println("Return=FALSE");
            System.out.println("----------------");
        }
        System.out.println("CELL FUNC. TEST:");
        System.out.println("----------------");
        a.print(1);
        System.out.println("for x=0 y=0");
        System.out.println(String.valueOf(a.cell(0,0)));
        System.out.println("----------------");
        System.out.println("WRITE TEST:");
        System.out.println("----------------");
        a.writeToFile();
        System.out.println("Board has been written successfully to text file.");
        System.out.println("----------------");
    }







    /**
     * @param args
     * @throws FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException {
        int i=0,j=0;
        int selection=0,status=0,glb,result,last_move=-1,flag_1=1,flag_2=0,flag_3,flag_4,size_i,size_j;
        boolean validty;

        AbstractBoard []arr=new AbstractBoard[3];
        AbstractBoard a= new BoardArray1D(3,3);
        AbstractBoard b= new BoardArray1D(3,3);
        AbstractBoard c= new BoardArray1D(3,3);
        AbstractBoard x= new BoardArray2D();
        AbstractBoard y= new BoardArray2D();
        AbstractBoard z= new BoardArray2D();
        while(selection!=4){
            System.out.println("Please Select a Test:");
            System.out.println("1) BoardArray1D");
            System.out.println("2) BoardArray2D");
            System.out.println("3) Global Function");
            System.out.println("4) Exit");
            Scanner in = new Scanner(System.in);
            selection=in.nextInt();
            switch(selection){
                case 1:{
                    test_1D();
                    break;
                }
                case 2:{
                    test_2D();
                    break;
                }
                case 3:{
                    System.out.println("Select for Global Function:");
                    System.out.println("1) BoardArray1D");
                    System.out.println("2) BoardArray2D");
                    in = new Scanner(System.in);
                    glb=in.nextInt();
                    switch(glb){
                        case 1:{
                            b.move('L',1,0);
                            a.move('L',1,0);
                            a.move('U',1,0);
                            arr[0]=a;
                            arr[1]=b;
                            arr[2]=c;
                            validty=global_function(arr,3);
                            if(validty==true){
                                System.out.println("GLOBAL FUNTION: True");
                                System.out.println("");
                            }
                            else if(validty==false){
                                System.out.println("GLOBAL FUNTION: False");
                                System.out.println("");
                            }
                            a.move('U',1,0);
                            validty=global_function(arr,3);
                            if(validty==true){
                                System.out.println("GLOBAL FUNTION: True");
                                System.out.println("");
                            }
                            else if(validty==false){
                                System.out.println("GLOBAL FUNTION: False");
                                System.out.println("");
                            }
                            break;
                        }
                        case 2:{
                            y.move('L',1,0);
                            x.move('L',1,0);
                            x.move('U',1,0);
                            arr[0]=x;
                            arr[1]=y;
                            arr[2]=z;
                            validty=global_function(arr,3);
                            if(validty==true){
                                System.out.println("GLOBAL FUNTION: True");
                                System.out.println("");
                            }
                            else if(validty==false){
                                System.out.println("GLOBAL FUNTION: False");
                                System.out.println("");
                            }
                            x.move('U',1,0);
                            validty=global_function(arr,3);
                            if(validty==true){
                                System.out.println("GLOBAL FUNTION: True");
                                System.out.println("");
                            }
                            else if(validty==false){
                                System.out.println("GLOBAL FUNTION: False");
                                System.out.println("");
                            }
                            break;
                        }
                    }
                    break;
                }
                case 4:{
                    break;
                }
            }
        }
    }

    /**
     * returns true if the array contains a valid sequence of moves for a solution
     * @param Board is an Abstract array
     * @param size times to test
     * @return boolean
     */
    public static boolean global_function(AbstractBoard Board[],int size){
        int i=0,x=0,y=0,space_flag=1,space=-1,size_x=Board[i].get_size(0),size_y=Board[i].get_size(1);
        boolean status=true;
        while(i<size){
            Board[i].print(1);
            i++;
        }
        i=0;
        while(i<size-1 && status==true){
            while(x<size_x && space_flag==1){
                while(y<size_y && space_flag==1){
                    if(Board[i].cell(x,y)==space){
                        space_flag=0;
                        break;
                    }
                    y++;
                }
                if(space_flag==1){
                    y=0;
                    x++;
                }
            }
            space_flag=1;
            if(Board[i+1].cell(x+1,y)==space || Board[i+1].cell(x,y+1)==space || Board[i+1].cell(x-1,y)==space || Board[i+1].cell(x,y-1)==space){
                i++;
            }
            else{
                status=false;
                break;
            }
        }
        return status;
    }
}

