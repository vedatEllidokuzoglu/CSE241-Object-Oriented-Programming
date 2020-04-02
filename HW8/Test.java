
public class Test {
    public static void main(String[] args) {
        GTUSet<String> set = new GTUSet<>();
        GTUVector<Integer> test_vector = new GTUVector<>();
        System.out.println("----------SET TEST----------");
        System.out.println("-----EMPTY TEST:-----");
        if(set.empty()==true) {
            System.out.println("SET is empty.");
            System.out.println("");
        }
        else {
            System.out.println("SET is not empty.");
            System.out.println("");
        }
        System.out.println("-----SIZE TEST:-----");
        System.out.println("SET SIZE = " + set.size());
        System.out.println("");
        System.out.println("-----MAX SIZE TEST:-----");
        System.out.println("");
        System.out.println("SET MAX SIZE = " + set.max_size());
        System.out.println("");
        System.out.println("Inserting the names of the instructors to SET:");
        System.out.println("");
        set.insert("Muhammet Ali");
        set.insert("Yusuf Sinan");
        set.insert("Erdoğan");
        set.insert("Yakup");
        set.insert("Erkan");
        set.insert("Zafeirakis");
        set.insert("Burcu");
        set.insert("Mehmet Burak");
        set.insert("Rasih");
        set.insert("Samet");
        set.insert("Gökhan");
        System.out.println("After adding elements to SET:");
        System.out.println("");
        System.out.println("-----INSERT & BEGIN & END TEST:-----");
        System.out.println("SET Elements:");
        GTUIterator it1 = set.iterator();
        while(it1.hasNext())
        {
            System.out.println(it1.next() + " ");
        }
        it1 = set.iterator();
        System.out.println("");
        System.out.println("-----EMPTY TEST:-----");
        if(set.empty()==true) {
            System.out.println("SET is empty.");
            System.out.println("");
        }
        else {
            System.out.println("SET is not empty.");
            System.out.println("");
        }
        System.out.println("-----SIZE TEST:-----");
        System.out.println("SET SIZE = "+set.size());
        System.out.println("");
        System.out.println("-----ERASE TEST:-----");
        System.out.println("Erasing names of Burcu & Yusuf Sinan from the SET:");
        set.erase("Burcu");
        set.erase("Yusuf Sinan");
        System.out.println("SET Elements:");
        it1 = set.iterator();
        while(it1.hasNext())
        {
            System.out.println(it1.next() + " ");
        }
        it1 = set.iterator();
        System.out.println("");
        System.out.println("-----SIZE TEST:-----");
        System.out.println("SET SIZE = "+set.size());
        System.out.println("");
        System.out.println("-----CLEAR TEST:-----");
        System.out.println("Clearing all elements of SET");
        System.out.println("SET Elements:");

        set.clear();
        it1 = set.iterator();
        while(it1.hasNext())
        {
            System.out.println(it1.next() + " ");
        }
        it1 = set.iterator();
        System.out.println("");
        System.out.println("-----EMPTY TEST:-----");
        if(set.empty()==true) {
            System.out.println("SET is empty.");
            System.out.println("");
        }
        else {
            System.out.println("SET is not empty.");
            System.out.println("");
        }
        System.out.println("-----SIZE TEST:-----");
        System.out.println("SET SIZE = "+set.size());
        System.out.println("-----MAX SIZE TEST:-----");
        System.out.println("SET MAX SIZE= " + set.max_size());
        System.out.println("");
        System.out.println("----------------------------------------------------------------------------------------------------");
        System.out.println("");



        System.out.println("----------VECTOR TEST----------");
        System.out.println("-----EMPTY TEST:-----");
        if(test_vector.empty()==true) {
            System.out.println("VECTOR is empty.");
            System.out.println("");
        }
        else {
            System.out.println("VECTOR is not empty.");
            System.out.println("");
        }
        System.out.println("-----SIZE TEST:-----");
        System.out.println("VECTOR SIZE = "+test_vector.size());
        System.out.println("");
        System.out.println("-----MAX SIZE TEST:-----");
        System.out.println("");
        System.out.println("VECTOR MAX SIZE = "+test_vector.max_size());
        System.out.println("");
        System.out.println("Inserting integers (10,20,30,40,50,2,8,3,9,0,5) to VECTOR:");
        test_vector.insert(10);
        test_vector.insert(20);
        test_vector.insert(30);
        test_vector.insert(40);
        test_vector.insert(50);
        test_vector.insert(2);
        test_vector.insert(8);
        test_vector.insert(3);
        test_vector.insert(9);
        test_vector.insert(0);
        test_vector.insert(5);
        System.out.println("After adding elements to VECTOR:");
        System.out.println("");
        System.out.println("-----INSERT & BEGIN & END TEST:-----");
        System.out.println("VECTOR Elements:");
        GTUIterator it2 = test_vector.iterator();
        while(it2.hasNext())
        {
            System.out.println(it2.next() + " ");
        }
        it2 = test_vector.iterator();
        System.out.println("");
        System.out.println("-----EMPTY TEST:-----");

        if(test_vector.empty()==true) {
            System.out.println("VECTOR is empty.");
            System.out.println("");
        }
        else {
            System.out.println("VECTOR is not empty.");
            System.out.println("");
        }
        System.out.println("-----SIZE TEST:-----");
        System.out.println("VECTOR SIZE = "+test_vector.size());
        System.out.println("");
        System.out.println("-----ERASE TEST:-----");
        System.out.println("Erasing numbers of 10 & 0 from the VECTOR:");
        test_vector.erase(10);
        test_vector.erase(0);
        System.out.println("VECTOR Elements:");
        it2 = test_vector.iterator();
        while(it2.hasNext())
        {
            System.out.println(it2.next() + " ");
        }
        it2 = test_vector.iterator();
        System.out.println("");
        System.out.println("-----SIZE TEST:-----");
        System.out.println("VECTOR SIZE = "+test_vector.size());
        System.out.println("");
        System.out.println("-----CLEAR TEST:-----");
        System.out.println("Clearing all elements of VECTOR");
        test_vector.clear();
        System.out.println("VECTOR Elements:");
        it2 = test_vector.iterator();
        while(it2.hasNext())
        {
            System.out.println(it2.next() + " ");
        }
        it2 = test_vector.iterator();
        System.out.println("");

        System.out.println("-----EMPTY TEST:-----");
        if(test_vector.empty()==true) {
            System.out.println("VECTOR is empty.");
            System.out.println("");
        }
        else {
            System.out.println("VECTOR is not empty.");
            System.out.println("");
        }
        System.out.println("-----SIZE TEST:-----");
        System.out.println("VECTOR SIZE = "+test_vector.size());
        System.out.println("");
        System.out.println("-----MAX SIZE TEST:-----");
        System.out.println("VECTOR MAX SIZE= "+test_vector.max_size());
        System.out.println("");
    }
}
