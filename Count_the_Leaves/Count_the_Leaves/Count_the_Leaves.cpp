#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, par, cld;
    set<int> all;
    set<int> parent;
    while (cin >> n) {
        if (n == 0)break;
        all.clear();
        parent.clear();
        int i = 0;
        for (i = 0; i < n; i++) {
            cin >> par >> cld;

            //auto test = parent.find(par);
            //if (test == parent.end())//not exist
                parent.insert(par);

            //test = all.find(par);
            //if (test == all.end())
                all.insert(par);

            //test = all.find(cld);
            //if (test == all.end())
                all.insert(cld);
        }
        cin >> n;//the root

        cout << all.size() - parent.size() << endl;
    }
    return 0;
}
/*
There are multiple test cases. 
Each test case begins with an integer N (1 <= N <=1000).
In the following N lines, 
each line has two integer a and b (1 <= a,b <= 1000), 
indicating node a is node b’s parent. 
The next line contains an integer R, 
which represents the root of the Tree. You can assume that 
all the nodes will be on the same tree. 
The input is terminated by N = 0.
*/