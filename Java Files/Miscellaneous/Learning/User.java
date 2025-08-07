import java.io.Serializable;

public class User implements Serializable{
    String name;
    int age;

    public void Hello() {
        System.out.println("Hello, "+ name + " you are " + age + " years old");
    }
}
