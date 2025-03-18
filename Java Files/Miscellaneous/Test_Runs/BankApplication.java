import java.util.Scanner;

class Bank {
    private int balance = 1000;

    public synchronized void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount + ", New Balance: " + balance);
        } else {
            System.out.println("Insufficient funds for withdrawal of: " + amount);
        }
    }

    
    public synchronized  void deposit(int amount) {
        balance += amount;
        System.out.println("Deposited: " + amount + ", New Balance: " + balance);
    }
}

class Deposit implements Runnable {
    private Bank bank;
    private int amount;

    public Deposit(Bank bank, int amount) {
        this.bank = bank;
        this.amount = amount;
    }

    @Override
    public void run() {
        bank.deposit(amount);
    }
}

class Withdraw implements Runnable {
    private Bank bank;
    private int amount;

    public Withdraw(Bank bank, int amount) {
        this.bank = bank;
        this.amount = amount;
    }

    @Override
    public void run() {
        bank.withdraw(amount);
    }
}

public class BankApplication {
    public static void main(String[] args) {
        Bank bank = new Bank();
        
        try(Scanner in = new Scanner(System.in)) {
            System.out.println("Initial Balance: 1000");
            while(true) {
                System.out.println("Enter 1 to withdraw, 2 to deposit, 3 to exit");
                int choice = in.nextInt();
                switch(choice) {
                    case 1 :  
                              System.out.print("Enter amount to withdraw: ");
                              int withdrawAmount = in.nextInt();
                              Runnable withdrawTask = new Withdraw(bank, withdrawAmount);
                              Thread t1 = new Thread(withdrawTask);
                              t1.start();
                              t1.join();
                              break;
                    case 2 :  
                             System.out.print("Enter amount to be deposited: ");
                             int depositAmount = in.nextInt();
                             Runnable depositTask = new Deposit(bank, depositAmount);
                             Thread t2 = new Thread(depositTask);
                             t2.start();
                             t2.join();
                             break;
                    case 3  : 
                            System.out.println("Exiting");
                            Thread.sleep(1000);
                            return;
                    default : System.out.println("Invalid choice");
                }
            }
        } catch (InterruptedException e) {
            System.err.println("Thread interrupted");
        }
    }
}
        
