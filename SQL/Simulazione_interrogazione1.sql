CREATE TABLE Alberghi (Id INTEGER PRIMARY KEY, Nome TEXT, eta INT, nCamere INT, citta TEXT, sitoWeb TEXT);
CREATE TABLE Clienti (Id INTEGER PRIMARY KEY, Nome TEXT, Cognome TEXT, Nazionalita TEXT, AnnoDiNascita INT, nPernottamenti INT);
CREATE TABLE Pernottamenti (Id INTEGER PRIMARY KEY, nomeCliente,cognomeCliente, nAlbergo, costo);

INSERT INTO Alberghi VALUES(1, "Hotel Roma", 56, 10, "Venezia", "www.HotelRoma.it");
INSERT INTO Alberghi VALUES(2, "Hotel Miramonti", 89, 20, "Venezia", "www.HotelMiramonti.it");
INSERT INTO Alberghi VALUES(3, "Hotel Stella", 100, 40, "Roma", "www.HotelStella.it");

INSERT INTO Clienti VALUES(1, "Francesco", "Corrado", "Italiana", 2004, 2);
INSERT INTO Clienti VALUES(2, "Francesca", "Zermani", "Italiana", 2005, 1);
INSERT INTO Clienti VALUES(3, "Tommaso", "Bianchi", "Italiana", 2004, 3);
INSERT INTO Clienti VALUES(4, "Abdul", "Assad", "Irachena", 1995, 1);
INSERT INTO Clienti VALUES(5, "Mark", "Rosenberg", "Inglese", 1984, 1);

INSERT INTO Pernottamenti VALUES(1, "Francesco", "Corrado", "Hotel Roma", 55);
INSERT INTO Pernottamenti VALUES(2, "Francesco", "Corrado", "Hotel Miramonti", 60);
INSERT INTO Pernottamenti VALUES(3, "Francesca", "Zermani", "Hotel Stella", 100);
INSERT INTO Pernottamenti VALUES(4, "Tommaso", "Bianchi", "Hotel Roma", 90);
INSERT INTO Pernottamenti VALUES(5, "Tommaso", "Bianchi", "Hotel Miramonti", 32);
INSERT INTO Pernottamenti VALUES(6, "Tommaso", "Bianchi", "Hotel Stella", 78);
INSERT INTO Pernottamenti VALUES(7, "Abdul", "Assad", "Hotel Stella", 34);
INSERT INTO Pernottamenti VALUES(8, "Mark", "Rosenberg", "Hotel Roma", 45);

--Punto 1
SELECT Alberghi.Nome, MAX(Alberghi.eta) AS Eta_massima FROM Alberghi;

--Punto 2
SELECT Alberghi.Nome, Alberghi.nCamere FROM Alberghi
	GROUP BY Alberghi.nCamere;
	
--Punto 3
SELECT AVG(costo) AS Costo_medio FROM Pernottamenti;

--Punto 4
SELECT Clienti.Nazionalita, COUNT(*) AS Quanti FROM Clienti
	GROUP BY Clienti.Nazionalita
	HAVING Clienti.Nazionalita = "Italiana";
	
--Punto 5
SELECT COUNT(*) AS Hotel_totali_Venezia FROM Alberghi
	WHERE Alberghi.Citta = "Venezia";

--Punto 6
SELECT Alberghi.Nome,SUM(Pernottamenti.costo) AS Incasso_totale FROM Alberghi
	JOIN Pernottamenti
	ON Pernottamenti.nAlbergo = Alberghi.Nome
	GROUP BY Alberghi.Nome
	ORDER BY Alberghi.Nome DESC;
	
--Punto 7
SELECT Alberghi.Nome, Alberghi.citta, Alberghi.sitoWeb, MAX(Pernottamenti.costo) AS Costo_Massimo FROM Alberghi
	JOIN Pernottamenti
	ON Pernottamenti.nAlbergo = Alberghi.Nome;
	
--Punto 8
SELECT Clienti.Nome, Clienti.Cognome, Clienti.AnnoDiNascita, MAX(Clienti.nPernottamenti) AS Pernottamenti_massimi FROM Clienti;

--Punto 9
SELECT Clienti.Nome, Clienti.Cognome, SUM(Pernottamenti.Costo) AS Costo_totale FROM Clienti
	JOIN Pernottamenti
	ON Pernottamenti.nomeCliente = Clienti.Nome;
	
--Punto 10
SELECT Clienti.Nome, Clienti.Cognome, MIN(Pernottamenti.costo) AS Costo_minimo_dormita FROM Clienti
	JOIN Pernottamenti
	ON Pernottamenti.nomeCliente = Clienti.Nome;













