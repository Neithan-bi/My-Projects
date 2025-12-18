from abc import ABC, abstractmethod
class Appliance(ABC):
    @abstractmethod
    def turn_on(self):
        pass

class Fan(Appliance):
    def turn_on(self):
        print("Fan is now ON.")
class Light(Appliance):
    def turn_on(self):
        print("Light is now ON.")

fan = Fan()
fan.turn_on()
light = Light()
light.turn_on()
