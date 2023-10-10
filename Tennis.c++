#include <iostream>
#include <string>

using namespace std;

string determinerScore(int joueur1, int joueur2) {
    if (joueur1 == joueur2) {
        if (joueur1 >= 3) {
            return "Égalité";
        } else {
            return to_string(joueur1 * 15) + " partout";
        }
    } else if (joueur1 >= 3 || joueur2 >= 3) {
        int difference = joueur1 - joueur2;
        if (difference == 1) {
            return "Avantage Joueur 1";
        } else if (difference == -1) {
            return "Avantage Joueur 2";
        } else if (difference >= 2) {
            return "Joueur 1 gagne le jeu";
        } else if (difference <= -2) {
            return "Joueur 2 gagne le jeu";
        }
    } else {
        return to_string(joueur1 * 15) + " - " + to_string(joueur2 * 15);
    }
}

int main() {
    int joueur1, joueur2;

    cout << "Nombre d'échanges gagnés par Joueur 1 : ";
    cin >> joueur1;
    cout << "Nombre d'échanges gagnés par Joueur 2 : ";
    cin >> joueur2;

    string score = determinerScore(joueur1, joueur2);

    cout << "Score : " << score << endl;

    return 0;
}
