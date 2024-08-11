#include<bits/stdc++.h>
using namespace std;
int n,t,tn,b,f=-1;
map <int,string> mp;
map <string,int> m;
string s,ts,zs,ms;
int neicun[10000005];
int zhuan(string ss){
    if(ss=="byte"){
        return 1;
    }
    else if(ss=="short"){
        return 2;
    }
    else if(ss=="int"){
        return 4;
    }
    else if(ss=="long"){
        return 8;
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    mp[0]="ERR";
    for(int i=1;i<=n;i++){
        cin >> t;
        if(t==1){
            /*cin >> s >> tn;
            for(int i=1;i<=n;i++){
                cin >> ts >> ;
                zs+=zhuan()
            }
            mp[s]=-1;*/
        }
        else if(t==2){
            cin >> ts >> ms;
            ++b;
            m[ms]=b;
            mp[b]=ms;
            f+=zhuan(ts)-f%zhuan(ts);
            cout << f << endl;
            for(int i=1;i<=zhuan(ts);f++,i++){
                neicun[f]=b;
            }
        }
        else if(t==3){
            cin >> ms;
            int mu=m[ms],l=0,r=f,ans=0;
            while(l<=r){
                int mid=l+r>>1;
                while(neicun[mid]==0){
                    mid--;
                }
                if(neicun[mid]>=mu){
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            cout << ans << endl;
        }
        else if(t==4){
            cin >> t;
            cout << mp[neicun[t]] << endl;
        }
    }
    return 0;
}

