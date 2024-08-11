#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],c[10],d[10],e[10],bigans[801];
int n;
int same(int aa,int bb,int cc,int dd,int ee){
    for(int i=0;i<n;i++){
        if(aa==a[i]&&bb==b[i]&&cc==c[i]&&dd==d[i]&&ee==e[i]) return 1;
    }
    return 0;
}
int allcan(int aa,int bb,int cc,int dd,int ee){
    for(int i=0;i<n;i++){
        if(aa!=a[i]){
            if(bb!=b[i]){
                if(!((a[i]-aa+10)%10==(b[i]-bb+10)%10 && cc==c[i]&&dd==d[i]&&ee==e[i])) return 0;
            }
            else if(!(cc==c[i]&&dd==d[i]&&ee==e[i]&&bb==b[i])) return 0;
        }
        if(bb!=b[i]){
            if(aa!=a[i]){
                if(!((a[i]-aa+10)%10==(b[i]-bb+10)%10 && cc==c[i]&&dd==d[i]&&ee==e[i])) return 0;
            }
            else if(cc!=c[i]){
                if(!((c[i]-cc+10)%10==(b[i]-bb+10)%10 && aa==a[i]&&dd==d[i]&&ee==e[i])) return 0;
            }
            else if(!(cc==c[i]&&dd==d[i]&&ee==e[i]&&aa==a[i])) return 0;
        }
        if(cc!=c[i]){
            if(bb!=b[i]){
                if(!((c[i]-cc+10)%10==(b[i]-bb+10)%10 && aa==a[i]&&dd==d[i]&&ee==e[i])) return 0;
            }
            else if(dd!=d[i]){
                if(!((d[i]-dd+10)%10==(c[i]-cc+10)%10 && aa==a[i]&&bb==b[i]&&ee==e[i])) return 0;
            }
            else if(!(ee==e[i]&&dd==d[i]&&bb==b[i]&&aa==a[i])) return 0;
        }
        if(dd!=d[i]){
            if(cc!=c[i]){
                if(!((d[i]-dd+10)%10==(c[i]-cc+10)%10 && aa==a[i]&&bb==b[i]&&ee==e[i])) return 0;
            }
            else if(ee!=e[i]){
                if(!((e[i]-ee+10)%10==(d[i]-dd+10)%10 && aa==a[i]&&bb==b[i]&&cc==c[i])) return 0;
            }
            else if(!(ee==e[i]&&cc==c[i]&&bb==b[i]&&aa==a[i])) return 0;
        }
        if(ee!=e[i]){
            if(dd!=d[i]){
                if(!((e[i]-ee+10)%10==(d[i]-dd+10)%10 && aa==a[i]&&bb==b[i]&&cc==c[i])) return 0;
            }
            else if(!(cc==c[i]&&dd==d[i]&&aa==a[i]&&bb==b[i])) return 0;
        }
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }
    int now=0;
    for(int t=1;t<=9;t++){
        for(int i=0;i<n;i++){
            int x[5]={a[i],b[i],c[i],d[i],e[i]};
            for(int j=0;j<5;j++){
                int linshi=x[j];
                x[j]=(x[j]+t)%10;
                if(same(x[0],x[1],x[2],x[3],x[4])==0&&allcan(x[0],x[1],x[2],x[3],x[4])==1){//
                    bigans[now]=x[0]*10000+x[1]*1000+x[2]*100+x[3]*10+x[4];
                    now++;
                }
                x[j]=linshi;
            }
        }
    }

    for(int t=1;t<=9;t++){
        for(int i=0;i<n;i++){
            int x[5]={a[i],b[i],c[i],d[i],e[i]};
            for(int j=0;j<4;j++){
                int linshia=x[j],linshib=x[j+1];
                x[j]=(x[j]+t)%10;
                x[j+1]=(x[j+1]+t)%10;
                if(same(x[0],x[1],x[2],x[3],x[4])==0&&allcan(x[0],x[1],x[2],x[3],x[4])==1){//
                    bigans[now]=x[0]*10000+x[1]*1000+x[2]*100+x[3]*10+x[4];
                    now++;
                }
                x[j]=linshia;
                x[j+1]=linshib;
            }
        }
    }
    sort(bigans,bigans+now);
    for(int i=0;i<now;i++){
        if(bigans[i]!=bigans[i+1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
