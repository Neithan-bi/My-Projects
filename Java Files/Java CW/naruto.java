// Parent class
class Person {
    String name;
    int age;
    int mobile;
    
  
    public Person() {
        this.name = "bhuvi";
        this.age = 19;
        this.mobile = 1234567891;
    }

   
    public Person(String name, int age, int mobile) {
        this.name = name;
        this.age = age;
        this.mobile = mobile;
    }

    
    public void display() {
        System.out.println("Name is: " + name + " Age is: " + age + " Mobile: " + mobile);
    }
}

class Employee extends Person {
    String organisation;
    int empid;
    
  
    public Employee(String name, int age, int mobile, String organisation, int empid) {
        super(name, age, mobile);
        this.organisation = organisation;
        this.empid = empid;
    }

    
    public void display1() {
        super.display();
        System.out.println("Organisation: " + organisation + " Empid: " + empid);
    }
}


class Student extends Person {
    String name1;
    int id;
    
  
    public Student(String name1, int id, String name, int age, int mobile) {
        super(name, age, mobile);
        this.name1 = name1;
        this.id = id;
    }

    
    public void display2() {
        super.display();
        System.out.println("Name1: " + name1 + " ID: " + id);
    }
}

public class naruto {
    public static void main(String[] args) {
       
        Person bhuvi = new Person("pintu", 19, 234567);
        bhuvi.display();

        Student s1 = new Student("John", 101, "pintu", 19, 234567);
        s1.display2();
        
       
        Employee e1 = new Employee("Alice", 30, 987654321, "TechCorp", 1001);
        e1.display1();
    }
}

 