class Employee {
    String name;
    int age;
    String ph_no;
    String address;
    double salary;
    
    Employee(String name, int age, String ph_no, String address, double salary) {
        this.name = name;
        this.age = age;
        this.ph_no = ph_no;
        this.address = address;
        this.salary = salary;
    }

    public void printSalary() {
        System.out.println("Salary = "+salary);
    }

    public void printDetails() {
        System.out.println("Name = "+name);
        System.out.println("Age = "+age);
        System.out.println("Phone Number = "+ph_no);
        System.out.println("Address = "+address);
    }
}

class Officer extends Employee {
    String specialization;
    Officer(String name, int age, String ph_no, String address, double salary, String specialization) {
        super(name, age, address, ph_no, salary);
        this.specialization = specialization;
    }

    public void printSpecilization() {
        System.out.println("Speciliazation = "+specialization);
    }
}

class Manager extends Employee {
    String department;
    Manager(String name, int age, String ph_no, String address, double salary, String department) {
        super(name, age, address, ph_no, salary);
        this.department = department;
    }
    public void printDepartment() {
        System.out.println("Department = "+department);
    }
}

class EmployeeTest {
    public static void main(String[] args) {
        Officer officer1 = new Officer("Alice",22,"9046723104","Kochi",500000,"BTech");
        System.out.println("\nOfficer Details...");
        officer1.printDetails();
        officer1.printSalary();
        officer1.printSpecilization();

        Manager manager1 = new Manager("Bob",24,"8047643409","Kalady",600000,"CSE");
        System.out.println("\nManager Details...");
        manager1.printDetails();
        manager1.printSalary();
        manager1.printDepartment();
    }
}
