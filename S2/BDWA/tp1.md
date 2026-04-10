# TP Vins

## Jointures

### Questions principales


1)

```
SELECT DISTINCT n_viticulteur, nom FROM viticulteur NATURAL JOIN vin WHERE region = 'LOIRE' AND millesime = 1993;
```

2)

```
SELECT DISTINCT nom, prenom FROM buveur NATURAL JOIN commande NATURAL JOIN vin WHERE cru = 'POMMARD';
```

3)

```
SELECT region, COUNT(n_vin) AS nombre_de_vins FROM vin GROUP BY region;
```

4)

```
SELECT n_viticulteur, nom, count (n_vin) AS nombre_vins FROM viticulteur NATURAL JOIN vin GROUP BY n_viticulteur, nom;
```

5)

```sql
SELECT * FROM n_buveur, nom, prenom FROM buveur WHERE n_buveur NOT IN (SELECT n_buveur FROM buveur NATURAL JOIN commande);

SELECT * FROM n_buveur, nom, prenom FROM buveur AS b1 WHERE n_buveur NOT EXISTS (SELECT * FROM buveur AS b2 NATURAL JOIN commande WHERE b1.n_buveur = b2.n_buveur);

SELECT b.n_buveur, nom, prenom FROM buveur AS b LEFT JOIN commande AS c on b.n_buveur = c.n_buveur where n_commande IS NULL;
```

6)

```
SELECT n_vin, cru, n_commande, c_qte FROM vin NATURAL JOIN commande WHERE c_qte < 12;
```

...


## Agrégats

### Questions principales

1) 

```
SELECT COUNT(DISTINCT cru) FROM vin;
```

2)



