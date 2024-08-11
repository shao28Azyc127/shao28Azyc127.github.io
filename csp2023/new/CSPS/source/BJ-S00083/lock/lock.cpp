#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
#define pii pair<int,int>
#define p1(A) A.first
#define p2(A) A.second
inline int dis(int a,int b){
    if(b>=a)return b-a;
    return b+10-a;
}
struct LOC{
    int S[10];
    LOC(){
        memset(S,0,sizeof(S));
    }
}T[10];
int n;
inline bool chk(LOC A,LOC B){
    vector<pii>E;
    for(int i=0;i<5;i++)
        if(A.S[i]!=B.S[i])
            E.push_back({i,dis(A.S[i],B.S[i])});
    if(E.empty())return 0;
    else if(E.size()>2)return 0;
    else if(E.size()==1)return 1;
    else {
        if(p1(E[0])!=p1(E[1])-1)return 0;
        if(p2(E[0])!=p2(E[1]))return 0;
        return 1;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("lock2.in","r",stdin);
    //freopen("lock2.out","w",stdout);
    freopen("lock.in","r",stdin);////////////////////////////////////////////////////////
    freopen("lock.out","w",stdout);//remember to update
    int res=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++)
         cin>>T[i].S[j];
    LOC P;
    for(P.S[0]=0;P.S[0]<10;P.S[0]++)
    for(P.S[1]=0;P.S[1]<10;P.S[1]++)
    for(P.S[2]=0;P.S[2]<10;P.S[2]++)
    for(P.S[3]=0;P.S[3]<10;P.S[3]++)
    for(P.S[4]=0;P.S[4]<10;P.S[4]++){
        bool q=1;
        for(int i=1;i<=n;i++)
            q&=chk(P,T[i]);
        res+=q;
    }
    //cout<<res<<endl;
    printf("%lld\n",res);
    fflush(stdout);
    fflush(stdin);
    fclose(stdin);
    fclose(stdout);
    cout.flush();

    return 0;
}
