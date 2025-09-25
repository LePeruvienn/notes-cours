
**Expliquer ce que ça veut dire** $log_2(n)$ *le petit 2 ça veut dire que c'est en base 2*


Ici on teste pour 58 :


On prend tout les carré de 2 :

1 -> 2 -> 4 -> 16 -> 32 -> 64

On as fait **5** pour arriver à notre nombre. il faut alors un peu près **5**, ... notre nombre, comme il est proche de 64 on peut dire que c'est alors 5,8...

On peut aussi faire l'inverse et diviser par 2 58 jusqu' ace qu'on tombe sur 1 :

58 -> 29 -> 15 -> 7 -> 4 -> 2 -> 1 

Donc un peu près 6 !


## Dichotomie

```python
def dicho(tab,elt):
	if len(tab) == 1 and tab[0] != elt return False
	mid = len(tab/2)
	if tab[mid] == elt: return True
	if tab[mid] < elt return dicho(tab[mid], len(tab)], elt)
	if tab[mid] < elt return dicho(tab[0, mid], elt)
```



## Rafraichissement de mémoire

- Etant donnée une liste, vérifier si elle est triée

1) Ecrivez un algo
2) Quel est temps prend cet algorithme ?
3) Peut-on faire plus rapide ?

```python
def check_trier(tab)
	for i in range(1,tab):
		if tab[i-1] > tab[i] return False
	return True
```

- O(n)
- Non on ne peut pas faire plus rapide



On ne peut pas terminer l'algo avant d'avoir visiter toutes les cases donc l'algo ne peut pas faire plus,

Le résultat peut dépendre alors des cases qui reste






