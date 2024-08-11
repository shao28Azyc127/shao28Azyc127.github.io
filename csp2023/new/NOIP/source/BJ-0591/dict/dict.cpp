#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3005][3005];
int maxs[3005][3005],mins[3005][3005];
int main(){
freopen("dict.in","r",stdin);
freopen("dict.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;++i){
    string tmp;
    cin>>tmp;
    a[i][0]=tmp.length();
    for(int j=0;j<tmp.length();++j){
        a[i][j+1]=tmp[j]-'a';
        maxs[i][j+1]=a[i][j+1];mins[i][j+1]=a[i][j+1];

        //cout<<a[i][j]<<" ";
    }
    //cout<<endl;
}
int mm1=0,mm2=0;
for(int i=0;i<n;++i){
    sort(&mins[i][1],&mins[i][a[i][0]+1]);
    sort(&maxs[i][1],&maxs[i][a[i][0]+1]);
    reverse(&maxs[i][1],&maxs[i][a[i][0]+1]);
}
for(int i=0;i<n;++i){

    for(int j=1;j<=m;++j){
        if(a[i][j]<a[mm1][j]){

            mm1=i;break;
        }
        if(a[i][j]>a[mm1][j]){
            break;
        }
    }


}
for(int i=0;i<n;++i){
    if(i==mm1) continue;
    for(int j=1;j<=m;++j){
        if(a[i][j]<a[mm2][j]){
            mm2=i;break;
        }
        if(a[i][j]>a[mm2][j]){
            break;
        }
    }

}
//cout<<mm1<<" "<<mm2<<endl;
string s,s1;
for(int i=0;i<n;++i){
    char k='0';
    if(i!=mm1){for(int j=1;j<=m;++j){
        if(mins[i][j]<maxs[mm1][j]){
            k='1';
            break;
        }
        if(mins[i][j]>maxs[mm1][j]){
            break;
        }
    }}
    if(i==mm1){for(int j=1;j<=m;++j){
        if(mins[i][j]<maxs[mm2][j]){
            k='1';
            break;
        }
        if(mins[i][j]<maxs[mm2][j]){
            break;
        }
    }}
    s+=k;
}

cout<<s;
}