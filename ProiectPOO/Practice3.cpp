#include <iostream>
#include <cstring>
using namespace std;

class Train {
    static int totalTrains;
    const int trainID;
    int capacity;
    int passengersOnboard;
    char* manufacturer;
public:
    Train() : trainID(totalTrains) {
        totalTrains++;
        this->capacity = 0;
        this->passengersOnboard = 0;
        this->manufacturer = nullptr;
    }

    Train(int capacity, int passengersOnboard, const char* manufacturer) : trainID(totalTrains) {
        totalTrains++;
        this->capacity = (capacity > 0) ? capacity : 0;
        this->passengersOnboard = (passengersOnboard >= 0 && passengersOnboard <= this->capacity) ? passengersOnboard : 0;
        if (manufacturer) {
            this->manufacturer = new char[strlen(manufacturer) + 1];
            strcpy_s(this->manufacturer, strlen(manufacturer) + 1, manufacturer);
        }
        else {
            this->manufacturer = new char[2];
            strcpy_s(this->manufacturer, 2, "-");
        }
    }
    Train(const Train& t) : trainID(totalTrains) {
        totalTrains++;
        this->capacity = t.capacity;
        this->passengersOnboard = t.passengersOnboard;
        this->manufacturer = t.manufacturer ? new char[strlen(t.manufacturer) + 1] : nullptr;
        if (t.manufacturer) {
            strcpy_s(this->manufacturer, strlen(t.manufacturer) + 1, t.manufacturer);
        }
    }

    int getCapacity() const {
        return this->capacity;
    }

    void setCapacity(int capacity) {
        this->capacity = (capacity > 0) ? capacity : 0;
    }

    char* getManufacturer() const {
        return this->manufacturer;
    }

    void setManufacturer(const char* manufacturer) {
        if (this->manufacturer) {
            delete[] this->manufacturer;
        }
        if (manufacturer) {
            this->manufacturer = new char[strlen(manufacturer) + 1];
            strcpy_s(this->manufacturer, strlen(manufacturer) + 1, manufacturer);
        }
        else {
            this->manufacturer = new char[2];
            strcpy_s(this->manufacturer, 2, "-");
        }
    }

    friend ostream& operator<<(ostream& os, const Train& t) {
        os << t.trainID << "; " << t.capacity << "; " << t.passengersOnboard << "; ";
        os << (t.manufacturer ? t.manufacturer : "unknown") << endl;
        return os;
    }

    Train& operator=(const Train& t) {
        if (this != &t) {
            this->capacity = t.capacity;
            this->passengersOnboard = t.passengersOnboard;
            if (this->manufacturer) {
                delete[] this->manufacturer;
            }
            if (t.manufacturer) {
                this->manufacturer = new char[strlen(t.manufacturer) + 1];
                strcpy_s(this->manufacturer, strlen(t.manufacturer) + 1, t.manufacturer);
            }
            else {
                this->manufacturer = new char[2];
                strcpy_s(this->manufacturer, 2, "-");
            }
        }
        return *this;
    }

    int availableSeats() const {
        return this->capacity - this->passengersOnboard;
    }

    bool operator>(const Train& t) const {
        return this->capacity > t.capacity;
    }

    explicit operator int() const {
        return this->passengersOnboard;
    }

    operator string() const {
        return this->manufacturer ? string(this->manufacturer) : "-";
    }

    ~Train() {
        if (this->manufacturer) {
            delete[] this->manufacturer;
        }
    }
};

int Train::totalTrains = 1;

int main() {
    Train train1;
    cout << train1;
    cout << train1.getCapacity() << endl;

    char A[10] = "Transport";
    train1.setManufacturer(A);
    cout << train1;

    cout << train1.availableSeats() << endl;

    char B[5] = "G";
    Train train2(200, 120, B);
    cout << train2;

    if (train1 > train2) {
        cout << train1.getCapacity();
    }
    else {
        cout << train2.getCapacity();
    }

    Train train3(train2);
    cout << train3 << train2;
    train3 = train1;
    cout << train1 << train3;

    int passengers = static_cast<int>(train1);
    cout << passengers << endl;

    string manufacturer = train1;
    cout << manufacturer << endl;

    return 0;
}