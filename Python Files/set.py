fruits = {"apple","banana","cherry"}

fruits.add("orange")
fruits.remove("banana")
print("cherry" in fruits)
set_a = {1,2,3}
set_b = {3,4,5}
print(set_a.union(set_b))
print(set_a.intersection(set_b))
print(set_a.difference(set_b))


setni = {1,2,3,4,5}
setnig = {34,35,4326,3434,24}
setnig.add(424)
setnig.remove(34)
setni.add(2)
setni.remove(2)
print(setni.union(setnig))
print(setni.intersection(setnig))
li = [1,1,2,3,2,2,4,5,5,7,6]
losto = set(li)
print(losto)

string = "Yogurt ; Gurt:Yo , See you ; you:what?"
print(string[1:])
print(string[::4])
print(string[0:5])
print(string[0:5:2])
print(string[::-1])
