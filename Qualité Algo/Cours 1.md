
- Réfléchir sur la qualité des algo et leurs **temps** d'execution
- Réflexion **théoriques** des problèmes
	- Quel algo plus rapide suivant la situation
	- Et si l'entrée est dix fois plus grande ?
	- Peut on faire mieux ?
- Compréhension **pratique** : 
	- Mesurer le temps et comparer à la théorie
	- Concevoir des tests

# !! IL FAUT VENIR EN AMPHI TOUT NE SERA PAS EN TD !!




# Recherche dans un tableau

## Exemple :

- Tabeau de 10 entient, on veut savoir si 17 est dedans

1) De combien de question avez vous besoins ?
2) Combien de temps ça prend ?
3) Combien de temps ça prend pour 10000 entiers ?



```python
def search(tab, target):
	result = False
	for elt in tab:
		if elt == target:
			result = True
	return result
```

- Sur un tableau de longueur `n`, cet algo effectue un certain nombre d'opération (3n + 3 ...)

mais c'est quoi cette opératon ? ça prend combien de temps ?

- `n` = tab length
- La boucle de répète

=> **Temps total : O(n)**


#### Notation O

- La notation **O** exprime comment une fonction (le temps) passe à l'echelle quand son entrée s'agrandit
- Convetion : n est la taille de l'entrée
- O(1) => ne dépend pas de n
- O(n) ~ an + b
	- a = le temps pris par chaque itération de la boucle
	- b = temps pris en plus (indépendant de n)


- O(1) + O(1) = O(1)
- n * O(1) = O(n)
- n * O(n) + O(n) = O(n² + n) = O(n²)

On s'intersse au passage à l'echelle, donc on garde le terme dominant

On ne sait pas le temps que prend chaque opérantion donc en enlève les constantes

#### Meilleur cas  / pire cas 

- On veut réfléchir au différentes execution possible
	- Ceux qui sont rapide
	- Ceux qui sont lent

Exemple :

```python
def search(tab, target):
	for elt in tab:
		if elt == target:
			return True
	return False
```

- Meilleur cas : on commence par la target 
	- => **Complexité au meilleur cas : O(1)**
- Pire cas : le tableau de contient pas la target
	- **=> Complexité pire cas : O(n)**


### Piège de la complexité

1) **Il n'y pas que les boucles qui prenne du temps !!**
   - Chaqe appelle de fonction chaque mot clé peut prendre un temps O(n) ou plus !! Réfléchissez, testez !
     
2) Pas toujours évident de dire si un test correspond au meilleur cas ou au pire ! Il faut réfléchir à combien de question on pose au programme pour pouvoir le résoudre ! 


### Complexité de la recherche

- **IL EXISTE PAS D'ALGO DE TABLEAU QUI VISITE MOINS DE N CASES AU PIRE CAS !!**

### Recherche dans un tableau trié

- J'ai un tableau trié qui contient 10000 entiers
- Vous voulez savoir si 17 est dedans 

- Questions autrisée : "la case numéro <> est plus grand ou plus petite, égale à <>?"

