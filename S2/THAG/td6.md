# TD6

## Exercice 1.

Ordre des arrêtes : $(ab), (ac), (ad), (bd), (bf), (ce), (cf), (de), (ef)$

1.

(a)

$\gamma(bcfb) = (0, 0, 0, 1, -1, 0, 1, 0, 0)$

$\gamma(abfeda) = (1, 0, -1, 0, 1, 0, 0, -1, -1)$

(b)

$\gamma(bcfb) = \gamma(bcefb) - \gamma(cfec)$

\(c\)

Taille de la Base de cycle : $m - n + p = 4$

Base = {$(abc), (bcfb), (cfec), (aceda)$}

(d)

Pour faire cela, lors qu'on fait notre arbre pour trouver nos base de cycle, le but est de faire que l'arbre ne permette pas de créer le cycle $(bfcb)$.

Il faut alors créer sans en elevant au moins 2 arrête du cycle $(bfcf)$.

Base = {$(bfedacb), (cedac), (cfedac), (abc)$}


(e)

$\gamma(abfeda) = \gamma() + \gamma()$

2.

(a)

Ordre des arrêtes : $(ab), (ac), (ad), (bc), (bf), (ce), (cf), (de), (ef)$

Cocycle$(abf) = \{0, 1, 1, 1, 0, 0, -1, 0, -1\}$

Cocycle$(ae) = \{1, 1, 1, 0, 0, -1, 0, -1, 1\}$

(b)

$\gamma(ae) = \gamma(aefd) - \gamma(fd)$


\(c\)

$\gamma(G) = n - p = 6 - 1 = 5$

- Avec $n$ le nombre de sommet
- Et $p$ le nombre de composante connexe (et pas fortement ! donc on s'en fou du sens des arcs)

Donc ici tout le graphe est connexe, donc 1 seul composante connexe !

(d)

Base de cocylcle du graphe $G =\{$

- $(abcef) \rightarrow (0, 0, 1, 0, 0, 0, 0, -1, 0),$
- $(ed) \rightarrow (0, 0, -1, 0, 0, -1, 0, 0, 1),$
- $(abcde) \rightarrow (0, 0, 0, 0, 1, 0, 1, 0, 1),$
- $(acfed) \rightarrow (1, 0, 0, -1, -1, 0, 0, 0, 0),$
- $(bcdef) \rightarrow (-1, -1, -1, 0, 0, 0, 0, 0, 0)$

$\}$

(e)

$\gamma(abf) = (0, 1, 1, 1, 0, 0, -1, 0, -1)$

$\gamma(abf) = \gamma(bcdef) - \gamma(acdef) - \gamma(abcde)$

## Exercice 2

Ordre : $(ab), (ad), (ae), (bc), (be), (bf), (cf), (db), (de), (ec), (ef)$

1.

$\mu$ = cycle ; $\gamma$ = cocycle

$\mu(abcfeda) = (1, -1, 0, 1, 0, 0, 1, 0, -1, 0, -1)$

$\mu(bdefb) = (0, 0, 0, 0, 0, -1, 0, -1, 1, 0, 1)$

$\gamma(ac) = (1, 1, 1, -1, 0, 0, 1, 0, 0, -1, 0)$

$\gamma(bdef) = (-1, -1, -1, 1, 0, 0, -1, 0, 0, 1, 0)$

Base de cycle de $G$ :
- $(abeda) \rightarrow (1, -1, 0, 1, 0, 0, 1, 0, -1, 0)$
- $(abcfeda) \rightarrow (0, 0, 0, 0, 0, -1, 0, 0, )$
- $(adba) \rightarrow ()$
- $(aeda) \rightarrow ()$
- $(ecfe) \rightarrow ()$
- $(bfcb) \rightarrow ()$

Base de cocycle $\gamma(G) = n - p = 6 - 1 = 5$ :
- $(abcef) \rightarrow ()$
- $(ad) \rightarrow ()$
- $(abcdf) \rightarrow ()$
- $(cf) \rightarrow ()$
- $(abcde) \rightarrow ()$
