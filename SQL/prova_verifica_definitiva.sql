CREATE TABLE Musei (id INTEGER PRIMARY KEY, NomeMuseo TEXT, Citta TEXT, NSale INT);
CREATE TABLE Artisti (id INTEGER PRIMARY KEY, NomeArtista TEXT, Nazionalita TEXT);
CREATE TABLE Opere (id INTEGER PRIMARY KEY,Codice INT, Titolo TEXT, Stile TEXT, NomeMuseo TEXT, NomeArtista TEXT);

INSERT INTO Musei VALUES (1,"Galleria Degli Uffizi", "Firenze", 50);
INSERT INTO Musei VALUES (2,"Gallerie Dell'Accademia", "Firenze", 25);
INSERT INTO Musei VALUES (3,"Galleria Borghese", "Roma", 15);
INSERT INTO Musei VALUES(4,"Louvre", "Parigi", 100);
INSERT INTO Musei VALUES(5,"National Gallery", "Londra", 70);

INSERT INTO Artisti VALUES(1,"Michelangelo", "Italiana");
INSERT INTO Artisti VALUES(2,"Raffaello", "Italiana");
INSERT INTO Artisti VALUES(3,"Van Gogh", "Olandese");
INSERT INTO Artisti VALUES(4,"Paul Gauguin", "Francese");
INSERT INTO Artisti VALUES(5,"Pablo Picasso", "Spagnola");
INSERT INTO Artisti VALUES(6,"Claude Monet", "Francese");
INSERT INTO Artisti VALUES(7,"Leonardo Da Vinci", "Italiana");

INSERT INTO Opere VALUES(1,1, "La Gioconda", "Rinascimentale", "Louvre", "Leonardo Da Vinci");
INSERT INTO Opere VALUES(2,2, "David", "Rinascimentale", "Galleria Degli Uffizi", "Michelangelo");
INSERT INTO Opere VALUES(3,3, "La Scuola Di Atene", "Rinascimentale", "Galleria Borghese", "Raffaello");
INSERT INTO Opere VALUES(4,4, "Il Cristo Giallo", "Post Impressionismo", "Louvre", "Paul Gauguin");
INSERT INTO Opere VALUES(5,5, "La Siesta", "Post Impressionismo", "Galleria Degli Uffizi", "Paul Gauguin");
INSERT INTO Opere VALUES(6,6, "Tondo Doni", "Rinascimentale", "Gallerie Dell'Accademia", "Michelangelo");
INSERT INTO Opere VALUES(7,7, "Autoritratto", "Impressionismo", "Louvre", "Van Gogh");
INSERT INTO Opere VALUES(8,8, "Guernica", "Cubismo", "Louvre", "Pablo Picasso");
INSERT INTO Opere VALUES(9,9, "Sposalizio della Vergine", "Rinascimentale", "Galleria Borghese", "Raffaello");
INSERT INTO Opere VALUES(10,10, "I Girasoli", "Post Impressionismo", "National Gallery", "Van Gogh");
INSERT INTO Opere VALUES(11,11, "Guernica 2", "Cubismo", "Galleria Degli Uffizi", "Pablo Picasso");
INSERT INTO Opere VALUES(12,12, "Lo Stagno Delle Ninfe", "Impressionismo", "Gallerie Dell'Accademia", "Claude Monet");
INSERT INTO Opere VALUES(13,13, "Autoritratto", "Rinascimentale", "Gallerie Dell'Accademia", "Raffaello");
INSERT INTO Opere VALUES(14,14, "Trasfigurazione", "Rinascimentale", "Galleria Degli Uffizi", "Raffaello");
INSERT INTO Opere VALUES(15,15, "Opera Naif a Caso", "Naif", "Louvre", "Van Gogh");

SELECT * FROM opere;
SELECT * FROM musei;
SELECT * FROM artisti;
--Punto 3: Aggiungere la colonna Valore alla tabella opere
ALTER TABLE Opere ADD Valore INT;

