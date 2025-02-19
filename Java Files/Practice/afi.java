class baseclass {
    int x;
    int z = 100; 

    public baseclass(int x) {
        this.x = x;
    }

    public String display() {
        return "The value of x is " + x;
    }
}

class casschild extends baseclass {
    int y;

    public casschild(int x, int y) {
        super(x);
        this.y = y;
    }

    public void displaya() {
        System.out.println("Value of x = " + x);
        System.out.println("Value of z = " + super.z);
    }
}

public class afi {  
    public static void main(String args[]) {
        casschild c = new casschild(5, 2);
        c.displaya();
    }
}

