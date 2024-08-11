#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
typedef pair<int,int> PII;
PII path[N];
int nums[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,cnt=0,cntmaxhui=0,cntgroup=0,jumped=0;
    string s;
    cin>>n>>s;
    int l=0,r=1;
    //if(s[0]!=s[1])cout<<"false"<<endl;
    while(r<n){
        //cout<<l<<' '<<r<<endl;
        if(s[l]!=s[r]) l=r++;
        if(s[l]==s[r]){
            cnt++;
            path[cntmaxhui]=make_pair(l,r);
            if(l-1>=0&&s[l-1]==s[r+1]){
                l--,r++;
                path[cntmaxhui]=make_pair(l,r);
                jumped++;
            }
            else if(s[l-1]!=s[r+1]&&l-1>=0){
                path[++cntmaxhui]=make_pair(l,r);
                l=r++;
                jumped=0;
            }else{
                r=r+1-jumped;
                l=r-1;
                cntmaxhui++;
                jumped=0;
            }

        }
    }
    int cntall=cnt,maxcnt=0;
    bool flag=true;
    for(int i=0;i<cntmaxhui-1;i++){
        int l1=path[i].first,r1=path[i].second;
        int l2=path[i+1].first,r2=path[i+1].second;
        if((l1==0&&r1==0)||(l2==0&&r2==0)) continue;
        if(l2-r1>1){
            flag=false;
            nums[cntgroup++]=i+1-maxcnt;
            maxcnt=i;
        }
    }
    nums[cntgroup++]=cntmaxhui-maxcnt;
    if(flag) cntall+=(cntmaxhui-1)*cntmaxhui/2;
    else{
            for(int i=0;i<cntgroup;i++){
                cntall+=(nums[i]-1)*nums[i]/2;
            }
    }
    cout<<cntall;
    return 0;
}
