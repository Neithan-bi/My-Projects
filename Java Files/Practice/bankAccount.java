import java.util.Scanner;

public class bankAccount {
    String accnum, accname;
    double bal;

    public bankAccount(String accnum, String accname, double bal) {
        this.accnum = accnum;
        this.accname = accname;
        this.bal = bal;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            bal += amount;
            System.out.printf("Deposited: %.2f " , amount);
        } else System.out.println("Invalid deposit amount.");
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= bal) {
            bal -= amount;
            System.out.printf("Withdrawn: %.2f",amount);
        } else System.out.println("Invalid withdrawal amount or insufficient balance.");
    }

    public void checkBalance() {
        System.out.printf("Current Balance: %.2f" ,bal);
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Account Number: ");
        String accnum = scanner.nextLine();
        System.out.print("Enter Account Holder Name: ");
        String accname = scanner.nextLine();
        System.out.print("Enter Initial Balance: ");
        double bal = scanner.nextDouble();

        bankAccount account = new bankAccount(accnum, accname, bal);

        while(true) {
            System.out.println("\n--- Bank Menu ---");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Check Balance");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter deposit amount: ");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;

                case 2:
                    System.out.print("Enter withdrawal amount: ");
                    double withdrawAmount = scanner.nextDouble();
                    account.withdraw(withdrawAmount);
                    break;

                case 3:
                    account.checkBalance();
                    break;

                case 4:
                    System.out.println("Thank you for banking with us!");
                    scanner.close();
                    return;

                default: System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
