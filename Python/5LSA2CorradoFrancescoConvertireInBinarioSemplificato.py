
def convertInBinary(num):
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

x = int(input("Insert the number to be converted in binary: "))
convertInBinary(x)
