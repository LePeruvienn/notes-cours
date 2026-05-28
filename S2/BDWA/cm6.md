# 1. Fonctionnement d'un serveur 

## 1.1 Role du serveur HTTP

Comprendre les requetes HTTP des clients
- URL
- 

Construire la réponse
- Servir des documents
- Executer des programmes

Renvoiyer une réponse au client
- HTML, JSON, ect ...

Exemple de serveur : HTTP, Nginx, PaaS 

## 1.4 

Construction de la réponse HTTP des résultats d'execution
- Code de retour -> Code de Statut 
  - Succès (0) = 200
  - Erreur (!= 0) = 500

## 1.5 Serveur HTTP intégrer à PHP

Permet de tester le comportement serveur d'application PHP simplement en local

# 2. Interface HTTP évenmentielle, en Objet

## 2.1 Appel de méthode

Pricipe d'une *Application Programming Interface* (API)
- On appel des objets qui execute des méthode

## 2.6 Routage

Définitions des routes avec PHP `Route`

```php
class TodoController extends Controller {
    #[Route('todo/[id]')], name: 'todo_show',
        requierments: ['id' => '\d+'], method: ['GET'])]
    public function showAction(Todo $todo): Response {
        
        return ... ;
    }
}
```

Puis dans le HTML pour call l'action :

```html
<form action="todo_show" method=GET>
</form>
```

# 3. Gabarits (templates)

## 3.2 Moteur de gabarits Twig

Dans le PHP on déinis des variables

```php
array(
    'title' => "Ma page"
    'navigation' => array(
        array("href" = "/tasks/", caption = "Taches")
        array("href" = "/imgs/", caption = "Images")
        ...
    )
)
```

Ensuite on peut les utiliser dans le HTML de cette façon

```html

<h1> {{ title }} </h1>
<li>
    {% for item in navigation %}
        <li> <a href="{{ item.href }}"> {{ item.caption }} </a></li>
    {% endfor %}
</li>
```

## 3.4 Programmer en Twig

Similaire à Python, plutot simplement


```html
{% extends base.html.twig %}

{% block title %}{% endblock %}

{% block body %}
    ...
    {{ parent() }}
    ...
{% endblock %}

<h1>
    {% block("title") %}
</h1>

<main>
    {% block("body") %}
</main>
```


## 3.8 Coder en Symfony

On peut console.log les variables

Avec la fonction `dump` en twig

```
{% dump todo %}
```

Le problème c'est qu'il peut avoir différent affichage différents en fonction de l'environnement.

Sinon pour debug il y a le `Rendering Call Graph` qui nous indique quels bloc Twig sont surcharger
