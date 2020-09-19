# Sujet n°2.

L’alimentation provient simplement de l'USB 5V de l'UC du PC.
Il n'y pas de signal d'entrée, donc pas de GBF.

## Cahier des charges à remplir :

Il s'agit de créer une tension v1 /masse logique de niveaux 5V-0V. Les caractéristiques de cette tension v1 pour sa fréquence et son rapport cyclique vont être fonction des interrupteurs 11,12 et du potentiomètre P1. Une led rouge est utilisée pour renseigner du mode de fonctionnement.

Pour la pos1 de 11 :

- v1 est de fréquence fixe avec F=20kHz et son rapport cyclique est fixe à 1/2.
- La led rouge est allumée fixe.

Pour la pos2 de 11 :

- v1 a une fréquence F réglable de 100Hz jusqu’à 500Hz selon la position x1 de P1 et le rapport cyclique est fonction de la position de I2.
- La led rouge clignote à 1Hz avec un rapport cyclique fixe à 1/2.
- Pour x1=0 la fréquence F est égale à 100Hz et pourx1=1 la fréquence F est égale à 500Hz. Le réglage de F est linéaire avec la valeur de x1 qui peut être réglé entre 0 et 1.

- Pour la pos1 de I2 le rapport cyclique est fixe à une valeur 1/4 et pour la pos2 de I2 le rapport cyclique est fixe à une valeur 3/4.

## Ce qui est demandé :

1.	Faire le schéma LTspice qui permet de simuler le résultat de v1 selon les diverses configurations.
2.	Faire le schéma papier de câblage complet de votre montage. Un schéma est à faire par chaque étudiant et ils seront demandés lors de la validation.
3.	Écrire le programme. Soigner sa présentation.
4.	Réaliser le câblage en respectant l'utilisation des couleurs.
5.	Régler l'oscilloscope sur une base de temps qui permet de visualiser environ 2 périodes. Avec 11 en pos1.
Régler la référence OV de l’oscilloscope du signal visualisé v1 sur l’avant dernière ligne du bas de l’écran : le signal v1 est positif ou nul et il est donc inutile d’avoir une zone d’écran pour les tensions négatives.


Ne faire valider votre montage qu'après avoir bien vérifié que tout est correct :
- votre montage fonctionne et remplit intégralement le cahier des charges.
- l'oscilloscope est réglé comme demandé. 
- le programme arduino est affiché.