import java.util.Scanner;
import java.util.logging.*;

class Person {
    private String firstName;
    private String lastName;

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }
}

class Employi extends Person {
    private int id;
    private String title;

    public void setID(int id) {
        this.id = id;
    }

    public int getID() {
        return id;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}

public class Main {
    private static final Logger logger = Logger.getLogger(Main.class.getName());

    public static void main(String[] args) {
        Employi emp = new Employi();
        try (Scanner in = new Scanner(System.in)) {
            logger.info("Enter first name: ");
            emp.setFirstName(in.nextLine());
            
            logger.info("Enter last name: ");
            emp.setLastName(in.nextLine());
            
            logger.info("Enter ID: ");
            emp.setID(in.nextInt());
            in.nextLine();
            
            logger.info("Enter Title: ");
            emp.setTitle(in.nextLine());
            
            // Efficient Logging using Placeholders
            logger.log(Level.INFO, "First Name: {0}", emp.getFirstName());
            logger.log(Level.INFO, "Last Name: {0}", emp.getLastName());
            logger.log(Level.INFO, "ID: {0}", emp.getID());
            logger.log(Level.INFO, "Title: {0}", emp.getTitle());
        }
    }
}
