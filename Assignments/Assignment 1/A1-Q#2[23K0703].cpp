#include <iostream>
#include <cmath>

using namespace std;

class Table
{
    int totalSeats;
    int occupiedSeats;
    int freeSeats;
    bool clean;

public:
    Table()
    {
        totalSeats = 4;
        occupiedSeats = 0;
        freeSeats = totalSeats - occupiedSeats;
        clean = true;
    }

    Table(int totalSeats)
    {
        // Setting total seats to either 4 or 8
        float x = (float)totalSeats / 4;
        int y = (int)round(x);
        this->totalSeats = y * 4;

        if (this->totalSeats > 8)
        {
            this->totalSeats = 8;
        }
        else if (this->totalSeats < 4)
        {
            this->totalSeats = 4;
        }

        // Setting other paramenters accordingly
        occupiedSeats = 0;
        freeSeats = this->totalSeats - occupiedSeats;
        clean = true;
    }

    int getFreeSeats()
    {
        return this->freeSeats;
    }

    void setOccupiedSeats(int newOccupiedSeats)
    {
        this->occupiedSeats = newOccupiedSeats;
        this->freeSeats = this->totalSeats - this->occupiedSeats;
    }

    int getTotalSeats()
    {
        return this->totalSeats;
    }

    bool getCleanStatus()
    {
        return clean;
    }

    void HaveLunch()
    {
        clean = false;
    }

    void CleanTable()
    {
        clean = true;
    }
};

void EmptyTable(int index, Table tableArray[])
{
    tableArray[index].setOccupiedSeats(0);
    cout << "\n[+] Emptied Table#" << index << ".";
}

int OccupyTable(int numOfFriends, Table tableArray[], int totalTables)
{
    // Checking for a suitable table
    for (int i = 0; i < totalTables; i++)
    {
        if (tableArray[i].getFreeSeats() >= numOfFriends)
        {
            if (tableArray[i].getCleanStatus())
            {

                // Occupy the table

                tableArray[i].setOccupiedSeats(numOfFriends);
                cout << "\n[+] Table#" << i << " assigned with " << tableArray[i].getTotalSeats() << " seats.";

                return i;
            }
        }
    }

    cout << "\n[+] No free table to assign.";
    return -1;
}

int main()
{
    cout << "\n\nStudent ID: 23K0703" << endl;
    cout << "Name: Sarim Ahmed" << endl
         << endl;

    Table tableList[5] = {
        Table(4),
        Table(4),
        Table(4),
        Table(8),
        Table(8),
    };

    int table1Index = OccupyTable(4, tableList, 5);
    int table2Index = OccupyTable(6, tableList, 5);

    // Having Lunch
    tableList[table1Index].HaveLunch();

    // Leaving the table
    EmptyTable(table1Index, tableList);

    // Clean the table
    tableList[table1Index].CleanTable();

    EmptyTable(table2Index, tableList);
}