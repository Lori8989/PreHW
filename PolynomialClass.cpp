#include <iostream>
#include "function.h"
using namespace std;

Polynomial::Polynomial(){}

Polynomial::Polynomial(const int n, const int co[51]){
    for( int i=n ; i>0 ; i-- )
        this->coefficients[i] = co[i];
    this->greatestPower = n;

}
Polynomial Polynomial::add( Polynomial next)const{
    Polynomial tmp = *this;
    int gp1, gp2, bg;
    gp1 = tmp.greatestPower;
    gp2 = next.greatestPower;

    bg = gp1>gp2 ? gp1:gp2;
    tmp.greatestPower = bg;
    for( int i=bg ; i>=0 ; i-- ){
        if( i == gp2 )
            tmp.coefficients[i]+=next.coefficients[i], gp2--;
    }
    return tmp;
}

Polynomial Polynomial::subtract(const Polynomial next)const{
    int gp1, gp2, bg;
    Polynomial tmp = *this;
    gp1 = tmp.greatestPower;
    gp2 = next.greatestPower;
    bg = gp1>gp2 ? gp1:gp2;
    tmp.greatestPower = bg;

    for( int i=bg ; i>=0 ; i-- ){
        if(i == gp2)tmp.coefficients[i]-=next.coefficients[i], gp2--;
    }
    return tmp;
}

Polynomial Polynomial::multiplication(const Polynomial next)const{
    int gp1, gp2, bg, i, j;
    Polynomial tmp = *this;
    gp1 = tmp.greatestPower;
    gp2 = next.greatestPower;
    bg = gp1+gp2;
    tmp.greatestPower = bg;
    int cos[110] = {0};

    for( i=0 ; i<=gp1; i++ ){
        for( j=0 ; j<=gp2 ; j++ ){
            cos[i+j] += tmp.coefficients[i]*next.coefficients[j];
        }
    }
    for( i=0 ; i<=bg ; i++ )
        tmp.coefficients[i] = cos[i];
        
    return tmp;
}

void Polynomial::output()const{
    int i = this->greatestPower;
    for(;i>0;i--)
        cout<<this->coefficients[i]<<" ";
    cout<<this->coefficients[0];

}