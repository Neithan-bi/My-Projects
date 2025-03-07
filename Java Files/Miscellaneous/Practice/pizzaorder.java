public class pizzaorder {
    public static void main(String[] args) {
        pizza defaultPizza = new pizza();
        defaultPizza.displayOrder();
        pizza customPizza1 = new pizza(true, true);
        customPizza1.displayOrder();
        pizza customPizza2 = new pizza("gluten-free", true, false, false);
        customPizza2.displayOrder();
    }
}
