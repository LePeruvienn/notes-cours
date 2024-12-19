# Fiche de Révision - Programmation Multimédia : L'image

## 1. Chaîne de traitement des médias
- **Étapes** :
  1. Acquisition de l’information depuis le monde réel (ex : capteur optique).
  2. Encodage, stockage, et édition des données.
  3. Restitution dans le monde réel.

---

## 2. Représentations des couleurs
- **Synthèse additive (RGB)** :
  - Couleurs primaires : Rouge, Vert, Bleu.  
  - Utilisée pour les écrans.
- **Synthèse soustractive (CMY)** :
  - Couleurs primaires : Cyan, Magenta, Jaune.  
  - Utilisée pour l’impression.

- **Modèles alternatifs** :
  - **HSV** : Teinte, Saturation, Luminosité. Avantages : Décorrélation des composantes.
  - **CIELAB** : L (Luminosité), a (Vert-Rouge), b (Bleu-Jaune). Utile pour évaluer la qualité de compression.

---

## 3. Histogramme et transformation d’image
- **Histogramme** : Représente le nombre d’occurrences des niveaux de gris ou des couleurs.
  - **Améliorations** :  
    - Normalisation : Étend les niveaux de gris sur toute la plage.  
    - Égalisation : Rend la répartition plus uniforme.  
    - Transformations logarithmiques ou exponentielles pour ajuster le contraste.

---

## 4. Filtrage
- **Filtrage linéaire (convolution)** : Utilise un noyau pour lisser ou détecter des contours.  
  - Ex. : Filtrage passe-bas (lissage).  
- **Filtrage non linéaire** :  
  - **Filtrage médian** : Élimine les bruits tout en préservant les contours.
  - **Filtrage gaussien** : Lissage avec une pondération gaussienne.

- **Détection de contours** :  
  - Sobel : Calcul des gradients horizontaux et verticaux.  
  - Canny : Détection précise des contours en combinant gradients et seuillage.

---

## 5. Classification et seuillage
- **Seuillage** : Conversion d'une image en niveaux de gris en une image binaire.
  - Ex. : Méthode d’Otsu pour déterminer automatiquement le seuil optimal.
- **Clustering (K-means)** : Regroupe les pixels en classes basées sur leurs caractéristiques (ex : couleurs).

---

## 6. Morphologie mathématique
- **Principes** : Manipulation d’images binaires avec des éléments structurants.
  - **Dilatation** : Agrandit les zones blanches.  
  - **Érosion** : Réduit les zones blanches.  
  - **Ouverture** : Érosion suivie de dilatation.  
  - **Fermeture** : Dilatation suivie d’érosion.  
- **Applications** : Élimination de bruit, détection de formes.

---

## 7. Étiquetage en composantes connexes
- **Objectif** : Identifier et étiqueter des régions connexes dans une image binaire.
  - Ex. : Détection d’objets tels que des panneaux.

---

## 8. Formats d’image
- **BMP** : Pas de compression. Fichiers volumineux.  
- **PNG** : Compression sans perte. Supporte la transparence.  
- **JPEG** : Compression avec perte. Taille réduite.  
- **WEBP** : Format moderne avec ou sans perte, supporte les animations.

---

## Outils recommandés
- **OpenCV** :
  - Traitements d’histogramme : `equalizeHist`, `calcHist`.  
  - Filtrages : `filter2D`, `GaussianBlur`, `medianBlur`.  
  - Détection de contours : `Canny`, `Laplacian`.  
  - Morphologie : `morphologyEx`.  
  - Étiquetage : `connectedComponents`.
