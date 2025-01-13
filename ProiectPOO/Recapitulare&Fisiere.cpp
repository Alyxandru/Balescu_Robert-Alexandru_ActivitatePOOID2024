#include <iostream>
#include <string.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Autobuz {
	static int nrAutobuze;
	const int nrInmatriculare;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	Autobuz() :nrInmatriculare(nrAutobuze) {
		capacitate = 0;
		nrPersoaneImbarcate = 0;
		producator = NULL;
		nrAutobuze++;
	}

	Autobuz(int capacitate, int nrPersoaneImbarcate, char* producator) :nrInmatriculare(nrAutobuze) {
		if (capacitate > 0) {
			this->capacitate = capacitate;
		}
		else {
			this->capacitate = 0;
		}
		if (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= this->capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		else {
			this->nrPersoaneImbarcate = 0;
		}
		if (producator != NULL) {
			this->producator = new char[strlen(producator) + 1];
			strcpy(this->producator, producator);
		}
		else {
			this->producator = NULL;
		}
		nrAutobuze++;
	}

	Autobuz(Autobuz& a) :nrInmatriculare(a.nrInmatriculare) {
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		if (this->producator != NULL) {
			delete[] this->producator;
		}
		if (a.producator != NULL) {
			this->producator = new char[strlen(a.producator) + 1];
			strcpy(this->producator, a.producator);
		}
		else {
			this->producator = NULL;
		}
	}

	~Autobuz() {
		if (producator != NULL) {
			delete[] producator;
		}
	}
	int getCapacitate() {
		return capacitate;
	}
	void setCapacitate(int capacitate) {
		if (capacitate > 0) {
			this->capacitate = capacitate;
		}
	}

	char* getProducator() {
		return producator;
	}

	void setProducator(char* producator) {
		if (this->producator != NULL) {
			delete[] this->producator;
		}
		if (producator != NULL) {
			this->producator = new char[strlen(producator) + 1];
			strcpy(this->producator, producator);
		}
		else {
			this->producator = new char[2];
			strcpy(this->producator, "-");
		}
	}
	Autobuz& operator=(Autobuz& a) {
		if (this != &a) {
			this->capacitate = a.capacitate;
			this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
			if (this->producator != NULL) {
				delete[] this->producator;
			}
			if (a.producator != NULL) {
				this->producator = new char[strlen(a.producator) + 1];
				strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
			}
			else {
				this->producator = NULL;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, Autobuz& a) {
		out << a.nrInmatriculare << "; " << a.capacitate << "; " << a.nrPersoaneImbarcate << "; ";
		if (a.producator != NULL) {
			out << a.producator;
		}
		else {
			out << "-";
		}
		return out;
	}

	friend istream& operator>>(istream& in, Autobuz& a) {
		in >> a.capacitate;
		in >> a.nrPersoaneImbarcate;
		if (a.producator != NULL) {
			delete[] a.producator;
		}
		char buffer[100];
		in >> buffer;
		a.producator = new char[strlen(buffer) + 1];
		strcpy(a.producator, buffer);
		return in;
	}

	void scriereFisierTxt(string numeFisier) {
		ofstream f(numeFisier, ios::out);
		f << capacitate << " " << nrPersoaneImbarcate << " ";
		int lungime = strlen(producator);
		f << lungime << " ";
		if (producator) {
			f << producator;
		}
		else {
			f << "-";
		}

		f.close();
	}

	void citireFisierTxt(string numeFisier) {
		ifstream f(numeFisier, ios::in);
		f >> capacitate;
		f >> nrPersoaneImbarcate;
		int lungime;
		f >> lungime;
		if (producator) {
			delete[] producator;
		}
		producator = new char[lungime + 1];
		f >> producator;

		f.close();
	}

	//FISIER BINAR
	void scriereFisierBinar(string numeFisier) {
		ofstream f(numeFisier, ios::out | ios::binary);
		/*int capacitate;
		int nrPersoaneImbarcate;
		char* producator;*/
		f.write((char*)&capacitate, sizeof(int));
		f.write((char*)&nrPersoaneImbarcate, sizeof(int));
		int lungime = strlen(producator);
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++) {
			f.write((char*)&producator[i], sizeof(char));
		}

		f.close();
	}

	void citireFisierBinar(string numeFisier) {
		ifstream f(numeFisier, ios::in | ios::binary);
		f.read((char*)&capacitate, sizeof(int));
		f.read((char*)&nrPersoaneImbarcate, sizeof(int));
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		if (producator) {
			delete[] producator;
		}
		producator = new char[lungime + 1];
		f.read(producator, lungime);
		producator[lungime] = '\0';

		f.close();
	}

	int getNumarLocuriLibere() {
		return capacitate - nrPersoaneImbarcate;
	}

	operator string() {
		return producator;
	}

	operator int() {
		return nrPersoaneImbarcate;
	}

	bool operator>(Autobuz& a) {
		return this->capacitate > a.capacitate;
	}

	int operator()() {
		return capacitate;
	}
};

int Autobuz::nrAutobuze = 1;

int main() {
	Autobuz a1;
	Autobuz a2(50, 25, new char[9] {"Mercedes"});

	cout << a1 << endl;
	cout << a2 << endl;

	a2.scriereFisierTxt("autobuz.txt");
	Autobuz a3;
	a3.citireFisierTxt("autobuz.txt");
	cout << a3 << endl;

	a3.scriereFisierBinar("autobuz.bin");
	Autobuz a4;
	a4.citireFisierBinar("autobuz.bin");
	cout << a4 << endl;

	return 0;
}