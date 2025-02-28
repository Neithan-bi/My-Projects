
interface Add {
    int add();
}
interface Sub {
    int sub();
}
class Cal implements Add,Sub {
    int a,b;

    public Cal(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public int add() {
        return a + b;
    }
    public int sub(){
        return a - b;
    } 
}
class GFG {
    public static void main(String[] args) {
        Cal x = new Cal(2, 1);
        System.out.printf("Addition : %d\n", x.add());
        System.out.printf("Subtraction : %d",x.sub());
    }
}