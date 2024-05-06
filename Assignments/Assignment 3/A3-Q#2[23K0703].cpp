#include <iostream>

using namespace std;

template <class T>
class Pet
{
public:
    string name;
    int age;

    Pet(
        string name,
        int age)
        : name(name),
          age(age) {}

    void virtual makeSound() = 0;
};

class Cat : public Pet<Cat>
{
public:
    Cat(
        string name,
        int age)
        : Pet(
              name,
              age) {}

    void makeSound()
    {
        cout << "Meow" << endl;
    }
};

class Dog : public Pet<Dog>
{
public:
    Dog(
        string name,
        int age)
        : Pet(
              name,
              age) {}

    void makeSound()
    {
        cout << "Bark" << endl;
    }
};

class Bird : public Pet<Bird>
{
public:
    Bird(
        string name,
        int age)
        : Pet(
              name,
              age) {}

    void makeSound()
    {
        cout << "Chirp" << endl;
    }
};

int main()
{
    // Header
    cout << "Name: Sarim Ahmed\nRoll Number: 23K0703\n\n";

    Cat cat("Nimbo", 1);
    Dog dog("Toto", 5);
    Bird bird("F16", 10);

    cout << "Name: " << cat.name << endl;
    cout << "Age: " << cat.age << endl;
    cat.makeSound();
    cout << endl;

    cout << "Name: " << dog.name << endl;
    cout << "Age: " << dog.age << endl;
    dog.makeSound();
    cout << endl;

    cout << "Name: " << bird.name << endl;
    cout << "Age: " << bird.age << endl;
    bird.makeSound();
    cout << endl;

    return 0;
}