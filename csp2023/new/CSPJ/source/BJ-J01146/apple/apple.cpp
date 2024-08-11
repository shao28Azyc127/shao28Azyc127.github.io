#include<bits/stdc++.h>
using namespace std;
int x;
bool vis[100010];
int main(){
		freopen("apple.in","r",stdin);
		freopen("apple.out","w",stdout);
		cin>>x;
		int cnt=x;
		int c=0;
		int a=0;
		int t=0;
		while(cnt>0){
				a++;
				c=2;
				for(int i=1;i<=x;i++){
						if(!vis[i]) c++;
						if(c%3==0&&!vis[i]){
								vis[i]=1;
								cnt--;
								if(i==x)   t=a;
							}
					}
			}
		cout<<a<<" "<<t;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
