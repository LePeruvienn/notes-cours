
```c
/*@
ensures \result == x+ 1 ;
*/
void foo(int x) 
{
    return x + 2;
}
```

```bash
frama-c ex1.c 
```

```c
/*@
requires 0 <= a < 100;
requires b < a;
*/
void foo(int a, int b);
```


## Maximum of 2 integers

```c
/*@
ensures (\result == x || \result == y) &&
        (\result >=  && \result >= y) ;
*/


// OR 

/*@
ensures (x >= y ==> \result == x &&
         y >= x ==> \result == y) ;
*/
int max2(int x, int y)
{
    return (x < y) ? y : x;
}
```

## Maximum of 3 integers

```c
/*@
ensures (\result == x || \result == y || \result == z) ;
ensures (\result >= x && \result >= y && \result >= z  ;
*/
int max3(int x, int y, int z)
{
    int a = max2(x, y);
    return max2(a, z);
}
```

## Spécification de la racine carré entière

🤓 **EXO TYPE EXAM**

Soit une fonction root qui prend en entier positif $n$ en paramêtre, et retourne sa carré entière positive.
 
Le résultat est définicomme un entier positif dont le carré est suéprieur ou égal à $n \times n$, mais strictement inférieur à $(n + 1) \times (n + 1)$

Ecrire le contrat de la fonction

```c
/*@
    requires x >= 0 ;
    ensures \result * \result <= x < (\result + 1) * (\result + 1) ;
    ensures \result > 0 ;
*/
int root(int x);
```

## Exercice - Quotient et reste dans une division euclidienne

```c
/*
    @ requires x >= 0 && y >= 0 ;
    @ decreases x ; 
    @ ensures x == \result.quo * y + \result.reste ;
    @ ensures 0 <= \result.reste < y ;
*/
quo_res div_eucli(int x, int y)
{
    quo_res res;
    if (x < y)
    {
        res.quo = 0;
        res.reste = x;
    }
    res = div_eucl(x - y, y);
    res.quo += 1;
    return res;
}
```

**IMPORTANT** : `@ decreases x ; ` permet de dire à frama-c que le paramêtre `x` décroit à chaque appel récursif. Sinon frama-c ne pourra valider le contrat.


## Pointeurs et valeurs avant/après


```c
/*@
ensures *x == \old(*y) && *y ==\old(*x)
*/
void swap(void* a, void* b)
{
    void* temp = a;
    *b = *a;
    *a = *temp;
}
```


## Runtime Error/RTE

Que se passe-t-il si son exécute le programme suivante ?

```c
int main(void)
{
    int x = abs(INT_MIN);
    printf("abs: %d\n", x);
}
```

Output 🤯

```
abs: -2147483648
```

Ici on as une érreur d'overflow :-(. C'est ce que l'ont appel une RTE (RunTime Error)

Jusqu'à présent, pas de vérifications des RTE.

On peut dire au programme des les vérifier grâce à la commande ;

```bash
frama-c abs.c -wp -wp-rte
```

Donc pour corriger notre fonction d'avant il faut 

```c
/*@
    requires x < INT_MIN ;
    ensures (x >= 0 ==> \result == x) ;
    ensures (x < 0 ==> \result == -x) ;
*/
int abs(int x);
```

## Déréférencement du pointeur `NULL`

```c
int main(void)
{
    int a = 3;
    int b = 7;
    int* c;
    swap(&a, &b);
    printf("swap: %d, %d\n", a, b);
    swap(&a, &c);
    printf("swap: %d, %d\n", a, *c);
}
```

Ici on fait un `printf` de la variable `c`, mais celle-ci n'as jamais été intialiser.


Pour fixer ce soucis dans la fonction swap il faut rajouter :

```c
/*@
    requires \valid(x) && \valid(y)
    ensures *x == \old(*y) && *y ==\old(*x)
*/
void swap(void* a, void* b)
{
    void* temp = a;
    *b = *a;
    *a = *temp;
}
```

Maintenant avec RTE ça marche 😎

**Validité des emplacements mémoires**

`\valid` précise la validité des emplacements mémoires :
- `\valid(p)` validité de `*p`
- `\valid(p+(x..y))` validité de `*(p+x) .. *(p+y)`


## Tableau


Echanger deux éléments dans un tableau `t`

