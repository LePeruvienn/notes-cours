# LZ77

Cette algo de compréssion marche avec 3 triplet par position : 

(`distance`, `longeur`, `caractère suivant`)

- `distance` : nombre de caractère en arrière ou commence la répétition
- `longeur` : nombre de caractère répété
- `caractère suivant` : le caractère qui rompt la répétition

**Exemple**

Avec le mot : `MISSISSIPPI`

1) `(0, 0, M)`
1) `(0, 0, I)`
1) `(0, 0, S)`
1) `(1, 1, I)`
1) `(3, 3, P)`

