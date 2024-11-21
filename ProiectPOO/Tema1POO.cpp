#include <iostream>
using namespace std;

class Autobuz {
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;
public:
	//constructor fara parametri
	Autobuz():idAutobuz(nrAutobuze) {
		nrAutobuze++;
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->producator = NULL;
	}
	//constructor cu parametri
	Autobuz(int capacitate, int nrPersoaneImbarcate, char* producator) :idAutobuz(nrAutobuze) {
		nrAutobuze++;
		//validari:
		if (capacitate > -1) {
			this->capacitate = capacitate;
		}
		else {
			this->capacitate = 0;
		}
		if (nrPersoaneImbarcate > -1 && nrPersoaneImbarcate <= this->capacitate)
		{
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		else {
			if (nrPersoaneImbarcate >= this->capacitate) {
				this->nrPersoaneImbarcate = this->capacitate;
			}
			else {
				this->nrPersoaneImbarcate = 0;
			}
		}
		if (producator != NULL) {
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator,strlen(producator)+1, producator);
		}
		else {
			//this->producator = NULL;
			this->producator = new char[2];
			strcpy_s(this->producator,2,"-");
		}
	}
	Autobuz(const Autobuz& a):idAutobuz(nrAutobuze) {
		nrAutobuze++;
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		if (this->producator != NULL) {
			delete[]this->producator;
		}
		if (a.producator != NULL) {
			this->producator = new char[strlen(a.producator) + 1];
			strcpy_s(this->producator,strlen(a.producator)+1, a.producator);
		}
		else {
			this->producator = NULL;
		}
	}


	int getCapacitate(){
		return this->capacitate;
	}
	void setCapacitate(int capacitate) {
		this->capacitate = capacitate;
	}
	char* getProducator() {
		return this->producator;
	}
	void setProducator(char* producator) {
		if (this->producator != NULL) {
			delete[]this->producator;
		}
		if (producator != NULL) {
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator,strlen(producator)+1, producator);
		}
		else {
			//this->producator = NULL;
			this->producator = new char[2];
			strcpy_s(this->producator,2, "-");
		}
		
	}
	//operator de afisare
	friend ostream& operator << (ostream& cout, const Autobuz& a) {
		cout << a.idAutobuz << "; " << a.capacitate << "; " << a.nrPersoaneImbarcate << "; ";
		if (a.producator != NULL) {
			cout << a.producator;
		}
		else {
			cout << "unknown";
		}
		cout << endl;
		return cout;
	}
	Autobuz& operator =(const Autobuz& a) {
		if (this != &a) {
			this->capacitate = a.capacitate;
			this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
			if (this->producator != NULL) {
				delete[]this->producator;
			}
			if (a.producator != NULL) {
				this->producator = new char[strlen(a.producator) + 1];
				strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
			}
			else {
				this->producator = new char[2];
				strcpy_s(this->producator, 2, "-");
			}
		}
		return *this;
		
	}

	int getNumarLocuriLibere() {
		return (this->capacitate - this->nrPersoaneImbarcate);
	}
	bool operator > (Autobuz& a) {
		return this->capacitate > a.capacitate;
	}

	explicit operator int() {
		return this->nrPersoaneImbarcate;
	}
	//cast la string
	operator string () {
		return this->producator;
	}

	~Autobuz() {
		if(this->producator != NULL)
		delete[]this->producator;
	}
	
};
int Autobuz::nrAutobuze = 1;

int  main() {
	Autobuz autobuz1;
	cout << autobuz1;
	cout << autobuz1.getCapacitate()<<endl;

	char marcel[7] = "Marcel";
	autobuz1.setProducator(marcel);
	cout << autobuz1;


	cout << autobuz1.getNumarLocuriLibere() << endl;

	char vector[4] = "BMW";
	Autobuz autobuz2(150, 100, vector);
	cout << autobuz2;
	if (autobuz1 > autobuz2) {
		cout << autobuz1.getCapacitate();
	}
	else{
		cout << autobuz2.getCapacitate();
	}
	//cout <<endl<< (autobuz1 > autobuz2)<<endl;

	//constructor de copiere
	Autobuz autobuz3(autobuz2);
	cout << autobuz3 << autobuz2;
	autobuz3 = autobuz1;
	cout << autobuz1 << autobuz3;

	int nrCalatori = /*explicit cast*/ (int)autobuz1;cout << nrCalatori << endl;
	string producatorulAutobuz = autobuz1;cout << producatorulAutobuz<<endl;

	return 0;

}