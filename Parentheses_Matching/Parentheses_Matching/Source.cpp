#include <iostream>
#include <string>

using namespace std;

bool isLeft(char c) {
	switch (c)
	{
	case '<':
	case '(':
	case '[':
	case '{': return true;

	default:
			return false;
	}

}

bool isMatch(char l, char r) {
//cout << l << " , " << r << endl;
	switch (l)
	{
	case '<': return r == '>';
	case '[': return r == ']';
	case '(': return r == ')';
	case '{': return r == '}';
	default: return false;
	}

	return false;
}



int main() {
	int t;
	string s;
	bool flag;
	char store[1001];
	int top;

	cin >> t;//t cases
	getline(cin, s);//skip empty one

	for (int i = 1; i <= t; i++) {
		top = -1;
		flag = true;
		getline(cin, s);
		for (string::iterator it = s.begin(); it != s.end(); it++) {
			if (isLeft(*it)) {
				store[++top] = *it;//store left in
				//cout << *it << " isLeft\n";
			}
			else if (top > -1 && isMatch(store[top], *it) == true) {
				top--;//abandon the top
				//cout << *it << " isMatch\n";
			}
			else {
				flag = false;//other character
				//cout << *it << " false\n";
				break;
			}
		}//store all match & no other character
		//cout << "previous : " << flag << endl;
		//cout << "top : " << top << endl;
		if (top == -1 && flag == true)flag = true;
		else flag = false;

		cout << "Case " << i << ": ";
		if (flag == true)
			cout << "Yes\n";
		else
			cout << "No\n";
		
	}
	return 0;
}



/*
2
[(<})]
{[()]}()
*/