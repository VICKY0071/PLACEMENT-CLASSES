#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int spaces = 0;
	for(int i = 0;i<n;i++){
		for(int sp = 0;sp < spaces;sp++)	cout <<' ';
		for(int j = 0;j<n - i;j++)	cout <<"* ";
		cout <<'\n';
		spaces++;
	}
	return 0;
}