
Valentin Honoré # 2) Héritage, classes abstraites et exceptions

**Rappel** :
- Structure de données (soit tuple soit tableau) **s'appelle un objet** qui est une **classe**
- Une classe **définis des attributs et des méthodes** avec son **Constructeur** et **destructeur**
- Chacun de ces él&ments a **une visiblitée** propre : (private,  public, protected)

### 1) Héritage

**Amélioré la réusabilité du code**
- En écrivant du code générique et factorisant des fonctionnalitées

**Exemples :**
- Class animal avec des classes enfant (chien , chat) qui ont des fonctionne commune (marcher)
- Objet d'un jeu vidéo (item) avec plusieurs classes filles (nourriture arme) un attribut commun (prix) et fonction commune (achter)

**Une classe dite fille peut hériter d'une autre classe dite mère**
- La classe fille hérite des méthode et attribut de sa classe mère
- Elle peut aussi en ajouter pour se spécialiser.

**-> La classe fille deviens un nouveau type et qui compatible avec sa classe mère !**

L'héritage est transitif : donc si A hérite de B qui hérite de C alors A hérite de C !

#### Transtypage

Une classe fille possède le meme type que sa classe mère !

```java
Item item = new Weapon(); // Valide !
```

Par contre deux classes fille qui hérite de la meme classe mère ne possède pas le meme type !

```java
Food food = new Weapon(); <- PAS VALIDE !!!

// MAIS :
Item item = new Weapon(); // Valide !
Item item = new Food(); // Valide !
```

#### Héritage et constructeur

