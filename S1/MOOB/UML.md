# TD de modélisation

## I. COURS

```mermaid
classDiagram

A --> B
C --|> D
E --* F
G -- H
I ..|> J
```

- **A-B** : ??? (svp aider moi je sais pas)
- **C-D** : Héritage (classes)
- **E-F** : Composition (possède)
- **G-H** : Association
- **I-J** : Implémentation (interface)
## II. EXOS

### Exercice 1 : Diagramme de classe, échauffement

**1) Tout auteur a écrit au moins un livre** :

```mermaid
classDiagram
	Auteurs "1" --|> "1..n" Livre
	Livre
```

**2) Un rectangle à deux sommet qui sont des points. On construit un rectangle à partir des coordonnées de deux points. IL est possible de calculer son périmètre et sa surface, ou encore le translater**

```mermaid
classDiagram
	
	Rectangle "0..n" --|> "2" Point
	Point
	
	class Rectangle{
		-Point[] points
		+Rectangle(Point p1, Point p2)
		+void Translater(Point p)
		+double Surface()
		+double Perimetre()
	}
	
	class Point{
		+int x
		+int y
	}
```

**3) Les personnes peuvent être associées à des établissements en tant qu'étudiants mais aussi professeurs**

```mermaid
classDiagram
	Etablissement
	Personne "Professeur" --|> Etablissement
	Personne "Etudiant" --|> Etablissement
```

**4) Tout es jours le facteur distribue des plis recommandés dans une zone géographique qui lui est affectée. Les habitants sont également associées à une zone géographique. Les recommandées sont de deux sortes : lettres ou colis. Comme plusieurs facteurs peuvent intervenir dans la même zone, on souhaite, pour chaque recommandé, connaître le facteur qui l'a distribué, en plus du destinataire.**

```mermaid
classDiagram
	Zone
	Habitant "1"-- "1..n" Zone
	Facteur "1" -- "1..n" Zone
	Recommande "1" -- "0..n" Habitant
	Recommande "1" -- "0..n" Facteur
	Lettre --|> Recommande
	Colis --|> Recommande
```

**5) Les cinémas sont composés de plusieurs salles. Les films sont projetés dans des salles. Les projections correspondantes ont lieu à chacune à une heure déterminé (utiliser une classe association)**

```mermaid
classDiagram
	Salle "*" --* "1" Cinema
	Cinema "1" *-- "*" Projection
	Film "1" *-- "*" Projection
	Projection
```

---
### Exercice 2 :  \[Annale d'examen\] Diagrammes de classe, exercice type

```mermaid
classDiagram
	class Compagnie{
		+Vol[] vols
	}
	class Vol{
		+bool estOuvert
		+Areoport lieuDepart
		+Areoport lieuArriver
		+Date dateDepart
		+Date dateArriver
		+Escale[] escales
		+void Ouvrir()
		+void Fermer()
	}
	class VolGenerique{
		+int numVolGenerique
		+Date date
		+Vol[] vols
	}
	class Reservation{
		+bool annule
		+Vol vol
		+Passager passager
	}
	class Personne{
		+int id
		+String Nom
		+String Prenom
		+String Adresse
	}
	class Client{
		+Reservation[] reservations
	}
	class Passager{
		+int code
		+int nbPointsFidelite
	}
	class Areoport{
		+Ville[] villesDesservient
	}
	class Ville{
	}
	class Escale{
		+Areoport areoport
		+Vol vol
		+Date arriver
		+Date depart
	}
	Compagnie "1" -- "*" Vol
	Vol "1" -- "*" Reservation
	Vol "*" --|>"1" VolGenerique 
	Reservation "*" -- "1" Client
	Reservation "1" -- "*" Passager
	Client --|> Personne
	Passager --|> Personne
	Vol "*" -- "1" Areoport : "Départ"
	Vol "*" -- "1" Areoport : "Arriver"
	Areoport "0..*" -- "1..*" Ville
	Ville
	Escale "*" -- "1" Vol
	Escale "*" -- "1" Areoport
```

---


## Exercice 3 : \[Annale d'examen\] Modification de diagramme de classe

```mermaid
classDiagram
	class Terme{
		+calculerValeur(): int
	}
	class Expression{
		+operateurBinaire: char
	}
	class Variable{
		+nom: String
		+valeur: int
	}
	class Constante{
		+valeur: int
	}
	
	Terme  --* "1" Opérande : "Opérande"
	Expression --|> Terme : "Extends"
	Variable --|> Terme
	Constante --|> Terme
	Binaire --|> Opérande
	Unitaire --|> Opérande
	Opérande
```
---
### Exercice 5 : \[Annale d'examen\] Du code le diagramme de classe

```mermaid
classDiagram
	 class Dessinable{
		+void dessiner()
		+void effacer()
	}
	<<interface>> Dessinable
	class Figure{
		#String couleur
		#String getCouleur()
		#void setCouleur(String c)
	}
	<<abstract>> Figure
	class Point{
		-float x
		-float y
		+Point(float x, float y)
		+float getX()
		+float getY()
	}
	class Cercle{
		-float rayon
		-Point centre
		+Cercle(Point centre, float rayon)
		+void dessiner()
		+void effacer()
	}
	class Rectangle{
		#Point sommets[]
		+Rectangle(Point, p, Point q)
		+void dessiner()
		+void effacer()
	}
	class Losange{
		#Point sommets[]
		+Losange(Point p, Point q)
		+void dessiner()
		+void effacer()
[]()	}
	
	Figure ..|> Dessinable : "Implements"
	Cercle --|> Figure
	Rectangle --|> Figure
	Losange --|> Figure
	Point "1" --* Cercle
	Point "2" --* Rectangle
	Point "2" --* Losange
```

---

### Exercice 6 : \[Annale d'examen\] Diagramme d'états-transition

```mermaid
classDiagram
	class Container{
		+capacite: int
		+taille: int
		+Container(cap: int)
		+ajouter(c: int, v: Objet)
		+retirer(c: Objet)
		+present(c: Objet) boolean
	}
```

```mermaid
stateDiagram
    [*] --> Vide : Container(n)
    Vide --> NonVide : ajouter(c,v)
    NonVide --> NonVide : ajouter(c,v)
    NonVide --> Vide : retirer(v)
    NonVide --> Plein : ajouter(c,v)
    Plein --> NonVide : retirer(v)
```
- Pas oulbier aussi qu'on peut retirer si meme si le container est vide (mais ne fait rien dans ce cas)
- Pas oulbier aussi qu'on peut ajouter si meme si le container est plein (mais ne fait rien dans ce cas)

Donc deux flèche vers eux même mais le rendu après il est moche

---

### Exercice 4 : Diagramme de classe

```mermaid
classDiagram
	class Universite{
	}
	class Salle{
		+identifiant: int
	}
	<<abstract>> Salle
	class Bureau{
	}
	class Classe{
		+nbChaise: int
	}
	class Departement{
		+nom: String
		+bureaux: Bureau[]
	}
	class Personne{
		+identifiant: int
	}
	<<abstract>> Personne
	class Professeur{
		+statut: int
	}
	class Employe{
	}
	
	Universite -- "*" Departement
	Universite -- "*" Salle
	
	Bureau --|> Salle
	Classe --|> Salle
	
	Professeur --|> Personne
	Employe --|> Personne
	
	Departement -- "*" Bureau
	
	Professeur "*" -- "1" Departement
	Employe "0..1" -- "1" Bureau : "Travaille"
```

