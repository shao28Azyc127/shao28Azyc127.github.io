#include<bits/stdc++.h>
using namespace std;
int x[10];
int cc[1010];
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
int Q(int aa, int bb){
    if(bb==0){
        return 1;
    }else if(bb==1){
        return aa;
    }else if(bb%2==1){
        int ggb=Q(aa, bb/2);
        return ggb*ggb*aa;
    }else{
        int ggb=Q(aa, bb/2);
        return ggb*ggb;
    }
}
void out_q(){
    int cb=x[4];
    int m=0;
    for(int i=2;i*i<=cb;i++){
        while(cb%i==0){
            cc[i]++;
            cb/=i;
        }
        m=max(m, i);
    }
    if(cb){
        cc[cb]++;
        m=max(m, cb);
    }
    x[4]=1;
    for(int i=2;i<=m;i++){
        x[3]*=Q(i, cc[i]/2);
        if(cc[i]%2==1){
            x[4]*=i;
        }
    }
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin>>t>>m;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        if(m<=1){
            cout<<0;
            continue;
        }
        for(int i=0;i<=m;i++){
            cc[i]=0;
        }
        x[4]=b*b-4*a*c;
        if(x[4]<0){
            cout<<"NO\n";
            continue;
        }
        x[1]=-b;
        x[2]=a+a;
        x[3]=1;
        x[5]=a+a;
        out_q();
        int ccc1=gcd(x[1], x[2]);
        x[1]/=ccc1;
        x[2]/=ccc1;
        if(x[2]<0&&x[1]>0){
            x[1]=-x[1];
            x[2]=-x[2];
        }

        int ccc2=gcd(x[3], x[5]);
        x[3]/=ccc2;
        x[5]/=ccc2;
        if(x[3]<0&&x[5]>0){
            x[5]=-x[5];
            x[3]=-x[3];
        }
        if(x[3]<0) x[3]=-x[3];
        if(x[1]==x[2]){
            cout<<1;
        }else if(x[1]!=0){
            cout<<x[1]<<'/'<<x[2];
        }
        if(x[4]!=0&&x[1]!=0)cout<<'+';
        if(x[4]>0){
            if(x[3]==x[5]){
                cout<<"sqrt("<<x[4]<<")";
            }else if(x[5]==1){
                cout<<x[3]<<'*'<<"sqrt("<<x[4]<<")";
            }else if(x[3]==1){
                cout<<"sqrt("<<x[4]<<")/"<<x[5];
            }else{
                cout<<x[3]<<'*'<<"sqrt("<<x[4]<<")/"<<x[5];
            }
        }
        cout<<endl;
    }
    return 0;
}