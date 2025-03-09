class Hello implements Runnable {
    String threadname;

    public Hello(String tname) {
        threadname = tname; }
    public void run() {
        for(int i = 0 ; i < 300 ; i++) System.out.println("Thread name : " + threadname+ " "+i*2); 
    }
}
class World implements Runnable {
    String threadname;

    public World(String tname) {
        threadname = tname; }
    public void run() {
        for(int i = 0 ; i < 300 ; i++) System.out.println("Thread name : " + threadname+ " "+i*2); 
    }
}

class ThreadDemo {
    public static void main(String[] args) {
        Hello h1 = new Hello("Hello");
        World h2 = new World("World");

        Thread t1 = new Thread(h1);
        Thread t2 = new Thread(h2);
        t1.start();
        t2.start();
    }
}