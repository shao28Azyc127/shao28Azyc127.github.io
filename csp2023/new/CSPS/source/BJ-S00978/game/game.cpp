#include<bits/stdc++.h>
using namespace std;

int n,b=0,ans=0,ans1=0,yy=1,sl1=0;
char a[200005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	for(int j=1;;j++){
	    for(int i=1;i<=n;i++) {
			if(a[i]=='1'){
				yy=3;
				continue;
			}
		    if(b==0){
			    b++;
		    }else{
		        if(a[i]==a[i-yy]){
				    b=0;
				    ans++;
				    if(a[i-1]!='1'&&a[i-2]=='1'){
						ans++;
					}
					/*else if(a[i-2]=='1'){
						ans++;
					}
					if(a[i+1]=='1'){
						ans++;
					}*/
			
				    a[i]='1';
				    a[i-1]='1';
				    sl1+=2;
				    yy=1;
			    }else{
					yy=1;
				}
		    }
	    }
	    if(sl1==n){
			ans++;
		    break;
		}
			
	    if(ans==ans1){
			break;
		}
		else{
			ans1=ans;
		}
    }
    cout<<ans;
	return 0;
}
