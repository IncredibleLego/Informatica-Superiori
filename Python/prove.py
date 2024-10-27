"""
listaA=[1,2,3,4,5]
listaB=[6,7,8,9]



def copiaLista(listA, listB):
	i=0
	x=0
	listC=[0,1,2,3,4,5,6,7,8,9]
	a = len(listA)
	print(a)
	for i in range(len(listA)):
		listC[i]=listA[i]
	for x in range(len(listB)):
		listC[i+x]=listB[x]
	print(listC)

		
copiaLista(listaA, listaB)
"""

import os
listA=["ciao", "weee"]
listB=["hello", "there", "howdy"]

def menu(listA, listB):
	scelta=1
	while(scelta!=0):
		os.system('cls')
		print("0: esci dal programma")
		print("1: leggi la lista")
		print("2: scrivi nella lista")
		print("3: svuota la lista")
		print("4: copia listaA in listaB")
		print("5: elimina le liste")
		print("6: unisci le due liste in una terza")
		print("7: appendi nel fileA un numero in automatico")
		print("8: scrivi parole nella lista filo al terminatore STOP")
		print("9: aggiungi contemporaneamente a più liste un testo in input")
		print("10: trova parola piu' lunga della lista")
		scelta=int(input("Scelta menu' principale: "))
		if(scelta==0):
			print("Grazie e arrivederci.\nFZ\n")
			break
		elif(scelta==1):
			print(listA)
			print(listB)
		elif(scelta==2):
			listA.append(str(input("inserisci parola da aggiungere")))
		elif(scelta==3):
			listA.clear()
			listB.clear()
		elif(scelta==4):
			copiaLista(listA, listB)
		elif(scelta==5):
			del(listA)
			del(listB)
		elif(scelta==6):
			mergeLista(listA, listB)
		elif(scelta==7): 
			listA.append(random.randint(0,100))
		elif(scelta==8):
			appendiLista(listA)
		elif(scelta==9):
			listeContemporanea(listA, listB)
		elif(scelta==10):
			longestLetter(listaA)
		else: print("Scelta errata. Rifai.\n")
		c = input()
		if c == " ":
			break

def copiaLista(listA, listB):
	i=0
	for i in range(len(listA)):
		listB[i]=listA[i]
	print(listB)
	

def copiaLista(listA, listB):
	i=0
	a=len(listA)
	b=len(listB)
	print("listA=", a, "listB=", b)
	if(len(listA)>len(listB)):
		for i in range(len(listA)):
			listB[i]=listA[i]
		print(listB)
	if(len(listA)<len(listB)):
		for i in range(len(listB)):
			listB[i]=listA[i]
		print(listB)




def mergeLista(listA, listB):
	listC= listA+listB
	print("le liste sommate sono", listC)

def appendiLista(lista):
	word=input("choose a word: ")
	while word!="stop":
		lista.append(word)
		word=input("choose a word: ") 

def listeContemporanea(listA, listB):
	testo=input("Scrivi un testo, termina con il tasto Invio: ")
	listA.append(testo)
	listB.append(testo)

def longestLetter(nomeFile):
	longest = 0
	longestW = ""
	i=0
	for i in words:
		if len(lista[i]) > longest:
			longest = len(lista[i])
			longestW = lista[i]
	print(longestW, "e' lunga", longest, "caratteri.")

menu(listA,listB)


def unique(listA):
	x=0
	uniqueList=[]
	for x in uniqueList:
		for x not in uniqueList:
		uniqueList.append(x)
	return uniqueList, len(uniqueList)
unique(listA)
