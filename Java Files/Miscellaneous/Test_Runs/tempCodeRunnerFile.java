class Bank {
    private int balance = 1000;

    public synchronized void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrew: " + amount + ", Remaining Balance: " + balance);
        } else System.out.println("Insufficient funds for withdrawal of: " + amount); }

    public void deposit(int amount) {
        balance += amount;
        System.out.println("Deposited: " + amount + ", New Balance: " + balance);
    }
}

class DepositRunnable implements Runnable {
    private Bank bank;
    private int amount;

    public DepositRunnable(Bank bank, int amount) {
        this.bank = bank;
        this.amount = amount;
    }

    public void run() {
        bank.deposit(amount);
    }
}

class WithdrawRunnable implements Runnable {
    private Bank bank;
    private int amount;

    public WithdrawRunnable(Bank bank, int amount) {
        this.bank = bank;
        this.amount = amount;
    }
