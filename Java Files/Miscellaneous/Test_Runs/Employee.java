
import java.util.*; 
class Employee {

    int ID, Salary;
    String FirstName, LastName;
    static Scanner in = new Scanner(System.in);
    public int getID() {
        return ID;
    }
    public String getFirstName() {
        return FirstName;
    }
    public String getLastName() {
        return LastName;
    }
    public int getSalary() {
        return Salary;
    }

    public int raiseSalary(int percent){
        Salary += percent;
        return Salary;

    }
    
}

