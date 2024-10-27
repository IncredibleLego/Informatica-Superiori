
def insertNumber(filename):
	f = open(filename, "w")
	number = input("Insert the number to be converted in binary: ")
	f.write(number)
	f.close()

def convertInBinary(filename):
	f = open(filename, "r")
	a = f.readlines()
	lis = [int(x) for x in a]
	num = lis[0]
	iniziale = num
	numero_convertito = ''
	while num >= 1:
		valore = num % 2
		numero_convertito += str(valore)
		num = num // 2
	if num == 0:
		numero_convertito += str(0)
	numero_convertito = numero_convertito[::-1]
	print("The number", iniziale, "in binary is", numero_convertito)
	f.close()


insertNumber("numero.txt")
convertInBinary("numero.txt")
