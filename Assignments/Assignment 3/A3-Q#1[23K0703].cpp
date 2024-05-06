#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class Medicine
{
protected:
    string name, formula;
    float retailPrice;
    int manufactureDate, expirationDate;

public:
    Medicine(
        string name,
        string formula,
        float retailPrice,
        int manufactureDate,
        int expirationDate)
        : name(name),
          formula(formula),
          retailPrice(retailPrice),
          manufactureDate(manufactureDate),
          expirationDate(expirationDate) {}

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getFormula()
    {
        return this->formula;
    }

    void setFormula(string formula)
    {
        this->formula = formula;
    }

    float getRetailPrice()
    {
        return this->retailPrice;
    }

    void setRetailPrice(float retailPrice)
    {
        this->retailPrice = retailPrice;
    }

    int getManufactureDate()
    {
        return this->manufactureDate;
    }

    void setManufactureDate(int manufactureDate)
    {
        this->manufactureDate = manufactureDate;
    }

    int getExpirationDate()
    {
        return this->expirationDate;
    }

    void setExpirationDate(int expirationDate)
    {
        this->expirationDate = expirationDate;
    }

    virtual void printMedicine() = 0;
};

class Tablet : public Medicine
{
    float sucroseLevel;

public:
    Tablet(
        string name,
        string formula,
        float retailPrice,
        int manufactureDate,
        int expirationDate,
        float sucroseLevel)
        : Medicine(
              name,
              formula,
              retailPrice,
              manufactureDate,
              expirationDate),
          sucroseLevel(sucroseLevel) {}

    void printMedicine()
    {
        cout << "=====Medicine Details=====" << endl;
        cout << "name: " << name << endl;
        cout << "formula: " << formula << endl;
        cout << "retailPrice: " << retailPrice << endl;
        cout << "manufactureDate: " << manufactureDate << endl;
        cout << "expirationDate: " << expirationDate << endl;
        cout << "sucroseLevel: " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine
{
    float absorptionPercentage;

public:
    Capsule(
        string name,
        string formula,
        float retailPrice,
        int manufactureDate,
        int expirationDate,
        float sucroseLevel)
        : Medicine(
              name,
              formula,
              retailPrice,
              manufactureDate,
              expirationDate),
          absorptionPercentage(absorptionPercentage) {}

    void printMedicine()
    {
        cout << "=====Medicine Details=====" << endl;
        cout << "name: " << name << endl;
        cout << "formula: " << formula << endl;
        cout << "retailPrice: " << retailPrice << endl;
        cout << "manufactureDate: " << manufactureDate << endl;
        cout << "expirationDate: " << expirationDate << endl;
        cout << "absorptionPercentage: " << absorptionPercentage << endl;
    }
};

class Syrup : public Medicine
{
public:
    Syrup(
        string name,
        string formula,
        float retailPrice,
        int manufactureDate,
        int expirationDate,
        float sucroseLevel)
        : Medicine(
              name,
              formula,
              retailPrice,
              manufactureDate,
              expirationDate) {}
};

class Pharmacist
{
public:
    void searchMedicine(Medicine *medicineList);
};

class Counter
{
public:
    void searchMedicine(Medicine *medicineList);

    void updateRevenue(Medicine &medicine);
};

bool operator==(Medicine &med1, Medicine &med2)
{
    return med1.getExpirationDate() == med1.getManufactureDate();
}

int main()
{
    // Header
    cout << "Name: Sarim Ahmed\nRoll Number: 23K0703\n\n";
}