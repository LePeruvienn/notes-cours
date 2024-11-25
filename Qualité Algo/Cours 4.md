
# Complexité en espace

- Complexité en **espace** et en **mémoire***
- C'est l'estimation de la quanité utilisé de mémoire vive (RAM)

Une varaible d'un type de base  : espace O(1) 4 ou 8 ou 16 octes

Pour une structure plus complex (chaine de caractère, tableau) il faut réfléchir à sa taille


```python
int x = 0 # => Espace O(1)
result = "yes" # => espace 3*O(1) = O(1)
tab = [0] * n # => espace 0(n) (si in taille de l'entrée)
```

## Règle de la complexité en espace

- La mémoire est réservé quand une variables est déclarer
- C'est la fonction qui déclare la variable qui paie (on ne paie pas pour ses arguments)
- Les variables sont libéré quand elles ne sont plus utilisé (garbage collection)

## Compromis temps / mémoire

- La notation O est pas toujours utilisé, on peut directement déterminé l'espace alloué
- On est souvent prêt à utiliser de la mémoire pour allez plus vite 
- Mais faut pas forcé tout de meme tout le monde à pas 64Go de RAM


# Exercices

Conseils
- regarder le nombre d'itération de la boucle
- 
