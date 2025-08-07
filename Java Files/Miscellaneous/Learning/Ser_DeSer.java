
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Ser_DeSer {
    
    public static void main(String[] args) throws IOException, ClassNotFoundException {

        User us = new User();
        us.name = "real";
        us.age = 17;

        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("Userpdfile.ser"));
        out.writeObject(us);
        out.close();
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("Userpdfile.ser"));
        us = (User) in.readObject();
        in.close();
        System.out.println(us.name);
        System.out.println(us.age);
}
}
