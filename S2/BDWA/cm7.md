
## Controle

Examen de cours : de 20-25 min avec des morceaux de code.

- Commande symfony
- Morceaux de code
- Question sur le TPs

Il y aura pas de BD surtout du symfony. On as le droit à une feuille A4

# Session et Contrôle d'accès

## 1 Session applicative

### 1.3 Application peut garder de la mémoire

- On peut stocker un état avant de s'arrête (ex: base de données)
- On peut créer des sessions unique par utilisateur

### 1.4 Execution conextextualité

À chaque requete au serveur :

- Identification du client
- Démarrage de l'application
- routage vers méthode controleurs

### 1.5 Comment identifier un client HTTP

- Argument dans l'URL
- Entête particuler de requête
  - OUI : **Cookie**

On 
