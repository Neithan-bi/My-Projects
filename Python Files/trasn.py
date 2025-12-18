from abc import ABC, abstractmethod

class Transport(ABC):
    @abstractmethod
    def fare(self, distance):
        pass

class Bus(Transport):
    def fare(self, distance):
        bus_fare = distance * 5
        print(f"Bus Fare for {distance} km: ₹{bus_fare:.2f}")

class Train(Transport):
    def fare(self, distance):
        train_fare = distance * 2
        print(f"Train Fare for {distance} km: ₹{train_fare:.2f}")

# Get distance from the user
try:
    travel_distance = float(input("Enter the distance to travel in km: "))

    # Create objects
    bus_journey = Bus()
    train_journey = Train()

    # Calculate and display the fares
    print("\n--- Fare Calculation ---")
    bus_journey.fare(travel_distance)
    train_journey.fare(travel_distance)

except ValueError:
    print("Invalid input. Please enter a valid number for the distance.")