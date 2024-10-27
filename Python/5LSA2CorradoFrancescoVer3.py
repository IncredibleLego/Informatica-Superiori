#Autore: Francesco Corrado
import os
import random

def menu(nomeFileA, nomeFileB):
	scelta=-1
	controllaFile(nomeFileA)
	controllaFile(nomeFileB)
	while(scelta!=0):
		os.system('clear')
		print("\nScegli l'operazione che vuoi eseguire:\n")
		print("0: uscita")
		print("1: leggi dai file")
		print("2: scrivi in fileA manualmente")
		print("3: appendi manualmente al fileA")
		print("4: svuota il fileA")
		print("5: copia dal fileA in fileB")
		print("6: appendi dal fileA al fileB")
		print("7: conta le parole nel fileA")
		print("8: conta le lettere nel fileB")
		print("9: scrivi in fileA casualmente")
		print("10: scrivi in fileB casualmente")
		scelta=int(input("Scelta menu' principale: "))
		if(scelta==0):
			print("Grazie e arrivederci.\nFC\n")
			break
		elif(scelta==1):
			leggiFile(nomeFileA)
			leggiFile(nomeFileB)
		elif(scelta==2):
			scriviFile(nomeFileA, "w")
		elif(scelta==3):
			scriviFile(nomeFileA, "a")
		elif(scelta==4):
			svuotaFile(nomeFileA)
		elif(scelta==5):
			copiaAppendiFile(nomeFileA, nomeFileB, "w")
		elif(scelta==6):
			copiaAppendiFile(nomeFileA, nomeFileB, "a")
		elif(scelta==7):
			contaParole(nomeFileA)
			print("Questa funzione non viene eseguita correttamente\ntuttavia i punti successivi sono stati eseguiti")
		elif(scelta==8):
			contaLettere(nomeFileB)
		elif(scelta==9):
			scriviCasualmente(nomeFileA)
		elif(scelta==10):
			scriviCasualmente(nomeFileB)
		else: print("Scelta errata. Rifai.\n")
		c = input()
		if c == " ":
			break

def controllaFile(nomeFile):
	try: prova=open(nomeFile)
	except FileNotFoundError: inizializzaFile(nomeFile)

def inizializzaFile(nomeFile):
	pFile=open(nomeFile, "x")
	pFile.close()

def leggiFile(nomeFile):
	pFile=open(nomeFile, "r")
	print("Il contenuto del file", nomeFile, "e':")
	print(pFile.read())
	pFile.close()

def scriviFile(nomeFile, modo):
	pFile=open(nomeFile, modo)
	testo=input("Scrivi un testo, termina con il tasto invio\n")
	pFile.write(testo)
	print("Testo inserito nel file", nomeFile)
	pFile.close()

def svuotaFile(nomeFile):
	pFile=open(nomeFile, "w")
	print("Il file", nomeFile, "e' stato svuotato con successo")
	pFile.close()

def copiaAppendiFile(nomeFile1, nomeFile2, modo):
	pFileA=open(nomeFile1, "r")
	pFileB=open(nomeFile2, modo)
	pFileB.write(pFileA.read())
	if (modo=="w"):
		print("Il file", nomeFile1, "è stato correttamente copiato nel file", nomeFile2)
	if (modo=="a"):
		print("Il file", nomeFile1, "è stato correttamente appeso nel file", nomeFile2)
	pFileA.close()
	pFileB.close()


def contaParole(nomeFile):
	fp=open(nomeFile, "r")
	words = fp.readlines()
	print(words)
	conta=0
#	for w in len(words):
	print("Il file", nomeFile,"contiene", len(words), "lettere.")
	fp.close()


def contaLettere(nomeFile):
	pFile=open(nomeFile, "r")
	words = pFile.read()
	conta=0
	for w in words:
		conta=conta+1
	print("Il file", nomeFile,"contiene", len(words), "lettere.")
	pFile.close()

def scriviCasualmente(nomeFile):
	pFile=open(nomeFile, "w")
	num=int(input("Inserisci quante lettere casuali vuoi immettere nel file:"))
	for i in range(num):
		testo=chr(random.randint(97,122))
		pFile.write(testo)
	print("Sono stati correttamente inseriti", num,"caratteri nel file", nomeFile)
	pFile.close()

menu("5LSA2CorradoFrancescoO.txt", "5LSA2CorradoFrancescoD.txt")
