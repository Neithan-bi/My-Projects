from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def start_engine(self):
        pass

class Car(Vehicle):
    def start_engine(self):
        print("Car engine started with a key.")
class Motorcycle(Vehicle):
    def start_engine(self):
        print("Motorcycle engine started with a button.")
class Start(Vehicle):
    def start_engine(self):
        print("Vehicle engine started.")
car = Car()
car.start_engine()
motorcycle = Motorcycle()
motorcycle.start_engine()
start = Start()
start.start_engine()
