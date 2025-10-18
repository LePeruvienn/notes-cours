
## Fonctions

```python
def func (params):
	__bloc__
	return _expression_
```

**Documentations fonctions

```pyhton
"""
	... un résumé ...
	:param: ...
	:return: ...
"""
```

Permet de mettre de la doc dans une fonction


**Paramètre par défault fonctions** :

```python
def plus (x,y=1): return x+y
```

Ici si on ne met pas y en paramètre, y alors prend la valeurs 1


**!! DANGER PARMAETRE PAR DEFAULT**

Les paramètre son définis une fois dès que la variable est définis donc il faut pas faire :

```python
def ouill (a, b=[])
```

Ici si on modifie b dans la fonctions alors il sera modifier pour tout les autres appels


**Pyhton peut récupérer plusieurs arguments**

```python
def divers_inputs(msg, *args):
	...
```

Ici args prend une infinité d'arguments, ces arguments seront mit sous forme de list


On peut aussi le faire d'une autres manière, avec une clée

```python
def divers_inputs_nommes (msg, **kargs):
	...

divers_input_nommes ("msg", {a="test", b="test2"})
```

ici ça nous retoure un dico



**Unpack sur les paramètres**

```python
def moins(a,b):
	...

# Unpacking
moins (**{"b":2,"a":1})
moins (*[2,1])
```



**On peut mettre des fonctions en parmètre des fonctions**

```python
def plus(a): return a+1 
def update (a, func):
	a = func (a)

a = 0
update (a , plus)

print (a) # Mtn a vaut 1
```


### Fonctions à la volée


```python
def update (a, func):
	a = func (a)

a=0

update (a, lambda a : a+1)
```


**On peut ajouter l'information de retour sur les fonctions**

PEP484 à voir

```python
def id_f (
		  id: expression,
		  id_def: expression = _val_,
		  id_vargs: expression
		  
) -> expression:
```

Toutes les expréssion ici sont les type qu'il faut qu'on écrive dans la doc



### Notions historiques


L'architechture d'objet python est le `dic`

le `this` en java est traduit par `self` en python

L'équivalent de référence `null` est remplacé par `none` !

Pour tester si un objet est `none` il vaut mieux tester avec  `is`
ex : `test is none`


### Exemple de classes


```python
class C:
	""" ... Doc ... """
	
	att_de_classe = 1 # Ajout à la volée (attribut static)

	def methode_de_classe (): # Pas de self
		C.att_de_classe = 2 # Change la valeur static

	def __init__ (self, nom): # constructerur
		self.att_nom = nom    # ajout à la volée # Ici on peut mettre tout les attributs pas static
		...

	# self.att_nom = "ee" # <-- fail faut pas faire ça 
```


#### Les sous classes

```python
class C_fille (C_mere_1, C_mere_2, ...): # Plusieur héritage possible
	__déclaration__
	
```

Problème si on fait des classes mère qui ont le meme nom de méthode, car il prendra alors la première des deux



## Portées des déclarations

Tout est public !! *ça peut créer des problème du coup*


convention "cambouis": les variable privé sont préfixé `_`
ex: `_variableprive`


Cas particulier, name mangling:

pour variable privé dans une classe :

`_nom_id`



