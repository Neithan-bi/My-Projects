from abc import ABC, abstractmethod

class Payment(ABC):
    @abstractmethod
    def pay(self, amount):
        pass

class CreditCardPayment(Payment):
    def pay(self, amount):
        print(f"Processing payment of ₹{amount:.2f} using Credit Card.")

class UpiPayment(Payment):
    def pay(self, amount):
        print(f"Processing payment of ₹{amount:.2f} using UPI.")

# Create objects
credit_card = CreditCardPayment()
upi = UpiPayment()

# Call their pay() methods
credit_card.pay(1550.75)
upi.pay(320.50)