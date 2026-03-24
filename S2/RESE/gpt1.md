Parfait 💪, je te fais une **fiche ultra condensée, claire et prête pour révision rapide**, basée sur tout ton cours et le mail du prof. On va droit à l’essentiel.

---

# 📝 FICHE RÉVISION – RÉSEAUX (EXAMEN)

---

## 1️⃣ Modèle en couches TCP/IP

| Couche                | Rôle clé                       | Exemple protocole/service                                     |
| --------------------- | ------------------------------ | ------------------------------------------------------------- |
| **Application**       | Interface avec l’utilisateur   | HTTP, DNS, SMTP, FTP                                          |
| **Transport**         | Fiabilité / multiplexage       | TCP (fiable, ordre, retransmission), UDP (rapide, non fiable) |
| **Internet / Réseau** | Acheminer les paquets          | IP, ICMP, routage                                             |
| **Liaison**           | Transmission sur lien physique | Ethernet, WiFi, VLAN                                          |
| **Physique**          | Transport des bits             | Câble cuivre, fibre, radio                                    |

**Astuce examen** : connaître **le rôle et un exemple** pour chaque couche.

---

## 2️⃣ Adressage IP

* **IP = identifiant d’interface** (pas forcément machine entière)
* **Masque = détermine réseau / hôte**
* **PC → réseau différent → passe par la passerelle (routeur)**

### Formules rapides

* Nombre de sous-réseaux : (2^n \geq \text{nombre de sous-réseaux})
* Nombre d’hôtes par sous-réseau : (2^h - 2)

---

## 3️⃣ Sous-réseaux

### FLSM (Fixed Length Subnet Mask)

* Même masque pour tous
* Simple, mais gaspille des adresses

### VLSM (Variable Length Subnet Mask)

* Masque adapté à chaque sous-réseau → optimise les adresses
* Empiler du plus grand au plus petit réseau

### Exemple VLSM

Réseau : 192.168.10.0/24

| Département  | Hôtes | Masque | Plage hôtes        | Broadcast      |
| ------------ | ----- | ------ | ------------------ | -------------- |
| Comptabilité | 50    | /26    | 192.168.10.1–62    | 192.168.10.63  |
| IT           | 30    | /27    | 192.168.10.65–94   | 192.168.10.95  |
| RH           | 10    | /28    | 192.168.10.97–110  | 192.168.10.111 |
| Direction    | 5     | /29    | 192.168.10.113–118 | 192.168.10.119 |

---

## 4️⃣ Routage IP

* Comparer réseau source / réseau destination :

  * Même réseau → envoi direct
  * Réseau différent → envoi à **passerelle par défaut**
* Routeur → utilise sa **table de routage** pour acheminer
* Concept clé : **table de routage**, **passerelle**, **route par défaut**

---

## 5️⃣ TCP vs UDP

| Protocole | Fiabilité | Connexion | Débit     | Exemple utilisation   |
| --------- | --------- | --------- | --------- | --------------------- |
| TCP       | Oui       | Orienté   | Plus lent | Téléchargement, email |
| UDP       | Non       | Non       | Rapide    | Streaming, jeux, DNS  |

---

## 6️⃣ Rappel rapide sous-réseaux courants

| Masque | Adresses totales | Hôtes max |
| ------ | ---------------- | --------- |
| /24    | 256              | 254       |
| /26    | 64               | 62        |
| /27    | 32               | 30        |
| /28    | 16               | 14        |
| /29    | 8                | 6         |

> Astuce : toujours retirer **réseau + broadcast**

---

## 7️⃣ Mini-méthode pour l’examen

1. Identifier réseau source + destination (IP & masque)
2. Décider : direct ou passerelle
3. Vérifier VLSM : **empiler du plus grand au plus petit**
4. Calculer adresse réseau, broadcast, plage hôtes
5. TCP / UDP → penser **fiabilité vs rapidité**

---

Si tu veux, je peux te créer **une version encore plus visuelle**, avec **schémas rapides pour TCP/IP, sous-réseaux et routage**, pour que tu puisses réviser **en 5 minutes chrono avant l’examen**.

Veux‑tu que je fasse ça ?
