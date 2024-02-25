#include <iostream>

using namespace std;

class Pet
{
    string healthStatus, species;
    int hungerLevel, happinessLevel;
    string *specialSkills;
    int numSpecialSkills;

public:
    Pet()
    {
        // Input initial details

        cout << "Enter Hunger Level: ";
        cin >> hungerLevel;

        cout << "Enter Happiness Level: ";
        cin >> happinessLevel;

        cout << "Enter Pet Species: ";
        cin >> species;

        updateHealth();

        cout << "Enter Number Of Special Skills: ";
        cin >> numSpecialSkills;

        specialSkills = new string[numSpecialSkills];

        for (int i = 0; i < numSpecialSkills; i++)
        {
            cout << "Enter Skill " << i + 1 << ": ";
            cin >> specialSkills[i];
        }
    }

    void updateHappiness()
    {
        if (hungerLevel > 5)
        {
            happinessLevel--;
        }
        else if (hungerLevel < 5)
        {
            happinessLevel++;
        }

        // Putting a cap on the updated values
        if (happinessLevel > 10)
        {
            happinessLevel = 10;
        }
        else if (happinessLevel < 1)
        {
            happinessLevel = 1;
        }
    }

    void updateHealth()
    {
        if (hungerLevel < 5)
        {
            healthStatus = "Healthy";
        }
        else
        {
            healthStatus = "Sick";
        }
    }

    void updateHunger()
    {
        string fedData;
        cout << "Do you want to feed the pet? (Y/n): ";
        cin >> fedData;

        if (fedData == "Y" || fedData == "y")
        {
            cout << "[+] Feeding the pet...";
            hungerLevel--;
        }
        else
        {
            cout << "[+] Not feeding the pet.";
            hungerLevel++;
        }

        // Putting a cap on the updated values
        if (hungerLevel > 10)
        {
            hungerLevel = 10;
        }
        else if (hungerLevel < 1)
        {
            hungerLevel = 1;
        }
    }

    void displayPetDetails()
    {
        cout << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Happiness Level: " << happinessLevel << endl;
        cout << "Hunger Level: " << hungerLevel << endl;

        cout << "Special Skills: " << endl;
        for (int i = 0; i < numSpecialSkills; i++)
        {
            cout << "Skill " << i + 1 << ": " << specialSkills[i] << endl;
        }
        cout << endl;
    }
};

class Adopter
{
    string name, mobileNumber;
    Pet adoptedPets[10];
    int numberOfAdoptedPets = 0;

public:
    Adopter()
    {
        cout << "Enter the adopter's name: ";
        cin >> name;

        cout << "Enter the adopter's mobile number: ";
        cin >> mobileNumber;
    }

    void adoptPet(Pet pet)
    {
        numberOfAdoptedPets++;
        cout << "Creating new array" << endl;
        Pet *newAdoptedList = new Pet[numberOfAdoptedPets];
        cout << "created new array" << endl;

        for (int i = 0; i < numberOfAdoptedPets; i++)
        {
            newAdoptedList[i] = adoptedPets[i];
        }
        newAdoptedList[numberOfAdoptedPets - 1] = pet;

    }

    void returnPet()
    {
        numberOfAdoptedPets--;
        Pet *newAdoptedList = new Pet[numberOfAdoptedPets];

        for (int i = 0; i < numberOfAdoptedPets; i++)
        {
            newAdoptedList[i] = adoptedPets[i];
        }

        Pet *temp;
        temp = adoptedPets;
        adoptedPets = newAdoptedList;
        newAdoptedList = temp;

        delete[] newAdoptedList;
        delete[] temp;
    }

    void displayAdoptedPets()
    {
        for (int i = 0; i < numberOfAdoptedPets; i++)
        {
            adoptedPets[i].displayPetDetails();
        }
    }
};

int main()
{
    // Name Header
    cout << "Student ID: 23K0703" << endl;
    cout << "Name: Sarim Ahmed" << endl
         << endl;

    cout << "[+] Demostrating the pet class..." << endl;

    // Pet myPet1, myPet2;
    // myPet1.displayPetDetails();

    // myPet1.updateHunger();
    // myPet1.updateHealth();
    // myPet1.updateHappiness();
    // myPet1.displayPetDetails();

    // myPet1.updateHunger();
    // myPet1.updateHealth();
    // myPet1.updateHappiness();
    // myPet1.displayPetDetails();

    // myPet1.updateHunger();
    // myPet1.updateHealth();
    // myPet1.updateHappiness();
    // myPet1.displayPetDetails();

    cout << "[+] Demostrating the adopter class..." << endl;
    Pet myPet1;

    Adopter adopter;

    adopter.adoptPet(myPet1);
    // adopter.adoptPet(myPet2);

    adopter.displayAdoptedPets();

    adopter.returnPet();
    adopter.displayAdoptedPets();
}