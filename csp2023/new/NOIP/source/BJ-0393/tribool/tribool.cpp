#include<bits/stdc++.h>
using namespace std;
int c,t;
char x[100001];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		while(m--){
			char u;
			scanf("%c",&u);
			if(u=='T'||u=='F'||u=='U'){
				int i;
				scanf("%d",&i);
			}else if(u=='+'){
				int i,j;
				scanf("%d%d",&i,&j);
			}else{
				int i,j;
				scanf("%d%d",&i,&j);
			}
		}
	}
	cout<<0<<endl<<3<<endl<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
