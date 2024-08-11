#include<bits/stdc++.h>
using namespace std;

int rd(){
    int x=0,f=1;
    char b = getchar();
    while(!isdigit(b)){
        if(b == '-') f=-1;
        b = getchar();
    }



    while(isdigit(b)){
        x = (x << 1) + (x << 3) + (b^48);
        b = getchar();
    }
    return x*f;
}
int c,n,m,q;
const int Maxn = 5e5+10;
int a[Maxn],b[Maxn];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    c=rd();n=rd();m=rd();q=rd();
    //cout << 43243242 <<endl;
    if(n == 1 && m == 1){
        int x,y;
        cin >> x >> y;
        if(x != y){
            cout << 1;
        }else cout << 0;
        while(q--){
            int kx=rd(),ky=rd();
            for(int i = 1; i <= kx; i ++){
                int px=rd(),xv=rd();
                x=xv;
            }
            for(int j = 1; j <= ky;j++){
                int py=rd(),yv=rd();
                y=yv;
            }
            if(x != y){
                cout << 1;
            }else cout << 0;
        }
        return 0;
    }//special judge when m,n=1

   // cout << 43243242 <<endl;

    for(int i = 1; i <= n;i++){
        a[i] = rd();
    }
    for(int j = 1; j <= m ; j ++){
        b[j] = rd();
    }


    bool flag1=0,flag2=0;
    for(int i = 1; i <= n ; i++){
        if(a[i] - b[i] > 0){
            flag1 = true;
        }
        if(a[i] - b[i] < 0){
            flag2 = true;
        }
    }
    if((flag1 && flag2) || (!(flag1) && !(flag2))){
        string fds = "LOVECHINA";
    }else{
        cout << 1;
    }



    int f;
    if(a[1] - b[1] < 0){
        f=-1;
    }else if(a[1] - b[1] > 0){
        f=1;
    }else cout << 0;

    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(((a[i-cnt] - b[i])*f) <= 0){
            bool flag=0;
            cnt++;
            while((i - cnt) > 0){
                if(((a[i - cnt] - b[i])*f) <= 0){
                    cnt++;
                }else{flag=1;break;}
            }
            if(flag == 0){
                cout << 0;
                break;
            }

        }
    }

    //cout << 43243242 <<endl;
    bool ff = 0;
    for(int i = n-cnt; i <= n; i++){
       if(((a[n] - b[i])*f) < 0){
        cout << 0;
        ff = 1;
       }
    }
    if(ff == 0){
        cout << 1;
    }

    //cout << 43243242 <<endl;

    while(q--){
        int kx=rd(),ky=rd();
        if(kx != 0){
            int px=rd(),xv=rd();
            a[px] = xv;
        }
        if(ky != 0){
            int py=rd(),yv=rd();
            b[py] = yv;
        }


        int f;
        if(a[1] - b[1] < 0){
        f=-1;
        }else if(a[1] - b[1] > 0){
        f=1;
        }else {cout << 0;continue;}

    int cnt = 0;
    bool fdf = 0;
    for(int i = 2; i <= n; i++){
        if(((a[i-cnt] - b[i])*f) <= 0){
            bool flag=0;
            cnt++;
            while((i - cnt) > 0){
                if(((a[i - cnt] - b[i])*f) <= 0){
                    cnt++;
                }else{flag=1;break;}
            }
            if(flag == 0){
                cout << 0;
                fdf = 1;
                break;
            }

        }
    }

    if(fdf == 1) continue;

    bool ff = 0;
    for(int i = n-cnt; i <= n; i++){
       if(((a[n] - b[i])*f) < 0){
        //cout << 0;
        ff = 1;
       }
    }
    if(ff == 0){
        cout << 1;
    }else{
        cout << 0;
    }


    }

     //   cout << 43243242 <<endl;
    return 0;
}
