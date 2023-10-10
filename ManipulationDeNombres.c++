#include <iostream>
#include <cstdlib>
#include <ctime>

int saisieEtSomme() {
    int num1, num2;
    std::cout << "Entrez le premier entier : ";
    std::cin >> num1;
    std::cout << "Entrez le deuxième entier : ";
    std::cin >> num2;
    int resultat = num1 + num2;
    std::cout << "La somme est : " << resultat << std::endl;
}

void triBulles(int tableau[], int taille) {
    bool echange;
    do {
        echange = false;
        for (int i = 0; i < taille - 1; i++) {
            if (tableau[i] > tableau[i + 1]) {
                int temp = tableau[i];
                tableau[i] = tableau[i + 1];
                tableau[i + 1] = temp;
                echange = true;
            }
        }
    } while (echange);
}

void sommeAvecPointeurs(int* a, int* b, int* c) {
    *c = *a + *b;
}

void sommeAvecReferences(int& a, int& b, int& c) {
    c = a + b;
}

int main() {

    saisieEtSomme();

    int num1 = 5, num2 = 7, num3 = 0;
    sommeAvecPointeurs(&num1, &num2, &num3);
    std::cout << "Somme avec pointeurs : " << num3 << std::endl;

    num1 = 10, num2 = 20, num3 = 0;
    sommeAvecReferences(num1, num2, num3);
    std::cout << "Somme avec références : " << num3 << std::endl;

    const int tailleTableau = 10;
    int tableau[tailleTableau];

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < tailleTableau; i++) {
        tableau[i] = rand() % 100;
    }

    std::cout << "Valeurs initiales du tableau : ";
    for (int i = 0; i < tailleTableau; i++) {
        std::cout << tableau[i] << " ";
    }
    std::cout << std::endl;

    triBulles(tableau, tailleTableau);

    std::cout << "Tableau trié par ordre croissant : ";
    for (int i = 0; i < tailleTableau; i++) {
        std::cout << tableau[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
