#include<bits/stdc++.h>
using namespace std;
string s;
int n;//i-j de zi chuan shi fou ke yi xiao chu
bool pd(string c){
	int nn=c.size()-1;
	for(int i=0;i<nn;++i)if(c[i]==c[i+1]){
		if(nn==1)return 1;
		return pd(c.substr(0,i)+c.substr(i+2,n-(i+2)+1));
	}
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,j,ans=0;
	cin>>n;
	cin>>s;
	for(i=0;i<=n;++i)for(j=i;j<=n;++j){
		if((j-i+1)%2==0){
			if(pd(s.substr(i,j-i+1)))ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int a[805][805],n;
string s;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,j,k,ans=0;
	cin>>n;
	cin>>s;
	for(i=2;i<=n;i+=2){//chang du
		for(j=0;j<=n-i+1;++j){//qi dian
			if(i==2){
				if(s[j]==s[j+1]){
					a[j][j+1]=1;
					ans++;
				}
			}
			else{
				int z=j+i-1;
				for(k=j;k<z;++k){
					if(s[k]==s[k+1]){
						if(a[j][z]==0){
							if(k==j)a[j][z]=a[k+2][z];
							else if(k==z-1)a[j][z]=a[j][z-2];
							else if(i==4)a[j][z]=(s[k-1]==s[k+2]);
							else if(k==j+1)a[j][z]=(s[k-1]==s[k+2])&a[k+3][z];
							else if(k==z-2)a[j][z]=(s[k-1]==s[k+2])&a[j][k-1];
							else a[j][z]=(a[j][k-1]&&a[k+2][z])|(a[j][k-2]&(s[k-1]==s[k+2])&a[k+3][z]);
							if(a[j][z]==1)ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}*/
