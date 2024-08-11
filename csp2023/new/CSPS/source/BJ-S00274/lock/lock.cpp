#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
int a[10][10];
map<string,int> m;
string s[10];
int main(){
    
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            int x;
            cin>>x;
            s[i]+=(x+'0');
            s[i]+=' ';
        }
        //cout<<s[i]<<' ';
        for(int j=0;j<=8;j+=2){
            for(int k=1;k<=9;k++){
                string t=s[i];
                int num=(t[j]-'0');
                num+=k;
                num%=10;
                t[j]=num+'0';
                m[t]++;
                //cout<<t<<endl;
                if(m[t]==n){
                    //cout<<t<<endl;
                    ans++;
                }
            }
        }
          for(int j=0;j<=6;j+=2){
            for(int k=1;k<=9;k++){
                string t=s[i];
                int n1=(t[j]-'0');
                int n2=(t[j+2]-'0');
                n1+=k;
                n2+=k;
                n1%=10;
                n2%=10;
                t[j]=n1+'0';
                t[j+2]=n2+'0';
                m[t]++;
                //cout<<t<<endl;
                if(m[t]==n){
                    //cout<<t<<endl;
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
