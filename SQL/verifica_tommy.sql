CREATE TABLE alberghi(id INTEGER PRIMARY KEY, fondazione INTEGER, camere INTEGER, sede TEXT, nome_albergo TEXT, sito_web TEXT);
CREATE TABLE clienti(id INTEGER PRIMARY KEY, nazionalita TEXT, nome_cliente TEXT, cognome_cliente TEXT, anno_di_nascita TEXT);
CREATE TABLE pernottamenti(id INTEGER PRIMARY KEY, nome_albergo TEXT, nome_cliente TEXT, volte TEXT, costo INTEGER);

INSERT INTO alberghi VALUES(1, 2000, 60, "Bormio", "Bianchi", "www.hotelBianchi.com");
INSERT INTO alberghi VALUES(2, 1980, 40, "Venezia", "Rossi", "www.hotelRossi.com");
INSERT INTO alberghi VALUES(3, 1990, 58, "Amalfi", "Esposito", "www.hotelEsposito.com");
INSERT INTO alberghi VALUES(4, 1995, 30, "Venezia", "Verdi", "www.hotelVerdi.com");
SELECT * FROM alberghi;
INSERT INTO clienti VALUES(1, "italiana", "Tommaso", "Bianchi", 2004);
INSERT INTO clienti VALUES(2, "italiana", "Lorenzo", "Della Valle", 2007);
INSERT INTO clienti VALUES(3, "francese", "Hugo", "Fracha", 2002);
INSERT INTO clienti VALUES(4, "tedesca", "Bastian", "Sweighester", 1980);
INSERT INTO clienti VALUES(5, "italiana", "Gianlugi", "Buffon", 1978);
SELECT * FROM clienti;
INSERT INTO pernottamenti VALUES(1, "Bianchi", "Tommaso", 2, 200);
INSERT INTO pernottamenti VALUES(2, "Rossi", "Bastian", 6, 900);
INSERT INTO pernottamenti VALUES(3, "Rossi", "Hugo", 1, 150);
INSERT INTO pernottamenti VALUES(4, "Bianchi", "Gianluigi", 4, 4000);
INSERT INTO pernottamenti VALUES(5, "Esposito", "Lorenzo", 3, 80);
INSERT INTO pernottamenti VALUES(6, "Verdi", "Tommaso", 1, 90);
INSERT INTO pernottamenti VALUES(7, "Bianchi", "Hugo", 4, 300);
INSERT INTO pernottamenti VALUES(8, "Esposito", "Bastian", 2, 100);
SELECT * FROM pernottamenti;

SELECT nome_albergo, sito_web, sede, MIN(fondazione) AS albergo_piu_vecchio FROM alberghi;
SELECT nome_albergo, sito_web, sede, fondazione, camere FROM alberghi ORDER BY camere ASC;
SELECT AVG(costo) AS costo_medio FROM pernottamenti;
SELECT COUNT(*) AS clienti_italiani FROM clienti WHERE nazionalita="italiana";
SELECT COUNT(*) AS alberghi_veneziani FROM alberghi WHERE sede="Venezia";
ALTER TABLE alberghi ADD incasso;
UPDATE alberghi SET incasso=4500 WHERE id=1;
UPDATE alberghi SET incasso=1050 WHERE id=2;
UPDATE alberghi SET incasso=180 WHERE id=3;
UPDATE alberghi SET incasso=90 WHERE id=4;
SELECT nome_albergo, sito_web, incasso, sede FROM alberghi ORDER BY incasso DESC;
SELECT alberghi.nome_albergo, alberghi.sede, alberghi.sito_web, MAX(pernottamenti.costo) AS costo_massimo_del_pernottamento FROM alberghi
JOIN pernottamenti
ON alberghi.nome_albergo=pernottamenti.nome_albergo;
SELECT clienti.nome_cliente, clienti.cognome_cliente, clienti.anno_di_nascita, SUM(pernottamenti.volte) AS volte_del_pernottamento FROM clienti
JOIN pernottamenti
ON clienti.nome_cliente=pernottamenti.nome_cliente
GROUP BY clienti.nome_cliente
ORDER BY volte_del_pernottamento DESC;
-- query 9 non svolta --
SELECT nome_cliente, MIN(costo) AS costo_minimo FROM pernottamenti;