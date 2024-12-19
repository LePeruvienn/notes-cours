# Fiche de Révision - Programmation Multimédia : Le Son

## 1. Notions de base
- **Définition du son** : Onde produite par une vibration mécanique dans un milieu (gaz, liquide, solide). 
- **Propagation** : Compression et décompression des molécules.
- **Vitesse** : Dépend du milieu et des conditions :
  - Air : 344 m/s à 20 °C.
  - Eau : 1482 m/s.
  - Acier : 5050 m/s.

---

## 2. Caractéristiques principales
- **Fréquence (Hz)** : Nombre d’oscillations par seconde.
  - Gamme de l’ouïe humaine : 20 Hz - 20 kHz.
  - Infrasons : < 20 Hz ; Ultrasons : > 20 kHz.
- **Amplitude (dB)** : Intensité perçue :
  - Seuil d’audibilité : 0 dB.
  - Seuil de douleur : 130 dB.
- **Longueur d’onde (\(\lambda\))** : Distance parcourue en une oscillation.

---

## 3. Acquisition du son
- **Conversion analogique-numérique** :
  - **Échantillonnage** : Prise d’un échantillon toutes les \( T_e \) secondes.
    - Fréquence d’échantillonnage \( F_e \geq 2 F_{\text{max}} \).
    - Ex. : Audio standard \( F_e = 44,1 \text{kHz} \).
  - **Quantification** : Conversion des valeurs en niveaux discrets.
  - **Codage** : Enregistrement des valeurs en binaire.

---

## 4. Spectre et fréquences
- **Spectre** : Analyse fréquentielle obtenue via la Transformée de Fourier (FFT).
  - Sons graves : Fréquences basses.
  - Sons aigus : Fréquences élevées.
- **Types de sons** :
  - **Pur** : Une seule fréquence.
  - **Complexe** : Plusieurs fréquences superposées (fondamentale + harmoniques).

---

## 5. Transformations et filtrages
- **Filtrage** : Extraction ou suppression de fréquences spécifiques.
  - **Passe-bas** : Garde les fréquences basses (< \( F_c \)).
  - **Passe-haut** : Garde les fréquences hautes (> \( F_c \)).
- **Réverbération** : Simule l’écho naturel :
  - \( s_r(t) = (1 - \alpha)s(t) + \alpha s(t - \Delta) \).
- **Distorsion** : Écrêtage du signal pour modifier son intensité.

---

## 6. Logiciels et formats audio
- **Logiciels de MAO (Musique Assistée par Ordinateur)** :
  - Composition : Ableton Live, Cubase.
  - Édition : Audacity, SoundForge.
  - Mixage : Virtual DJ, Mixxx.
- **Formats audio** :
  - **WAV** : Non compressé, qualité optimale.
  - **MP3** : Compression avec perte (réduction de 7 à 10 fois).

---

## 7. Compression MP3
- **Principes** :
  - Élimination des sons les moins perceptibles (effet de masque psychoacoustique).
  - Suppression des hautes fréquences au-delà de 20 kHz.
  - Optimisation pour une transmission rapide et un stockage réduit.
