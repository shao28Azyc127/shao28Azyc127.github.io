#include <bits/stdc++.h>
using namespace std;
FILE *f1=fopen("lock.in","r"),*f2=fopen("lock.out","w");
int n,s[10][10],v[6]={100000,10000,1000,100,10,1},w[10][10];
int h(){
    int ans=0,now=0;
    vector<int>a,b;
    for(int c=1;c<=9;c++){
        for(int j=1;j<=5;j++){
            int x=w[1][j]+(s[1][j]+c)*v[j];
            a.push_back(x);
        }
        for(int j=1;j<=4;j++){
            int x=w[1][0]/v[j-1]+w[1][0]%v[j+2]+(s[1][j]+c)*v[j]+(s[1][j+1]+c)*v[j+1];
            a.push_back(x);
        }
    }
    for(int c=1;c<=9;c++){
        for(int j=1;j<=5;j++){
            int x=w[2][j]+(s[2][j]+c)*v[j];
            b.push_back(x);
        }
        for(int j=1;j<=4;j++){
            int x=w[2][0]/v[j-1]+w[2][0]%v[j+2]+(s[2][j]+c)*v[j]+(s[2][j+1]+c)*v[j+1];
            b.push_back(x);
        }
    }
    sort(a.begin(),a.begin()+81);
    sort(b.begin(),b.begin()+81);
    for(int i=0;i<=a.size();i++){
        while(b[now]<a[i]){
            if(b[now]==a[i]){
                ans++;
                break;
            }
            now++;
        }
    }
    return ans;
}
int main(){
    int ans;
    fscanf(f1,"%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            fscanf(f1,"%d",&s[i][j]);
            w[i][0]+=s[i][j]*v[j];
        }
        w[i][1]=w[i][0]-s[i][1]*v[1];
        w[i][2]=w[i][0]-s[i][2]*v[2];
        w[i][3]=w[i][0]-s[i][3]*v[3];
        w[i][4]=w[i][0]-s[i][4]*v[4];
        w[i][5]=w[i][0]-s[i][5]*v[5];
    }
    if(n==1){
        ans=81;
        fprintf(f2,"%d",ans);
        return 0;
    }
    if(n==2){
        ans=h();
        fprintf(f2,"%d",ans);
        return 0;
    }
    fprintf(f2,"%d",ans);
    return 0;
}
