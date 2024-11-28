//#include <iostream>
//using namespace std;
//
//
//
//class Pix{
//private:
//    const int idProdus;
//    static int nrProduse;
//    int nrMarciInStoc;
//    float* pretProdus;
//    bool pixCuGel;
//    string culoare;
//public:
//    Pix() :idProdus(nrProduse) {
//        nrProduse++;
//        this->nrMarciInStoc = 0;
//        this->pretProdus = NULL;
//        this->pixCuGel = true;
//        this->culoare = "yellow";
//    }
//    Pix(int nrMarciInStoc, float* pretProdus, bool pixCuGel, string culoare) :idProdus(nrProduse) {
//        nrProduse++;
//        this->nrMarciInStoc = nrMarciInStoc;
//        this->pretProdus = new float[nrMarciInStoc];
//        for (int i = 0; i < nrMarciInStoc; i++) {
//            this->pretProdus[i] = pretProdus[i];
//        }
//        this->pixCuGel = pixCuGel;
//        this->culoare = culoare;
//    }
//    int operator()() {
//        return this->nrMarciInStoc;
//    }
//    int operator()(int n) {
//        return this->nrMarciInStoc + n;
//    }
//    float* operator()(float rataInflatie) {
//        for (int i = 0; i < this->nrMarciInStoc; i++) {
//            this->pretProdus[i] = this->pretProdus[i] * rataInflatie;
//        }
//        return this->pretProdus;
//    }
//    float* getPretProdus() {
//        return this->pretProdus;
//    }
//    void setPretProdus(float* pretProdus, int nrMarciInStoc) {
//        this->nrMarciInStoc = nrMarciInStoc;
//        if (pretProdus != NULL) {
//            delete[]this->pretProdus;
//        }
//        this->pretProdus = new float[nrMarciInStoc];
//        for (int i = 0; i < nrMarciInStoc; i++) {
//            this->pretProdus[i] = pretProdus[i];
//        }
//    }
//    friend ostream& operator <<(ostream& cout,const Pix& p) {
//        cout << "Se afla pixuri (ID:" << p.idProdus << ") de culoarea " << p.culoare;
//                if (p.pixCuGel) {
//                    cout << ", cu gel. ";
//                }
//                else cout << ", fara gel. ";
//                cout << "Avem " << p.nrMarciInStoc << " marci diferite la preturile de: ";
//                if (p.nrMarciInStoc != 0) {
//                    for (int i = 0; i < p.nrMarciInStoc; i++) {
//                        cout << p.pretProdus[i] << "RON ";
//                    }
//                    cout << endl;
//                }
//                else cout << "-" << endl;
//                return cout;
//    }
//    ~Pix() {
//        if (pretProdus != NULL) {
//            delete[]this->pretProdus;
//        }
//    } 
//};
//int Pix::nrProduse = 1;
//int main() {
//    Pix pix1;
//    float* vector = new float[5] {1, 2, 3, 4, 5};
//    pix1.setPretProdus(vector, 5);
//    cout << pix1;
//    cout << pix1(20)<<endl;
//    float inflatie = 1.2;
//    float* vector2 = pix1(inflatie);
//    for (int i = 0; i < 5; i++) {
//        cout << vector2[i] << " ";
//    }
//    cout << endl;
//}