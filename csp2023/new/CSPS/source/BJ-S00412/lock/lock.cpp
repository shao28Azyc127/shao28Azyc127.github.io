#include <iostream>
#include<map>
#include<set>
#include<cstring>
using namespace std;
set<string> a;
map<string,int> mp;
int ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,l;
    string c;
    string s,e;
    cin>>n;
    for (int i=1;i<=n;i++){
        s=' ';
        for (int j=1;j<=5;j++){
            cin>>c;
            s+=c;
        }
        l=s.size();
        a.clear();
        for (int j=1;j<=2;j++){
            for (int k=1;k+j-1<l;k++){
                for (int h=-9;h<=9;h++){
                    e=s;
                    if (h==0)
						continue;
                    e[k]=((e[k]-'0'+h)%10+10)%10+'0';
                    if (j==2)
                        e[k+1]=((e[k+1]-'0'+h)%10+10)%10+'0';
                    if (e!=s)
						a.insert(e);
                }
            }
        }
        for (auto i:a){
            mp[i]++;
        }
    }
    for (auto it:mp){
        if (it.second==n){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
