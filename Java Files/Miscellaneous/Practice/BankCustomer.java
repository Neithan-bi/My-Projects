class BankAccount {
    int balance;

    public BankAccount(int balance) {
        this.balance = balance;
    }

    public synchronized void withdraw(int amount, String name) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println(balance);
        } else {
            System.out.println("Insufficient balance");
        }
    }
}

class Customer extends Thread {
    BankAccount account;
    int amount;
    String name;

    public Customer(BankAccount account, int amount, String name) {
        this.account = account;
        this.amount = amount;
        this.name = name;
    }
    @Override
    public void run() {
        account.withdraw(amount, name);
    }
}

public class BankCustomer {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(10000);
        Customer c1 = new Customer(account, 9500, "sukesh");
        Customer c2 = new Customer(account, 2000, "bhuvi");

        c1.start();
        c2.start();
    }
}
