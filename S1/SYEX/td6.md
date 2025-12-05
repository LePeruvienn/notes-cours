# Threads

## Threads POSIX

Les thread POSIX ou Pthread sont une API pour l développement d'applications parallèles qui partages les même données.

## Pthread

L'espace mémoire n'est pas dupliqué.

POSIX ajoute à l'espoace virtuele à ala pile et à la TLS.

### Création de pthread

**Fonctions**

```c
// Créer un nouveau trhead et son point d''entre est la fonction func avec l'arguement arg.
int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*func) (void*), void* arg);

// Termine le thread avec le status val. `Un return x` équivalent à un `pthread_exit(x)`
// => ça veut dire qu'on peut faire les deux !!! (on peut très bien faire juste de return)
void pthread_exi(void *ret);


// Les deux fonction retourne 0 en cas de succès et un code d'érreur sinon.
```

**Exemple**

```c
void* print(void *str) {

    printf((char*) str);
    return NULL;
}

int main(int argc, char* argv) {

    pthread_attr_t att;
    pthread_attr_init(&att);

    pthread_t th;
    pthread_create(&th, &att, print, "hel");

    sleep(1);
    printf("lo\n");

    return 0;
}
```

### Attente

**Fonction**

```c
// Attend la fn du thread et délivre son statut
int phtread_join(pthread_t th, void**statut);
```

**Exemple**

```
void* print(void *str) {

    printf((char*) str);
    return NULL;
}

int main(int argc, char* argv) {

    pthread_attr_t att;
    pthread_attr_init(&att);

    pthread_t th;
    pthread_create(&th, &att, print, "hel");

    // vvv ICI A LA PLACE DU SLEEP
    pthread_joint(th, NULL)
    printf("lo\n");

    return 0;
}
```


### MUTEX

**Fonctions**

```c
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Permet de vérouiller la mutex.
int pthread_mutex_lock(pthread_muex_t* mutex);
// Dévrouiller la mutex
int pthread_mutex_unlock(pthread_muex_t* mutex);

// les deux fonction retourne 0 et code d'érreur si erreur
```
