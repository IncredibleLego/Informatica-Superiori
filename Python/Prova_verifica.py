#Autore: Francesco Corrado
import os


def menu(nomeFile1, nomeFile2, nomeFile3, nomeFile4):
	scelta=-1
	try: prova=open(nomeFile1)
	except FileNotFoundError: InizializzaFile(nomeFile1)
	try: prova=open(nomeFile2)
	except FileNotFoundError: InizializzaFile(nomeFile2)
	try: prova=open(nomeFile3)
	except FileNotFoundError: InizializzaFile(nomeFile3)
	try: prova=open(nomeFile4)
	except FileNotFoundError: InizializzaFile(nomeFile4)
	while(scelta!=0):
		os.system('cls')
		print("\nScegliere una delle seguenti opzioni\n");
		print("0: esci dal file");
		print("1: leggi dai file uno.txt due.txt tre.txt quattro.txt");
		print("2: scrivi nel file uno.txt");
		print("3: svuota i file uno.txt due.txt tre.txt e quattro.txt");
		print("4: elimina i file uno.txt due.txt tre.txt e quattro.txt");
		print("5: copia il file uno.txt nel file due.txt");
		print("6: appendi il file due.txt nel file uno.txt");
		print("7: appendi un testo contemporaneamente a uno.txt due.txt tre.txt e quattro.txt");
		print("8: effettua un gioco per indovinare un valore numerico");
		print("9: inserisci dei valori in una lista e dai come output la lista con solo i numeri unici");
		scelta=int(input("Scelta menu' principale: "))
		if(scelta==0):
			print("Grazie e arrivederci.\nFC\n")
			break
		elif(scelta==1):
			leggiFile(nomeFile1)
			leggiFile(nomeFile2)
			leggiFile(nomeFile3)
			leggiFile(nomeFile4)
		elif(scelta==2):
			scriviFile(nomeFile1, "w")
		elif(scelta==3):
			svuotaFile(nomeFile1)
			svuotaFile(nomeFile2)
			svuotaFile(nomeFile3)
			svuotaFile(nomeFile4)
		elif(scelta==4):
			eliminaFile(nomeFile1)
			eliminaFile(nomeFile2)
			eliminaFile(nomeFile3)
			eliminaFile(nomeFile4)
		elif(scelta==5):
			copiaAppendiFile(nomeFile1, nomeFile2, "w")
		elif(scelta==6):
			copiaAppendiFile(nomeFile2, nomeFile1, "a")
		elif(scelta==7):
			appendiFile(nomeFile1, nomeFile2, nomeFile3, nomeFile4)
		elif(scelta==8):
			indovinaNumero()
		elif(scelta==9):
			listaValUnici()
		else: print("Scelta errata. Rifai.\n")
		c = input()
		if c == " ":
			break

def InizializzaFile(nomeFile):
	fp=open(nomeFile, "x")
	fp.close()

def leggiFile(nomeFile):
	fp=open(nomeFile, "r")
	print("Contenuto del file:", nomeFile,":")
	print(fp.read())
	fp.close()

def scriviFile(nomeFile, modo):
	fp=open(nomeFile, modo)
	testo=input("Scrivi un testo, termina con il tasto invio\n")
	fp.write(testo)
	print("Testo inserito nel file", nomeFile)
	fp.close()

def svuotaFile(nomeFile):
	fp=open(nomeFile, "w")
	print("Il file", nomeFile, "e' stato svuotato con successo")
	fp.close()

def eliminaFile(nomeFile):
	os.remove(nomeFile)
	print("Il file", nomeFile, "è stato eliminato con successo")
	
def copiaAppendiFile(nomeFile1, nomeFile2, modo):
	fp1=open(nomeFile1, "r")
	fp2=open(nomeFile2, modo)
	fp2.write(fp1.read())
	if (modo=="w"):
		print("Il file", nomeFile1, "è stato correttamente copiato nel file", nomeFile2)
	if (modo=="a"):
		print("Il file", nomeFile1, "è stato correttamente appeso nel file", nomeFile2)
	fp1.close()
	fp2.close()
	
def appendiFile(nomeFile1, nomeFile2, nomeFile3, nomeFile4):
	fp1=open(nomeFile1, "a")
	fp2=open(nomeFile2, "a")
	fp3=open(nomeFile3, "a")
	fp4=open(nomeFile4, "a")
	testo=input("Scrivi un testo da appendere, termina con il tasto invio\n")
	fp1.write(testo)
	fp2.write(testo)
	fp3.write(testo)
	fp4.write(testo)
	print("Il testo è stato inserito correttamente nei file")
	fp1.close()
	fp2.close()
	fp3.close()
	fp4.close()
	
def indovinaNumero():
	x=0
	count=1
	userAns=0
	import random
	Min = int(input("Inserisci il valore minimo possibile del numero: "))
	Max = int(input("Inserisci il valore massimo possibile del numero: "))
	x =random.randint(Min, Max)
	print(x)
	while(x != userAns):
		userAns = int(input ("Prova a indovinare il numero: "))
		if(x == userAns):
			print("Congratulazioni! Hai indovinato, il numero era", x)
			print("Ci hai messo", count, "tentativi per indovinare")
		else:
			if(x < userAns):
				print("Sbagliato! Il numero corretto è più piccolo della tua risposta")
				count=count+1
			else:
				print("Sbagliato! Il numero corretto è più grande della tua risposta")
				count=count+1

def listaValUnici():
	listA = list()
	lenght = int(input("Inserisci quanto deve essere lunga la lista: "))
	for i in range(lenght):
		listA.append(int(input("Inserisci il valore nella lista: ")))
	print("Lista originale:", listA)
	uniqueList = list()
	for x in listA:
		if x not in uniqueList:
			uniqueList.append(x)
	print("Lista senza doppi:", uniqueList)
"""
def addWords(filename):
	f = open(filename, "w")
	word = input("Choose a word: ")
	while word != "stop":
		f.write(word + "\n")
		word = input("Choose a word: ")
	f.close()
	
def getLongest(filename):
	f = open(filename, "r")
	longest = 0
	longestW = ""
	words = f.readlines()
	for w in words:
		if len(w) > longest:
			longest = len(w)
			longestW = w
			
	print(longestW, "e' lunga", longest, "caratteri.")
	
addWords("exercise.txt")
getLongest("exercise.txt")
		"""

menu("uno.txt", "due.txt","tre.txt","quattro.txt")
	
	
	
	
	
	
