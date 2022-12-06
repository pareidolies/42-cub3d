# 42-cub3d

Bienvenue sur la page de notre projet cub3d ! Le but de ce projet est de créer un univers en 3d grâce à la technique du raycasting et à la minilibx de 42. Il fonctionne sur linux.

> make bonus && ./cub3d_bonus maps_bonus/museum_bonus.cub

Voici quelques notes et conseils pour ce projet.

## Conseils pour le parsing (by jdubilla)

[A COMPLETER]

## La méthode du raycasting (by smostefa)

La bible pour comprendre le raycasting est le tutoriel de [lodev](https://lodev.org/cgtutor/raycasting.html). Il est très complet et plutôt clair, je vais donc me contenter de vous faire une introduction générale au raycasting (pour ceux qui aiment avoir une vision d'ensemble avant de se lancer dans des calculs plus détaillés) et ajouter quelques éléments qui m'ont aidée dans le projet.

Tout d'abord, il faut savoir que le raycasting est une sorte de "faux 3d", puisque l'on va se baser sur une carte en 2d pour donner simplement une "sensation" de 3d. Pour cela, il va s'agir de lancer autant de rayon depuis la position du personnage que la largeur de l'écran d'affichage, et pour chaque rayon de calculer la distance à laquelle celui-ci cogne un mur. Cette distance va nous permettre d'établir proportionnellement la taille du mur (avec une petite correction en plus pour éviter l'[effet fisheye](https://fr.wikipedia.org/wiki/Objectif_fisheye)).

![R7TAtQf](https://user-images.githubusercontent.com/96736158/202495984-479fc463-2a16-40cf-953d-f31c3d5b365e.png)

[crédits schéma](https://tiplanet.org/forum/viewtopic.php?t=15033)

Le tutoriel de lodev travaille avec des vecteurs, donc si vous n'avez pas fait beaucoup de maths au lycée, prenez le temps de bien comprendre cette notion et les calculs avec des matrices !

Pour calculer l'endroit précis où le rayon cogne un mur en faisant le moins de calculs possibles, il faut vérifier à chaque croisement entre le rayon et une arête. Si on vérifiait à chaque pixel du rayon, cela prendrait beaucoup de trop de temps à l'ordinateur de faire tous les calculs, et si on vérifiait à des échelons arbitraires, on risquerait de louper le moment de la rencontre entre le rayon et le mur.

![Capture d’écran 2022-11-17 à 17 12 16](https://user-images.githubusercontent.com/96736158/202498559-fa4d2c8a-4536-4b66-a933-31a923744ae6.png)

[crédits schéma](https://lodev.org/cgtutor/raycasting.html)

On va calculer cela pour les arêtes verticales d'une part, pour les arêtes horizontales d'autre part, en choisissant la distance la plus courte. C'est le calcul des fameux deltadist et sidedist en utilisant simplement... Pythagore ! Attention, il faut garder l'information du type d'arête qui a été utilisé (horizontal) ou (vertical) car elle permet de savoir quel type de mur a été atteint.

![Capture d’écran 2022-11-17 à 17 12 47](https://user-images.githubusercontent.com/96736158/202498683-4eb5d0cf-7c78-4025-a011-1fa0e73f54ec.png)

[crédits schéma](https://lodev.org/cgtutor/raycasting.html)

Pour les novices des mathématiques, voici les détails de la simplification du calcul de deldist effectué par lodev :

[A COMPLETER]

Ensuite, pour éviter l'effet fisheye, nous allons calculer non pas la distance de la position du joueur au mur, mais ce que l'on va appeler perpwalldist, à savoir la plus courte distance entre le plan caméra et le mur. En effet, sans cela, les murs pourraient sembler "arrondis". Lodev démontre avec cette fois-ci le théorème de Thalès comment on arrive alors à une formule très jolie et simple grâce à la cohérence des calculs précédents : perpwalldist = (sidedist - deltadist).

![Capture d’écran 2022-11-17 à 17 19 58](https://user-images.githubusercontent.com/96736158/202500275-f76c4927-c0de-48a4-aa71-9275c3af14a3.png)

[crédits schéma](https://lodev.org/cgtutor/raycasting.html)

Dès lors, il n'y a plus qu'à calculer la taille du mur proportionnellement à la taille de votre écran (vous pouvez faire des murs carrés comme lodev, mais pourquoi pas plus hauts ou plus petits selon le type d'univers que vous souhaitez créer !), puis la coordonnée y de la position du sommet du mur et celle de son pied, sachant que le centre du mur doit se situer au milieu de l'écran.

Ainsi, vous pouvez afficher chaque pixel de l'écran d'une certaine couleur s'il se situe entre le haut et le bas du mur, et d'une autre couleur pour le sol et le plafond.

**Conseil :** Toujours faire attention à bien avoir en tête les valeurs qui sont des _int_ et celles qui sont des _double_. De mauvaises conversions peuvent générer des erreurs qu'on ne parvient pas à comprendre tout de suite en voyant le résultat.

## Les hooks

Quand vous souhaitez vous déplacer à l'aide des touches WASD, il suffit de vérifier si le déplacement va provoquer une collision avec un mur, et si ce n'est pas le cas, de modifier la position du joueur, puis de relancer le raycasting.

Pour les rotations avec les flèches droite et gauche, il va falloir faire appel à la [matrice de rotation](https://en.wikipedia.org/wiki/Rotation_matrix) pour calculer les nouvelles coordonnées des vecteurs. La formule est donnée dans la page Wikipedia.

**Conseil :** Il est préférable de supprimer l'autorepeat pour optimiser la vitesse des déplacements et des mouvements de rotation dans votre projet et éviter les bugs.

Normalement, à ce stade, vous devriez arriver à quelque chose qui ressemble à ceci :

![Séquence-01](https://user-images.githubusercontent.com/96736158/202499382-357241a1-e3f6-4e46-add4-3a0cb0f2bb59.gif)

A présent, il faut ajouter les textures. Au lieu d'afficher des couleurs, il va falloir aller chercher à chaque fois le bon texel de la texture. Je vous renvoie ici à [lodev](https://lodev.org/cgtutor/raycasting.html#Wolfenstein_3D_Textures_) qui l'explique vraiment très bien.

Pour trouver vos textures, sachez qu'il en existe de toutes faites, mais vous pouvez aussi vous amuser à redimensionner des images png de votre choix (en 256 * 256 par exemple), puis à la convertir en xpm pour avoir toute la liberté que vous voulez.

**Quelques sites utiles et fiables pour l'aspect design du projet:**

Pour redimensionner les images : https://www.iloveimg.com/fr/redimensionner-image/png-redimensionner

Pour les convertir en xpm : https://convertio.co/fr/png-xpm/

Pour choisir des couleurs : https://htmlcolorcodes.com/fr/

## Les bonus

* Pour le parquet qui vient remplacer la couleur du sol, c'est exactement le même principe que pour les textures des murs, mais au lieu de travailler colonne par colonne, ce sera ligne par ligne.

* Pour les sprites, c'est également le même principe que la texture des murs, avec en plus une couleur noire qu'il ne faudra pas afficher à l'écran car elle correspond aux contours du sprite. Si vous souhaitez créer vos propres sprites à partir de photos et que vous avez la chance d'avoir Photoshop, la technique consiste à entourer l'élément de la photo qui vous intéresse avec le lasso magnétique ou le lasso automatique, puis à inverser la sélection, ensuite il suffit d'appuyer sur la touche delete, ce qui supprimera le contour du sprite, et d'enregistrer la photo en png (c'est important !) avant de la convertir en xpm. Le contour sera alors considéré comme du noir.

* Pour les portes, rien de plus simple, il faudra juste les stocker dans une liste chaînée par exemple, et vérifier quand le joueur se déplace s'il se situe dans le rayon d'une porte, et si oui la remplacer provisoirement par un espace vide dans la map. Il y a des façons plus élaborées de traiter cette question de l'ouverture et de la fermeture des portes, cela pourrait faire l'objet d'une amélioration du projet.

* Nous avons également une minimap qui s'affiche en haut à gauche avec la position du joueur en temps réel, et un menu que l'on peut afficher avec le touche m, et dont on peut modifier les valeurs (vitesse de déplacement, vitesse de rotation, couleurs du plafond, etc) avec les touches + et -.

**Note :** Lorsque lodev utilise des opérations bitwise, cela revient à utiliser modulo pour éviter les overflows.

Et voici un petit aperçu du résultat final :

![cub3d-2022-11-11_17 58 30_1](https://user-images.githubusercontent.com/96736158/202507280-bf591c8a-0e63-4b73-b1ea-34db635da098.gif)

Les tableaux exposés dans notre musée virtuel sont :
- Le Main tenant un miroir déformant et les Visages de Escher
- _Chop Suey_ de Hopper
- _Le Baiser_ de Klimt
- _L'Absinthe_ de Degas
- _La Joconde_ de Leonard de Vinci
- Un _Action Painting_ de Jackson Pollock

## Ressources : 

Méthode du raycasting :

https://lodev.org/cgtutor/raycasting.html

https://github.com/iciamyplant/Cub3d-Linux

https://www.youtube.com/watch?v=js7HW65MmNw&list=PL0H9-oZl_QOHM34HvD3DiGmwmj5X7GvTW

https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

https://zestedesavoir.com/articles/153/comment-doom-et-wolfenstein-affichaient-leurs-graphismes/

Pour les sprites :

https://lodev.org/cgtutor/raycasting3.html

Pour le sol :

https://lodev.org/cgtutor/raycasting2.html

Pour les operations bitwise équivalent modulo :

https://mziccard.me/2015/05/08/modulo-and-division-vs-bitwise-operations/

Et si vous avez besoin de vous rafraîchir la mémoire concernant la minilibx de 42 :

https://harm-smits.github.io/42docs/libs/minilibx

https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx

https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx

**Un très grand merci à lodev pour son tutoriel, et n'hésitez pas à nous écrire si vous avez des questions/suggestions pour ce projet !**
