#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,ans=0,t=0,x,y;
	queue<int> a;
	cin>>n;
	x=n;
	y=n;
	bool flag=false;
	for(int i=1;i<=n;i++)a.push(i);
	while(!a.empty()){
        ans++;
        if(!flag)t++;
        for(int i=1;i<=x;i++){
            if(i%3==1){
                if(a.front()==n)flag=true;
                a.pop();
                y--;
            }
            else{
                a.push(a.front());
                a.pop();
            }
        }
        x=y;
	}
	cout<<ans<<" "<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
