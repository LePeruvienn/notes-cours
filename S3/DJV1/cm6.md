# Animation

À quoi ça vous fait penser ?

- Cinématique
- Keyframe (Etat-Clé) c'est l'était à un instant T de notre objet (position, scale, rotation, ...)
- Sprite
- Mouvement
- Rig / Skeleton, c'est le squelette "de notre modèle" avec tout les articulation qui permette de définir comment notre modèle se transformen
- Blend, c'est la manière dont on transitionne entre deux animations, mais ça peut aussi faire référence à jouer plusieurs animation en même temps sur un même modèle (par exemple séparer haut du corps / bas du corps)
- Blender (Logiciel) (GOAT) (😎)

## Timeline et keyframes

Les animations sont définis avec des keyframes sur une timeline

- Chaque keyframe possède les données de l'objet qu'on veut animé à un instant T (position, couleur, rotation, ....)
- Puis le moteur d'animation va faire de l'interpolation pour définir le mouvement entre les différentes frames
- On peut utiliser des courbes de bézier pour avoir plus de précisions sur les valeurs entre les keyframes.


## Animator (Unity)

C'est une machine à état permettant de définir quelles animation est jouer à quelle moment.

Il permet de définir l'ensembes des animations possible d'un objet :

- On peut dedans la décomposer en sous-machine à état
- On peut y définir des blend-tree pour définir les différentes transitions entre mes animations
- On peut y rajouter des paramêtre (`int`, `float`, `bool`) qui en fonction de leurs valeur perme de changer d'animation
- On peut rajouter des conditions de sorties (temps ou des conditions sur des paramêtre)

> NOTE: Le paramêtre de type `Trigger` est un booléen qui se remet automatiquement à false à la frame suivante.

## Blend

Elle consiste à mélanger plusieurs animations.

- Par exemple lorsqu'on change d'animation, on peut jouer les deux animations en même temps pendant un cours instant pour avoir une transition plus douce.

- On peut aussi fair du blend avec plusieurs calques en animation avec un blend-tree.

### Blend Tree

Elle permet de jouer plusieurs animatio ne même temps au sein d'un même état.

- Par exemple elle permet de mélanger les différente animations de marche (avant, recul, droite, gauche), pour les "mélanger" lorsqu'on avance en diagonal !

On peut blend plus une animation ou une autres avec un facteur.

### Calques

On peut créer des **Mask** sur le rig afin de séparer plusieurs partie du cors de l'animation.

Ensuite dans blender on peut créer un blend-tree par partie du corps afin de pouvoir jouer plusieurs animations en même temps.


## Paramêtre

Petit exemple de code

```cs
private Animator _animator;
private int _forwardID;
private int _dieID;

protected void Awake()
{
    _animator  = GetComponent<Animator>();
    _forwardID = Animator.StringToHash("Forward"); // ATTENTION AU NOM!!
    _dieID     = Animator.StringToHash("Die");     // Evitez les espaces et caractère spéciaux !
}

public void Method()
{
    _animator.SetFloat(_forwardID, 5.0f);
    _animator.SetTrigger(_dieID);
}
```

Il faut évitez de nommé nos paramêtre avec des espaces ou caractère spéciaux car on y références par leurs nom directement !!

## Animation de personnages


### Modélisation en T-pose t A-pose.

Souvent en modélisation on la pose par défaut se fait en **T-pose** et en **A-pose**.

C'est car lorsqu'on va animer ces modèle la, les différentes mesh et textures du modèle vont être déformer de façon à faire l'animation. Si notre personnage est dans une position ou il y a déjà beaucoup de membre plier, alors lorsqu'on va le remettre dans une position plus naturelle, alors il y aura beaucoup de mesh et de texture qui vont être déformer.

On veut alors évitez au plus les membre plier donc on essaye de créer les modèle humanoide on préfère les mettre dans une position avec les membres les moins plié possible.

Donc on préfère modéliser dans ce genre de pose !

**Mais pourquoi la A-pose est mieux que la T-pose ?**
- Car la A-pose est une position plus naturelle pour les modèle donc il y aura souvent moins de déformation.
- En T-pose lorsqu'on va plier les bras autour de notre corps, les vertices de l'épaule vont être déformer.


## Rigging


C'est le squelette de notre mesh avec toutes ses articulations.

C'est la qu'on définit ou il y aura de la déformation dans notre mesh.

## Skinning

C'est le fait de définir quelles vertices est lié à quelle rig.

Donc quelle est l'impact as le déplacement du rig sur se vertices la.

De plus ont peut aussi mettre plusieurs rig sur les même vertices avec des degré "d'impact" plus ou moins faible. De cette façon lorsqu'il y a des rig qui se déplacent en même temps tout peut être déplacer au même moment qu'il y ai un mouvement uniforme pour chaque vertices.

Le but est d'éviter qu'un rig controle complétement tout une partie des vertices ce qui peut créer des mouvemet moins naturelle.


## Blend Shape

?



