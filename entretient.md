# Sommaire des éléments à réviser :

1. [Ligne de commande Bash (ou équivalent)](#ligne-de-commande-bash-ou-équivalent)
2. [Système Linux](#système-linux)
3. [Routage IP](#routage-ip)
4. [Protocole TCP](#protocole-tcp)
5. [Service DNS](#service-dns)
6. [Inversion de matrice](#inversion-de-matrice)
7. [Intégration par parties](#intégration-par-parties)
8. [Développement limité](#développement-limitée)
9. [Probabilité conditionnelle](#probabilité-conditionnelle)
10. [Loi de De Morgan](#loi-de-de-morgan)
11. [Complexité au pire cas](#complexité-au-pire-cas)
12. [Liste chaînée](#liste-chaînée)
13. [Graphe non orienté](#graphe-non-orienté)

---

## 1. Ligne de commande Bash (ou équivalent)

**Éléments clés à réviser :**
- **Commandes de base** : `cd`, `ls`, `cp`, `mv`, `rm`, `touch`, `echo`, etc.
- **Gestion des fichiers** : redirection (`>`, `>>`), pipes (`|`), et redirection d’erreur (`2>`).
- **Variables d'environnement** : `$PATH`, `$HOME`, `$USER`, etc.
- **Boucles et conditions** : `for`, `while`, `if`, `case`.
- **Manipulation de fichiers et dossiers** : utilisation de `find`, `grep`, `cut`, `awk`, `sed`.
- **Permissions** : `chmod`, `chown`, `chgrp`.
- **Exécution de scripts** : comprendre les shebangs (`#!/bin/bash`).

---

## 2. Système Linux

**Éléments clés à réviser :**
- **Architecture de base** : noyau, gestionnaire de processus, système de fichiers.
- **Commandes de gestion de processus** : `ps`, `top`, `kill`, `htop`.
- **Gestion des utilisateurs et groupes** : `useradd`, `passwd`, `groupadd`.
- **Gestion de l'espace disque** : `df`, `du`, `fdisk`.
- **Gestion des services** : `systemctl`, `service`.
- **Logs systèmes** : fichiers sous `/var/log` et commandes `dmesg`, `journalctl`.
- **Installation de logiciels** : `apt`, `yum`, `rpm`, `dpkg`.

---

## 3. Routage IP

**Éléments clés à réviser :**
- **Table de routage** : comprendre le contenu de la table (`ip route`, `netstat -r`).
- **Types de routage** : statique vs dynamique (RIP, OSPF, BGP).
- **Commutation de paquets** : comment les paquets sont acheminés sur un réseau.
- **Sous-réseaux et CIDR** : calcul de sous-réseaux, notation CIDR (`/24`, etc.).
- **Masques de sous-réseau** : relation avec les adresses IP et le routage.

---

## 4. Protocole TCP

**Éléments clés à réviser :**
- **Modèle OSI et TCP/IP** : couche transport (TCP), encapsulation et dé encapsulation.
- **Connexions TCP** : établissement et fermeture de connexion (SYN, ACK, FIN, etc.).
- **Contrôle de flux** : fenêtre glissante, congestion.
- **Port et sockets** : numéros de port, notion de socket (ex : `localhost:8080`).
- **Fiabilité de TCP** : retransmissions, séquencement, détection d'erreurs.

---

## 5. Service DNS

**Éléments clés à réviser :**
- **Résolution DNS** : fonctionnement de la résolution des noms (récursif et itératif).
- **Enregistrements DNS** : A, AAAA, CNAME, MX, NS, PTR.
- **Serveurs DNS** : serveurs autoritaires, caches, et serveurs de résolution.
- **Zones DNS** : zones directes et inverses.
- **Cache DNS** : explication du cache et des TTL (Time To Live).

---

## 6. Inversion de matrice

**Éléments clés à réviser :**
- **Méthode d'inversion** : utiliser la méthode de Gauss-Jordan ou la méthode des cofacteurs.
- **Propriétés des matrices** : matrice inversible, non inversible, singularité.
- **Calcul d'inverse** : formule de l'inverse d'une matrice $2 \times 2$ et $3 \times 3$.

---

## 7. Intégration par parties

**Éléments clés à réviser :**
- **Formule d'intégration par parties** : 
  $$
  \int u \, dv = uv - \int v \, du
  $$
- **Choix des fonctions $u$ et $dv$** : critères pour choisir la fonction à dériver et celle à intégrer.
- **Applications classiques** : intégration des produits de fonctions, réduction d'intégrales.

---

## 8. Développement limité

**Éléments clés à réviser :**
- **Concept de développement limité** : approximation d’une fonction autour d’un point.
- **Formule de Taylor** : 
  $$
  f(x) = f(a) + f'(a)(x-a) + \frac{f''(a)}{2!}(x-a)^2 + \cdots
  $$
- **Applications du développement limité** : approximation des fonctions, calculs numériques.

---

## 9. Probabilité conditionnelle

**Éléments clés à réviser :**
- **Définition** : 
  $$
  P(A|B) = \frac{P(A \cap B)}{P(B)}
  $$
- **Propriétés** : règle de multiplication des probabilités, indépendance conditionnelle.
- **Applications** : jeux de hasard, systèmes de filtrage.

---

## 10. Loi de De Morgan

**Éléments clés à réviser :**
- **Formulation des lois** :
  - $$
    \neg (A \land B) = \neg A \lor \neg B
    $$
  - $$
    \neg (A \lor B) = \neg A \land \neg B
    $$
- **Applications logiques** : simplification de formules booléennes et circuit logique.

---

## 11. Complexité au pire cas

**Éléments clés à réviser :**
- **Notations asymptotiques** : $O(n)$, $O(\log n)$, $O(n^2)$.
- **Analyse des algorithmes** : analyse du temps d'exécution au pire cas (ex : recherche dans un tableau, tri, etc.).
- **Exemples courants** : tri à bulles ($O(n^2)$), tri rapide ($O(n \log n)$).

---

## 12. Liste chaînée

**Éléments clés à réviser :**
- **Structure de données** : liste chaînée simple, doublement chaînée, circulaire.
- **Opérations** : ajout, suppression, recherche, inversion.
- **Complexité** : comparaison avec les tableaux (avantages/inconvénients).

---

## 13. Graphe non orienté

**Éléments clés à réviser :**
- **Définition** : ensemble de sommets et d'arêtes non orientées.
- **Représentation** : matrice d'adjacence, liste d'adjacence.
- **Propriétés** : connexité, cycles, arbres couvrants.
- **Algorithmes classiques** : BFS (Breadth-First Search), DFS (Depth-First Search), Dijkstra (pour les graphes pondérés).
