#include <iostream>

using namespace std;

class Pet
{
    string healthStatus, species;
    int hungerLevel, happinessLevel;
    string *specialSkills;
    int numSpecialSkills;

public:
    Pet() {}

    Pet(int hungerLevel, int happinessLevel, string species, int numSpecialSkills)
    {
        // Input initial details

        this->hungerLevel = hungerLevel;

        this->happinessLevel = happinessLevel;

        this->species = species;

        updateHealth();

        this->numSpecialSkills = numSpecialSkills;

        if (this->numSpecialSkills > 0)
        {
            specialSkills = new string[this->numSpecialSkills];

            for (int i = 0; i < this->numSpecialSkills; i++)
            {
                cout << "Enter Skill " << i + 1 << ": ";
                cin >> specialSkills[i];
            }
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
        fflush(stdin);
        cout
            << "Do you want to feed the pet? (Y/n): ";
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

        if (this->numSpecialSkills > 0)
        {
            cout << "Special Skills: " << endl;
            for (int i = 0; i < this->numSpecialSkills; i++)
            {
                cout << "Skill " << i + 1 << ": " << specialSkills[i] << endl;
            }
        }
        cout << endl;
    }
};

class Adopter
{
    string name, mobileNumber;
    Pet *adoptedPets;
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
        Pet *newAdoptedList = new Pet[numberOfAdoptedPets];

        for (int i = 0; i < numberOfAdoptedPets - 1; i++)
        {
            newAdoptedList[i] = adoptedPets[i];
        }
        newAdoptedList[numberOfAdoptedPets - 1] = pet;

        Pet *temp = adoptedPets;
        adoptedPets = newAdoptedList;
        newAdoptedList = temp;

        if (numberOfAdoptedPets - 1 > 0)
        {
            delete[] newAdoptedList;
        }
    }

    void returnPet()
    {
        numberOfAdoptedPets--;
        if (numberOfAdoptedPets > 0)
        {
            Pet *newAdoptedList = new Pet[numberOfAdoptedPets];

            for (int i = 0; i < numberOfAdoptedPets; i++)
            {
                newAdoptedList[i] = adoptedPets[i];
            }

            Pet *temp = adoptedPets;
            adoptedPets = newAdoptedList;
            newAdoptedList = temp;

            delete[] newAdoptedList;
        }
        else
        {
            delete[] adoptedPets;
        }
    }

    void displayAdoptedPets()
    {
        for (int i = 0; i < this->numberOfAdoptedPets; i++)
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

    int happinessLevel, hungerLevel, numSpecialSkills;
    string species;

    // Initializing pet one object
    cout << "Enter happiness level for myPet1: ";
    cin >> happinessLevel;

    cout << "Enter hunger level for myPet1: ";
    cin >> hungerLevel;

    cout << "Enter species for myPet1: ";
    cin >> species;

    cout << "Enter number of myPet1's special skills: ";
    cin >> numSpecialSkills;

    Pet myPet1(hungerLevel, happinessLevel, species, numSpecialSkills);

    myPet1.displayPetDetails();

    // Initializing pet one object
    cout << "Enter happiness level for myPet2: ";
    cin >> happinessLevel;

    cout << "Enter hunger level for myPet2: ";
    cin >> hungerLevel;

    cout << "Enter species for myPet2: ";
    cin >> species;

    cout << "Enter number of myPet2's special skills: ";
    cin >> numSpecialSkills;

    Pet myPet2(hungerLevel, happinessLevel, species, numSpecialSkills);

    myPet2.displayPetDetails();

    myPet1.updateHunger();
    myPet1.updateHealth();
    myPet1.updateHappiness();
    myPet1.displayPetDetails();

    myPet1.updateHunger();
    myPet1.updateHealth();
    myPet1.updateHappiness();
    myPet1.displayPetDetails();

    myPet1.updateHunger();
    myPet1.updateHealth();
    myPet1.updateHappiness();
    myPet1.displayPetDetails();

    cout << "[+] Demostrating the adopter class..." << endl;

    Adopter adopter;

    cout << "\n[+] Adopting myPet1";
    adopter.adoptPet(myPet1);

    cout << "\n[+] Adopting myPet2";
    adopter.adoptPet(myPet2);

    cout << "\n[+] Displaying Adopted Pets";
    adopter.displayAdoptedPets();

    cout << "\n[+] Returning Last Pet";
    adopter.returnPet();

    cout << "\n[+] Displaying Adopted Pets";
    adopter.displayAdoptedPets();
}