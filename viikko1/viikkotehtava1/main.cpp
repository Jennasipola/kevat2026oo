#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(){
    srand(time(0));
    int salainenLuku = rand () % 20+1;
    int arvattuLuku;


    do {
        std::cout << "Arvaa luku 1-20 valilta." << std::endl;
        std::cin >> arvattuLuku;


        if (arvattuLuku > salainenLuku){
            std::cout << "Luku on liian suuri, kokeile uudestaan!" << std::endl;
        } else if (arvattuLuku < salainenLuku){
            std::cout << "Luku on liian pieni, kokeile uudestaan!" << std::endl;
        } else {
            std::cout << "Oikein arvattu!" << std::endl;
        }

    } while (arvattuLuku != salainenLuku);

    cout << "Peli sulkeutuu painamalla Enter";
    cin.ignore();
    cin.get();

    return 0;
}

//osa2

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game() {
    srand(time(0));
    int salainenLuku = rand() % 20 + 1;
    int arvattuLuku;
    int arvausKerrat = 0;

    do {
        cout << "Arvaa luku 1-20 valilta: ";
        cin >> arvattuLuku;

        arvausKerrat++;

        if (arvattuLuku > salainenLuku) {
            cout << "Luku on liian suuri, kokeile uudestaan!" << endl;
        } else if (arvattuLuku < salainenLuku) {
            cout << "Luku on liian pieni, kokeile uudestaan!" << endl;
        } else {
            cout << "Oikein arvattu!" << endl;
        }

    } while (arvattuLuku != salainenLuku);

    return arvausKerrat;
}

int main() {
    int tulos = game();
    cout << "Arvasit luvun oikein " << tulos << " yrityksellä!" << endl;

    cout << "Paina Enter sulkeaksesi ohjelman...";
    cin.ignore();
    cin.get();

    return 0;
}

//osa3
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum) {
    int salainenLuku = rand() % maxnum + 1;
    int arvattuLuku;
    int arvausKerrat = 0;

    do {
        cout << "Arvaa luku 1-" << maxnum << " valilta: ";
        cin >> arvattuLuku;

        arvausKerrat++;

        if (arvattuLuku > salainenLuku) {
            cout << "Luku on liian suuri, kokeile uudestaan!" << endl;
        } else if (arvattuLuku < salainenLuku) {
            cout << "Luku on liian pieni, kokeile uudestaan!" << endl;
        } else {
            cout << "Oikein arvattu!" << endl;
        }

    } while (arvattuLuku != salainenLuku);

    return arvausKerrat;
}
int main() {
    srand(time(0));

    int tulos = game(40);

    cout << "Arvasit luvun oikein " << tulos << " yrityksella" << endl;

    cout << "Paina Enter sulkeaksesi ohjelman...";
    cin.ignore();
    cin.get();

    return 0;
