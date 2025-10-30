# Introduction à l'IA générative

*On se présente tous ...*

Le but de se cours est juste d'expliquer comment marche l'IA générative.

Une IA aujourd'hui permet
- Des LLMs qui créer du contenue à partir d'entrée "naturelle" (textes, ...)

### Histoire de l'IA

**Orginine de l'IA**
- `1943` Première de modélisation mathématique d'un neurone.
- `1950` Test de turing.
- `?` Conférence de Dartmouth : naissance du terme "IA".
- `?` Période froide dans les années 70 : on avais pas assez de puissance de calcul pour avancer.
- `1998` YannLeCun - LENet-5
- `2009` ImageNet lancé : énorme base de données d'image (permet d'entrainer des IA)

**Explosion du deep learning**
- `2012` AlexNet : 80% de réusite sur ImageNet
- `2016` AlphaGo (DeepMind)
- `2017` Transformer - "Attention is All You need" (permet de faire faire comprendre les mot aux machines)

**L'ère des grands modèle de language (LLM)**
- `2018` : BERT (Google)
- `2020` : ChatGPT (OpenAI)
- `2021` : DALL-E & Clip (OpenAI)


### Les différentes IA

**Pyramide**

```
      GenAI
   Deep Learning
 Machine Learning
-  AI classique   -
```

**Machine Learning**
En gros c'est le fait d'apprendre des choses au machine via des données.
- Cela permet par exemple de prédire des données. (Ex: prédire le salaire des futurs alternant 💸)

Deux phase dans le machine learning importante :
1) Entrainement : On entraine l'IA en lui donnant la question puis la réponse
2) Test : On lui pose la question sans lui donné de réponse pour voir si il est chaud ou guez

**Deep Learning**
Ells fonctionne avec des réseaux de neurones.

Dans un réseau de neurones il y essentiellement 3 couches
1) **Couche d'Entrée** (Input)
2) **Couche Intermédiare**
3) **Couche Sortie** (Output/Résultat)

### IA Générative

Différences avec les autres ! Le but est pas de prédire ou de devenir ce qui est une entrée.
- Le but est de créer du nouveau contenu !!


**Ou est ce qu'on peut appliquer l'IA générative?**
- Texte & communication
- Code & ingénierie
- Image & Design
- ... 

En gros ça sert à plein de truc

**Cas d'usage emblématique**
- Productivité : Rédaction automatique d'email
- Développement : Créer des logiciel
- ...

### Sous le capot - Notions NLP

**Comment elle apprend ?**
Elle apprend à reconnaitres des patterns dans d'immense volumes de donnnées puis à reproduire ou inventer de nouvelles combinaisons cohérentes.

- "*Elle apprend le monde, puis imagine à partir de ce qu'elle as appris* ..." - Cf: 🤓


**Embeddings**
C'est la façon dont l'IA comprend le ses des mots.
- **On prend un mot on le vectorise** (on le transforme en chiffres)

On appèle les outils qui font ça des **modèle d'embeddings**

!! Elle ne permet pas de comprendre une phrase juste de vectorisé les mots dans l'espace !!


**Transformers**

C'est une architecture qui permet de comprendre le contexte entier d'une phrase !

- En l'utilisant, on peut la combiner avec un outils de génération de texte afin de générer des phrases cohérentes (comme l'as fait ChatGPT)!

**Qu'est-ce que c'est qu'un LLM?**

C'est un outils qui permet de communiquer via des "language naturelle !"
- Comprendre du texte humain
- Réponre avec du text humain


**Comment on génère du texte avec un LLMs?**

- On vectorise des mots et les transformes en *tokens*.
- Puis en fonction des *tokens* précédent il va prédire le prochain token à entrée.

En gros il vectorise les mots afin de faire des calcul de probabilité du mot.


**Au carrefour des technologies**

```
(Artificial Intelligence : 
    (Machine learning:
        (DeepLeraning )
    )
)

On peut retrouver dedans aussi (Natural Language processing , Computer Vision)
```

### RAG : Retrieval Augmented Generation

- Retrivial : **Extration d'information**
- Augmented Geneartion : **Génération Augmenté**

**Le problème de l'IA**:
- A du mal à connaitre le contexte lorsque les tokens sonts trop nombreux (quad ya trop de texte)
- Aussi c'est que elle ne connais que les données publique (peut pas deviner des choses privé, elle doit se re entrainer c'est chiant)

Le but de RAg est de réglé ces problèmes

**Architecture**

```
                    Corpus Documentaire
                             | 
                             |
                             v
 Utilisateur : Question --> RAG --> Question Augmenté : LLMS
```

Permet de données plus de contexte aux question d'un LLMs comme ça il as le contexte :

- En fait on prend les infos qu'elles as besoin dans les documents qu'on lui as donné
- On améliore la question données par l'utilisateur
- On envoie cette question à l'IA


=> **C'est vraiment cool aujourd'hui comme ça les entreprise exposes pas leurs datas aux entreprise IA !**


### Recherche de similarité

Le but est de trouvé des objets/vecteurs (mots, phrase, ...) similaires.

Un des moyens le plus utilisé est similarité sémantique via cosinu :
  - Les deux objets sont vectorisé dans l'espace
  - Leurs niveau de similarité est le cosinus de l'angle qui est entres les deux veceteurs


# Prompt Engeineering

### Erreurs les plus communes

- Prompt trop vague ou ambigu
- **Absence de contexte** : Toujours inclure, le rôle, l'objectif et le public visé
- **Manque de contrainte explicite**
- Mauvais enchainement des requetes
- **Absences d'exemples** : Les LLMs apprennent beaucoup par analogie.

### Bonnes pratiques

- Donner un role clair
- **Utilise une structure logique** : Contexte -> Tacge -> Contraintes -> Format de sortie attendu
- Utilisé des exemple (Few-shot prompting)
- **Itérer** : Tester -> Analyser -> Ajouter le prompt
- **Guide le raisonenement (COT: Chain of Toughts)**
- Spécifier le format de sortie
- Ajouter des gardes-fou : pour qu'on ne puisse pas "*jailbreak*" l'IA (lui faire générer des trucs pas cool et pas prévu).


### Méthode R.EACT

- **R**ole
- **E**xample
- **A**ction
- **C**ontext
- **T**one/Target

(*CACA* Cf: Doryan le gros nulle)


### Les limites de l'IA générative

- Manque de compréhension dumonde réelle
- Hallucination et erreurs factuelles
- Dépendance aux données d'Entrainement
- Biais et stéréoptype
- Manque de transparences
- Problème de cout et de scalabilité
- Enjeux éthique et juridique
