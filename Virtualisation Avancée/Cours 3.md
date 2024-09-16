# Kubernates

kubernates est poen sourcs



Comment interafr avec le cluster ??

kubectl


**Master Node** gère toutes les différentes node


## Les pods et des noeuds


**Un noeuds** : machine de travail de kubernates


## Workload


Work load (charge de travail) est une applications fonctionnant sur kubernates


## Deployement

- C'est un objets Kubernetes
- Créations de Pods et deReplicaSets
- Enregistrement du déploiement, qui permet après de revenir à un état anterieur


## Modules de base Kubernates

1) Crée un cluster kubernates
2) Déployer une application
3) Explorez votre application
4) Exposer votre appkication publiquement
5) MEttre à l'échelle votre application
6) Mettre à jour votre application

## RéplicationControllers



### Crée un cluster

**Minikube**

C4est ne distribution allégée de Kubernetes, qui assure une performance maixmale pour utilisé es fonctions de Kubenetes tout en profitant d'une cahrge de travail minimale

- Hyper opti pour les contenaire et cluster


### Kubectl

Commandes qui permettes de controlé les cluster kubernetes

- **kubectl get** : liste les ressources
- **kubectl describe** : affiches les infos sur une ressources
- **kubectl logs** : affches le journale d'un conteneur dans un pod
- **kubectl exec** : execute une commande sur un contener dans un pod


### Utiliser kube ctl pour créer un déloiement


- kubectl create deployment nom --image=nom-images
- kubectl create deployment ngix-dep --image=nginx
  
- kubectl get deployments
- kube describe deployment ngnix-dep
- kube logs deployment ngnix-dep
- kubectl delete deployment nginx-dep



C'est mieux de créer une deployment à chaque début de projet, car créer un deployment créer un cluster en meme temps


### Les fichiers YAML

- Le déploiement des Kubernetes Yaml conteint des princapes spécifications suivantes
	- **apiVersion** => apps/v1 (la version stable)
	- **Kind**
	- **metadata**
	- **spec**

*(Voir diapo pour exemple)*

Tout les diapo sont sur moodle (cours 2)


