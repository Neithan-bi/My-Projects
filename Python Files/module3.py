def calculate_average_and_grade():
    try:
        # Input marks for 3 subjects
        marks = input("Enter marks for 3 subjects (space-separated): ").split()
        
        # Handle if no subjects are entered
        if len(marks) == 0:
            print("No subjects entered.")
            return
        
        # Convert marks to integers and calculate average
        marks = [int(mark) for mark in marks]
        average = sum(marks) / len(marks)
        
        # Determine grade
        if average >= 90:
            grade = "A"
        elif average >= 75:
            grade = "B"
        elif average >= 50:
            grade = "C"
        else:
            grade = "Fail"
        
        print(f"Average: {average:.2f}, Grade: {grade}")
    
    except ValueError:
        print("Invalid input. Please enter numeric values only.")
    
    finally:
        print("Cleanup: Program execution completed.")

if __name__ == "__main__":
    calculate_average_and_grade()