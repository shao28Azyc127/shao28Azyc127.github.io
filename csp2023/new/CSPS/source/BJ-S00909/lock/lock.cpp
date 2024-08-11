#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int a[n][5]={},ot=0;//是否已输出
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
    }
    if(n==1){
        cout<<81;
        ot=1;
    }
    if(n==2){
        int c[5]={};//差值
        int d=0;//差值位数量
        for(int i=0;i<5;i++){
            if(a[0][i]!=a[1][i]){
                c[i]=(a[0][i]-a[1][i]+10)%10;
                d++;
            }
        }
        if(d==1){
            int p=0;
            for(int i=0;i<5;i++){
                if(c[i]!=0){
                    p=i;
                }
            }
            if(p==0||p==4){
                cout<<10;
            }else{
                cout<<12;
            }
            ot=1;
        }
        if(d==2){
            int p[2]={};
            int q=0;
            for(int i=0;i<5;i++){
                if(c[i]!=0){
                    p[q]=i;
                    q++;
                }
            }
            if(p[1]-p[0]!=1){
                cout<<2;
            }else{
                if(c[p[0]]==c[p[1]]){
                    cout<<10;
                }else{
                    cout<<6;
                }
            }
            ot=1;
        }
        if(d==3){
            int p[3]={};
            int q=0;
            for(int i=0;i<5;i++){
                if(c[i]!=0){
                    p[q]=i;
                    q++;
                }
            }
            if(p[1]-p[0]!=1&&p[2]-p[1]!=1){
                cout<<0;
                ot=1;
            }
            bool t1=c[p[0]]==c[p[1]];
            bool t2=c[p[1]]==c[p[2]];
            if(p[1]-p[0]!=1&&!t2){
                cout<<0;
                ot=1;
            }
            if(p[2]-p[1]!=1&&!t1){
                cout<<0;
                ot=1;
            }
            if(ot==0){
                if(t1&&t2){
                    cout<<4;
                }else{
                    cout<<2;
                }
                ot=1;
            }
        }
        if(d==4){
            int p[4]={};
            int q=0;
            for(int i=0;i<5;i++){
                if(c[i]!=0){
                    p[q]=i;
                    q++;
                }
            }
            if(c[1]==0||c[3]==0){
                cout<<0;
                ot=1;
            }
            bool t1=c[p[0]]==c[p[1]];
            bool t2=c[p[2]]==c[p[3]];
            if(!(t1&&t2)){
                cout<<0;
                ot=1;
            }
            if(ot==0){
                cout<<2;
                ot=1;
            }
        }
        if(d==5){
            cout<<0;
            ot=1;
        }
    }
    if(ot==1){
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int b[5][10]={};//每位每个数字出现次数
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            b[j][a[i][j]]++;
        }
    }
    for(int i=0;i<5;i++){
        int h=0;
        for(int j=0;j<10;j++){
            if(b[i][j]>1){
                h++;
            }
        }
        if(h>1){
            cout<<0;
            ot=1;
        }
    }
    int q[5]={};//每位有几个数字出现
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++){
            if(b[i][j]!=0){
                q[i]++;
            }
        }
    }
    int r=0;//有几位数变动
    for(int i=0;i<5;i++){
        if(q[i]>1){
            r++;
        }
    }
    if(r==1&&ot==0){
        cout<<10-n;
        ot=1;
    }else{
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int f=0;
                for(int k=0;k<4;k++){
                    int g=a[i][k]-a[j][k];
                    if(g!=0){
                        if(f==0){
                            f=g;
                        }else{
                            if(g!=-f){
                                cout<<0;
                                ot=1;
                            }
                        }
                    }
                }
            }
        }
        if(ot==0){
            cout<<1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
