//#include <iostream>
//using namespace std;
//
//class Colet {
//private:
//    const int idColet;
//    float greutate;
//    int nrProduse;
//    float* pretProdus;
//    bool esteLivrat;
//
//public:
//    // Default constructor
//    Colet() : idColet(0) {
//        this->greutate = 0.0;
//        this->nrProduse = 0;
//        this->pretProdus = NULL;
//        this->esteLivrat = false;
//    }
//
//    // Parameterized constructor
//    Colet(int idColet, float greutate, int nrProduse, float* pretProduse, bool esteLivrat) : idColet(idColet) {
//        this->greutate = greutate;
//        this->nrProduse = nrProduse;
//        if (nrProduse > 0 && pretProduse != NULL) {
//            this->pretProdus = new float[nrProduse];
//            for (int i = 0; i < nrProduse; i++) {
//                this->pretProdus[i] = pretProduse[i];
//            }
//        }
//        else {
//            this->pretProdus = NULL;
//        }
//        this->esteLivrat = esteLivrat;
//    }
//
//    // Destructor
//    ~Colet() {
//        if (this->pretProdus != NULL) {
//            delete[] this->pretProdus;
//        }
//    }
//
//    // Getter and setter for greutate
//    float getGreutate() {
//        return this->greutate;
//    }
//
//    void setGreutate(float greutate) {
//        this->greutate = greutate;
//    }
//
//    // Getter and setter for esteLivrat
//    bool getLivrare() {
//        return this->esteLivrat;
//    }
//
//    void setLivrare(bool esteLivrat) {
//        this->esteLivrat = esteLivrat;
//    }
//
//    // Copy constructor
//    Colet(const Colet& c) : idColet(c.idColet) {
//        this->greutate = c.greutate;
//        this->nrProduse = c.nrProduse;
//        if (c.pretProdus != NULL) {
//            this->pretProdus = new float[c.nrProduse];
//            for (int i = 0; i < c.nrProduse; i++) {
//                this->pretProdus[i] = c.pretProdus[i];
//            }
//        }
//        else {
//            this->pretProdus = NULL;
//        }
//        this->esteLivrat = c.esteLivrat;
//    }
//
//    // Copy assignment operator
//    Colet& operator=(const Colet& c) {
//        if (this != &c) {
//            this->greutate = c.greutate;
//            this->nrProduse = c.nrProduse;
//
//            if (this->pretProdus != NULL) {
//                delete[] this->pretProdus;
//            }
//
//            if (c.pretProdus != NULL) {
//                this->pretProdus = new float[c.nrProduse];
//                for (int i = 0; i < c.nrProduse; i++) {
//                    this->pretProdus[i] = c.pretProdus[i];
//                }
//            }
//            else {
//                this->pretProdus = NULL;
//            }
//
//            this->esteLivrat = c.esteLivrat;
//        }
//        return *this;
//    }
//
//    // Friend function for output
//    friend ostream& operator<<(ostream& cout, const Colet& c) {
//        cout << "ID Colet: " << c.idColet
//            << ", Greutate: " << c.greutate
//            << ", Nr. Produse: " << c.nrProduse
//            << ", Preturi: {";
//
//        if (c.pretProdus != NULL) {
//            for (int i = 0; i < c.nrProduse; i++) {
//                cout << c.pretProdus[i]<<", ";
//            }
//        }
//        else {
//            cout << "0";
//        }
//
//        cout << "}Este Livrat: " << (c.esteLivrat ? "Da" : "Nu") << endl;
//        return cout;
//    }
//    //friend istream& operator>>(istream& cin, Colet& c) {
//    friend istream& operator >>(istream& cin, Colet& c) {
//        cin >> c.greutate;
//        cin >> c.nrProduse;
//
//        if (c.pretProdus != NULL) {
//            delete[] c.pretProdus;
//        }
//        if (c.nrProduse > 0) {
//            c.pretProdus = new float[c.nrProduse];
//            cout << "Enter prices of products: ";
//            for (int i = 0; i < c.nrProduse; i++) {
//                cin >> c.pretProdus[i];
//            }
//        }
//        else {
//            c.pretProdus = NULL;
//        }
//        cin >> c.esteLivrat;
//        return cin;
//    }
//
//};
//
//int main() {
//    Colet colet1;
//    cout <<colet1;
//
//    float preturi[] = { 100.5, 200.75, 50.25 };
//    Colet colet2(1, 10.5, 3, preturi, true);
//    cout << colet2;
//
//    Colet colet3(colet2);
//    cout << colet3;
//
//    colet1 = colet3;
//    cout << colet1;
//
//
//    return 0;
//}
