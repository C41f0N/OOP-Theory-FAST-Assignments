#include <iostream>
#include <cmath>

using namespace std;

class Drone
{
protected:
    float latitude, longitude, altitude, speed;

public:
    Drone(
        float latitude,
        float longitude,
        float altitude,
        float speed)
        : latitude(latitude),
          longitude(longitude),
          altitude(altitude),
          speed(speed) {}

    virtual void adjustAltitude(float altitude)
    {
        this->altitude = altitude;
    }

    virtual void setSpeed(float speed)
    {
        this->speed = speed;
    }
};

class FlyableDrone : virtual public Drone
{
public:
    FlyableDrone(
        float latitude,
        float longitude,
        float altitude,
        float speed)
        : Drone(
              latitude,
              longitude,
              altitude,
              speed)
    {
    }
    virtual void takeoff()
    {
        altitude += 50;
    }

    virtual void land()
    {
        altitude = 0;
    }

    virtual void navigateTo(float latitude, float longitude, float altitude)
    {
        this->latitude = latitude;
        this->longitude = longitude;
        this->altitude = altitude;
    }
};

class ScannableDrone : virtual public Drone
{
public:
    ScannableDrone(
        float latitude,
        float longitude,
        float altitude,
        float speed)
        : Drone(
              latitude,
              longitude,
              altitude,
              speed)
    {
    }

    virtual void scanArea(int radius)
    {
        cout << "Scanning everything in " << radius << "km radius." << endl;
    }
};

class ReconDrone : public FlyableDrone, public ScannableDrone
{
    int cameraResolution;
    float maxFlightTime;

public:
    ReconDrone(
        float latitude,
        float longitude,
        float altitude,
        float speed)
        : FlyableDrone(
              latitude,
              longitude,
              altitude,
              speed),
          ScannableDrone(
              latitude,
              longitude,
              altitude,
              speed),
          Drone(
              latitude,
              longitude,
              altitude,
              speed)
    {
    }

    void navigateTo(float latitude, float longitude, float altitude) override
    {

        float horizDistance = pow(pow(longitude - this->longitude, 2) + pow(latitude - this->latitude, 2), 0.5);
        float verticalDistance = this->altitude - altitude;
        float directDistance = pow(pow(verticalDistance, 2) + pow(horizDistance, 2), 0.5);

        float estimatedTime = (float)(directDistance / speed);

        cout << "Estimated time to reach (" << latitude << ", " << longitude << ", " << altitude << ") is " << estimatedTime << " seconds." << endl;

        FlyableDrone::navigateTo(latitude, longitude, altitude);
    }

    void scanArea(int radius) override
    {
        try
        {
            if (radius <= 50)
            {
                ScannableDrone::scanArea(radius);

                // Rnadom objects being detected
                cout << "Bird detected at (13.222, 23.225, 2.99)" << endl;
                cout << "Car detected at (14.242, 32.2222, 2.99)" << endl;
                cout << "Human detected at (11.522, 82.2522, 2.99)" << endl;
            }
            else
            {
                throw radius;
            }
        }
        catch (int e)
        {
            cout << "Requested radius is out of range" << endl;
        }
    }
};

int main()
{
    // Header
    cout << "Name: Sarim Ahmed\nRoll Number: 23K0703\n\n";

    ReconDrone drone1(0, 0, 0, 50);

    drone1.takeoff();
    drone1.navigateTo(101, 102, 103);

    drone1.scanArea(101);
    drone1.scanArea(25);
}