--Punto 4: Aggiornare i dati della tabella opere inserendo gli
--opportuni importi dentro la colonna valore
UPDATE Opere SET Valore = 50 WHERE Codice=1;
UPDATE Opere SET Valore = 2000 WHERE Codice=2;
UPDATE Opere SET Valore = 2000 WHERE Codice=3;
UPDATE Opere SET Valore = 50 WHERE Codice=4;
UPDATE Opere SET Valore = 50 WHERE Codice=5;
UPDATE Opere SET Valore = 50 WHERE Codice=6;
UPDATE Opere SET Valore = 2000 WHERE Codice=7;
UPDATE Opere SET Valore = 50 WHERE Codice=8;
UPDATE Opere SET Valore = 50 WHERE Codice=9;
UPDATE Opere SET Valore = 2000 WHERE Codice=10;
UPDATE Opere SET Valore = 50 WHERE Codice=11;
UPDATE Opere SET Valore = 50 WHERE Codice=12;
UPDATE Opere SET Valore = 50 WHERE Codice=13;
UPDATE Opere SET Valore = 50 WHERE Codice=14;
UPDATE Opere SET Valore = 50 WHERE Codice=15;

--Punto 5: Scrivere due inserimenti sbagliati
INSERT INTO Opere ("Tondo Doni", "Rinascimentale", "Uffizi", "Michelangelo");
INSERT INTO Opere (7, "Autoritratto", "Impressionismo", "Van Gogh"); 

--Punto 6.1: Estarre le opere ordinate in ordine decrescente
SELECT Opere.Titolo, Opere.Valore FROM Opere ORDER BY Valore DESC;

--Punto 6.2: Valore complessivo delle opere per ciascun museo
SELECT Opere.NomeMuseo, SUM(Valore) AS ValoreTotale FROM Opere GROUP BY NomeMuseo;

--Punto 6.3: Conteggio degli artisti per nazionalità
SELECT Artisti.Nazionalita, COUNT(*) AS Quanti FROM Artisti GROUP BY Nazionalita;

--Punto 6.4: Nome dell'artista e titolo delle opere conservate agli uffizi o alla national Gallery
SELECT Opere.NomeArtista, Opere.Titolo FROM Opere WHERE NomeMuseo = "Galleria Degli Uffizi" OR NomeMuseo = "National Gallery";

--Punto 6.5: Nome dell'artista e titolo delle opere conservate a Firenze
SELECT Opere.NomeArtista, Opere.Titolo, Musei.citta FROM Opere 
	JOIN Musei ON Opere.NomeMuseo = Musei.NomeMuseo
	WHERE Musei.Citta = "Firenze";

--Punto 6.6: Nome dell'artista e titolo delle opere di artisti spagnoli conservati a Firenze
SELECT Opere.NomeArtista, Opere.Titolo
	FROM Opere WHERE Opere.NomeArtista 
	IN (SELECT Artisti.NomeArtista FROM Artisti WHERE Nazionalita="Spagnola") 
	AND NomeMuseo IN(SELECT Musei.NomeMuseo FROM Musei WHERE Citta="Firenze");

--Punto 6.7: Per ciascun artista il nome e il numero di opere agli Uffizi
SELECT Artisti.NomeArtista, COUNT(Opere.NomeArtista) AS opere_totali FROM Artisti
	LEFT OUTER JOIN Opere
	ON Artisti.NomeArtista = Opere.NomeArtista AND Opere.NomeMuseo = "Galleria Degli Uffizi"
	GROUP BY Artisti.NomeArtista;
	
--Punto 6.8: Il nome dei musei di Firenze che conservano opere di artisti francesi
SELECT Opere.NomeMuseo
	FROM Opere 
	JOIN Musei ON Opere.NomeMuseo = Musei.NomeMuseo
	JOIN Artisti ON Artisti.NomeArtista = Opere.NomeArtista
	WHERE Musei.Citta = "Firenze" AND Artisti.Nazionalita = "Francese";	

--Punto 6.9: Le città in cui sono conservate almeno due opere di Raffaello
SELECT Musei.Citta, Opere.NomeArtista, COUNT(*) AS Opere_raffaello
	FROM Musei
	JOIN Opere ON Musei.NomeMuseo=Opere.NomeMuseo
	WHERE Opere.NomeArtista="Raffaello" GROUP BY Musei.Citta HAVING Opere_raffaello>=2;
	
--Punto 6.10: Cancellare tutte le opere di Stile Naif
SELECT * FROM Opere;
DELETE FROM opere WHERE Opere.Stile = "Naif";	
SELECT * FROM Opere;

--Punto 6.11: Gli Artisti che hanno realizzato opere superiori a 1000$
SELECT Opere.NomeArtista FROM Opere 
	GROUP BY Opere.NomeArtista 
	HAVING SUM(Opere.Valore)>1000;

SELECT DISTINCT Opere.NomeArtista FROM Opere
	LEFT OUTER JOIN Artisti ON Opere.NomeArtista=Artisti.NomeArtista
	WHERE Opere.Valore>=1000
	ORDER BY Opere.Valore ASC;
	



