#include <string>
#include <iostream>
using namespace std;

class Animal{
    public:
        Animal(string name) : Name(name){}
        virtual void MakeSound() = 0 ;

    private:     string Name;
};
class Dog : public Animal{
    Dog(string name): Animal(name) {}
    void MakeSound(){
        cout << "bow-wow" << endl;
    }
};

class Cat : public Animal{
    Cat(string name): Animal(name) {}
    void MakeSound(){
        cout << "meow" << endl;
    }
};

int main(){
    Cat kitty( "kitty" );
    Dog doggy( "doggy" );
    kitty.MakeSound();
    doggy.MakeSound();
    return 0;
}
