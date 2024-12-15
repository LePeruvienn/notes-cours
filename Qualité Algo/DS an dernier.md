
# 1. Cacul de la médiane

1) Compléxité au pire des cas : *O(n)* et au au pire cas : *O(n)*, avec *n* la longueur du tableau. On parcours dans tout les cas la boucle donc la compléxité ne change pas
   
2) On fait *(n - 1)/2* pour impaire et *n/2 - 1* pourpair itération (à la locuche c'est *n/2*). La compléxité au pire cas est de O(n²) et au meilleur cas aussi !!! En fait on ne peut pas changer la taille du tableau!!!

3) La complexité en mémoire est de taille *O(n)*

4)  La compléxité est de *O(n log(n))*
```python
def mediane(tab):
	return tab.sort()[len(tab)//2]
```

5) C'est pas possible de faire plus rapide que *O(n)* car il faut pouvoir parcourir au moins une fois tout le tableau pour pouvoir savoir quelle est la médiane.
```python
def median_is_pos(tab):
	nb = 0
	for i in range(len(tab)):
		if i < 0:
			nb = nb + 1
	return nb < len(tab) // 2
```

6) Complexité de pivoter : *O(n)*. Complexité de order : *O(n²)* et au meilleur cas *O(n)*

# 2. Artithmétique sur des grand nombres

1) 