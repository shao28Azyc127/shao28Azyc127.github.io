#include<bits/stdc++.h>
using namespace std;
int k,l,r,s=0;
string a;
int main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
cin>>k>>a;
for(int i=0;i<k;i++){
    for(int j=1;j<=k-i;j++){
        string a1=a.substr(i,j);
        int size=a1.size();
        for(int q=1;q<size;q++){
        	if(a1[q]==a1[q-1]){
        		if(size!=q+1)for(int l=q+1;l<size;l++)a1[l-2]=a1[l];
				size-=2;
				q=0;
           	}
  		}
  		if(!size)s++;
    }
}
cout<<s;
return 0;
}
