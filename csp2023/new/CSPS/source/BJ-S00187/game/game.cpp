#include<bits/stdc++.h>
using namespace std;
int n;
char a[100005];
bool huiwen(int a1,int b1){
	if((b1-a1+1)%2==1) return false;
	else{
	    for(int i=a1,j=b1;i<=b1;i++,j--){
		    if(a[i]!=a[j]){
			    return false;
		    }
	    } 
	}
	return true;
}
bool check(int a2,int b2){
	if(huiwen(a2,b2)) return true;
	else if((b2-a2+1)%2==1) return false;
	else{
		if(b2-a2==1) return false;
		else{
		bool falg=false;
		for(int i=a2;i<=b2;i++){
			if(huiwen(a2,i)){
				falg=true;
				return check(i+1,b2);
			}
		}
		if(falg==false) return false;
	    }
	}
} 
bool check2(int a3,int b3)
{
	if((b3-a3+1)%2==1) return false;
	if(check(a3,b3)) return true;
	else{
		for(int i=a3,j=b3;i<=b3;i++,j--){
		    if(a[i]!=a[j]){
			    if(check(i,j)) return true;
			    else{
					if(a3+1==b3&&a[a3]!=a[b3]) return false;
					if(a3+1==b3&&a[a3]==a[b3]) return true;
					for(int j=a3+1;j<=b3;j+=2){
						if(check(a3,j)) return check2(j+1,b3);
						else return check(a3,j)&&check(j+1,b3);
					}
				}
		    }
	    } 
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>a+1;
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check3(i,j)){
				sum++;
				for(int k=i;k<=j;k++) cout<<a[k];
				cout<<endl;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
