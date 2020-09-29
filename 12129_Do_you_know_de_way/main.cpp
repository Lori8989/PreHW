#include <iostream>

using namespace std;

int main()
{
    int l, r;//, ans = 2000000000, x, y;
    cin>>l>>r;
/*
    for( int redge = r;;){
        int ledge = l;
        for(; ledge < redge ; ledge++ ){
            if( redge % ledge == 0 ){
                //cout<<"can :"<<ledge<<", "<<redge<<endl;
                if(redge + ledge < ans){
                    ans = redge + ledge;
                    x = ledge;
                    y = redge;
                }

            }
        }
        redge--;
        if( redge < 2*l )
            break;
    }
*/
    cout<<l<<" "<<2*l<<endl;

    return 0;
}

/*
a * 2  -- a*3
(a+1) * 3 -- 4*(a+1)

*/
