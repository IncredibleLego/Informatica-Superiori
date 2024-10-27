CREATE TABLE Negozi(ID INTEGER PRIMARY KEY, Nome TEXT, Citta TEXT, SitoWeb TEXT, AnnoFondazione INT, Superificie INT);
CREATE TABLE Clienti(ID INTEGER PRIMARY KEY, Nome TEXT, Cognome TEXT, AnnoDiNascita INT, NumeroAcquisti INT);
CREATE TABLE Articoli(ID INTEGER PRIMARY KEY, Nome TEXT, nCliente TEXT, nNegozio TEXT, Prezzo INT);

INSERT INTO Negozi VALUES (1, "La Rinascente", "Milano", "www.Rinascente.it", 1950, 1000);
INSERT INTO Negozi VALUES (2, "Zara Roma", "Roma", "www.Zara.it", 1987, 500);
INSERT INTO Negozi VALUES (3, "Negozio Duomo", "Milano", "www.Duomo.it", 1990, 30);
INSERT INTO Negozi VALUES (4, "Michelangelo Shop", "Firenze", "www.Michelangelo.it", 2005, 76);

INSERT INTO Clienti VALUES (1, "Francesco", "Corrado", 2004, 3);
INSERT INTO Clienti VALUES (2, "Tommaso", "Bianchi", 2003, 1);
INSERT INTO Clienti VALUES (3, "Francesca", "Zermani", 2005, 1);
INSERT INTO Clienti VALUES (4, "Andrea", "Fraccaro", 1980, 1);
INSERT INTO Clienti VALUES (5, "Riccardo", "Cavadini", 2010, 1);
INSERT INTO Clienti VALUES (6, "Mirko", "Delloca", 2009, 1);

INSERT INTO Articoli VALUES (1, "Cuffiette", "Tommaso", "La Rinascente", 70);
INSERT INTO Articoli VALUES (2, "Power bank", "Francesco", "La Rinascente", 20);
INSERT INTO Articoli VALUES (3, "Pallina", "Francesca", "Zara Roma", 12);
INSERT INTO Articoli VALUES (4, "Zaino", "Andrea", "Negozio Duomo", 50);
INSERT INTO Articoli VALUES (5, "Penna", "Francesco", "Michelangelo Shop", 1);
INSERT INTO Articoli VALUES (6, "Quaderno", "Riccardo", "Zara Roma", 10);
INSERT INTO Articoli VALUES (7, "Libro", "Mirko", "Michelangelo Shop", 15);
INSERT INTO Articoli VALUES (8, "Computer", "Francesco", "La Rinascente", 400);

--Punto 1
SELECT Clienti.Nome, COUNT(*) AS Numero_Clienti FROM Clienti;

--Punto 2
SELECT COUNT(*) AS Numero_Negozi_Milano FROM Negozi
	WHERE Negozi.Citta = "Milano";
	
--Punto 3
SELECT Negozi.Nome, Negozi.Citta, Negozi.SitoWeb,Negozi.Superificie FROM Negozi
	ORDER BY Negozi.Superificie;
	
--Punto 4
SELECT Negozi.Nome, Negozi.Citta, Negozi.SitoWeb, MIN(Articoli.Prezzo) AS Prezzo_Minore FROM Negozi
	JOIN Articoli
	ON Articoli.nNegozio = Negozi.Nome;
	
--Punto 5
SELECT AVG(Articoli.Prezzo) AS Costo_medio_articolo FROM Articoli;

--Punto 6 (Incompleto)
SELECT Clienti.Nome, Clienti.Cognome, Clienti.AnnoDiNascita, Clienti.NumeroAcquisti FROM Clienti
	WHERE Clienti.NumeroAcquisti = MAX(Clienti.NumeroAcquisti);
	
--Punto 7
SELECT Clienti.Nome, Clienti.Cognome, SUM(Articoli.Prezzo) AS Spesa_totale FROM Clienti
	JOIN Articoli
	ON Articoli.nCliente = Clienti.Nome
	GROUP BY Clienti.Nome
	ORDER BY Spesa_totale DESC;
	
--Punto 8
SELECT Negozi.Nome, COUNT(*) AS Numero_articoli FROM Negozi
	JOIN Articoli
	ON Articoli.nNegozio = Negozi.Nome
	GROUP BY Negozi.Nome
	ORDER BY Numero_articoli DESC;
	
--Punto 9
SELECT Negozi.Nome, Negozi.SitoWeb, MAX(Negozi.AnnoFondazione) AS Anno_fondazione FROM Negozi;

--Punto 10
SELECT Clienti.Nome, Clienti.Cognome, MAX(Clienti.AnnoDiNascita) AS Anno_di_nascita FROM Clienti;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	