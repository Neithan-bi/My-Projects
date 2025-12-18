from abc import ABC, abstractmethod

class BankAccount(ABC):
    @abstractmethod
    def account_details(self):
        pass

class SavingsAccount(BankAccount):
    def account_details(self):
        print("--- Savings Account Details ---")
        print("Interest Rate: 4.5% per annum")
        print("Features: Minimum balance required, limited transactions.")

class CurrentAccount(BankAccount):
    def account_details(self):
        print("\n--- Current Account Details ---")
        print("Interest Rate: 0%")
        print("Features: Overdraft facility, suitable for businesses.")

savings = SavingsAccount()
current = CurrentAccount()

savings.account_details()
current.account_details()