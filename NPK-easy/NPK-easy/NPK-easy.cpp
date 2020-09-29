#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

queue<int> countryLine[3];
list<int> countryPos;

int main()
{
    int n, num;
    cin >> n;//n commands
    string cmd;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "DEQUEUE") {
            int idx = countryPos.front();//the first country
            cout << countryLine[idx].front() << endl;//print out
            countryLine[idx].pop();//he goes away
            if (countryLine[idx].empty())
                countryPos.pop_front();
        }
        else {
            cin >> num;
            int idx = num % 3;
            countryLine[idx].push(num);//into his country line
            
            if (find(countryPos.begin(), countryPos.end(), idx) == countryPos.end())//find if his country has in
                countryPos.push_back(idx);//if no, push to the list
        }
    }
    
    return 0;
}