```c
/*@
requires \valid(a+(0..(n-1))) ;
requires n1 < n && n2 < n2 ;
requires 0 <= n && 0 =< n1 && 0 =< n2 ;

ensures \old(a[n1]) == a[n2] && \old(a[n2]) == a[n1] ;
*/
void array_swap(int n, int a[], int n1, int n2);
{
    int temp = a[n1];
    a[n1] = a[n2];
    a[n2] = temp;
}
```

## Quotient dans une division euclidienne

```c
/*@
requieres x >= 0 && y > 0 ;
decreases x;
ensures \exists integer r ; (x == \result * y + r && 0 <= r < y)
*/
int quotient(int x, int y)
{
    if (x < y) return 0;
    return quotient(x - y, y) + 1;
}
```

## Reste dans une division euclidienne

```c
/*@
requieres x >= 0 && y > 0 ;
decreases x;
ensures \exists integer q ; (x == y * q + \result) ;
ensures 0 <= \result < y ;
*/
int reste(int x, int y)
{
    if (x < y) return x;
    return reste(x - y, y);
}
```

(pour celle la c'est ok si il reste une règle qui ne valide pas)


## Le plus petit carré suéprieur à un entier

Soit une fonction `sq` qui prend un entier positif `n` et qui calcul le plus petit nombre dont le carré est suéprieur ou égale à `n`.


```c
/*@
requires n >= 0;
ensures \forall interger i; 0 <= i < \result ==> i * i < n
ensures \result >= && \result * \result  >= n
*/
int sq(int n)
{
    int i = 0;
    for (; i * i >= n; ++i) {}
    return i * i;
}
```

## Logique du premier ordre

La logique du premier ordre (encore appelée logique des prédicats) est le formalisme logique sous-jacent aux contrats et assertions de ACSL et WP.

3 notions à introduire :

1. signature
2. terme (expression) et 
3. formule prédicats

### Syntaxe 

#### Formules

- 
- 

### Variable libre et variables liée

Une variable est lié si elle n'est pas libre.

- Une variable est lié lorsqu'elle est introduite par un quantificateur (`\forall`, `\exists`)
- Une variable libre c'est les variables spécial (ex: `\result`) et les paramêtre de la fonction.

### En ASCSL

| Notation math. | ACSL       | Sémantique | 
| -------------- |------------|----------- |
| $\top$         | `\true`    | toujours vrai    |
| $\bot$         | `\false`   | toujours faux    |
| $\lnot A$      | `!A`       | non A   |
| $A \land B$    | `A && B`   | A et B   |
| $A \lor B$     | `A \|\| B` | A ou B   |


### Exercice 

Ecrire en logique du premier ordre (à la ACSL) les phrases suivante:

1. pour tout entier i, pour tout entier j, si i < j alors i + 1 < j +1.

```
\forall interger i, j ; i < j ==> i + 1 ==> j + 1
```

2. il existe au moins deux entiers différents.

```
\exists integer x; \exists integer y ; !(x != y)
```

3. Pour tout entier il existe un entier qui lui est strictement plus grand.

```
\forall integer x; \exists integer y ; x < y
```

4. la relation $<$ est irreflexive assymétrique, et transitive

```
\forall integer x; !(x < x) ;
\forall integer x, y ; x < y ==> !(y < x) ;
\forall interger x, y, z ; (x < y && y < z) ==> x < z ;
```


## Exercice 

`a` est le pgdc (plus grand diviseur commun) de `n` et `m` (`a`, `n` et `m` sont des variables libres)

```
(\exists integer k, k' ; n == k * a && m == k' * a) &&
(\forall integer b ;
\exists integer p, p', n == p * b && m == p' * b) ==> b <= a)
```


## Tableau (2)

On veut faire le contrat pour une fonction qui cherche un élément dans un tableau.

```c
int find(int n, int a[], int v)
```

- Si on retourne un index valide, alors il doit avoir dans l'index du tableau l'élément

```
ensures 0 <= \result < n ==> a[\result] == v;
```

- Si on retourne `-1` c'est à dire que dans le tableau il n'y pas l'élément

```
ensures \result == -1 ==> 
    (\forall integer i ; 0 <= i < n == > a[i] != v)
```

- Si le résultat est ....


Mais en fait même avec tout les règles ça marche pas ...

## Les problèmes viennent de la ... boucle

Ici comme avant comme il faut cj

```c
int find(int n, int a[], int v)
{
    /*@
        loop assigns i ;
        loop variant n - i ;
    */
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == v)
            return i;
    }

    return -1;
}
```

....


# FAIRE LES EXOS QUI SONT DERRIERRE!!
