#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >>n;
	int spaces = n -1;
	for(int i = 0;i<n;i++){
		for(int sp = 0;sp<spaces;sp++)	cout <<" ";
		for(int j = 0;j<i + 1;j++){
			cout <<"*";
		}
		spaces--;
		cout <<'\n';
	}
	return 0;
}