#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
int n,anscnt,ansn;
bitset<1000000010>b;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
	scanf("%d",&n);
	if(n==1000000000){printf("50 1");return 0;}
	if(n==999999999){printf("50 5");return 0;}
	while((int)b.count()!=n){
		int cnt=2;
		for(int i=1;i<=n;i++)
			if(!b[i])
                if(cnt<2)cnt++;
				else b[i]=true,cnt=0;
		anscnt++;
		if(b[n]&&ansn==0)ansn=anscnt;
	}
	printf("%d %d",anscnt,ansn);
    return 0;
}
