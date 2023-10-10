#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string capitalizeFirstLetter(string str) {
    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
    return str;
}

string capitalizeAllLetters(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

int main() {
    string prenom;
    cout << "Entrez votre prenom : ";
    cin >> prenom;
    cout << "Bonjour, " << capitalizeFirstLetter(prenom) << " !" << endl;


    string nom;
    cout << "Entrez votre nom et prenom (séparés par un espace) : ";
    cin.ignore();
    getline(cin, nom);
    size_t espace = nom.find(' ');
    string nomDeFamille = nom.substr(0, espace);
    string prenomComplet = nom.substr(espace + 1);
    cout << "Bonjour, " << capitalizeFirstLetter(prenomComplet) << " " << capitalizeAllLetters(nomDeFamille) << " !" << endl;

    srand(time(0)); 
    int nombreAleatoire = rand() % 1001;
    int nombreSaisi;
    cout << "Devinez le nombre entre 0 et 1000 : ";
    cin >> nombreSaisi;
    if (nombreSaisi < nombreAleatoire) {
        cout << "Le nombre saisi est plus petit que le nombre généré." << endl;
    } else if (nombreSaisi > nombreAleatoire) {
        cout << "Le nombre saisi est plus grand que le nombre généré." << endl;
    } else {
        cout << "Félicitations ! Vous avez deviné le nombre." << endl;
    }

    int essais = 1;
    while (nombreSaisi != nombreAleatoire) {
        cout << "Essai suivant : ";
        cin >> nombreSaisi;
        essais++;
    }
    cout << "Félicitations ! Vous avez deviné le nombre en " << essais << " essais." << endl;

    int nombreChoisiParUtilisateur;
    cout << "Choisissez un nombre entre 0 et 1000 : ";
    cin >> nombreChoisiParUtilisateur;

    int min = 0;
    int max = 1000;
    int essaisOrdinateur = 0;

    while (true) {
        int nombreDevineParOrdinateur = (min + max) / 2;
        essaisOrdinateur++;

        if (nombreDevineParOrdinateur == nombreChoisiParUtilisateur) {
            cout << "L'ordinateur a deviné votre nombre (" << nombreChoisiParUtilisateur << ") en " << essaisOrdinateur << " essais." << endl;
            break;
        } else if (nombreDevineParOrdinateur < nombreChoisiParUtilisateur) {
            min = nombreDevineParOrdinateur + 1;
        } else {
            max = nombreDevineParOrdinateur - 1;
        }
    }

    return 0;
}
