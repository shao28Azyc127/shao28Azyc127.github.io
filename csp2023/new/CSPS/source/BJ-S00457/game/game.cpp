#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e6+1;
string s;
int f[N];
long long ans=0,m=1,n,g,i,j,l=0;
void sou(int x,int y){
        g=y;
        if(x<0){
                return ;
        }
        else if(y>n-1){
                if(f[x-1]==true){
                        if(s[x]==s[x-1]){
                                for(int j=x-2;j>=0;j-=2){
                                        if(s[j]==s[j-1]){
                                                ans++;
                                        }
                                        else{
                                                break;
                                        }
                                }
                        }
                        ans++;
                }
        }
        else if(s[x]!=s[y]){
                if(f[x-1]==true){
                       if(s[x]==s[x-1]){
                                for(int j=x-2;j>=0;j-=2){
                                        if(s[j]==s[j-1]){
                                                ans++;
                                        }
                                        else{
                                                break;
                                        }
                                }
                        }
                        ans++;
		}
                return;
        }
        else{
                if(s[x]==s[x+1]){
                        ans+=2;
                }
                ans++;
                f[x]=true;
                f[y]=true;
                sou(x-1,y+1);
        }

}
int main(){
        freopen("game.in","r",stdin);
        freopen("game.out","w",stdout);
        cin >>n>>s;
        for(int i=0;i<n;i++){
                l=0;
                if(s[i]==s[i+1]){
                        f[i]=true;
                        f[i+1]=true;
                        for(int j=i+2;j<n;j+=2){
				if(s[j]==s[j+1]){
			        m++;
                                f[j]=true;
                                f[j+1]=true;
                        }
                                else{
                                        break;
                                }
			        l+=2;
			}
			i+=l;
			for(int j=1;j<m;j++){
			        ans+=j;
			}
                }
                m=1;
        }
        for(int i=0;i<n;i++){
                //cout<<i<<" "<<ans<<endl;                                      
                if(s[i]==s[i+1]){
			f[i]=true;
			f[i+1]=true;
			ans++;
			sou(i-1,i+2);
			i=g-1;
                }
                //cout<<i<<" "<<ans<<endl;                                      
        }
        cout<<ans;
        return 0;
}
