#include <iostream>

using namespace std;

class Enemy;
class Player
{
protected:
    int playerID, health;
    string playerName;

public:
    Player(
        int playerID,
        string playerName)
        : playerID(playerID),
          playerName(playerName),
          health(100) {}

    void takeDamage(int damage)
    {
        health -= damage;
    }

    int getHealth()
    {
        return this->health;
    }
};

class Weapon
{
    string weaponsList[5];

public:
    Weapon()
    {
        weaponsList[0] = "Knife";
        weaponsList[1] = "Pistol";
        weaponsList[2] = "AK-47";
        weaponsList[3] = "RPG";
        weaponsList[4] = "Nuke";
    }

    void use()
    {
        int option;

        // Print all weapons
        cout << "==============================\n";
        cout << "     SELECT YOUR WEAPON!\n";
        cout << "==============================\n\n";
        cout << "Option\tName\n";

        for (int i = 0; i < 5; i++)
        {
            cout << "[" << i + 1 << "]\t" << weaponsList[i] << endl;
        }

        // Selecting a weapon
        cout << "\nEnter your option: ";
        cin >> option;

        // Using the weapon
        cout << "[+] Your weapon is " << weaponsList[option - 1] << "!" << endl;
    }
};

class Character : public Player
{
    int level, points;
    string experience;

public:
    Character(
        int playerID,
        string playerName)
        : level(0),
          points(0),
          experience("Beginner"),
          Player(playerID, playerName) {}

    void levelUp()
    {
        if (experience == "Beginner")
        {
            experience = "Intermidiate";
        }
        else if (experience == "Intermidiate")
        {
            experience = "Advanced";
        }
        else if (experience == "Advanced")
        {
            experience = "Expert";
        }
    }

    void playGame(Enemy *enemy);
};

class Enemy : public Player
{
    int damage;

public:
    Enemy(int playerID,
          string playerName,
          int damage)
        : Player(playerID, playerName)
    {
        if (damage > 10)
        {
            this->damage = 10;
        }
        else if (damage < 1)
        {
            this->damage = 1;
        }
        else
        {
            this->damage = damage;
        }
    }

    void attack(Character *character)
    {
        // Select weapon
        Weapon weapons;

        weapons.use();
        character->takeDamage(this->damage);
    }
};
void Character::playGame(Enemy *enemy)
{
    Weapon weapons;

    weapons.use();

    enemy->takeDamage(5);
    this->points += 10;
    levelUp();
}

int main()
{
    Enemy enemy(12345, "Baba Bandook", 10);
    Character character(12342, "Burqa Avenger");

    Enemy *e = &enemy;
    Character *c = &character;

    while (e->getHealth() > 0 && c->getHealth() > 0)
    {
        cout << "Your health is " << c->getHealth() << endl;
        cout << "Enemy's health is " << e->getHealth() << endl;

        c->playGame(e);
        e->attack(c);
    }

    if (e->getHealth() <= 0 && c->getHealth() <= 0)
    {
        cout << "\n\n       THE GAME WAS A DRAW." << endl;
    }
    else if (e->getHealth() <= 0)
    {
        cout << "\n\n       THE CHARACTER WON." << endl;
    }
    else
    {
        cout << "\n\n       GAME OVER." << endl;
    }
}
