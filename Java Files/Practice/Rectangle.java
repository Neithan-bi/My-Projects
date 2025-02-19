public class Rectangle {
     int length;
     int breadth;
     int count;
   public Rectangle(int length, int breadth) {
       this.length = length;
       this.breadth = breadth;
       count++;
   }
   public int area() {
       return length * breadth;
   }
   public int perimeter() {
       return 2 * (length + breadth);
   }
   public int recount()
    {
        return count;
    }
}