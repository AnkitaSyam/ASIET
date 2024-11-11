class Student {
    int id;
    String name;
    String dept;

    Student(int id, String name, String dept) {
        this.id = id;
        this.name = name;
        this.dept = dept;
    }   
    
}

public class GCTest {
    public static void main(String[] args) {
        Student s1 = new Student(21, "Bob", "CSE");
        s1 = null; //Make the object eligible for garbage collection
        System.gc(); //Request garbage collection

        try {
            Thread.sleep(1000); //Give garbage collector some time to run
        } catch (Exception e) {
        }
        System.out.println("Delete Student Class");
    }
}
