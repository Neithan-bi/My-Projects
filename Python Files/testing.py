try:
    list1 = list(map(int, input("Enter first list: ").split()))
    list2 = list(map(int, input("Enter second list: ").split()))
    if len(list1) != len(list2):
        raise ValueError("Lists are not of equal length")
    result = [a+b for a, b in zip(list1, list2)]
    print("Added List:", result)
except ValueError as e:  print("Error:", e)
