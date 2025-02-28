class Box {
    double width, height, depth;

    public Box() {
        this.width = this.height = this.depth = -1; 
    }

    public Box(double width, double height, double depth) {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    public Box(double side) { 
        this.width = this.height = this.depth = side;
    }

    public double volume() {
        return width * height * depth;
    }
}

class BoxWeight extends Box {
    double weight;

    public BoxWeight() {
        super();
        this.weight = -1; 
    }

    public BoxWeight(double width, double height, double depth, double weight) {
        super(width, height, depth);
        this.weight = weight;
    }

    public BoxWeight(double side, double weight) { 
        super(side);
        this.weight = weight;
    }
}

class Shipment extends BoxWeight {
    double cost;

    public Shipment() {
        super();
        this.cost = -1; 
    }

    public Shipment(double width, double height, double depth, double weight, double cost) {
        super(width, height, depth, weight);
        this.cost = cost;
    }

    public Shipment(double side, double weight, double cost) { 
        super(side, weight);
        this.cost = cost;
    }

    public void display() {
        System.out.println("Dimensions: " + width + " x " + height + " x " + depth);
        System.out.println("Volume: " + volume());
        System.out.println("Weight: " + weight);
        System.out.println("Shipping Cost: " + cost);
    }
}

public class ship {
    public static void main(String[] args) {
        Shipment shipment1 = new Shipment(10, 15, 20, 50, 100);
        System.out.println("Shipment 1:");
        shipment1.display();

        System.out.println("\nShipment 2:");
        Shipment shipment2 = new Shipment(10, 30, 150);
        shipment2.display();
    }
}
