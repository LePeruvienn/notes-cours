
**Django**: Framework python

Beaucoup de docs sur Moodle


On aura des TP qui se suiveront qui permetterons de construire une webapp complète (un peu comme FEUR PIZZA)


Tout ça sera fait sur un git (le git de l'IUT) il faudra données l'accès au prof pour qu'il voit nos travaux
Faudra faire des commit spéciaux pour chaque début de TP : `DEBUT TP2` ...

La série de TP ce trouve sur Moodle

TP extrémement guidé

Il ya de la doc/code sur webdev (de Blanchetti)


DuckTyping = faiblement typé

**Docs/Peps de Python**
docs.python.org/3/
peps.python.org/pep-0000/ (ici on est sur le peps 0000)
Il ya 
- la docs: qui sont les règle que python comprend et comment luifaire comprendre
- les peps: les standart de programmation ou de syntax de python (genre de recommandation de commment coder tel ou tel chose)

## Syntax Python

La syntaxe de python se fait sous forme de bloc

chaque espace/tab de différence par rapport à celui de dessus représente un sous blocs, l'inverse marche aussi
(il vaut mieux mettre des espace et pas des tabs)

Pas de caratère de fin d'inscrution il est remplacer par une fin de ligne 
- !! On peut prolongé des ligne en mettant à la fin de la ligne un `\` python ne prendra alors pas en compte la fin de ligne (à utilser sii vraaaaaiment besoin)

Commentaire python = `#`

Quand on bosse sur un projet il faut se mettre d'accord sur quelle nombre d'espace on utilise
*Par défault : 4 espaces*
*Par défault: 79 colonnes max (72 pour les commentaires)*

! Si l'instruction fait plus de 79 colonnes (on peut faire la technique du `\` ) mais aussi on peut utiliser les paranthèse sur plusieur ligne,
ex:
``` 
f (4, 3)

====

f (
    4,
    3
)
```


## Variables et type


Pas de variable sans valeurs on est obligé de leurs attribuer une valeurs à la déclaration


Les variable ont 2 types de portées:

Soit elle sont en dehors d'une fonction et d'une classe
- Donc elles ont une porté global sur tout le fichier (mais pas dans les fonctions ou autres)

Soit elle sont dans une fonction:
- Donc leurs portée se fait que à l'interieur de la fonction

ex:
```python
x = "dehors"
def f():
	#global x <- On peut faire ça si on a vraiment besoin de récupérer la vraible de l'exterieur (A NE PAS FAIRE NORAMALEMENT)
	#print(x) <- MArCHE pAS X EST PAS DECLARER DANS LE FONCTION
	 x = "dedans"
	 print(x)
```



Dans python comme on est dans le duckTyping on peut changer le type de la variable
```python
x=2
x="a"
```
On peut faire ça, ça va marcher, mais faut vraiment faire attention
*De base c'est jamais à faire, c'est une très mauvais idée*

Car par exemple ça peut créer des type error:

```python
x = "toto"
print(x) # Output: toto
print(x + "titi toto") # Output: toto titi
print (x/4) # Output: TypeError !
```
a
**Faire vraiment attention à ce que les autres écrivent sur les variable**



### types primitifs
- int
- float (tout les nombre à virgule, !! bug de précision parfois comme dans JS)
- str
- bool

On peut afficher les types comme ça:

```python
print(type(variable))
```

Les varaible de bases sont **immutable**

ça veut dire que qaund on fait des opérations, l'interpréteur stock et valeurs pour en créer une nouvelle, ce qui alloue beaucoup de mémoire qu'on ne peut pas controlé


### Les strings

On peut utiliser les `" ... "` ou les `' ... '` pour définier une chaine de caractère

Si on veut mettre des `'` et des `"`
On peut alors mettre des triples ! `""" ... """` ou `''' '''`
*(attention certain IDE ne savent pas comment coloirer les triples)*

```python
s = ''' il dit: " Je s'appelle groot" ... '''
```
ici on a un exemple avec des `"` et des `'` qu'on peut faire en utilisant les tripes `'`



**Les chanes de caractère fonction comme des tableaux** donc on peut utilsé les index et toutes les commandes qui vont avec

On peut concaténé les chaine avec des + ou en mettant rien
```python
"il" + "dit"
"feu" "re" # <- pas utilisé cette méthode c'est ilisible
```

**Mais les chaine de caractère sont aussi considérer comme des objets !** Donc il ya es méthodes en plus qui peuvent être utiliser
ex:
- .find()
- .index()
- .strip() *enleve tout les caractère blanc inutile*
- ... (tout est dans le diapo)
*très pratique*



### Formatage des strings


```python
# Classique on remplace le %s par le nom
"Hello %s" % name

# Avec un dictionnaire %(clé)type ex: s = string, .2f = float puis 2 chiffre, ...
"A: %(a)s, B: %(b).2f, B: %(b)04d" \
% {'a': 'string', 'b': '3.14159}
# Ici après on met le notre dictionnare associcé

# Avec une méthode str
"A: {a}, B: {b}".format (a='str', b=3.14159)

# F-Strings
f"variable: {name}"
f"calcul expréssion: {4*5}"
f"fonctions {f()}"


## OPTIONS DE FORMATAGES

# Go regarder la doc pour le reste ..
```



## Structure de données intégrées

tableaux
```python
tableau=["a","b"]
```

On peut utilisé les clé pour trouver une valeurs  mais on peut aussi:

```python
l=["a","b","c"]

print(l[-1]) # affiche le dernier
print(l[-2]) # affiche l'avant dernier
...
```


On peut utiliser le tableau de plusieurs façon
- comme un tableau
- comme une pile: ajout:`.append()` , retrait: .`pop()`
- comme une file: ajout `.append()`, retrait: `.pop(0)` *on fait 0 pour pop le premier*
- comme une liste: `.append()` , `.extend()` `[ .. : .. : .. ]` *[début : fin : pas]*
	-  ex: `toto` on peut faire [0 : 1 : 2] ce qui donne `tt`
	- On peut assi mettre des nombre négatif dans les clé pour récupérer les avant dernier ect ...
	- ça permet de pas écrire de boucle for !!!
	-  on peut aussi écrire comme ça directement `"toti"[2:4]` *meme pas besoin de nom de variable !!*

### Les tuples

les tuples sont **immutable** *On peut pas les changer !!*

```python
t=("a","b","c")
```

C'est la meme chose que les liste sinon

Les tuples sont utiles pour retourner plusieurs valeurs !!

```python
def f():
	return (1,2)

# donc si après je fais :

x,y = f()
print(x,y) # renvoie 1 2
```



### Ensemble

```python
e={1,3,3,3,"a",(1,2)} # On peut mettre ce qu'on veut
print(e) # Mais ici tout les répétition sont pas possible donc il y aura que un 3 dans la liste !

e.add(4) # On peut rajouter des valeurs
e.remove(4) # Ou en supprimer
e.add([1,2]) # valeur hashable seuelement, d'ou l'utilité des tuples
e.add([1,2], [1,2]) # c'est la meme chose car ils sont pas immutable donc ils peuvent devenir différent, ça deviens le bordel
e.add((1/,2)) # Il vaut mieux alors utiliser tout le temps des tuples !!!
```


### Dictionnaire

Syntax: `{cle : valeur}`
Lecture `dico[cle]`
Ecriture `dico[cle] = valeur`

*Remarque*: historiquement les objects en python sont des dicos
- Donc les valeurs peuvent être des **fonctions**


### Comprehension *(à lire en anglais)*

le but: créer à la volé des list tuples set dict

On peut créer des tableau en méttant en eux des expréssion régulière:

```python
[i for i in range(10) if i%3==0] # Cette liste donne tout les multiple de 3

def f(x): return 10*x # On définis une fonction juste pour l'exemple

[f(i) for i in [1,2,3]] # !! Générateur, renvoie [10,20,30]

tuple(f(i) for i in [1,2,3]) # !! version tuple (askip ça marche un peu bizzarement mais ça marche)

dict( i : i**2 for i in range(5)) # !! Dicitonnaire, renvoie les 5 premier carré avec la clé leurs nombre de base

{i for i in 'ababaaesecef' if i not in 'abd'} # !! Set # renvoie une liste de tout sauf abd, mais comme c'est un set il ne fait pas de double !! (l'odre est bizzare à ne pas prendre ne compte dans les set)
```



## Instructions de controle de flux 

```python
if a:
	__bloc__
elif b:
	__bloc__
else:
	__bloc__

# ternaire
a = 1 if bool1 else 2
a = 1 if bool1 else "2" # On peut mettre des type différents 

# Met la valeur 1 si bool1 vrai et 2 si bool1 fausse
# A ne pas trop utilisé sauf si c'est plus lisible
```

(On peut mettre ce qu'on veut à la place de `a` et `b` tant qu'il peut le transformer en booléen)



```python
while bool:
	__bloc__

while bool:
	__bloc_quand_vrai__
else:
	__bloc_final__ 
	# On met ça pour faire une isntruction après la sortie de la boucle
```

On peut utilisé `break` `continue` `return` dans les bloc pour arretez u
*(conitnue fait sauter la fin de la boucle, il vérifie aussi le bool donc on peut faire un `if continue` pour vérifier*


```python
for var in iterable:
	__bloc__
else:
	_boc_final__ # Meme chose on le fait à la fin de la boucle
```

Le for prend toutes les structure de données: `list` `tuple` `set` `dict` *!! dict sont itérables !!*


Donc pour les dict il vaut mieux faire un truc comme ça

```python
for dict in dic.items() # retourn tout les objets de la forme (clé : valeur)
```

On peut aussi faire quelquechose similaire pour les tableaux:

```python
for (i,v) in enumerate(["a","b"]) # ce qui donne: {(0 : "a"), (1 : "b")}
```


### Exception

*Comment ça marche les exception mal expliqué mais moi je comprend tkt*
Les exception sont gérer avec la pile dans l'appel, quand un appel à une erreur il remonte la pile des appels pour demander si ils sait pourquoi il s'est planter, sinon il remonte encore dans la pile. Si personne sait le programme s'arrête


```python
try: 
	__bloc__
except: _type_Exception1_ as var: # Attrape les type d'erreur
	_bloc traitement_
except: _type_Exception2_ as var:
	_bloc traitement_
...
else: 
	__bloc_tutti_fruiti__ # Attrappe toutes les exceptions (A NE PAS FAIRE YEN A TROP A CONNAITRE)
finally:
	__bloc_ramasse_miete__ # bloc pour nettoyer
```





# la suite

- fonction
- modele
- ...

