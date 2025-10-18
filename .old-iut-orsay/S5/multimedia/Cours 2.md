Code cours : **R5A06**
## Le son
### Vitesse de propagation

Les ondes sonores se déplacents :
- à 344 m/s dans l'air à 20°C

### L'amplitude

- Caractéristique importante du son
- C'est ce qui défini l'intensité perçu
- Sa mesure est le Decibels
- Est douloureux à entendre à partir de 120 DB

### Analogie au numérique

- Acquisition : Transformer les pression de l'air en signaux électrique
- Numérisation : Echantillonnage temporel : on récupèr un enchantillon toutes les $T_e$ secondes
- Théorème de Shannon : La fréquence d'échantillonnage doit être bien choisie 
	- $F_e >= 2Fmax$  du signal, pour l'audiau $F_e$ = 44,1 kHz

### Le spectre

C'est la représetation des fréquences
- Peut être calculer par *Transformé de Fourier* (FFT)

En musique, en musique les notes de haque gamme sont associées à une valeur de fréquence qui leur est propre

La voix humaine à une fréquence netre 100 et 500Hz
- Cette voix peut varier si on s'entraine/chuchote/chanteur ect (70Hz - 1000Hz)


Sur le spectre on représente génératement les fréquence centré sur 0 Hz et les fréquence vont de -$F_e$ / 2 et $F_e$ / 2.
- Fonctions python : `fft` et `fftshift` pour centre le spectre sur 0


### Son pur et son composé/complexe

Le spectre est composé d'one sonors différentes fréquence => Dans ce cas il est considérer alors comme complex


### La repéstation temps-fréquence

Le son est découpé temporellement en M segmentes.

On affiche un graphique avec le temps en abcisse et la fréquence en ordonnées. Puis pour chaque point sa couleurs varie en foncton de son amplitude


Dans ces graphique on peut récupérer des points clées pour pouvoir après reconnaitre des sons (c'est ce que l'appliation Shazam utilise)


### Hauteur et timbre

La **hauteur** d'un son c'est sa fréquence fodamentale

Son **timbre** ou couleur, il est différent pour chaque type de son c'est ce qui différencie les sons meme si ils ont pas la meme fréquence et amplitude : par exemple une meme note jouer par différents instrument


### Filtrage

Objectifs : débruiter un son, récupérer que une partie de'un son

- Le filtrage pass-bas récupère les fréquence faible et atténnue les fréquence hautes

Il existe luieurs type de filtres:
- par gains
- fréquence de coupure
- ordre
- ondulation tolérées ou non

## Transformation du son
### Réverbération

C'est l'écho naturel qui se produit dans un espace

### Distortion

Saturer un son quand il est à un certain seuil



## Logiciels

L'informatique musicale s'es développpé au meme rythme que leurs capcité de calcul des ordinateurs
- Musique Assisté par ordinateur (MAO)
- Edition et montage 


## Format de fichiers

MP3 :
- Compression avec un filtre passe base à raide de 20kHz, supprime les sons presque imperceptible

WAV

