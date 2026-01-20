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
