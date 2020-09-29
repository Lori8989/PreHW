#include "function.h"
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


void RleCodec::encode()//->3A
{
    int cnt=0;
    char prev='\0';
    std::stringstream ss;
    for( auto c : code_str ){
        if( c != prev ){//current is a new letter
            if( cnt>0 ){
                if( cnt==1 )
                    ss << prev;
                else if( cnt==2 )
                    ss << prev << prev;
                else
                    ss << cnt << prev;

            }
            cnt = 1;//it's c
            prev = c;
        }
        else{
            cnt++;//first case or current same with previous
        }

    }
    if( cnt>0 ){//the last continous
        if( cnt == 1 )
            ss << prev;
        else if( cnt == 2)
                 ss << prev << prev;
        else
            ss << cnt << prev;

        cnt++;//but they don't have this line??
     }
    code_str = ss.str();
    encoded = true;
}

void RleCodec::decode()//->AAA
{
    std::stringstream os;
    std::string int_str;

    for( auto c : code_str ){
        if( std::isdigit(c) ){
            int_str.push_back(c);
        }
        else{
            int cnt = 0;
            std::stringstream is{int_str};//number will in
            is >> cnt;//but if nothing in, do nothing

            if( cnt==0 ){//no number
                os << c;
            }
            else{
                for( int i=0 ; i<cnt ; i++ )
                    os << c;
            }

            int_str.clear();
        }
    }
    code_str = os.str();
    encoded = false;
}
