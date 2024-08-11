#include <bits/stdc++.h>
using namespace std;
struct node{
    string type;
    string name;
};
node s[105];
int sum[105];
string s1;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int dis=1;
    int j=1;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==2){
            cin>>s[j].type>>s[j].name;
            cout<<sum[dis]<<"\n";
            if(s[j].type=="short")sum[dis]=sum[dis-1]+1;
            if(s[j].type=="int")sum[dis]=sum[dis-1]+3;
            if(s[j].type=="long")sum[dis]=sum[dis-1]+7;
            dis++;
            j++;
        }
        else if(op==3){
            cin>>s1;
            for(int k=1;k<j;k++){
                if(s1==s[k].name){
                    if(s[k].type=="long")
                        cout<<sum[k]-sum[k-1]+1-8<<"\n";
                    if(s[k].type=="int")
                        cout<<sum[k]-sum[k-1]+1-4<<"\n";
                    if(s[k].type=="short")
                        cout<<sum[k]-sum[k-1]+1-2<<"\n";
                    break;
                }
            }
        }
        else if(op==4){
            long long addr;
            cin>>addr;
            for(int i=1;i<dis;i++){
                if(sum[i]>addr){
                    if(s[i].type=="long")
                        cout<<sum[i]-sum[i-1]+1-8<<"\n";
                    if(s[i].type=="int")
                        cout<<sum[i]-sum[i-1]+1-4<<"\n";
                    if(s[i].type=="short")
                        cout<<sum[i]-sum[i-1]+1-2<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}
