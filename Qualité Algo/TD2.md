## Q1. Cherchez les élément en commun d'une listes

**Regarder si il y a au mois un élement commun**

- Solution "naive"

```python
def element_commun(tab1,tab2):
	for i in range(len(tab1)):
		for j in rnage(len(tab2)):
			if tab1[i] is tab2[j]:
				return True
	return False
```

=> Complexité $n^2$

- Une des meillers solution

```python
def element_commun(tab1,tab2):
	tab2.sort()
	for i in range(len(tab1)):
		if dicho(tab1[i], tab2):
			return True
	return False
```

=> Compexité $n \times log(n)$

**Renvoyez tout les éléments communs des deux listes**

Meme complexité pour les 2 algo sauf qu'on fait toujours le pire cas !!

## Q2. Tableau de 1 millions de int, ont doit faire des opération dessus, vaut mieux t il le trier ?

ça peut dépendre du cas, mais la plupart du temps on as intérêt à le trier. La compexité et l'efficatité ne change pas en fonction de la taille

=> En fat ça dépend du nombre de recherche sur le tableau, si on fait 1 recherche il faut mieux pas la trier mais pour des millions de recherche il vaut mieux trier avant. **C'est rentable si le nombre de recherche $n$ est superieur à $log(n)$**
## Q3. Etant données une liste et une cible, trouver 2 entiers dans la liste dont la somme vaut la cible


```python
def somme_cible(tab, cible):
	
	for i in range()
```

## Q4. Trouver la 7ème valeur plus grande d'une liste, puis faire pour la la N-ème aleur plus grande

```python
def n_plusgrande(tab, n):
	maxVals = [0 for i in range(n)]
	for i in range(len(tab)):
		if ()
```

Complexité $n$

## Q5. Dans un tableau d'entier tab, trouver le morceau tab[a:b] avec la somme maximale