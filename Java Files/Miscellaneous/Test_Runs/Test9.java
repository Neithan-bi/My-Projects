public class Test9 {    
      int a, b;
   
    Test9()
    {
        a = 10;
        b = 20;
    }
   
    public void print()
    {
        System.out.println ("a = " + a + " b = " + b + "\\n");
    }
}

class Test5 
{

    public static void main(String[] args)
    {
        Test9 obj1 = new Test9();
        Test9 obj2 = obj1;

        obj1.a += 1;
        obj1.b += 1;

        System.out.println ("values of obj1 : ");
        obj1.print();
        System.out.println ("values of obj2 : ");
        obj2.print();

    }
}
