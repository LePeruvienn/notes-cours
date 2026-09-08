# Introduction à Unity

## Architechture orienté composant

C'est le fait d'avoir un objet, aucun on lui attache des "composant" pour lui donner un "rôle dans la scène".

Ex:
- On attache à notre objet un mesh et un material pour qu'il soit unobjet visible dans le jeu
- Mais si on veut par exemple une source sonore, alors je lui attache le composant "AudioSource"
- ...

En fait chaque noeud du graphe de scène est ce que l'ont appelle un "**Game Objet**" auquel on peut attacher tout les composant qu'on veut.

On peut aussi attacher des composant "custom", grâce à scripts qui avec du code auront le comportement voulu.

**Objets**
- Chaque objet dans notre Architechture as un ID et peut être instancier (cloner) et détruit

**Composant**
- On peut les ajouter aux game objects

**Behaviour**
- Dispose d'une boucle update

**MonoBehaviour**
- Classe mère de tout les script et hérite de componant et behaviour, qui permette d'implémentaire des fonction custom qu'on peut attacher à nos objets

## Inspecteur VS Code

Dans Unity l'inspecteur est dans l'éditeur une fenêtre permettant d'acceder aux proprité de l'objet.

On peut en rajouter dans le code via les `[SerializedField]` qu'on peut alors ensuite modifier directement via l'inspecteur.

## Diagramme de classe

Tout les script qu'on développe hérite souvent de la classe `MonoBehaviour` qui hérite de la classe `GameObjet`.

Il ya plusieurs autres classe et c'est plus compliqué mais c'est du détail

## Event functions

Ce sont des fonctions qui s'éxecute à certain event

- `OnAwake`
- `OnStart`
- `OnDestroy`
- ...

## Coroutine

- Permet de sortir de la boucle d'éxecution du moteur (faire des pauses)
- C'est pas du multi-threading, car c'est executer après/avant l'update ?


C'est une fonction qui renvoie un `IEnumertor` (interface d'énumération en C#).

Exmple :

```cs
IEnumertor MyCoroutine()
{
    Debug.Log("ma couroutine démarre");
    yield return new WaitFOrSeconds(2.f);
    ...
}
```

Pour démarer une coroutine on utilise `StartCoroutine`

ex :

```cs
// on garde une référence de la coroutine pour pouvoir l'arrêter si on veut ou pas ect
_myCorotine = StartCoroutine(MyCoroutine());
```

