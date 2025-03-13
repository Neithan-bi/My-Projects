public class practice1 {
    public static void main(String[] args) throws InterruptedException {
     //   System.out.println(Thread.activeCount());
      //  Thread.currentThread().setName("Main Thread");
        //System.out.println(Thread.currentThread().getName());
        
        Thread.currentThread().setPriority(10);
        //System.out.println(Thread.currentThread().getPriority());
       // System.out.println(Thread.currentThread().isAlive());

      /* for(int i = 3 ; i > 0; i--){
            System.out.println(i);
            Thread.sleep(1000);
       }
       System.out.println("done"); */


       myclass t2  = new myclass();
       t2.start();
       System.out.println(t2.isAlive());
       t2.setName("2nd Thread");
       System.out.println(t2.getName());
       t2.setPriority(5);
        System.out.println(t2.getPriority());
        t2.setDaemon(true);
        System.out.println(t2.isDaemon());


    }
}
