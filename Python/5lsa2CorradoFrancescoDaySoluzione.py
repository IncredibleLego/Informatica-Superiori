listA = list()
lenght = int(input("Insert how long you want the list to be: "))
for i in range(lenght):
	listA.append(int(input("Insert the value into the list: ")))
print(listA)

def unique(listA):
	uniqueList = []
	flag = False
	for i in range(len(listA)):
		for j in range(i):
			if listA[i] == listA[j]:
				flag = True
				print("LMAO")
			if not flag:
				uniqueList.append(listA[i])
			flag = False
	return uniqueList, len(uniqueList)

print(uniqueList)

def unique3(listA):
	uniqueList = []
	for x in listA:
		if x not in uniqueList:
			uniqueList.append(x)
	return uniqueList, len(uniqueList)
