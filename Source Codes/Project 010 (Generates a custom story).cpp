// Generates a personalized story for children.
// The program ask for a female name, a male name, and a location.
// The program then display a story containing the collected informations.

#include <iostream>

using namespace std;

int main()
{
    string girlName = "girl_name";
    string boyName = "boy_name";
    string locationName = "location_name";

    cout << "Veuillez entrer un prenom de fille: ";
    cin >> girlName;
    cout << endl << "Veuillez entrer un prenom de garcon : ";
    cin >> boyName;
    cout << endl << "Veuillez entrer le nom d'un lieu: ";
    cin >> locationName;
    cout << endl << endl;

    cout << boyName << " " << "Super Souris et la maison ideale" << endl << endl;

    cout << "Il etait une fois, a " << locationName << ", une famille de souris" << endl;
    cout << "qui vivait dans un terrier de lapins. Monsieur Souris passait ses" << endl;
    cout << "journees a cueillir des fruits rouges dans les bois avec sa fille," << endl;
    cout << "alors que Madame Souris s’occupait de la maison." << endl << endl;

    cout << "Un jour, pendant que Madame Souris etait occupee a ses taches habituelles" << endl;
    cout << "et que Monsieur Souris et sa fille " << girlName << " etaient dehors, il y eut" << endl;
    cout << "un tremblement de terre qui detruisit tout dans leur maison. Madame" << endl;
    cout << "Souris eut a peine le temps de s'eloigner que le terrier s'ecroula." << endl << endl;

    cout << "Quand le tremblement de terre fut termine, Monsieur Souris, Madame Souris et " << girlName << endl;
    cout << "allerent voir ce qui avait cause tous ces degats. Ils aperçurent des ouvriers" << endl;
    cout << "en train de construire une route juste a cote de chez eux. La famille Souris" << endl;
    cout << "dut demenager." << endl << endl;

    cout << "Ne trouvant pas de nouvel habitat, ils firent appel a " << boyName << " Super Souris, " << endl;
    cout << "la souris qui arrange tout. Muni d'une cape rouge et d'une culotte bleue" << endl;
    cout << "sur un pantalon jaune, il descendit de son pays magique perche sur un nuage." << endl << endl;

    cout << boyName << " fit le tour de la terre, cherchant l'endroit ideal pour cette famille," << endl;
    cout << "mais surtout pour " << girlName << " dont il etait tombe amoureux des le premier regard." << endl;
    cout << "Enfin, dans un champ, il trouva une guitare abandonnee et se dit qu'en la garnissant" << endl;
    cout << "de paille, la famille Souris pourrait tres bien y habiter. Volant le plus vite possible," << endl;
    cout << "il rejoignit la famille Souris pour les informer de sa decouverte." << endl;
    cout << "Ils furent emerveilles a l'idee d'habiter un tel endroit." << endl << endl;

    cout << boyName << " Super Souris demanda a son amie la chauve-souris de transporter toute" << endl;
    cout << "la famille sur son dos. Ils furent emmenes jusqu'a la guitare." << endl << endl;

    cout << "C'est alors que " << boyName << " s'empressa d'avouer son amour pour " << girlName << " et demanda" << endl;
    cout << "la permission de l'emmener dans le palais de son pays magique," << endl;
    cout << "la ou les souris volent et ou les chats n'existent pas." << endl << endl;

    cout << "Apres avoir longuement reflechi, Monsieur et Madame Souris accepterent." << endl;
    cout << "Et puisque l'amour fait pousser des ailes, " << girlName << " et " << boyName << " s'envolerent" << endl;
    cout << "tous les deux pour le pays magique." << endl << endl;

    cout << "Finalement, " << boyName << " et " << girlName << " se marierent et eurent beaucoup" << endl;
    cout << "de Super Souriceaux et Super Souricettes." << endl << endl;

    system("pause");

    return 0;
}