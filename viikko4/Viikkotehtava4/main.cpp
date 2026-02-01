#include <iostream>
#include <string>
using namespace std;

class Pankkitili{
public:
    Pankkitili (const std::string& omistaja) : omistaja(omistaja), saldo(0){}

    double getBalance() const{
        return saldo;
    }

    virtual bool deposit (double amount){
        if (amount < 0) return false;
        saldo += amount;
        return true;
    }
    virtual bool withdrawal(double amount){
        if (amount < 0 || amount > saldo) return false;
        saldo -= amount;
        return true;
    }
protected:
    std::string omistaja;
    double saldo;

};


    class Luottotili : public Pankkitili{
public:
        Luottotili (const std::string& omistaja, double luottoRaja) : Pankkitili(omistaja), luottoRaja(luottoRaja){}
    bool deposit (double amount) override{
        if (amount < 0) return false;
        saldo += amount;
        if (saldo > 0) saldo=0;
        return true;

    }

    bool withdrawal (double amount) override{
        if (amount < 0) return false;
        if (saldo - amount < -luottoRaja) return false;
        saldo -= amount;
        return true;
    }

protected:
    double luottoRaja;

};

class Asiakas{
public:
    Asiakas (const std::string& nimi, double luottoRaja) : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja){}

    std::string getNimi() const{ return nimi; }

    void showSaldo() const {
            std::cout << "Pankkitili: " << kayttotili.getBalance() << " EUR\n";
            std::cout << "Luottotili: " << luottotili.getBalance() << " EUR\n";
}
     bool talletus (double amount){
         return kayttotili.deposit(amount);
            }
     bool nosto (double amount){
         return kayttotili.withdrawal(amount);
        }
    bool luotonMaksu (double amount){
        return luottotili.deposit(amount);
        }
    bool luotonNosto (double amount){
        return luottotili.withdrawal(amount);
        }
    bool tiliSiirto(double amount, Asiakas& vastaanottaja) {
        if (amount < 0) return false;

        if (!kayttotili.withdrawal(amount)) {
            return false;
        }

        vastaanottaja.talletus(amount);
        return true;
    }

private:
    std::string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

    };

//ohjelman testaus
    int main() {
        Asiakas a("Matti", 500.0);

        a.talletus(1000);
        a.nosto(200);
        a.luotonNosto(300);
        a.luotonMaksu(150);

        a.showSaldo();

        std::cout << "Paina Enter sulkeaksesi ohjelman...";
        std::cin.get();

        return 0;
    }


//ohjelman testaus 2 osalla
    int main() {
        Asiakas a("Matti", 500.0);
        Asiakas b("Liisa", 300.0);

        a.talletus(1000);

        a.tiliSiirto(200, b);

        std::cout << "Matti:\n";
        a.showSaldo();

        std::cout << "\nLiisa:\n";
        b.showSaldo();

        std::cin.get();
        return 0;
    }

