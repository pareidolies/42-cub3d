# 42-cub3d

Bienvenue sur la page de notre projet cub3d ! Le but de ce projet est de créer un univers en 3d grâce à la technique du raycasting et à la minilibx de 42. Il fonctionne sur linux.

> make bonus && ./cub3d_bonus maps_bonus/museum_bonus.cub

Voici quelques notes et conseils pour ce projet.

## Conseils pour le parsing (by jdubilla)

[A COMPLETER]

## La méthode du raycasting (by smostefa)

La bible pour comprendre le raycasting est le tuto de lodev. Il est très complet et plutôt clair, je vais donc me contenter de vous faire une introduction générale au raycasting (pour ceux qui aiment avoir une vision d'ensemble avant de se lancer dans des calculs plus détaillés) et ajouter quelques éléments qui m'ont aidée dans le projet.

Tout d'abord, il faut savoir que le raycasting est une sorte de "faux 3d", puisque l'on va se baser sur une carte en 2d pour simplement donner une "sensation" de 3d. Pour cela, il va s'agir de lancer autant de rayon depuis la position du personnage que la largeur de l'écran d'affichage, et pour chaque rayon de calculer la distance à laquelle il cogne contre un mur. Cette distance va nous permettre d'établir proportionnellement la taille du mur (avec une petite correction en plus pour éviter l'effet fisheye).

![R7TAtQf](https://user-images.githubusercontent.com/96736158/202495984-479fc463-2a16-40cf-953d-f31c3d5b365e.png)

Crédits : https://tiplanet.org/forum/viewtopic.php?t=15033

Le tutoriel de lodev travaille avec des vecteurs, donc si vous n'avez pas fait S, prenez le temps de bien comprendre cette notion et les calculs avec des matrices !

Pour calculer l'endroit précis où le rayon cogne un mur en faisant le moins de calculs possibles, il faut vérifier à chaque croisement entre le rayon et une arête. 

![Capture d’écran 2022-11-17 à 17 12 16](https://user-images.githubusercontent.com/96736158/202498559-fa4d2c8a-4536-4b66-a933-31a923744ae6.png)

On va calculer cela pour les arêtes verticales, puis pour les arêtes horizontales, en choisissant la distance la plus courte. C'est le calcul des fameux deltadist et sidedist en utilisant simplement... Pythagore ! Attention, il faut garder la donnée horizontale ou verticale car elle permet de savoir quel type de mur a été atteint.

![Capture d’écran 2022-11-17 à 17 12 47](https://user-images.githubusercontent.com/96736158/202498683-4eb5d0cf-7c78-4025-a011-1fa0e73f54ec.png)

Pour les novices des mathématiques, voici le détails de la simplification du calcul de deldist effectué par lodev :

[A COMPLETER]

Ensuite, pour éviter l'effet fisheye, nous allons calculer non pas la distance de la position du joueur au mur, mais ce que l'on va appeler perpwalldist, à savoir la plus courte distance entre le plan caméra et le mur. En effet, sans faire cela, les murs pourraient sembler "arrondi". Lodev démontre comment on arrive alors à sidedist - deltadist, en utilisant cette fois-ci le théorème de Thalès.

![Capture d’écran 2022-11-17 à 17 19 58](https://user-images.githubusercontent.com/96736158/202500275-f76c4927-c0de-48a4-aa71-9275c3af14a3.png)

Dès lors, il n'y a plus qu'à calculer la taille du mur proportionnellement à la taille de votre écran (vous pouvez faire des murs carrés comme lodev, mais pourquoi pas plus hauts ou plus petits !), puis la coordonnée du haut du mur et de son bas, sachant que le centre doit se situer au milieu.

Ainsi, pour chaque pixel de l'écran, vous pouvez l'afficher d'une certaine couleur pour le mur, et d'autre autre pour le sol et le plafond.

## Les hooks

Quand vous souhaitez vous déplacer à l'aide des touches WASD, il suffit de vérifier si le déplacement va provoquer une collision avec un mur, et si ce n'est pas le cas, de modifier la position du joueur, puis de relancer le raycasting.

Pour les rotations avec les flèches droite et gauche, il va falloir faire appel à la matrice rotation pour calculer les nouvelles coordonnées des vecteurs : https://en.wikipedia.org/wiki/Rotation_matrix

Normalement, à ce stade, vous devriez arriver à quelque chose qui ressemble à ceci :

![Séquence-01](https://user-images.githubusercontent.com/96736158/202499382-357241a1-e3f6-4e46-add4-3a0cb0f2bb59.gif)

A présent, il faut ajouter les textures. Au lieu d'afficher des couleurs, il va falloir aller chercher à chaque fois le bon texel de la texture. Je vous renvoie ici à lodev qui l'explique vraiment très bien.

Pour trouver vos textures, il y en a des toutes faites, mais vous pouvez aussi vous amuser à redimensionner des images png de votre choix (en 256 * 256 par exemple), puis à la convertir en xpm.

Pour redimensionner les images :
Pour les convertir en xpm :
Pour choisir des couleurs :

## Les bonus

* Pour le parquet qui vient remplacer la couleur du sol, c'est exactement le même principe que pour les textures des murs, mais au lieu de travailler colonne par colonne, ce sera ligne par ligne.

* Pour les sprites, c'est également le même principe que la texture des murs, avec en plus une couleur noire qu'il ne faudra pas afficher car elle correspond aux contours du sprite.

* Pour les portes, rien de plus simple, il faudra juste les stocker dans une liste chaînée par exemple, et vérifier quand le joueur se déplace s'il se situe dans le rayon d'une porte, et si oui la remplacer provisoirement par un espace vide dans la map.

* Nous avons également une minimap qui s'affiche en haut à gauche, et un menu que l'on peut afficher avec le touche m, et modifier des valeurs avec + et -

Et voici un petit aperçu du résultat final :



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

Pour les operations bitwise et modulo :

https://mziccard.me/2015/05/08/modulo-and-division-vs-bitwise-operations/
