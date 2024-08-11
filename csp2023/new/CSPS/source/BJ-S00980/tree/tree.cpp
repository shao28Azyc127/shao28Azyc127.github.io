#include<bits/stdc++.h>
using namespace std;
int n=0;
struct block{
	long long a=0;
	int b=0;
	int c=0;
	int h=0;
	bool vis=0;
}bk[100003];
struct bian{
	int s=0,e=0;
}bsz[100003];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> bk[i].a >> bk[i].b >> bk[i].c;
	}
	for(int i=0;i<n-1;i++){
		cin >> bsz[i].s >> bsz[i].e;
	}
	int day=0;
	while(1){
		day++;
		for(int i=0;i<day;i++){
			bk[i].h+=(max(bk[i].b+day*bk[i].c,1));
		}
		bool flag=1;
		for(int i=0;i<n;i++){
			if(bk[i].h<bk[i].a){
				flag=0;
			}
		}
		if(flag==1){
			cout << day+1;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