La première instruction d'un constructeur d'une classe fille doit être une invocation du constructeur de la classe mère. *(je crois qu'en vrai t'es pas obligé mais c'est souvent plus pratique)*

```java
class Item {
	private int weight;
	public void setWeight(int w) { weight = w}
	public Item() { super(); }
}
```


#### Héritage et Surcharge

On peut reécrire lees fonction des classe mère avec un `@Override` afin de les redéfinir !

```java
class Item {

	public void render() {
		// Print item se nomme bla bla
	}
}

class Weapon extends Item {

	public int degats;

	@Override
	public void render() {
	
		// Print Cette arme se nomme blabla et fait 10 dégats !
	}
	
	// On pourrais aussi la dedéfnir en utilisant la méthode de la classe mère avec super !
	
	@Override
	public void render() {
	
		super.render() // Print Cette item se nole bla bla
		// et fait 10 dégats !
	}
}
```

On peut surcharger les fonction (c'est à dire définir plusieurs fois la même fonction dans la même classe) en changeant soit ses attribut soit son type de retour !

```java
class A {

	@Override
	public void affiche(int a) {
	}
	
	public void afficher(String a) {
	}
}
```


#### Modificateur : Final

Permet de définir des variable qu'on peut modifier mais dont on ne peut pas changer sa référence

```java
final Item = new Item();
item.name = "test"; // Autorisé
item.price = 2; // Autorisé 
item = new Item() // INTERDI !!!
```

#### Ecapsulation

- **Private** : Visible seulement dans la classe et nulle part ailleurs
- **Protected** : Visible par toutes les classes qui sont dans le même package
- **Public** : Visible par toute les classes

#### Polymorphisme

Permet d'attribué à un objet d'être une instance de plusieurs classe !
- Comme `Weapon` et `Food` qui peuvent être tout les deux des instance aussi de `Item`

**Info : Toutes les classes hérite de la classe nommé Object !**
- Cette classe possède la méthode toString() qui permet d'afficher des infos sur l'objet en question (de base ça affiche juste la référence ne mémoire).
- **IMPORTANT** : Le prof à dit de redéfinir cette méthode dans toutes les classes  qu'on créer afin à la place afficher des infos lié à notre classe (sinon *bruit de coup de fouet* ).

#### Classes et méthode abstraite

On peut vouloir définir des classes et des méthodes qui doivent être instancié ou utlisé **uniquement via leurs classes filles** !

On peut faire ça grâce au mot clé `abstract`. Cela fait en sorte que la classe fille à l'obligation de redéfinir ces méthode ou de les remettre aussi en abstract.


```java
// Classe qu'on ne peut pas instancié mais on peut créer des classes qui en hérite !
// En fait c'est logique avec un Objet Animal tout court ça existe pas il ya toujours un type (chie, chat ...)
// IL EST PAS POSSIBLE DE FAIRE new Animal() !!! INTERDI -> il est interdit d'instancier les classes abstraite (comme jlai expliqué en haut c pas logique)
abstract class Animal {
	....
	
	// Classe abstraire à redéfinir dans les calsses enfant
	public abstract void manger();
}

class Chien {
	
	public void manger () {
		// Ici on définit comment le chien mange
	}
}
```


#### Interfaces

**Limites de l'héritage JAVA** : On peut hériter seulement d'une seule classe à la fois !
-> SOLUTION : Utiliser les **Interfaces** !

Les **Interfaces** sont :
- Un peu près comme les classes abstraite fonctionne de la meme façon (sauf que la au lieu de `extends` on écrit `implements`)
- Elles peut seulement définir des méthode et pas des attributs, qu'on est obligé d'implémenter dans les classes.
- On peut peut pas les instancier
- On peut implémenter plusieurs interfaces en meme temps !

*Le Prof : "On peut voir les interfaces un peu comme le truc le plus abstrait qu'on peut faire !"

```java
interface Weapon {
	public int getDamage();
}

interface Potion {
	public void Drink();
}

// Notre poisin est une arme et une potion en meme temps !
class Poison implements Weapon, Potion {

	// Obligé d'implétemeter les méthode de Weapons
	public int getDamage() {
		...
	}
	
	// Obligé d'implétemeter les méthode de Potion
	public void Drink() {
		...
	}
}
```

## 2) Exceptions

Le but des exception est de pouvoir **gérer les erreurs créer par le programme** !
Elle permet de faire des actions spécifique lors d'exécution anormale du programme (par exemple si on divise par zéro)

**Exemple** : Imaginons on veut gérer l'érreur quand on divise par zéro
- On peut renvoyé - infini (un peu nul)
- Afficher un message d'érreur spécifique et renvoyer 0


Ces exception afin de remonter par exemple des erreur qui se trouve bas dans les les appelles de fonction


**Mot clés** :
- Pour lever une exception on utlise la mot clé `throw`
- Pour définir quelles exception sont lévé par une fonction on utlise `throws`
-> A NE PAS CONFONDRE !

**Gérer les exception**

Toutes les exception hérite du type `Exception`, on peut en créer de nouvelles.
Voici 3 exception utile :
- ClassCastException
- IllegalArgumentExcetion
- IndeexOutOfVBOundsException


Ces Exception sont utlisé afin de changer le comportement du programme en fonction de celle qui est lever.
Pour gérer les exception on utlise les mot clé `try`, `catch` et `finally`

```java
void double log(double x) throws NegativeValue {

    if (x <=0) throw new NegativeValue;

    else return Math.log(x)
}

try {

    log(0)

} catch (NegativeValue e) {

    System.out.println("Vous avez entré une valeurs négative, recommencer");

} finally {

    System.out.println("Fin d'execution du programme")
}
```

- `try` : permet de définir un block ou l'ont va effectuer des actions qui vont potentiellement levé une exception.
- `catch` : si l'exception en paramêtre est levé, execute le code qui est dans le block.
- `finally` : block qui s'execute quoi qu'il arrive après le try et enventuellement le catch.


**Conseils** :
- Utlisé que les exception pour les cas exceptionelle.
- N'attrapez que les exception si vous avez quelque chose d'intéressant à faire avec.


**Les différents érreurs en JAVA**
- Erreur de compilation 
- Erreur d'execution 
- Exception non vérifier : Arret du programme -> Solution gérer l'exception
- Exception vérifier : Le programme remonte une exception -> Solution changer les param du programme


#### Mais ou sont les objets ?

En fait en TP on créer plein de classes et d'Exception mais JAVA en fournis aussi déjà par défaut. On les retrouves souvente dans le package `Java.Utils`.

Il peuvent forunir par exemple des interfaces et des classes.


#### Les deux familles de structure de données

En faisant un `import java.utils` on as accès à plusieurs structure de données dont les collections.

La collection stocke une collection d'éléments
- Tableaux extensibles  : `ArrayList`
- Listes chainées : `LinkedList`
On peut y acceder avec de **itérateurs**

La liste d'associe des clé et des valeurs
- La table de hachage : `HashSet`
- L'arbre binaire de recherche : `TreeSet`
Permet d'associer une clé avec une valeurs


#### Collection d'éléments

Interface `Collection<E>` (avec E c'est le type qu'on veut)


#### Les itérateurs

Un itérateur permet de  force à toi j'ai pu eu le temps de noter


# 3) Architechture logicielle

Il faut réfléchir avant de coder 🤓 Le but est de comprendre quelles classes, sous classes, intefaces on va devoir créer afin de développer la meilleur appli possible.


**UML** : c'est un type de schéma qui permet de modéliser les classes et interfaces de notre application. C'est dessus qu'on va créer modéliser l'architechture logicelle de notre application.

#### Les diagrammes de cas d'utilisation et de séquence.

Il ya plusieurs type de diagrammes

**Diagramme de cas d'utilisation** : Ensemble de scénario réalisant un objetif utilsateur.

Dans ces diagramme on modélise essentiellement 2 éléments : 
- Les utilisateurs
- Leurs actions
Dans le schéma on lit les utilisateurs à leurs actiosn qui leurs sont possible de réaliser.

C'est ici ou on définis tout les possibles utilisateurs de l'application et toutes leurs actions possibles.
-> Par exemple : Utilisateur adim peut supprimer des articles, et utilisateur client peut consulter le catalogue.

Les différents utilisateurs de l'application peuvent hériter d'autres utilisateurs afin de généralier les intéractions.
-> Par exemple un Admin peut acceder au catalogue du site tout comme un client, on peut alors les faire hérité de l'utilisateur "visiteur du site" afin de généralisé les interaction.

On peut aussi relier les actions avec des "includes", c'est à dire que l'action qu'on créer dépend du fait qu'une action précédente à bien été faite avant.
-> Par exemple : Payer includes ajouter un article dans son panier.

On peut aussi faire queqlue chose de similaire avec "extends" qui implique que l'action

**Diagramme de séquence**

Souvent le diagramme de se fait après avoir faire le diagramme d'utilisation.

**Elle permet de dérire une action utlisateur via ses intéraction avec notre application.**
- Dedans on va montrer les requetes effectuer par le client sur l'application via des fleche vers la droite
- Puis on va représenter les réponse de l'application via des fleche en retour.

Par exemple, pour commander: 
```
Client -> Commande(article) -> Site Web
Client <- Message(commande confirmer !) <- Site Web
```

⚠️ Ce diagramme peut représenter un dialogue entre plusieurs utilisateur mais jamais directement ! Il as toujours le but de montrer les intéraction des différents utilisateurs via notre system. (doc en gros on met toujours un system dans notre diagramme, et les utilisateurs ne communique jamais directement entre eux)


#### Diagramme de classes

Ici on vuet juste modélié le systeme interne et avec les différentes classes qui le compose.

Dedans chaque classes est représenter par une rectangle avec :
- **le nom de la classe** au dessus
- **attribut** et **méthodes** à l'interieur ou on précise leurs **visiblitée** (private public ...)


On peut créer une **relation entre les classes via des fleches** relier entre elles.
**Il peut avoir plusieurs type de relation d'associations**.

**Association classqiue avec flèche pleine**
Elle est utlisé pour parler d'action qui sont effectuer entre les classes.

- On peut définir les roles des différentes classes par rapport aux autres
  Ex : La classe Apprenti ---Travaille-->  Classe Entreprise

- Dans ces fleche on peut aussi dire combien de relation chaque classes ont par rapport à l'autres
  Ex: La classe Apprenti .1 --Travaile--> 0.* Classe Enterprise.
  Ici on voit que un apprenti à toujours 1 entreprise. Mais une entreprise à de 0 à * (signifie infini) nombre d'apprenti



**Association Agrégation (flèche avec un losange à la fin)**
Elle est utilisé pour dire qu'une classes possède plusieurs attribut qui sont eux meme d'autres classes.
-> Ex: Un maille est agréer avec, un titre, un message, un auteur et un destinataire.
   Donc on relie la classes mail avec le losange partant de la classe mail

Exemple de diagramme de classes avec agrégation de mail

```
          titre
            |
            |
            ^
            v
auteur---<>mail<>---destinataire
            ^
            v
            |
            |
          message

- Légende

<> : Losange horizontale

^ 
v : Losange verticale
```


**Héritage (fleiche pas pleine avec pointillé)**

L'héritage entre les classe se fait avec uen fleche pas pleine et avec des pointillé
```
Classe fille - - - - - |> Classe mère
```

