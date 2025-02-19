class pizza {
    String crust;
    boolean extraCheese;
    boolean olives;
    boolean onions;

    public pizza() {
        this.crust = "regular";
        this.extraCheese = false;
        this.olives = false;
        this.onions = true;
    }
    public pizza(boolean extraCheese, boolean olives) {
        this.crust = "regular";
        this.extraCheese = extraCheese;
        this.olives = olives;
        this.onions = true;
    }
    public pizza(String crust, boolean extraCheese, boolean olives, boolean onions) {
        this.crust = crust;
        this.extraCheese = extraCheese;
        this.olives = olives;
        this.onions = onions;
    }
    public void displayOrder() {
        System.out.println("Pizza Order:");
        System.out.println("Crust: " + crust);
        System.out.println("Extra Cheese: " + extraCheese);
        System.out.println("Olives: " + olives);
        System.out.println("Onions: " + onions);
        System.out.println();
    }
   
}
