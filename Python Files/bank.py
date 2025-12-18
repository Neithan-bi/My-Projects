balance = 1000
withdrawal = float(input("Enter amount to withdraw: "))
if withdrawal > balance:
    print("Insufficient funds. Cannot withdraw.")
else:
    balance -= withdrawal
    print(f"Withdrawal successful. New balance: {balance}")
