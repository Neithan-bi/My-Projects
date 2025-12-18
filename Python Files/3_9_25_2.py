from abc import ABC,abstractmethod
class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Rectangle(Shape):
    def area(self):
        length = float(input("Enter length of rectangle: "))
        width = float(input("Enter width of rectangle: "))
        print("Area of rectangle:", length * width)
        
class Circle(Shape):
    def area(self):
        radius = float(input("Enter radius of circle: "))
        print("Area of circle:", 3.14 * radius * radius)

rect = Rectangle()
rect.area()
circ = Circle()
circ.area()

