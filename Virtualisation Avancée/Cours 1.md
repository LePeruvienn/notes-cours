**Pourquoi virtualiser ?**
- Optimisation des ressources
- Flexibilité
- L'isolation


Machine hôte
	+
Machine invitée (VM)

Chaque machine virtuelle à une IP et utilise l'hardware de la machine hot


**2 type de virtualisation:**

Légère et dure

Virtualisation dure = rajout de machine sur la machine hote (Virtualized Deployemet)
-  C'est le Hyprvisor qui fait le lien entre les machine virtuelles et l'OS/hardware
  
VIrtualisation légère = virtualisation sur un docker (Container Deployement)
- C'est le Container runtime qui fait le lien


## Bases des conteuneurs


Conteuneur = méthode de virtuailisation


Docker = plateforme qui permet de déployer des applications te de les tester facilement


**On execute des contenuer sur DOCKER**
- Les conteneur sont créers à partir d'un modèle à partir d'images

Un conteneuur conteint tout ce dont une application logicielle a besoin pour s'executer


```sh
docker pull image #en local
```

Permet de récupérer une image docker

doker hub -> permet de trouver des images officiels *(Mysql, PHP, ...)*


!! Pour qu'un service fonctionne il faut lui attribuer un port et éventuellement une entrée clavier, micro ...

Dans les ports il y a les **well known port** qui sont les port connu par leurs fonctionnalités:
- 80: HTTP
- 21: FTP
- 22: SSH
- 443: HTTPS
- 3393: RDP
- 476: SMTP


 **DOCKER ENGINE** c'est un run time qui permet de lancer des applications


*Allez voir les commandes essentiels docker pour mémorisez*


**RESEAUX DE DOCKER**

```sh
docker network create [OPTIONS] NETWORK
```


**DOCKER COMPOSE**

PEret de composer un résaeux de plusieurs docker à l'aide un fichier de configuration `.yaml`

Ex: MySQL Wordpress (les dans dans un containeur séprarer et tout regrouper dans une docker compose)


