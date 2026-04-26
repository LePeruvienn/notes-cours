---
title: CM2
---


# Cadre, enjeux et stratégie

- **La directive européenne NIS** (Network Information et Security)

## Législation Française

**Loi de 1978***

**Loi Godfraindu 5 janvier 1988**
- Répréssion de la criminalité informatique 
- Sanctions (emprisonement et amendes)
- ...

## Législation Européenne

**Directive**
- Acte législatif adopté par le Conseil de l'Union européenne
- Doit être **transposé** dans chaque pays !!

**Réglement**
- Acte législatif émis par une autorité autres que le parlement européen.

En fait chaque pays doit faire en sorte d'appliquer les directive, en mettant en place les reglément adapté dans chacun de leurs pays.

Exemple : **Le RGPD** !
- En france c'est la CNIL qui applique le RGPD
- Sanctions : amendes et prison


Les principes du RGPD :

- **Transparence** : il faut dire quoi et quand lorsqu'on collecte
- **Légitime** : il faut avoir des raison valable de collecter
- **Minimisation** : il faut collecter seulement ce qui est nécessaire
- **Exactitude** : il faut que les données soit juste
- **Sécurité** : il faut les garder de manière sécurisé
- **Conservation limitée** : il faut les garder seulement si on en as besoin

Le consentement doit être aussi obligatoire (libre et éclairer),

il existe néanmoins quelquest exceptions :

- Execution du contrat
- obligations légales
- intérêt vitaux
- intérêt légitime

**DPF** (Data Privacy Framework), est un accord entre l'UE et les US qui reconnait un niveau de protection équivalent à celui de l'UE.


**DORA** (Digital Operation Resilience Act),

Elle as pour objectif d'améliorer a **résilience opérationelle numérique** du secteur financier.

- C'est à dire que en cas de sinistre informatique (le DataCenter à brulé, encryptage des données), l'entreprise doit avoir les moyens de se remettre en place ses données.

# TP1 - Enquête sur une fuite de données

1)

- Identification de la cible
- Création du malware
- Ciblage de l'employé 
- Fishing (via mail)
- Elévation des privilèges
- Mouvement latéral (recherche des informations critiques)
- Accès BD et extraction des données
- Effacement des logs et empreintes

Probablement via une attaque APT (Menace Persistance Avancé)

2)

- Mot de passe faible
- Authentification faible (moins de deux étapes de connection)
- Logiciel pas à jour (faille connu sur les logiciels installés)
- Session ouverte (erreur humaine)

3)

Technique :
- Faille dans le logiciel antivirus

Humaine :
- Oublie de fermeture de session + fishing

Organisationel :
- Faible politque de sécurité de la part de l'entreprise (mot de faible, vérouillage de session non automatique)
- Non détection de l'attaque

4)

Fuite de données : 

- Sanctions RGDP
- Image publique (perte de client ? De confiance ?)

5)

Court :

- Mettre à jour les logiciels et mots de passe.
 

Moyen :

- Mettre la politque SSI : (Imposer un mot de fort, mise à jour des logiciels, vérouillage automatique, forcer le changement de mot de passe)
- Imposer des serveurs de rebonds et un bastion pour accéder aux différents serveurs de PROD/serv d'admin.
- Durcissement (ie faire le ménage des comptes inactifs/d'admin des permissions de chaque compte) Pas avoir des droits pas nécessair
e
- Forcer formation sécu au sein de l'entreprise

## Correction


