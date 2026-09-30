# Scalabilité

On en parle pour adresser une augentation du nombres des utilisateurs.

Metre à l'échelle un service ou une application : augemnter les capacité physique d'un serveur.

## Scalabilité technique

|            | Observabilité | Problème | Origine |
| ---------- | --------------| -------- | ------- |
| App JS     | Des outils coté nagiatueurs qui listent les traces hors network | trop d'appelle pas de gestion de cache interne | mauvaise intégration des libraries |
| Server     |  | server est distant | pas de CDN |
| Server App |               | trop de call, trop long | mauvaise intégration des librairies |
| BDD        |               |          |         |


Deux façon d'augmenter la sacalibité d'un serveur : 
- **Horizontal** : augemnter le nombre de serveurs
- **Vertical** : augmenter la puissance des serveurs

## Politique de load balancing

- **Round robin** : envoyer la requête sur un serveur aléatoire
- **Affinité d'IP** : on renvoie toujours sur la requête sur même serveur
- ou "*Rule based*" avoir une règle custom (par exemple trier les serveur par région)

Le **Round robin** est très utile pour répartir les utilisateurs sur plusieurs serveurs de manière équilibrer. Le soucis avec ça c'est que du coup un même utilisateur va passer par différent serveurs, et chaque serveur devra stocker à nouveau le cache (duplication du cache !!! et autre soucis).

On peut alors avoir un **serveur de cache** type *Redis* ou *Kafka* qui permette d'avoir différent serveur qui gère seulement les requête et qui puise leurs cache depuis ces serveurs la, ce qui règle alors le soucis de cache.

Sinon une autres manière plus naïve est de trier par **Affinité d'IP** ce qui assigne chaque IP utilisateur à un serveur unique. Ça règle le soucis de cache (car chaque utilisateur est sur le même serveur) mais du coup ça peut surcharger les serveurs les plus populaire.


### Base de données

Il est possible en base de données de faire du load balancer.

La stratégie conciste à avoir une base de données dite "*master*" qui possède les droit d'écriture et de lectures, et d'autres bases de données dites "*slaves*".

**Cela permet de répartir le load (les calculs du aux requetes) du à la lectures sur tout les slaves** !

> Mais les load d'écriture reste tous sur le master !

### Règle du Théorème CAP

- **C**onsistency : le systeme renvoie toujours la même réponse (même sur des requête au même moment)
- **A**vailibility : le système répond immédiatement à l'interrogation
- **P**artition Tolerent : le stockage du système est distribué

**Théorème CAP** dit que :
> Un système ne **peut vérifier que 2 des 3** éléments précédent !

Exemple :
- AP : SMS, MongoDB, toujours dispo, le stockage distribué mais si on envoie un message au même moment on aura pas les même données.
- CP : S3, Toujours les même données, réparti sur plusieurs serveurs, mais le temps de synchronisation ne permet pas de réponse immédiate.
- CA : SGBDR (MySQL, MariaDB, Postgres), permet d'avoir les même données de façon immédiate, mais cela implique d'avoir tout sur une seul base de donnée.

***Aparte : Que faire quand le master sature ?***
> On peut utliser de la partition de disque, on peut utiliser la **partition de base de données** !
> Cela consiste, à partitionner les données de la base de donnée en plusieurs fichiers. Ainsi on peut garder la partie de la base de donées la moins lu dans un fichier qui sera alors lu très rarement.


## Indices dans base de données relationnels

> ici tout les exemple sont avec Postgres. 

Quand on fait une requête pour récupérer les données d'une collone dans une table.


Avec $N$ le nombre de lignes et $M$ le nombre de colonnnes : 

- Sans index on fait $N \times M$ opération.
- Sans index on fait $N \times 2 + M$ opération.

Donc postgre SQL ici adapte en essayant de prédire le nombre d'objet renvoyer la méthode la plus efficace

On peut utiliser `EXPLAIN` qui nous permet de voir le **coût théorique des requêtes** qu'on va lui donner, et ce qu'il ferais en cas réelle, par exemple :

```pgsql
postgres=# EXPLAIN SELECT * FROM film WHERE votes > 0 AND votes < 1000;
                                QUERY PLAN                                 
---------------------------------------------------------------------------
 Index Scan using film_votes on film  (cost=0.28..20.84 rows=328 width=30)
   Index Cond: ((votes > 0) AND (votes < 1000))
(2 rows)
```

Ici on voit que selon ses calcul, il devrais avoir 328 lignes qui seront dumper dont il utilisera les indices (on le voit avec `Index Scan` au début). Il as prédit un cout entre `0.28` et `20.84`.

```pgsql
postgres=# EXPLAIN SELECT * FROM film WHERE votes > 0 AND votes < 2000;
                       QUERY PLAN                       
--------------------------------------------------------
 Seq Scan on film  (cost=0.00..42.66 rows=883 width=30)
   Filter: ((votes > 0) AND (votes < 2000))
(2 rows)
```

La par contre on voit que selon sa prédiction il y aura 883 lignes, donc il prefera ne pas utiliser les indices (on le boit ave `Seq Scan` au début de la ligne). Le cout prédit est entre `0.00` et `42.66 `.


Ici avec `EXPLAIN` **ON N'EXECUTE PAS LES REQUETES**. Mais c'est très interessant car il permet de voir le comportement de la base de données sans gacher du temps de calcul (pratique en prod !).

Si on veut faire une analyse prédictive puis tester le comportement réelle on peut utiliser `ANALYSE` après le `EXPLAIN` comme ceci `EXPLAIN ANALYSE`.

Donc on peut faire par exemple 

``` postgres
postgres=# EXPLAIN ANALYSE SELECT * FROM film WHERE votes > 0 AND votes < 1000;
                                                        QUERY PLAN
--------------------------------------------------------------------------------------------------------------------------
 Index Scan using film_votes on film  (cost=0.28..20.84 rows=328 width=30) (actual time=0.047..0.114 rows=326.00 loops=1)
   Index Cond: ((votes > 0) AND (votes < 1000))
   Index Searches: 1
   Buffers: shared hit=10
 Planning:
   Buffers: shared hit=3
 Planning Time: 0.176 ms
 Execution Time: 0.207 ms
(8 rows)
```

Ici dans l'output on peut ensuite comparer les valeurs prédite par le `EXPLAIN`.

**Créer une table d'indices** :
```SQL
create index table_col on table(col);
```

**Supprimer une table d'indices** :
```SQL
drop index table_col;
```
