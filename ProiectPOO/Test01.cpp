//#include <iostream>
//using namespace std;
//
//
////Proiect Brutarie(Balescu Robert-Alexandru)
//class Angajat {
//	int age;
//	string name;
//	float salary;
//public:
//	Angajat() {
//		this->age = 0;
//		this->name = "unknown";
//		this->salary= 0;
//	}
//	Angajat(int age, string name, float salary) {
//		this->age = age;
//		this->name = name;
//		this->salary = salary;
//	}
//};
//class Pita {
//	static int id;
//	const int idPita;
//	string typePita;
//	bool pitaIntegrala;
//	float price;
//public:
//	Pita():idPita(id){
//		id++;
//		this->typePita = "normal";
//		this->pitaIntegrala = false;
//		this->price = 5;
//	}
//	Pita(float price) :idPita(id) {
//		id++;
//		this->typePita = "normal";
//		this->pitaIntegrala = true;
//		this->price = price;
//	}
//	const Pita& operator=(const Pita& p) {
//		this->typePita = p.typePita;
//		this->pitaIntegrala = p.pitaIntegrala;
//		this->price = p.price;
//		return *this;
//	}
//	friend ostream& operator<<(ostream& cout, const Pita& p) {
//		cout << "Id Pita: " << p.idPita << " Type Pita: " << p.typePita;
//		if (p.pitaIntegrala) {
//			cout << " Pita este integrala";
//		}
//		else {
//			cout << " Pita nu-i integrala";
//		}
//		cout << endl << " Pita costa: " << p.price << endl;
//		return cout;
//	}
//	
//
//};
//class Consumables {
//	string category;
//	int nrProducts;
//	string* consumable;
//public:
//	Consumables() {
//		this->category = "fainoase";
//		this->nrProducts = 0;
//		this->consumable = NULL;
//	}
//	Consumables(string category, int nrProducts, string* consumable) {
//		this->category = category;
//		this->nrProducts = nrProducts;
//		this->consumable = new string[nrProducts];
//		for (int i = 0;i < nrProducts;i++) {
//			this->consumable[i] = consumable[i];
//		}
//	}
//	void setCategory(string category) {
//		this->category = category;
//	}
//	string getCategory() {
//		return this->category;
//	}
//	friend ostream& operator<<(ostream& cout, const Consumables& c) {
//		cout << "categoria este: " << c.category << " avand " << c.nrProducts << " produse" << endl;
//		cout << "produsele sunt: " << endl;
//		for (int i = 0;i < c.nrProducts;i++) {
//			cout << c.consumable[i]<<", ";
//		}
//		cout << endl;
//		return cout;
//	}
//	~Consumables() {
//		if (this->consumable) {
//			delete[]this->consumable;
//		}
//	}
//};
//int Pita::id = 1;
//
//void main() {
//	Pita pita1;
//	Pita pita2(10);
//	cout << pita1 << pita2;
//	pita2 = pita1;
//	cout << pita1 << pita2;
//	/*string products[] = {"lapte", "lapte bio", "branza", "cascaval", "smantana"};
//	Consumables consumables1("lactate", 5, products);
//	cout << consumables1;*/
//
//}