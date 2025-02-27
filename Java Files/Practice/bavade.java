import java.io.*;   
interface testInteterface { 
    final int a = 10;
    void display();
}
class testClass implements testInteterface {
    public void display() {
        System.out.println("bavade");
    }
}
class bavade{
    public static void main(String[] args) {
        testClass t =  new testClass();
        t.display();
        System.out.println(t.a);
    }
}