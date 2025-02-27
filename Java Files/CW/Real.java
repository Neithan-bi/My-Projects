

interface Vehicle {
    void changeGear();
    void speedUp();
    void applyBreak();
}

class Bicycle implements Vehicle {
    int speed, gear;
    public Bicycle(int speed, int hear) {
        this.speed = speed;
        this.gear = gear;
    }
    public void changeGear() { 
        gear ++;
    } 

    public void speedUp(){
        speed += 5;
    }

    public void applyBreak(){
        speed -= 3;
    }
    public void printStates(){
        System.out.printf("Bicycle - Speed : %d \nGear : %d",speed,gear);
    }
}
class bike implements Vehicle{
        int speed , gear;

        public bike(int speed, int gear) {
            this.speed = speed;
            this.gear = gear;
        }
        public void changeGear(){ gear++;}

        public void speedUp() {
            speed+= 7;
        }
        public void applyBreak() { speed -= 4; }

        public void printStates() {
            System.out.printf("Bike - Speed : %d \nGear : %d",speed,gear);
        }
}   
public class Real {
    public static void main(String[] args) {
        Bicycle bicycle = new Bicycle(0,1);
        bicycle.changeGear();
        bicycle.speedUp();
        bicycle.applyBreak();
        System.out.println("Bicycle present state.");
        bicycle.printStates();
        bike Bike = new bike(0,1);
        Bike.changeGear();
        Bike.speedUp();
        Bike.applyBreak();
        System.out.println("Bike present state.");
        Bike.printStates();
    }

}
