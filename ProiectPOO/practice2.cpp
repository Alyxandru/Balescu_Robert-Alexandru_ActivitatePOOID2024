#include <iostream>
using namespace std;

class Tastatura {
private:
	const int idTastatura;
	static int nrTastaturi;
	int nrTaste;
	bool luminite;
	char* producator;
	int* pretPerTasta;
public:
	Tastatura() :idTastatura(nrTastaturi) {
		nrTastaturi++;
		this->nrTaste = 0;
		this->luminite = false;
		this->producator = NULL;
		this->pretPerTasta = NULL;
	}
	Tastatura(int nrTaste, bool luminite, char* producator, int* pretPerTasta) :idTastatura(nrTastaturi) {
		nrTastaturi++;
		this->nrTaste = nrTaste;
		this->luminite = luminite;
		if (producator != NULL)
		{
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
		else {
			this->producator = new char[2];
			strcpy_s(this->producator, 2, "-");
		}
		if (nrTaste >0 && pretPerTasta != NULL) {
			this->pretPerTasta = new int[nrTaste];
			for (int i = 0; i < nrTaste;i++) {
				this->pretPerTasta[i] = pretPerTasta[i];
			}
		}
		else{
			this->pretPerTasta = NULL;
		}
	}
	~Tastatura() {
		if (this->producator != NULL) {
			delete[]this->producator;
		}
		if (this->pretPerTasta != NULL) {
			delete[]this->pretPerTasta;
		}
	}
	Tastatura(const Tastatura& c):idTastatura(nrTastaturi) {
		nrTastaturi++;
		this->nrTaste = c.nrTaste;
		this->luminite = c.luminite;
		if (this->producator != NULL) {
			delete[]this->producator;
		}
		if (c.producator != NULL) {
			this->producator = new char[strlen(c.producator) + 1];
			strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
		}
		else {
			this->producator = new char[2];
			strcpy_s(this->producator, 2, "-");
		}
		if (this->pretPerTasta != NULL) {
			delete[]pretPerTasta;
		}
		if (c.nrTaste > 0 && c.pretPerTasta != NULL) {
			this->pretPerTasta = new int[c.nrTaste];
			for (int i = 0; i < c.nrTaste; i++) {
				this->pretPerTasta[i] = c.pretPerTasta[i];
			}
		}
		else {
			this->pretPerTasta = NULL;
		}
	}
	Tastatura& operator =(const Tastatura& c) {
		if (this != &c) {
			this->nrTaste = c.nrTaste;
			this->luminite = c.luminite;
			if (this->producator != NULL) {
				delete[]this->producator;
			}
			if (c.producator != NULL) {
				this->producator = new char[strlen(c.producator) + 1];
				strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
			}
			else {
				this->producator = new char[2];
				strcpy_s(this->producator, 2, "-");
			}
			if (this->pretPerTasta != NULL) {
				delete[]pretPerTasta;
			}
			if (c.nrTaste > 0 && c.pretPerTasta != NULL) {
				this->pretPerTasta = new int[c.nrTaste];
				for (int i = 0; i < c.nrTaste; i++) {
					this->pretPerTasta[i] = c.pretPerTasta[i];
				}
			}
			else {
				this->pretPerTasta = NULL;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& cout, const Tastatura& t) {
		cout << t.idTastatura << " " << t.nrTaste << " ";
		if (t.producator != NULL) {
			cout << t.producator;
		}
		else {
			cout << "unknown";
		}
		cout << " preturi per tasta: ";
		if (t.nrTaste > 0 && t.pretPerTasta != NULL) {
			for (int i = 0; i < t.nrTaste; i++) {
				cout << t.pretPerTasta[i];
				if (i < t.nrTaste - 1) cout << ", ";
			}
		}
		else {
			cout << "-";
		}
		return cout;
	}

};
int Tastatura::nrTastaturi = 0;


int main() {

	Tastatura tastatura1;
	//cout << tastatura1;
	char producator[7] = {"Qwerty"};
	int preturi[3] = {10, 10, 12};
	Tastatura tastatura2(3, 1, producator, preturi);
	cout <<tastatura2;
	tastatura1 = tastatura2;
	cout << tastatura1;


	return 0;
}

