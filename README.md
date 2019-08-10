# BDD MySQL C++
Ce projet permet de tester l'utilisation d'une base de données en C++, inspiré par O. Dartois.
Il met en oeuvre d'une part une structure User composé de 4 champs, et d'autre part une base de données mon_site, comprenant une table users.
On pourra noter l'utilisation de std::unique_ptr au lieu de pointeur nu pour les valeurs de retour de chaque fonction de la bibliothèque "standard", qui simplifie grandement la gestion de la mémoire.
 
## Quels paquets faut-il installer ?
Pour utiliser les BDD en C++, il faut installer les paquets suivants sur Ubuntu :
* sudo apt-get install libmysqlcppconn-dev
* sudo apt-get install libmysqlcppconn7
 
## L'erreur "undefined reference to 'get_driver_instance'" apparaît lors de la compilation ..
Cette erreur est due au fait qu'il faut lier dynamiquement la bibliothèque mysqlcppconn à l'exécutable du projet.
Pour cela, il suffit d'ajouter l'option "-lmysqlcppconn" à la commande g++ ou encore d'ajouter la ligne suivante pour un CMake :
+ target_link_libraries (<executable> mysqlcppconn)
 
## Comment utiliser la classe SQLRequester ?
Un exemple concret d'utilisation de cette classe est donnée avec la classe SQLRequesterTest qui a pour objectifs d'effectuer une requête d'insertion et de sélection.
Il est conseillé de créer une classe dérivée de SQLRequester pour votre projet, qui regroupe toutes les fonctions en lien avec la base de données.
Il est déconseillé de toucher à la classe SQLRequester sauf si vous savez ce que vous faites ;)
 
## Procédure de test
Pour savoir si votre BDD est utilisable en C++ :
1. Téléchargez ce projet et installer la BDD disponible dans mon_site.sql
2. Changez les variables mdp et pseudo dans testDB.cpp de façon à ce que le programme puisse se connecter à la base de données.
3. Compilez le projet avec make.
4. Exécutez, aucune erreur n'apparaîtra si tout est bien configurée.
