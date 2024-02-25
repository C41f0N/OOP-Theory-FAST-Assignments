#include <iostream>
#include <cmath>

using namespace std;

class RollerCoaster
{
    string name;
    float height;
    float length;
    float speed;
    int capacity;
    int currentNumRiders;
    bool rideInProgress;

public:
    RollerCoaster()
    {
        name = "roller coaster";
        height = 500.0;
        length = 2000.0;
        speed = 0;
        capacity = 20;
        rideInProgress = false;
    }

    RollerCoaster(string name, float height, float length, int capacity)
    {
        this->name = name;
        this->height = height;
        this->length = length;
        this->speed = 0;
        this->rideInProgress = false;

        if (capacity % 2 == 0 || capacity % 3 == 0)
        {
            this->capacity = capacity;
        }
        else
        {
            // Will always be an odd number, hence the closest multiple of
            // two (any even number) can be obtained by adding 1.
            this->capacity = capacity + 1;
        }

        // Capping the capacity to always be greater than 3
        if (this->capacity <= 3)
            this->capacity = 4;
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    float getLength()
    {
        return this->length;
    }

    void setLength(float length)
    {
        this->length = length;
    }

    float getHeight()
    {
        return this->height;
    }

    void setHeight(float height)
    {
        this->height = height;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    void setCapacity(int capacity)
    {
        if (capacity % 2 == 0 || capacity % 3 == 0)
        {
            this->capacity = capacity;
        }
        else
        {
            // Will always be an odd number, hence the closest multiple of
            // two (any even number) can be obtained by adding 1.
            this->capacity = capacity + 1;
        }

        // Capping the capacity to always be greater than 3
        if (this->capacity <= 3)
            this->capacity = 4;
    }

    bool getProgressStatus()
    {
        return this->rideInProgress;
    }

    void setProgressStatus(bool rideInProgress)
    {
        this->rideInProgress = rideInProgress;
    }

    float getSpeed()
    {
        return this->speed;
    }

    int getCurrentlySeated()
    {
        return this->currentNumRiders;
    }

    int loadRiders(int numOfRiders)
    {

        // check if ride in progress
        if (rideInProgress)
        {
            return -1;
        }

        if (numOfRiders > capacity)
        {
            currentNumRiders = capacity;
            return numOfRiders - capacity;
        }
        else
        {
            currentNumRiders = numOfRiders;
            return 0;
        }
    }

    int startRide()
    {
        if (rideInProgress)
        {
            return -1;
        }

        if (currentNumRiders != capacity)
        {
            return capacity - currentNumRiders;
        }

        rideInProgress = true;
        return 0;
    }

    void stopRide()
    {
        if (rideInProgress)
        {
            rideInProgress = false;
        }
    }

    void unload()
    {
        if (!rideInProgress)
        {
            currentNumRiders = 0;
        }
    }

    void accelerate()
    {
        this->speed += 3;
    }

    void applyBrake()
    {
        this->speed -= 7;
    }
};

int main()
{
    // Header
    cout << "\n\nStudent ID: 23K0703" << endl;
    cout << "Name: Sarim Ahmed" << endl
         << endl;

    RollerCoaster rollerCoaster1;
    RollerCoaster rollerCoaster2("Sarim's Roller Coaster", 100, 1000, 6);

    // Printing rollerCoaster1's data
    cout << "rollerCoaster1's Name: " << rollerCoaster1.getName() << endl;
    cout << "rollerCoaster1's Current Seated: " << rollerCoaster1.getCurrentlySeated() << endl;
    cout << "rollerCoaster1's Speed: " << rollerCoaster1.getSpeed() << endl;
    cout << "rollerCoaster1's Capacity: " << rollerCoaster1.getCapacity() << endl;
    cout << "rollerCoaster1's Height: " << rollerCoaster1.getHeight() << endl;
    cout << "rollerCoaster1's Length: " << rollerCoaster1.getLength() << endl;
    cout << "rollerCoaster1's Progress Status: " << rollerCoaster1.getProgressStatus() << endl
         << endl
         << endl;

    // Printing rollerCoaster2's data
    cout << "rollerCoaster2's Name: " << rollerCoaster2.getName() << endl;
    cout << "rollerCoaster2's Current Seated: " << rollerCoaster2.getCurrentlySeated() << endl;
    cout << "rollerCoaster2's Speed: " << rollerCoaster2.getSpeed() << endl;
    cout << "rollerCoaster2's Capacity: " << rollerCoaster2.getCapacity() << endl;
    cout << "rollerCoaster2's Height: " << rollerCoaster2.getHeight() << endl;
    cout << "rollerCoaster2's Length: " << rollerCoaster2.getLength() << endl;
    cout << "rollerCoaster2's Progress Status: " << rollerCoaster2.getProgressStatus() << endl
         << endl
         << endl;

    rollerCoaster2.setHeight(1200.0);
    rollerCoaster2.setLength(120.0);
    rollerCoaster2.setName("Not Sarim's Roller Coaster");

    cout << rollerCoaster2.loadRiders(7) << endl;
    rollerCoaster2.startRide();

    rollerCoaster2.accelerate();
    rollerCoaster2.accelerate();
    rollerCoaster2.accelerate();
    rollerCoaster2.accelerate();

    // Printing rollerCoaster2's data
    cout << "rollerCoaster2's Name: " << rollerCoaster2.getName() << endl;
    cout << "rollerCoaster2's Current Seated: " << rollerCoaster2.getCurrentlySeated() << endl;
    cout << "rollerCoaster2's Speed: " << rollerCoaster2.getSpeed() << endl;
    cout << "rollerCoaster2's Capacity: " << rollerCoaster2.getCapacity() << endl;
    cout << "rollerCoaster2's Height: " << rollerCoaster2.getHeight() << endl;
    cout << "rollerCoaster2's Length: " << rollerCoaster2.getLength() << endl;
    cout << "rollerCoaster2's Progress Status: " << rollerCoaster2.getProgressStatus() << endl
         << endl
         << endl;

    rollerCoaster2.applyBrake();

    // Printing rollerCoaster2's data
    cout << "rollerCoaster2's Name: " << rollerCoaster2.getName() << endl;
    cout << "rollerCoaster2's Current Seated: " << rollerCoaster2.getCurrentlySeated() << endl;
    cout << "rollerCoaster2's Speed: " << rollerCoaster2.getSpeed() << endl;
    cout << "rollerCoaster2's Capacity: " << rollerCoaster2.getCapacity() << endl;
    cout << "rollerCoaster2's Height: " << rollerCoaster2.getHeight() << endl;
    cout << "rollerCoaster2's Length: " << rollerCoaster2.getLength() << endl;
    cout << "rollerCoaster2's Progress Status: " << rollerCoaster2.getProgressStatus() << endl
         << endl
         << endl;
}