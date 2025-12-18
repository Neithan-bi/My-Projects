#Rulles for recursion....
def bigr(n): # rule 2 : Inner parameters
    if n == 0:
        return 0  # rule 1 : Stop the recursion with base condition
    return n + bigr(n-1) #rule 3[(n+1)]: changes to iterating variable
#rule 4 : Remaining value from every recursive call
print(bigr(5))