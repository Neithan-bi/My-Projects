class BankAccount {
    private String accNo;
    private String accHold;
    private double balance;
    private String accType;
    
    public BankAccount(String accNo, String accHold) {
        this.accNo = accNo;
        this.accHold = accHold;
        this.balance = 0.0;
        this.accType = "Savings";
    }
    public BankAccount(String accNo, String accHold, double balance) {
        this.accNo = accNo;
        this.accHold = accHold;
        this.balance = balance;
        this.accType = "Savings";
    }
    public BankAccount(String accNo, String accHold, double balance, String accType) {
        this.accNo = accNo;
        this.accHold = accHold;
        this.balance = balance;
        this.accType = accType;
    }
    public void display() {
        System.out.println("Account Number: " + accNo);
        System.out.println("Account Holder: " + accHold);
        System.out.println("Balance: $" + balance);
        System.out.println("Account Type: " + accType);
        System.out.println("------------------------------");
    }
}

public class BankSystem {
    public static void main(String[] args) {
        BankAccount account1 = new BankAccount("1001", "Alice Johnson");
        BankAccount account2 = new BankAccount("1002", "Bob Smith", 1500.0);
        BankAccount account3 = new BankAccount("1003", "Charlie Davis", 5000.0, "Current");
        System.out.println("Bank Accounts Details:\n");
        account1.display();
        account2.display();
        account3.display();
    }
}


