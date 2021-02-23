#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >>n;
	int spaces = n - 1;
	for(int i = 1;i<=n;i++){
		for(int sp = 0;sp < spaces;sp++)	cout <<' ';
		for(int j = 1;j<=i;j++)	cout <<j;
		for(int j = i - 1;j>=1;j--)	cout <<j;
		spaces--;
		cout <<'\n';
	}
	spaces = 1;
	n -= 1;
	for(int i = n;i>=1;i--){
		for(int sp = 0;sp<spaces;sp++)	cout <<" ";
		for(int j = 1;j<=i;j++)	cout <<j;
		for(int j = i - 1;j>=1;j--)	cout <<j;
		spaces++;
		cout <<'\n';
	}
	return 0;
}