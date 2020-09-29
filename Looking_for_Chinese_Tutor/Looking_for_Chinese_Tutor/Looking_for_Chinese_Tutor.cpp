#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

map<string, string> theMap = {
    {"Wa","Waninoko"},
    {"Mi","Milotic" },
    {"Ma","Magikarp"},
    {"Va","Vaporeon"},
    {"Sh","Sharpedo"},
    {"Tapu","Tapu Fini"},
    {"Em","Empoleon"},
    {"La","Lapras"},
    {"Pi","Pikachu"},
    {"Pe","Pikachu"},
    {"Me","Mega Gyarados"}
};

/*
Wa	Waninoko
Mi	Milotic
Ma	Magikarp
Va	Vaporeon
Sh	Sharpedo
Tapu	Tapu Fini
Em	Empoleon
La	Lapras
Pi, Pe	Pikachu
Me	Mega Gyarados
*/
int main()
{
    string names, school;
    int n;//n cases
    cin >> n;

   
    while (n--) {
        bool able = false;
        cin >> names >> school;
        for (auto& p : theMap) {
            if (names.substr(0, p.first.size()) == p.first) {
                able = true;
                cout << names << " the " << school << " " << p.second << "\n";
                break;
            }
        }

        if(able == false)
            cout << names << " is looking for a Chinese tutor, too!\n";
    }
    return 0;
}
