// The Tortoise and the Hare
// Main.cpp (Main function | Program execution begins and ends there) 

/*
 EXERCICE 8.12 PSEUDOCODE

 - utilisation de nombre al�atoire pour recr�ation de la simulation
 - cr�er un array de 70 cases
 - chacune des 70 cases repr�sente une position le long du parcours de course
 - la ligne d'arriv�e est � la case 70
 - le premier a atteindre la case 70 re�ois : "pail of fresh carrots and lettuce"
 - Le parcours serpente le long d'une montagne glissante, donc parfois les pr�tendants perdent du terrain.
 - Il y a une horloge qui tic-tac une fois par seconde.
 - Le programme doit utiliser les fonctions "moveTortoise" et "moveHare" pour ajuster la position des animaux selon les r�gles de la Figure 8.18
 - Ces fonctions doivent utiliser des pointeurs passe-par-r�f�rence pour modifier la position de la tortue et du li�vre.
 - Utilisez des variables pour garder une trace des positions des animaux (les num�ros de position vont de 1 � 70).
 - Commencer chaque animal � la position 1 (c'est-�-dire la "starting gate")
 - Si un animal glisse � gauche avant la case 1, d�placez l'animal vers la case 1.

 PERCENTAGE (FIG 8.18)
 - G�n�rez les pourcentages de la Figure 8.18 en produisant un entier al�atoire i dans la plage 1 <= i <= 10
 - Pour la tortue, effectuez une :
   > "fast plod"   quand 1 <= i <= 5  (50%) actual move : 3 case a droite
   > "slip"        quand 6 <= i <= 7  (20%) actual move : 6 case a GAUCHE
   > "slow plod"   quand 8 <= i <= 10 (30%) actual move : 1 case a droite

 -  Utilisez une technique similaire pour d�placer le li�vre :
   > "sleep"       quand 1 <= i <= 2  (20%) actual move : ne bouge pas
   > "big hop"     quand 3 <= i <= 4  (20%) actual move : 9 case a droite
   > "big slip"    quand 5 <= i <= 5  (10%) actual move : 12 case a GAUCHE
   > "small hop"   quand 6 <= i <= 8  (30%) actual move : 1 case a droite
   > "small slip"  quand 9 <= i <= 10 (20%) actual move : 2 case a GAUCHE

BEGIN THE RACE BY DISPLAYING :

BANG !!!!!
AND THEY'RE OFF !!!!!

- Pour chaque tick de l'horloge (c'est-�-dire chaque it�ration d'une boucle), affichez une ligne � 70 positions indiquant la lettre "T" en position de tortue (tortoise) et la lettre "H" en position de li�vre (hare).
- Parfois, les concurrents atterrissent sur la m�me case. Dans ce cas, la tortue mord le li�vre et votre programme devrait afficher "OUCH!!!" commen�ant � cette position.
- Toutes les positions autres que le "T" , le "H" ou "OUCH!!!" (en cas d'�galit�) doit �tre vide.

WINNING
- Apr�s avoir affich� chaque ligne, testez si l'un ou l'autre des animaux a atteint ou d�pass� la case 70.
- Si c'est le cas, affichez le gagnant et terminer la simulation.
- Si la tortue gagne, affichez "TORTOISE WINS!!! YAY!!!" | "LA TORTUE GAGNE!!! YAY!!!"
- Si le li�vre gagne, affichez "Hare wins. Yuch." | "Le li�vre gagne. Yuch."
- Si les deux animaux gagnent sur le m�me tic d'horloge, afficher "It's a tie."
- Si aucun animal ne gagne, refaites la boucle pour simuler le prochain tic-tac de l'horloge.
*/

#include <iostream>

using namespace std;

int main()
{


	system("pause");

	return 0;
}