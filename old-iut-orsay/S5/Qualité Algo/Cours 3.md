
### Exemple : isSorted

```python
def isSorted(tab):
	for in range(len(tab) - 1):
		if tab[i] > tab[i + 1]:
			return False
	return True
```


### Prochain problème les tris

**Tri par insertion**

```python
def insertSort(tab):
	result = []
	for elt in tab:
		insertInOrder(elt, result)
	return result
```

- Complexité au meilleur cas : dépend complétement de `insertInOrder`
- SI `insertInOrder` prend un temps de O(n) au pire, le trie prendra alors O(n²) au pire
- Ne pas penser qu'il n'y a que les coubles qui comptes !

```python
def insertInOrder(elt, result):
	for (i, val) in enumerate(result):
		if elt < val:
			result.insert(elt, i)
```

- Meilleur cas : O(1) -> elt est plus petit
- Pire cas : O(n) -> elt est plus grand que tout les chiffre


**Merge Sort**

```python
def mergeSort(tab):
	if len(tab) == 1 : return tab
	mid = len(tab)/2
	tab1 = mergeSort (tab[:mid])
	tab2 = mergeSort (tab[mid:])
	return merge(tab1,tab2)
```

- La fonction merge prend un temsp O(n)
- C'est un peu plus rapide (toujours O(n)) si une lsit est entièrement inferieur à l'autre


### Notes :

- On ne peut pas trier une liste en moins de O(n * log(n)) !!



### Pause bonus : Enigme

- Vous voulez savoir à partir de combien d'étage **exactement** unen chute casse votre modèle de téléphone.
- Vous avez un téléphone casse, c'est fini !
- Meilleur algorithme avec un télhpone ? Avec deux téléphone ? (difficile !)


### ...

```python
def recherche(tab,elt):
	# OPTION 1 : Complexité O(n)
	for val in tab:
		if elt == val:
			return True
	# OPTION 2 : Complexité O(log n)
	return dicho(tab,elt)
```


