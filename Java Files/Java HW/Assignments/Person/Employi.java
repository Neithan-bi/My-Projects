import java.util.*;
class Employi extends person {
    private int id;
    private String title;

    public void setID(int id) {
        this.id = id;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getID() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public static void main(String[] args) {
        Employi emp = new Employi();
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter first name: ");
        emp.setFirstName(in.nextLine());
        
        System.out.print("Enter last name: ");
        emp.setLastName(in.nextLine());

        System.out.print("Enter ID: ");
        emp.setID(in.nextInt());
        in.nextLine(); 

        System.out.print("Enter Title: ");
        emp.setTitle(in.nextLine());

        System.out.println("\nEmployee Details:");
        System.out.println("First Name: " + emp.getFirstName());
        System.out.println("Last Name: " + emp.getLastName());
        System.out.println("ID: " + emp.getID());
        System.out.println("Title: " + emp.getTitle());

        in.close();
    }
}

