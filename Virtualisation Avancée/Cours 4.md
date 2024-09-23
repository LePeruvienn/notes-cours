# On termine Kubernates


Le fichier Yaml de déploiement nginx

(voir sur le diapo)


## Les services

- une manière abstraite d'exposer une application s'exeutant sur un ensemble de **Pods** en tant que service réseau
- Chaque service ) une adresse IP et un port qui ne chaget jamais tant que le service existe

## Type de stockage en Kubernetes

- mémoire locales du noeud
- Volumes en coloud
- volumes en partage de fichiers
- Systeme de fichier distribués
- **Type de volumes spéciaux tel que PersitentVolumeClaim, secret et gitRepo**


Node -> Pod -> Container

## Persistent Volume Claim


Il faut faire une demande à chaque fois pour accéder aux données/ ou pour écrire des données

-> Un service 

## Création d'un secret


- echo -n   '[value1]' | base64
- echo -n   '[value2]' | base64

C'est comme ça qu'on chiffre des données *(dans la vrai vie on fait un chiffrement plus dur mais c'est une manière de faire)*

