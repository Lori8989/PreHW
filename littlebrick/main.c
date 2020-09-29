#include <stdio.h>

int gcd(int a,int b) {
	int i;
	if(a>b){
        for(i=a;i>0;i--){
        if(a%i==0&&b%i==0)
            break;
	}
	}
	else{
        for(i=b;i>0;i--){
        if(a%i==0&&b%i==0)
            break;
	}
	}

	return i;
}

int lcm(int a, int b) {
	return a*b/gcd(a,b);
}

int power(int a, int b) {
	return pow(a,b);
}
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n",gcd(lcm(power(a,b),c),d));
	printf("%d\n",gcd(power(lcm(a,b),c),d));
	printf("%d\n",lcm(gcd(power(a,b),c),d));
	printf("%d\n",lcm(power(gcd(a,b),c),d));
	printf("%d\n",power(gcd(lcm(a,b),c),d));
	printf("%d\n",power(lcm(gcd(a,b),c),d));

	return 0;
}
