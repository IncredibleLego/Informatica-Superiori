
import os

def menu(nomeFileA, nomeFileB):
	scelta=-1
	while(scelta!=0):
		os.system('cls')
		print("0: esci dal programma")
		print("1: leggi dai file")
		print("2: scrivi (distruttiva) nel fileA")
		print("3: appendi al fileA")
		print("4: svuota il fileA")
		print("5: copia (distruttiva) del fileA nel fileB")
		print("6: elimina il fileA")
		scelta=int(input("Scelta menu' principale: "))
		if(scelta==0):
			print("Grazie e arrivederci.\nFC\n")
			break
		elif(scelta==1):
			leggiDalFile(nomeFileA)
			leggiDalFile(nomeFileB)
		elif(scelta==2):
			scriviAppendiNelFile(nomeFileA, "w")
		elif(scelta==3):
			scriviAppendiNelFile(nomeFileA, "a")
		elif(scelta==4):
			svuotaFile(nomeFileA)
		elif(scelta==5):
			copiaFile(nomeFileA, nomeFileB)
		elif(scelta==6):
			eliminaFile(nomeFileA)
		else: print("Scelta errata. Rifai.\n")
		c = input()
		if c == " ":
			break

def leggiDalFile(nomeFile):
	fp=open(nomeFile, "r")
	print("Contenuto del file", nomeFile, ":")
	print(fp.read())
	fp.close()

def scriviAppendiNelFile(nomeFile, modo):
	fp=open(nomeFile, modo)
	testo=input("Scrivi un testo, termina con il tasto Invio\n")
	fp.write(testo)
	print("Testo inserito nel file", nomeFile)
	fp.close()

def svuotaFile(nomeFile):
	fp=open(nomeFile, "w")
	print("Il file", nomeFile, "e' stato svuotato con successo")
	fp.close()

def copiaFile(nomeFileA, nomeFileB):
	fpA=open(nomeFileA, "r")
	fpB=open(nomeFileB, "w")
	fpB.write(fpA.read())
	fpA.close()
	fpB.close()
	print("Il file", nomeFileA, "e' stato copiato correttamente nel file", nomeFileB)
	
def eliminaFile(nomeFile):
	os.remove(nomeFile)
	print("Il file è stato eliminato con successo")
	
menu("fileOriginale.txt", "fileCopia.txt")

