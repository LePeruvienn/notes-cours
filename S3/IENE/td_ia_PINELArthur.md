# TD1

## 1. Empreinte carbone d’un programme d’apprentissage automatique


1. Calculer la consommation d’énergie et l’empreinte carbone associée au scénario de référence avec l’outil Green Algorithms.

10.35 kig CO2e footprint


2. Le PUE utilisé est un PUE par défaut. Que devient votre empreinte carbone si vous utilisez un datacenter avec un PUE d’1,2 ? 1

PUE = 1.2 => 7.96 kgCO2e Carbon footprint

3. Une partie importante de la consommation non informatique d’un datacenter vient de la climatisation. Qu’en déduisez-vous sur la pertinence d’utiliser un PUE moyen ?

Pour rappel le PUE se calcule de la façon suivante :

$$
PUE = \frac
{consommation \ totale \ datacenter}
{consommation \ informatique}
$$

Le PUE moyen permet de déterminé la quantité d'énergie qui est en utiliser en plus pour refroidir / garder en bon état le material informatique du data center.

Il est pertinent car il permet de voir la quantité totale d'énergie perdu. Par rapport à la quantité réellle qu'on as besoin.



4. Si l’on suppose que la consommation d’électricité du datacenter suit la répartition de la figure 2, quelle proportion de la consommation d’électricité a-t-on étudiée avec Green Algorithms ? (attention cependant car dans cette figure, il n’y a que des CPU donc ce n’est pas réellement transposable à notre cas d’étude)


On regarde seulement la partie usage, et non les autres phases du cycle de vie compris dans cette utilisation.


5. Quels avantages et inconvénients voyez-vous à utiliser un tel outil plutôt qu’un package python comme CodeCarbon ?

Avantage :
- Facile d'utilisation, résultat instanée

Désavantage:
- Peu précis, pas automatique


## 2. Prise en compte du cycle de vie

1. Si l’on suppose que la répartition de l’empreinte carbone des serveurs du datacenter suit la répartition du tableau 2, quelle proportion de l’empreinte carbone a-t-on étudiée avec Green Algorithms ?

On as calculer la partie usage qui représente 45% des émissions de CO2.

2. Comment pensez-vous que l’empreinte carbone évolue si les serveurs sont sur un cloud plutôt qu’en local ? Testez votre hypothèse avec un cloud Azure en ”France Central”
pour avoir une localisation similaire.

Je pense que ça va augmenter un peu, mais comme ce ne va pas vraiment changer comme la localisation ne change pas.

3. Est-ce que la comparaison cloud/serveurs locaux avec Green Algorithms de permet de conclure sur l’intérêt environnemental du cloud par rapport à des serveurs locaux ?

Non pas vraiment, si les serveurs sont au même endroit alors, la consommation ne change pas vraiment. il n'y a pas vraiment d'intérêt.

4. Comparez l’empreinte obtenue avec un modèle plus ancien (NVIDIA P100 par exemple, de 2016) et un modèle plus récent et plus spécialisé (TPU v3 par exemple, de 2018). Qu’en concluez-vous ?

Les GPU plus récent consomme plus que les anciens modèles.


5. De quelles informations auriez-vous besoin pour estimer l’empreinte carbone en incluant la fabrication des équipements ?

J'aurais besoin des informations sur le cout d'extraction des materiaux et anciens que le coût de produciton du GPU.






