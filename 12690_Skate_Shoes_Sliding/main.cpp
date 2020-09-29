#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l = 0, r = 0;

    cin>>n;
    while( n-- ){
        char c;
        cin>>c;
        if( c == 'L' )
            l++;
        else
            r++;
    }

    cout<<l+r+1<<endl;


    return 0;
}
