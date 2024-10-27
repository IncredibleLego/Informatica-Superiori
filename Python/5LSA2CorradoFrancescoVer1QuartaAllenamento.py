#Autore: Francesco Corrado

import os

def menu(nomeFile1, nomeFile2, nomeFile3, nomeFile4):
	scelta=-1
	while(scelta!=0):
		os.system('cls')
		print("\nScegliere una delle seguenti opzioni\n");
		print("0: esci dal file");
		print("1: leggi dai file uno.txt due.txt tre.txt quattro.txt");
		print("2: scrivi nel file uno.txt fino all'inserimento del carattere ','");
		print("3: scrivi nel file due.txt fino all'inserimento del carattere ';'");
		print("4: svuota i file uno.txt due.txt tre.txt e quattro.txt");
		print("5: elimina i file uno.txt due.txt tre.txt e quattro.txt");
		print("6: copia il file uno.txt nel file due.txt");
		print("7: appendi il file due.txt nel file uno.txt");
		print("8: appendi un testo contemporaneamente a uno.txt due.txt tre.txt e quattro.txt");
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
			scriviFile(nomeFile2, "w")
		elif(scelta==4):
			svuotaFile(nomeFile1)
			svuotaFile(nomeFile2)
			svuotaFile(nomeFile3)
			svuotaFile(nomeFile4)
		elif(scelta==5):
			eliminaFile(nomeFile1)
			eliminaFile(nomeFile2)
			eliminaFile(nomeFile3)
			eliminaFile(nomeFile4)
		elif(scelta==6):
			copiaAppendiFile(nomeFile1, nomeFile2, "w")
		elif(scelta==7):
			copiaAppendiFile(nomeFile2, nomeFile1, "a")
		elif(scelta==8):
			appendiFile(nomeFile1, nomeFile2, nomeFile3, nomeFile4)
		else: print("Scelta errata. Rifai.\n")
		c = input()
		if c == " ":
			break



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
	
	
menu("uno.txt", "due.txt","tre.txt","quattro.txt")










