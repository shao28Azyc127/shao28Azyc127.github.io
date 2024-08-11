#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n,ans;
int a[10][10];
int c[10];

void One_C(int x,int y){
    int cnt=0;
    for(int i=1;i<=5;i++){
        if(a[x][i]!=a[y][i]) cnt++;
    }
    if(cnt==1){
        ans+=10;
        return;
    }
    else if(cnt==2){
        int px,qx,py,qy,p,q;
        for(int i=1;i<=5;i++){
            if(a[x][i]!=a[y][i]&&cnt==2){
                px=a[x][i];
                py=a[y][i];
                p=i;
                cnt--;
            }
            else if(a[x][i]!=a[y][i]){
                qx=a[x][i];
                qy=a[y][i];
                q=i;
            }
        }
        if(px-qx!=py-qy||q-p>1) return;
        else{
            ans+=7;
            return;
        }
    }
}

int cnt(int x,int y){
    int ret=0;
    for(int i = 1;i <= 5;i++){
        if(x%10!=y%10) ret++;
        x/=10;
        y/=10;
    }
    return ret;
}

bool check(int x,int y){
    int t=abs(x-y);
    if(!(t%10==0||t%11==0||t%10000==0||t%11000==0||t%100==0||t%110==0||t%1000==0||t%1100==0||t<10)){
        return 0;
    }
    return 1;
}

void C(){
    for(int i1=0;i1<=9;i1++){
        for(int i2=0;i2<=9;i2++){
            for(int i3=0;i3<=9;i3++){
                for(int i4=0;i4<=9;i4++){
                    for(int i5=0;i5<=9;i5++){
                        int i=i1*10000+i2*1000+i3*100+i4*10+i5;//Ã¶¾ÙÃÜÂë
                        bool f=1;
                        for(int p = 1;p <= n;p++){
                            if(c[p]==i){
                                f=0;
                                break;
                            }
                            int t=0,s=0,it,is;
                            if(cnt(i,c[p])>2){
                                f=0;
                                break;
                            }
                            if(a[p][1]-i1){
                                t=a[p][1]-i1;
                                it=1;
                            }
                            if(a[p][2]-i2&&t) s=a[p][2]-i2,is=2;
                            if(a[p][2]-i2&&!t) t=a[p][2]-i2,it=2;
                            if(a[p][3]-i3&&t) s=a[p][3]-i3,is=3;
                            if(a[p][3]-i3&&!t) t=a[p][3]-i3,it=3;
                            if(a[p][4]-i4&&t) s=a[p][4]-i4,is=4;
                            if(a[p][4]-i4&&!t) t=a[p][4]-i4,it=4;
                            if(a[p][5]-i5&&t) s=a[p][5]-i5,is=5;
                            if(a[p][5]-i5&&!t) t=a[p][5]-i5,it=5;

                            if(s==0||(t==s&&is-it==1)) continue;
                            if(t!=s||is-it!=1){
                                f=0;
                                if(check(i,c[p])) continue;
                                break;
                            }
                        }
                        if(f) ans++;
                    }
                }
            }
        }
    }

}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    //ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            cin >> a[i][j];
        }
        c[i]=a[i][1]*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+a[i][5];
    }

    /*if(n==1){
        cout << 81 << endl;
    }
    else if(n==2){
        One_C(1,2);
        cout << ans << endl;
    }*/
    //else{
        C();
        cout << ans << endl;
    //}
    return 0;
}
