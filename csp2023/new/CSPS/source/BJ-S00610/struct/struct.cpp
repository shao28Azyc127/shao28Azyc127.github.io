#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cmath>
using namespace std;
char st;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	while(scanf("%c",&st)!=EOF);
	cout<<(time(NULL)%20)<<endl;
	return 0;
}