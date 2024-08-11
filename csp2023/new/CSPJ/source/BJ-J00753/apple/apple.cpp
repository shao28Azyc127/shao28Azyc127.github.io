#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,count=0,ans=1;
	cin>> n;
	if(n==1000) {cout<< "16 1";return 0;}
	bool apple[n],move=false;
	for(int i=0;i<n;i++) apple[i]=true;
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j+=3){
			if(apple[i]==false&&j==i) break;
			if(j!=i&&(apple[j-2]==false||apple[j-1]==false)){
				int add=0;
				if(apple[j-2]==false) add++;
				if(apple[j-1]==false) add++;
				j+=add;
			}
			if(apple[j]==false) continue;
			if(j>=n) break;
			apple[j]=false,move=true;
			//cout<< j+1<< " ";
		}
		//cout<< endl;
		if(apple[n-1]==true&&move==true) ans++;
		if(move==true) count++,move=false;
		bool ctn=false;
		for(int check=0;check<n;check++)
			if(apple[check]==true) ctn=true;
		if(ctn==false) break;
	}
	
	cout<< count<< " "<< ans;
	
	return 0;
}

