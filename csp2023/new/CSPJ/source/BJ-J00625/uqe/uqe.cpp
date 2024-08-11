#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int gcdF(int a, int b){
    int yushu;
    if(b == 0){
        return a;
    }
    return gcdF(b,a%b);
}

void youlishu(int a, int b, int c){
    int sq = b*b - 4*a*c;
    //ind d = sqrt(sq);
    int xfz,xfmu;
    double x1,x2;
    int tmp=-1;
    x1 = (tmp*b + sqrt(sq))/(2*a);
    x2 = (tmp*b - sqrt(sq))/(2*a);
    xfz = tmp*b + sqrt(sq);
    xfmu = tmp*b - sqrt(sq);
    if(max(xfz,xfmu) == 0 && a>0){
        cout << 0 << endl;
        return;
    }
    if(x1>x2){
        xfz = tmp*b + sqrt(sq);
        xfmu = 2*a;
        int tmp = gcdF(abs(xfz),abs(xfmu));
        xfz = xfz/tmp;
        xfmu = xfmu/tmp;
        if(xfz*xfmu<0){
             if(abs(xfz) ==abs (xfmu)){
                cout << tmp*abs(xfz) << endl;
            }else{
                cout << xfz << '/' << xfmu << endl;
            }
            //cout <<'-'<<abs(xfz) << '/' << abs(xfmu) << endl;
        }else{
            //cout << xfz << '/' << xfmu << endl;
             if(xfz == xfmu){
                cout << xfz << endl;
            }else{
                cout << xfz << '/' << xfmu << endl;
            }
        }
    }

}
void wulishu(int a, int b , int c){
    int sq = b*b - 4*a*c;
    int xfz,xfmu;
    double x1,x2,q1,q2;
    int tmp=-1;
    x1 = (tmp*b + sqrt(sq))/(2*a);
   x2 = (tmp*b - sqrt(sq))/(2*a);
    //xfz = tmp*b + sqrt(sq);
   // xfmu = tmp*b - sqrt(sq);
    if(b!=0){
        int tmp = gcdF(abs(b),abs(2*a));
        xfz = b/tmp;
        xfmu = 2*a/tmp;
        if(xfz*xfmu<0){
            //cout <<'-'<<abs(xfz) << '/' << abs(xfmu) << endl;
             if(abs(xfz) ==abs (xfmu)){
                cout << tmp*abs(xfz) << endl;
            }else{
                cout << xfz << '/' << xfmu << endl;
            }
        }else{
            if(xfz == xfmu){
                cout << xfz << endl;
            }else{
                cout << xfz << '/' << xfmu << endl;
            }

        }
    }else{
        int q2;
        int tmp=2*a*2*a;
        if(sq%tmp==0){
            sq=sq/tmp;
            int i = 2;
            int t=1;
            while(i*i<sq){
                int tmp=i*i;
                if(sq%tmp == 0){
                    t = t*i;
                    sq = sq/tmp;
                }
                i++;
            }
            cout << t <<"*sqrt("<<sq<<")" << endl;
        }else{
            cout <<"*sqrt("<<sq<<")/"<<2*a << endl;
        }

    }


}
int main(){
    freopen("uqe.in","r",stdin);
   freopen("uqe.out","w",stdout);
    int T,M;
    cin >> T >> M;
    int a,b,c;
    int sq;
    for(int i=1; i<=T; i++){
        cin >> a >> b >> c;
        sq = b*b - 4*a*c;
        if(sq < 0){
            cout << "NO" << endl;
            continue;
        }
        if(a==0 && b==0){
            cout << 0 << endl;
            continue;
        }
        int d;
        d = sqrt(sq);
        if(sq == d*d){
            youlishu(a,b,c);
        }else{
            wulishu(a,b,c);
        }

    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
