# TD2

## 1. Bilan environnemental : principe

**A. Quel scénario de référence est sous-entendu dans cette figure, c’est-à-dire que suppose- t-on qu’il se serait passé sans ce nouveau système de gestion de l’énergie ? Comment est appelé ce type de scénario de référence ?**

Le scénario supposé est de remplacer la gestion du chauffage et de la climatisation par une IA. Et grâce à cela optimiser sa consommation et de baisser les impacts environnementaux.

Dans le schéma on peut voir ici qu'on suppose les impact du 1er, deuxième et troisième ordre.

**B. De quel ordre sont chacune des conséquences indiquées sur le premier niveau de couleur ?**

Dans ce qui consomme le plus à ce qui consomme le moins

**C. Quelles sont les conséquences environnementales probables pour chaque type d’effet : vont-ils plutôt augmenter ou réduire l’impact environnemental ? Mettre des flèches ↗ ou ↘ à droite des feuilles de l’arbre pour indiquer si les impacts vont augmenter ou baisser.**

↗ ou ↘

1er Ordre : 
- Système de gestion d'énergie : ↗ augmente
- IoT : ↗ augmente
- Système d'IA : ↗ augmente

2ème ordre :
- Réduction de la consommation de chauffage  : ↘ baisse
- Réduction de la consommation d'électricité : ↘ baisse
- Réduction de des plaintes : ↘ baisse

3ème ordre :
- Réinvesstiemment des économie : ↗ ou ↘ ça dépend de ce qu'on en fait
- Effet sur le réseau électrique : ↘ baisse ça dépend du rendement je pense

## 2. Calcul de l’empreinte directe du système numérique lui-même

**Pourquoi 12 mois et non 5 ? Les capteurs, la passerelle et le cloud consomment de l’énergie en continu, même hors saison de chauffe (ventilation, climatisation éventuelle, monitoring CO2/occupation). Les 205 tonnes annoncées, elles, ne couvrent que les 5 mois d’hiver observés. Calculez donc l’empreinte du système sur 12 mois, puis ramenez-la à un équivalent 5 mois (proportionnellement) pour la comparer au chiffre du livre blanc — et gardez cette différence de périmètre temporel en tête pour la discussion finale.**

*On se limitera dans ce TD à l’empreinte carbone, par manque de temps de la prof pour rassembler plus
de données.*


Ici on fait 12 mois pour couvrir toutes les période de l'année (que ce soit hiver, été, ect ...) ou les température peuvent faire varier la consommation d'électricité du serveur.


| Poste           | Calcul          |  Résultat       |
| --------------- | --------------- | --------------- |
| Fabrication Capteur | $15 \times 6 \times 1/15$ |  6 kg/CO2     |
| Fabrication passerelle| $1 \times 15 \times 1/15$ | 1 kg/C02 |
| Usage capteur | $15 \times 0.5 \times 8760$ | 65,7 kWh/an |
| Usage passerelle | $1 \times 5 \times 8760$ | 43,8 kWh/an|
| Usage cloud | $10 \times 365 \times 1.2$ | 4,38 kWh/an|
| Totale d'énergie usage  | $65,7 + 43,8 + 4,38$ | 133,88 kWh/an |
| Empreinte carbone  | $624 \times (0,029 \times 133,88 + 6 + 1)$ | 67 790 kg/C02 |
| Equivalent sur 5 mis  | $67 790 \times 5/12$ | 2 829 kg/C02 |

**Quels équipements ont le plus d’impact ? Quelle phase du cycle de vie ?**

Les capteurs et les passerelles ont le plus d'impact. Sur 1 an la fabraication la partie du cycle de vie qui pollue le plus.

**Comment l’impact évolue-t-il si vous changez le pays ? (analyse de sensibilité)**

L'impact est plus grand dans les autres pays. En france il est un peu plus grand, mais en europe en générale, il est excissivement plus grand en europe.

La suède et en france sont très basse notamment grâce au nucléaire (France) et aux énergie renouvelable (Suède)

**La durée de vie choisie pour les capteurs vous semble-t-elle raisonnable ?**

Je pense que c'est OK, en vrai, mais 15 ans ça me parait un peu optimiste. Mais c'est quelque chose qui peut être variable donc pas important.

**Quels impacts directs n’ont pas été pris en compte dans ce calcul ?**

Ici la phase de fin de vie est pas prise en compte.


## 3. Réduction des consommations énergétique



## 4. Effet rebonds rebonds et systèmique






