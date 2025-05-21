
# Le language `SHACL`


**SHACL** = Shape Constraint Language
- But : vaider des pgraghes RDF en spécifiant la "forme" (Shape) à lquelle on souhaite qu'un graph
- Se base sur la syntaxe turtle

### Modèle SHACL

Une forme est une collection de Targets (cibles) et Constraints (contraintes) :
- **Targets** : spécifieles noeuds (sous-ensemble des données) dans le graphe qu'il faudra valider
- **Constraint** : spécifie comment faut-il valider ces noeuds

### Processeurs SHACL

- Prend en entrée un graphe RDF et un graph de forme SHACL
- Il ne change pas les données du graphe RDF
- Il les valide ou pas et dit si il y a des erreurs

### Targets

Les déclarations de targets permet de spécifier les ressources RDF qu'on souhaite valider. Il y a 4 moyens de cibler des ressources RDF

1) `sh:targetClass` => cibler toutes les instante de classes
2) `sh:targetNode` => 
3) `sh:subjectOf` => cibler tout les sujets de la classe 
4) ...



**Pour tester `SHACL` en ligne :**
shaci-playground.com !








