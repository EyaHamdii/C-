#include <iostream>
#include <string>

using namespace std;

class Papier {
private:
    int age;
    int somme;

public:
    void ecrire(int a, int s) {
        age = a;
        somme = s;
        cout << "[Spectateur] (j'écris le papier)\n";
    }

    int getAge() const { return age; }
    int getSomme() const { return somme; }
};

class Spectateur {
private:
    int age;
    int somme;

public:
    void entrerDonnees() {
        cout << "[Spectateur] (j'entre en scène)\n";

        cout << "Quelle age as tu ? ";
        cin >> age;

        do {
            cout << "Combien t'as d'argent en poche (<100) ? ";
            cin >> somme;
            if (somme >= 100)
                cout << "Erreur : La somme doit être inférieure à 100 !\n";
        } while (somme >= 100);
    }

    void ecrirePapier(Papier &papier) {
        papier.ecrire(age, somme);
    }
};

class Assistant {
public:
    int calculMagique(const Papier &papier) {
        cout << "[Assistant] (je lis le papier)\n";
        int age = papier.getAge();
        int somme = papier.getSomme();

        cout << "[Assistant] (je calcule mentalement)\n";
        return (((age * 2) + 5) * 50 + somme) - 365;
    }
};


class Magicien {
public:

    void deviner(int resultat) {
        cout << "[Magicien] un petit tour de magie...\n";


        int total = resultat + 115;


        int age = total / 100;


        int somme = total % 100;


        cout << "[Magicien]\n";
        cout << "- hum... je vois que vous êtes âgé de " << age
             << " ans et que vous avez " << somme << " francs en poche !\n";
    }
};


int main() {

    Spectateur spectateur;
    Papier papier;
    Assistant assistant;
    Magicien magicien;


    spectateur.entrerDonnees();
    spectateur.ecrirePapier(papier);

    int resultat = assistant.calculMagique(papier);
    cout << "[Assistant] J'annonce : " << resultat << " !\n";


    magicien.deviner(resultat);

    return 0;
}
