import java.util.*;
class random {
public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter account number: ");

    String accountNumber = scanner.nextLine();

    System.out.print("Enter account holder name: ");

    String accountHolderName = scanner.nextLine();

    System.out.print("Enter initial balance: ");

    double balance = scanner.nextDouble();

    bankAccount account = new bankAccount(accnum, accname, bal);

    System.out.println("\nPerforming operations:");

    System.out.println("\n1. Check Balance:");

    account.checkBalance();

    System.out.print("\n2. Enter amount to deposit: ");

    double depositAmount = scanner.nextDouble();

    account.deposit(depositAmount);

    account.checkBalance();

    System.out.print("\n3. Enter amount to withdraw: ");

    double withdrawAmount = scanner.nextDouble();

    account.withdraw(withdrawAmount);

    account.checkBalance();

    System.out.println("\nOperations complete. Thank you!");

    }}