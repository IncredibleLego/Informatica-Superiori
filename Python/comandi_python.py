#Tipi di variabili. Le variabili non vanno dichiarate prima di
#essere utilizzate
int 3
float 3.0
str hello
bool true
None

type(3) #output: int, serve a trovare il tipo di una variabile
float(3) ----> 3.0 #converte una variabile in un altro tipo

% = #Resto di una divisione
** = #Potenza

input("What Is your Age?") #Fa una domanda all'utente che può rispondere, la risposta sarà sempre string
age = int(input("What Is your Age?"))#Qui si è cambiato il tipo in int

#Liste 
x = [1,2,3] #Dichiaro una lista
x.append(4) #Inserisco un elemento nella lista
x = [1,2,3,4]
x.append("five")
x = [1,2,3,4, "five"] #Puoi appendere tipi diversi di variabili

a=[1,2,3] b=[4,5,6]
a+b = [1,2,3,4,5,6] #Due liste si possono sommare

c=['a','b','c','d','e']
c=[1:4] = ['b', 'c', 'd'] #Prende gli elementi compresi tra 1 e 4
[1:6:2] = # [Inizio:Fine:LunghezzaPasso]
c=[1:] #Va fino alla fine della stringa
c=[:3] #Va dall'inizio fino alla posizione 3
c[-1]  #Prende l'ultimo elemento 

#Tuple (sono come le liste, ma non si possono modificare ne aggiungere valori)
x=(1,2,3)
x[1] = 2

list(x) ----> [1,2,3]
tuple(b) -----> (4,5,6)

#Dictionary
x = {key: value, key2: value}
{'hello': 0, 'bye': 1}
x['hello'] = 0

#Loops
for x in range(10): #Scrive tutti i valori 1-9
       print(x)

x=0
y=dict()
for x in range(1,16): #Crea un dictionary e inserisce i valori dei quadrati da 1 a 15
        y[x]=x*x
print(y)

#Pulisci lo schermo
import os
os.system('cls')
#Equivalente di getchar()
c = input()
if c == " ":
	break

#File
fp=open(nomeFile, "r") #Apri il file, lettera indica il modo
fp.read() #Leggi il file
fp.close() #Chiudi il file
fp.write() #Scrivi nel file
fp.readlines() #Leggi le linee in un file
os.remove(nomeFile) #Elimina file


#Controllo file
try: prova=open(nomeFileA)
except FileNotFoundError: InizializzaFile(nomeFileA)
try: prova=open(nomeFileB)
except FileNotFoundError: InizializzaFile(nomeFileB)

def InizializzaFile(nomeFile):
	fp=open(nomeFile, "x")
	fp.close()








