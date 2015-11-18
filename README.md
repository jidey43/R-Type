# R-Type

Lancer le CMakeLists.txt à la racine via la gui de CMake génerer le projet en Visual 2k15 sous Windows ou un Makefile sous Unix

La SFML est directement embarquée dans le dossier du client, pour rendre le projet completment portable.

La SFML est compilée satiquement

Les executables sont générés dans /bin

Les projets doivents etres générés en debug mode

L'architecture de dossier est la suivante :

* root
  * Client
    * SFML
    * src
        * ALL CLIENT SOURCES
    * includes
        * ALL CLIENT HEADERS
  
  * Server
    * src
        * ALL SERVER SOURCES
    * includes
        * ALL SERVER HEADERS
  
  * Common
    * ALL COMMONS FILES BETWEEN CLIENT AND SERVER
