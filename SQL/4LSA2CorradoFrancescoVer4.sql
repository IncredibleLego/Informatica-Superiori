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

SELECT Alberghi.Nome, MAX(Alberghi.eta) AS Eta_massima FROM Alberghi --Punto 1
	GROUP BY Alberghi.eta
	HAVING eta = MIN(eta);
	
SELECT Alberghi.Nome, Alberghi.nCamere FROM Alberghi --Punto 2
	GROUP BY Alberghi.nCamere;

SELECT AVG(costo) AS Costo_medio FROM Pernottamenti --Punto 3
	GROUP BY Costo_medio;
	
SELECT Clienti.Nazionalita, COUNT(*) AS Quanti FROM Clienti --Punto 4
	GROUP BY Clienti.Nazionalita
	HAVING Clienti.Nazionalita = "Italiana";
	
SELECT Alberghi.Nome AS Hotel_totali_venezia, COUNT(*) AS Quanti FROM Alberghi --Punto 5
	GROUP BY Alberghi.Nome
	HAVING Alberghi.Citta = "Venezia";
	
SELECT Alberghi.Nome, Pernottamenti.costo AS Costo_totale FROM Pernottamenti --Punto 6
	GROUP BY Alberghi.Nome
	ORDER BY Costo_totale DESC;









