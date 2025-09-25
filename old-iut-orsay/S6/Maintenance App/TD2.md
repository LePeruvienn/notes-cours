# Debug cout

```c++
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int *t = new int[1] // !! ADD !! allouer de la mémoire pour 1 entier
  // si t pas initialisé = crash programme, corruption mémoire, autre erreurs
  // en gro si ct : int *t // zone aléatoire ou invalide de la mémoire;
  
  cout << "Il est passé par ici" << endl; // !! ADD !! le "endl" a la fin
  t[0] = 0; // initialisation
  cout << "Valeur de t[0] : " << t[0] << endl;
  
  delete[] t; // !! ADD !! libérer la mémoire
  return 0
}
```
