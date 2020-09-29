
#include <string>
#include <map>
#include <iostream>

using namespace std;


int main() {
    map<string,int> BefAft;// stores(beforei,afteri) pair, in lexicological order of before
    map<string,int> Count;// stores(beforei,Ki) denoting there’re Ki data have label = beforei
    map<int,string> Index;// store(i,beforei), which means beforei is the ith element in table T

    string before;
    int after, idx = 1;

    while (cin >> before) { // input a string until EOF
        if (before == "----------")//stop the part
            break;
        cin >> after;

        pair<string, int> pairBA(before, after);
        pair<string, int> pairCount(before, 0);
        pair<int, string> pairIdx(idx, before);

        BefAft.insert(pairBA);
        Count.insert(pairCount);
        Index.insert(pairIdx);

        idx++;
    };

    string str_x, str_y;
    int numData = 0;
    int numUnlabeled = 0;

    while (cin >> str_x) {
        cin >> str_y;
        numData++;
 //       cout << "cin : " << str_x  << ", " << str_y << endl;

        auto test = BefAft.find(str_y);
        if (test == BefAft.end()) {//not appear
            numUnlabeled++;
            cout << str_x << " unlabeled" << endl;
        }
        else {//has after , count++
            cout << str_x << " " << test->second << endl;
            auto testCount = Count.find(str_y);
            testCount->second++;
        }

    }
 //   cout << "**" << endl;
    cout << endl;
    cout << "total # of data: " << numData << endl;

    map<int,string>::iterator it;
    for (it = Index.begin(); it != Index.end(); it++) {
        string s = it->second;// or (*it).second
        auto test = Count.find(s);

        cout << s << ": " << test->second << endl;
    }

    cout << "unlabeled: " << numUnlabeled << endl;
    return 0;
}
/*
good_sample 1
bad_sample -1
normal_sample 0
----------
A good_sample
C good_sample
B normal_sample
E good_sample
J xxx_sample
K normal_sample

*/
