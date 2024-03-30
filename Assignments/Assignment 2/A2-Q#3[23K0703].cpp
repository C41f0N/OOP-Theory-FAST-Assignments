#include <iostream>

using namespace std;

class DarazPersonalData
{
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    DarazPersonalData(
        string firstName,
        string lastName,
        string address,
        string city,
        string state,
        string zip,
        string phone)
        : firstName(firstName),
          lastName(lastName),
          address(address),
          city(city),
          state(state),
          zip(zip),
          phone(phone)
    {
    }

    string getFirstName()
    {
        return this->firstName;
    }

    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }

    string getLastName()
    {
        return this->lastName;
    }

    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }

    string getAddress()
    {
        return this->address;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    string getCity()
    {
        return this->city;
    }

    void setCity(string city)
    {
        this->city = city;
    }

    string getState()
    {
        return this->state;
    }

    void setState(string state)
    {
        this->state = state;
    }

    string getZip()
    {
        return this->zip;
    }

    void setZip(string zip)
    {
        this->zip = zip;
    }

    string getPhone()
    {
        return this->phone;
    }

    void setPhone(string phone)
    {
        this->phone = phone;
    }
};

class DarazCustomerData : public DarazPersonalData
{
    int customerNumber, loyaltyPoints;

public:
    DarazCustomerData(
        string firstName,
        string lastName,
        string address,
        string city,
        string state,
        string zip,
        string phone,
        int customerNumber,
        int loyaltyPoints)
        : DarazPersonalData(
              firstName,
              lastName,
              address,
              city,
              state,
              zip,
              phone)
    {
        this->customerNumber = customerNumber;
        setLoyaltyPoints(loyaltyPoints);
    }

    int getCustomerNumber()
    {
        return this->customerNumber;
    }

    void setCustomerNumber(int customerNumber)
    {
        this->customerNumber = customerNumber;
    }

    int getLoyaltyPoints()
    {
        return this->loyaltyPoints;
    }

    void setLoyaltyPoints(int loyaltyPoints)
    {
        if (loyaltyPoints < 0)
        {
            this->loyaltyPoints = 0;
        }
        else
        {
            this->loyaltyPoints = loyaltyPoints;
        }
    }
};

class DarazLoyaltyProgram
{
public:
    void addLoyaltyPoints(DarazCustomerData &customer, int points)
    {
        int currentPoints = customer.getLoyaltyPoints();
        customer.setLoyaltyPoints(currentPoints + points);
    }

    float redeemLoyaltyPointsForDiscounts(DarazCustomerData &customer, int points)
    {
        int currentPoints = customer.getLoyaltyPoints();
        float discount = 0, discountRate = 3;

        if (currentPoints >= points)
        {
            customer.setLoyaltyPoints(currentPoints - points);
            discount = points * discountRate;
        }

        cout << "Discount Availed is " << discount << endl;

        return discount;
    }

    void displayTotalLoyaltyPoints(DarazCustomerData &customer)
    {
        cout << "Loyalty points for " << customer.getFirstName() << " are: " << customer.getLoyaltyPoints() << endl;
    }
};

int main()
{
    DarazLoyaltyProgram loyaltyProgram;

    DarazCustomerData customerData("Sarim", "Ahmed", "A-214", "Karachi", "Sindh", "101", "03121234567", 1234, 220);

    loyaltyProgram.displayTotalLoyaltyPoints(customerData);

    loyaltyProgram.redeemLoyaltyPointsForDiscounts(customerData, 200);
    loyaltyProgram.displayTotalLoyaltyPoints(customerData);

    loyaltyProgram.addLoyaltyPoints(customerData, 100);
    loyaltyProgram.displayTotalLoyaltyPoints(customerData);
}