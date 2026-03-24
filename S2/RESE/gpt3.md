Parfait 😎, voici **la fiche 4 ultra visuelle et synthétique**, prête pour révision ultra-rapide, qui combine IP privées/publiques, routage, sous-réseaux, TCP/UDP et WAN.

---

# 📝 FICHE 4 – RÉSEAUX VISUELLE (5 min chrono)

---

## 1️⃣ IP Privée vs Publique

```
Privée (non routable Internet)        Publique (routable Internet)
10.0.0.0/8                            Tout autre IP hors privé
172.16.0.0/12
192.168.0.0/16
```

* Machine interne → IP privée
* NAT sur routeur → traduit IP privée → IP publique
* Exemple : 192.168.1.10 → NAT → 51.12.34.56

---

## 2️⃣ Routage & Passerelle

```
PC: 192.168.1.10 /24
Destination: 192.168.8.5
Masque → calcul réseau
192.168.1.0 ≠ 192.168.8.0
→ envoi au routeur / passerelle par défaut
```

* Routeur utilise **table de routage** pour acheminer le paquet
* PC **ne connaît pas tout Internet**, juste sa passerelle

---

## 3️⃣ Sous-réseaux VLSM

```
Réseau: 192.168.10.0/24
Départements:
Comptabilité: 50 hôtes → /26 → .1–62, Broadcast: .63
IT: 30 hôtes → /27 → .65–94, Broadcast: .95
RH: 10 hôtes → /28 → .97–110, Broadcast: .111
Direction: 5 hôtes → /29 → .113–118, Broadcast: .119
```

✅ Astuce examen : empiler **du plus grand au plus petit**

---

## 4️⃣ TCP vs UDP

```
TCP → fiable, ordre, retransmission, plus lent
Ex: téléchargement, mail

UDP → rapide, non fiable, pas d’ordre
Ex: streaming vidéo, jeux, DNS
```

---

## 5️⃣ WAN – 3 niveaux hiérarchiques

```
[Accès] → utilisateur final (filaire/radio)
[Collecte / Métro] → mutualisation régionale
[Cœur / Backbone] → transport national/continent
```

* Interconnexion opérateurs : Transit (payant) / Peering (gratuit)

---

## 6️⃣ Codage & Transport info

```
Capture → Codage source → Codage canal → Transmission → Décodage
Débit = bits/sec
Temps de transit = propagation + traitement
```

* Codes longueur fixe : ASCII
* Codes longueur variable : Huffman
* Codage canal = protection contre erreur

---

## 7️⃣ Raccourci mémo examen

```
Privée → interne, Publique → Internet
Sous-réseau → réseau / hôte / broadcast
TCP = fiable, UDP = rapide
Routeur = passerelle par défaut
VLSM = optimiser chaque sous-réseau
WAN = Accès / Métro / Cœur
```

---

💡 **Truc ultime** : relis cette fiche **5 minutes avant l’examen**, et tu as **toutes les notions essentielles** avec les exemples clés.

---

Si tu veux, je peux te faire **un petit quiz flash de 10 questions en mode “vrai/faux ou QCM rapide”**, basé sur **ces 4 fiches**, pour tester ta mémoire et tes réflexes avant le contrôle.

Veux‑tu que je fasse ça ?
