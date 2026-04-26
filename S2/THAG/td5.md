---
title: TD5
---

# Exercice 3

1)

Il s'agit d'un tri topologique, 

On peut dire qu'un tel graphe a au moins une source que l'ont numérote avec 1. Puis on la retire.

Le graphe obtenu est snas circuit donc on au au moins une source l'on numérote 2.

Par récurence, nous avons numérote tous les sommets en respectant la contrainte de croissance.

2)

On considère lessommets dans l'ordre inverse du tri topologique. Nous avons alors jamais le choix pour numéroté les sommets  soit un un puit que l'on numérote par 0, sot tous les sucessuers sont numérotés.

La fonction de Grundy et le noyau sont donc uniques **dans ce cas précis** (*graphe sans circuit*).

**REMARQUE IMPORTANTE**
```
Quand le graphe est sans circuit,
la fonction de Grundy est alors unique.
```

