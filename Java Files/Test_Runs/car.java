class car {
    int id, enginecapacity, price;
    String model, fueltype;
    public car(int id, int enginecapacity,int price, String model, String fueltype) {
        this.id = id;
        this.enginecapacity = enginecapacity;
        this.price = price;
        this.model = model;
        this.fueltype = fueltype;
    }
    public void displayDetails() {
        System.out.println("The Details :-");
        System.out.println("Car id " + id + ".");
        System.out.println("The price of car " + price + ".");
    }
    
}
