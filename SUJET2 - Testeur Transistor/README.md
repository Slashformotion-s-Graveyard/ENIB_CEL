# Sujet n°2

L'alimentation provient simplement de l'USB 5V de l'UC du PC.
Il n'y a pas de signal d'entrée, donc pas de GBF.

## Cahier des charges à remplir :

Il s'agit de détecter le fonctionnement d'un transistor bipolaire npn BC 547 C et de mesurer son amplification β lorsqu'il est en fonctionnement linéaire. Pour ce β les valeurs de Vce et Ic seront précisées. En supplément Vbe sera également précisée.

Une led verte devra s'allumer si le transistor est correct.
Une led rouge devra s'allumer si le transistor est défaillant ou absent.
Les courants dans les leds seront gérés au plus simple.

Un appui bref sur BP1 lancera le test du transistor et un nouvel affichage des valeurs de β, de Vbe, de Vce et de Ic sur la fenêtre monitoring. Un nouvel affichage, et un seul, à chaque nouvel appui sur BP1, pas davantage.

L'état des leds est conservé jusqu'éà un nouvel appui sur BP1.

## Ce qui est demandé :

1.	Faire le schéma du montage. On précise qu'il faut veiller ) ne pas détruire le transistor par une surintensité pour Ic et/ou Ib. Il faut Ic < 40m1 et Ib < 1mA. Il faut simuler et mesurer les courants sur LTspice avant de réaliser le montage réel.
2.	Faire une recherche sur le net pour trouver où se trouve l'émetter, le collecteur et la base du npn BC 547 C. Lors du montage réel câblez le avec attention, le transistor est un composant fragile, un mauvais câblage est immédiatement destructeur.
3.	Expliquer la stratégie à mettre en oeuvre avec l'arduino.
4.	Ecrire le programme.
5.	Veiller à écrire un programme qui donne une présentation sur la fenêtre monitoring qui soit limpide pour la signification des grandeurs affichées:
		β = ... ; Vbe = ...V ; Vce = ...V ; Ic = ...mA
6.	L'amplification β sera arrondie à une valeur entière.
7.	Une fois que le programme fonctionne pour un transistor en bon état il faut tester (et modifier en conséquence) votre programme pour la détection d'un transistor défectueux.
	Pour cela tester différentes configurations:
	 - ne pas mettre de transistor
	 - ne pas relier la base
	 - ne pas relier le collecteur
	 - court-circuiter l'émetteur et le collecteur par un fil
	 - court-circuiter l'émetteur et la base par un fil
8.	Selon le résultat du test afficher également "transistor ok" ou "transistor défaillant"
9.	Câbler le multimètre pour afficher Vce


Ne faire valider votre  montage qu'après avoir bien vérifié que tout est correct :
 - votre montage fonctionne
 - le multimètre est câblé pour afficher Vce
 - le programme arduino est affiché
 - la fenêtre monitoring affiche ce qui est demandé