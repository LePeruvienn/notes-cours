
# GeoSPARQL

- Standart  par l'OGC (Open GeoSpatioal consortium)
- But : modéliser est intérrogé les données géographique sur le web
- Aligné avec d'autres standart de données géographique


## Vocabulaire GeoSPARQL

prefix.css => Site internet pour trouver les infos sur des préfix

(Voir diapo pour le schema)

**geo : spatialObject** 
- geo : Feature (sous class de spatialObject) => son type = ex : f
- geo : Geometry (sous classe de SpatialObject) son tye = ex : g

types:
- geo : hasGeometry
- geo : asWKT


## Fonctiosn GeoSPARQL

- **geof : contains** 
- **geof : distance** : retourne la distance entre de type ex : g
- **goet : intersection**

## TP2 GeoSPARQL


Importer les fichiers CSV

Modéliser le graph csv en fichier rdf

ON as un fichier qui content les région avec leurs code


Si on le écris en rdf irectement :

```c
# Si on fait un par un
reg:1 rdf:type iut:Région ;
	  rdfs:label "Guadloupe"@fr ;

```

Dans **OntoRefine**:

On définis 3 triplet de type : dep , iut  reg

```c
rerg:code_region a iut:Region
```

Dans le diapo y a un tuto onto refine

