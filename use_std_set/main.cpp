#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> readvector(){
    int i = 0;
    vector<int> nw;

    while (cin >> i )
    {
        if (i == 0)break;
        nw.push_back(i);
    }

    return nw;
}

void printvector( vector<int> v ){
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << "\n";
}

int getvalue( vector<int> v ){
    int value = 0;
    int size = v.size();

    for (int i = 0; i < size; i++) {
        value += (size - i) * v.at(i);
    }

    return value;
}

struct mycmp{
    bool operator ()(const vector<int>& l, const vector<int>& r) const{
        return l < r;
    }
};


int main()
{
    string cmd;
    set<vector<int>,mycmp> s;

    while( cin >> cmd ){
        if( cmd == "insert" ){
            vector<int> nw;
            nw = readvector();

            set<vector<int>, mycmp>::iterator it;

            for (it = s.begin(); it != s.end(); it++) {

                vector<int> cur = *it;

                if( getvalue(nw) == getvalue(cur) ){
                    cout<<"exist"<<endl;
            		s.erase(cur);
            		reverse(nw.begin(),nw.end());
            		break;
                }
            }
        }
        else if( cmd == "range_out" ){
            int from = getvalue(readVector());
            int to = getvalue(readVector());

            set<vector<int>, mycmp>::iterator it;
            for (it = s.begin(); it != s.end(); it++) {
                vector<int> cur = *it;
                int key = getvalue(cur);
                if ((key >= from) && (key <= to))
                    printvector(cur);
                else if (key > to)
                    break;
            }
        }
        else if( cmd == "output" ){
            set<vector<int>, mycmp>::iterator it;
            for (it = s.begin(); it != s.end(); it++) {
                vector<int> cur = *it;
                printvector(cur);
            }
               
        }
    }
    return 0;
}
