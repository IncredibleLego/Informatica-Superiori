#def range2(stop, start=0,step=1):
#	x=start
#	listA = []
#	while x < stop:
#		listA.append(x)
#		x += step
#	return listA
#
#print(range2(10,2))
#print(range2(10,2,2))
#print(range2(10))
#
#print(range(10))


listA = list()
lenght = int(input("Insert how long you want the list to be: "))
for i in range(lenght):
	listA.append(int(input("Insert the value into the list: ")))


def numUnique(list1):
	i=0
	j=0
	count=0
	for i in range(lenght):
		for j in range(lenght):
			print("I =", i)
			print("J =", j)
			if j!=i:
				if listA[j] == listA[i]:
					count+=1
					print("count = ", count)
			numUnique.append = listA[j]
	return(count)

count=int(numUnique(listA)/2)
print("You had a total of", count, "duplicate numbers")

