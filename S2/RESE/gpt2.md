---
title: GPT2
---

Parfait 😎, je vais te faire **une deuxième fiche condensée**, avec d’autres points essentiels tirés de ton cours, pour compléter la première. On va se concentrer sur **WAN/LAN, topologies, interconnexion, transport d’information**, bref tout ce que ton prof a insisté.

---

# 📝 FICHE RÉVISION 2 – RÉSEAUX (complémentaire)

---

## 1️⃣ Types de réseaux selon la portée

| Type    | Portée / Exemple            | Débit                  | Usage                         |
| ------- | --------------------------- | ---------------------- | ----------------------------- |
| **PAN** | 1–10 m (Bluetooth, USB)     | Haut débit             | Équipements personnels        |
| **LAN** | 100 m–1 km (Ethernet, WiFi) | Très haut débit        | Réseau d’entreprise ou maison |
| **MAN** | 1–50 km                     | Moyennement haut débit | Réseau urbain ou campus       |
| **WAN** | >50 km (Internet, MPLS)     | Variable               | Interconnexion sites distants |
| **RAN** | Région / ville              | Variable               | Réseau mobile                 |

> Astuce examen : connaître **différences portée / débit / usage**.

---

## 2️⃣ Topologies réseau

| Topologie | Avantages                 | Inconvénients                      |
| --------- | ------------------------- | ---------------------------------- |
| Bus       | Simple, peu coûteux       | Collision, panne câble bloque tout |
| Étoile    | Facile à administrer      | Dépend du noeud central            |
| Anneau    | Accès déterministe        | Panne d’un poste bloque le réseau  |
| Maillé    | Très fiable               | Très coûteux en câbles             |
| Hybride   | Mixe plusieurs topologies | Complexité de gestion              |

**Astuce examen :** savoir distinguer **physique vs logique**.

---

## 3️⃣ Mode de gestion

* **Client-serveur** : centralisation, administration facile, sécurité +
* **Pair-à-pair (P2P)** : décentralisé, facile pour petit réseau, pas de serveur central

---

## 4️⃣ WAN et organisation des réseaux étendus

* WAN = réseau sur longue distance, souvent loué chez un opérateur

* Composé de **3 niveaux** :

  1. **Accès / Desserte** → connexion finale utilisateur (filaire ou radio)
  2. **Métro / Collecte** → collecte régionale, mutualisation
  3. **Cœur / Backbone** → transport national / continental, très haut débit

* Modes d’interconnexion :

  * **Transit** : opérateur paye pour acheminer trafic
  * **Peering** : échange gratuit de trafic entre opérateurs (direct)

---

## 5️⃣ Transport de l’information

* Étapes :

  1. Capture → analogique ou numérique
  2. Codage source → compression, codage binaire
  3. Codage canal → protéger contre bruit / erreurs
  4. Transmission → support physique (câble, fibre, radio)
  5. Décodage → restitution au destinataire

* Débit binaire : nb de bits / seconde

* Temps de transit : dépend vitesse propagation + traitement équipements

---

## 6️⃣ Codage source et canal

* **Codes longueur fixe** : même nb bits par symbole (ex : ASCII)
* **Codes longueur variable** : taille adaptée à probabilité symbole (ex : Huffman)
* Codage canal → ajoute redondance pour corriger erreurs

---

## 7️⃣ Couche Internet et routage

* Routeur = décide du chemin via table de routage
* Route interne = IGP (ex : OSPF, IS-IS)
* Route externe = BGP (entre AS, Internet)
* **AS (Autonomous System)** → ensemble de réseaux contrôlé par une seule entité
* ISP tiers :

  * Tier 1 → backbone mondial, 100% peering
  * Tier 2 → mix transit / peering
  * Tier 3 → achète transit

---

## 8️⃣ Services applicatifs et multimédia

* **Services classiques** : DNS, email, Web
* **Services multimédia** : streaming, VoIP
* Multimédia → combine voix, vidéo, données → nécessite QoS
* Objectif : **transport efficace de différents types de flux sur un même réseau**

---

💡 **Mémo express examen :**

> “Réseaux = définir portée, topologie, gestion, transport.
> WAN = Accès / Métro / Cœur.
> Routage = table + passerelle.
> Codage = source + canal.
> TCP/UDP = fiabilité vs rapidité.
> VLSM = optimiser chaque sous-réseau selon besoin.”

---

Si tu veux, je peux maintenant te faire **une fiche 3 avec des schémas et exemples concrets** (IP, sous-réseau, TCP/UDP, routage) pour **révision visuelle ultra rapide** avant l’examen.

Veux‑tu que je fasse ça ?
