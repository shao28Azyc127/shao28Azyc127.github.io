#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int c,t;
int n,m;
char op[100011];
int gog[100011];
int tot[100011];
int ori[21],fin[21];
bool ifu[100011];
int bel[100011];
void inline ru(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> op[i] >> tot[i];
        if(op[i]=='-'||op[i]=='+') cin >> gog[i];
        else if(op[i]=='F') gog[i]=-3;
        else if(op[i]=='T') gog[i]=-2;
        else if(op[i]=='U') gog[i]=-1;
    }
}
void inline sol1(){//0F 1U 2T
    int ans=n;
    int tmp=0,tmpans=0;
    for(int i=0;i<=pow(3,n)-1;i++){
        bool flag=true;
        memset(ori,0,sizeof(ori)); memset(fin,0,sizeof(fin));
        tmp=i;tmpans=0;
        for(int j=1;j<=n;j++){
            fin[j]=ori[j]=tmp%3;
            if(ori[j]==1) tmpans++;
            tmp/=3;
        }

        if(tmpans>=ans) continue;
        //cout << "hee" << endl;
        for(int j=1;j<=m;j++){
            if(op[j]=='F') fin[tot[j]]=0;
            else if(op[j]=='U') fin[tot[j]]=1;
            else if(op[j]=='T') fin[tot[j]]=2;
            else if(op[j]=='+') fin[tot[j]]=fin[gog[j]];
            else if(op[j]=='-') fin[tot[j]]=2-fin[gog[j]];
        }
        for(int j=1;j<=n;j++){
            if(fin[j]!=ori[j]) flag=false;
            //cout << ori[j] << endl;
        }
        if(flag){
            ans=min(ans,tmpans);
            //cout << i << ' ' << ans << endl;
            /*
            for(int j=1;j<=n;j++) cout << ori[j];
            cout << endl;
            for(int j=1;j<=n;j++) cout << fin[j];
            cout << endl << endl;
            */
        }

    }
    cout << ans << endl;
}
void inline sol2(){
    memset(ifu,false,sizeof(ifu));
    int ans=0;
    for(int i=1;i<=m;i++){
        if(op[i]=='U') ifu[tot[i]]=true;
        else if(op[i]=='F'||op[i]=='T') ifu[tot[i]]=false;
    }
    for(int i=1;i<=n;i++){
        if(ifu[i]){
            ans++;
            //cout << i << endl;
        }
    }
    cout << ans << endl;
}
void inline sol3(){
    memset(bel,0,sizeof(bel));
    int ans=0;
    for(int i=1;i<=n;i++) bel[i]=i;
    for(int i=1;i<=m;i++){
        if(op[i]=='U') bel[tot[i]]=-1;
        if(op[i]=='+'){
            bel[tot[i]]=bel[gog[i]];
        }
    }
    for(int i=1;i<=n;i++){
        int tmp=bel[i];
        for(int j=0;j<=m;j++){
            if(tmp==-1){
                ans++;
                break;
            }
            tmp=bel[tmp];
        }
    }
    cout << ans << endl;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    cin >> c >> t;
    for(int i=1;i<=t;i++){
        ru();
        if(c==1||c==2) sol1();
        else if(c==3||c==4) sol2();
        else if(c==5||c==6) sol3();
        else{
            sol2();
        }
    }
	return 0;
}
// i? tot[i]? gog[i]?
/*
-3 F
-2 T
-1 U
*/
/*
1-2 meijv+baosou (ac sample)
3-4(ac sample?)
if have T/F/U make it to the end
else make it to no U
5(ac sample)
begin: make it to all T
moni repeatedly
5-6
记录终值由谁的初值而来，并查集维护
7-8
9

10

*/
/*
sqrt???
*/
