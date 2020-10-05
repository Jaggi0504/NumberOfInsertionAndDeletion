#include<bits/stdc++.h>
using namespace std;

void output(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	int dp[m+1][n+1];
	for(int j=0;j<=n;j++) {
		dp[0][j] = 0;
	}
	for(int i=0;i<=m;i++) {
		dp[i][0] = 0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout<<"Number of deletions required are: "<<m-dp[m][n]<<endl;
	cout<<"Number of insertions required are: "<<n-dp[m][n]<<endl;
}

int main() {
	string s1, s2;
	cout<<"Enter string 1: "<<endl;
	cin>>s1;
	cout<<endl;
	cout<<"Enter string 2: "<<endl;
	cin>>s2;
	cout<<endl;
	output(s1, s2);
	return 0;
}
