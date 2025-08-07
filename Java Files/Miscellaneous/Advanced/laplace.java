import java.lang.reflect.*;
class Temp {
    int field1 = 5;
    private int field2 = 9;
    protected String field3 = "Teja";
    private static final String field4 = "Toppr";

    public void printInfo(){
        System.out.println("Field3 is " +field3);
        System.out.println(field1);
        System.out.println(field2);
    
    }
    protected void printAURA() {
        System.out.println(field4);
    }
}
 class laplace {
    public static void main(String[] args) throws Exception {
        Temp t = new Temp();
        Temp trefer = Temp.class.getDeclaredConstructor().newInstance();
        Method[] meth = trefer.getClass().getDeclaredMethods();
        for(Method m : meth){
            System.out.println("Method name : " + m.getName());
        }
        trefer.printInfo();
        Constructor[] construct = trefer.getClass().getDeclaredConstructors();
        for(Constructor c : construct) {
            System.out.println("Constructor name : " + c.getName());
        }
    }
}