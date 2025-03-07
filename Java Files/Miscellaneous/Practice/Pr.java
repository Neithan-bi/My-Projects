
class Pr {
     public static void main(String[] args) {
          Rectangle rect1 = new Rectangle(4, 5);
          Rectangle rect2 = new Rectangle(5, 8);
          System.out.println("Area: " + rect1.area());
          System.out.println("Perimeter: " + rect1.perimeter());
          System.out.println("Area: " + rect2.area());
          System.out.println("Perimeter: " + rect2.perimeter());
          System.err.println(rect1.recount());
          System.err.println(rect2.recount());
              }
          }