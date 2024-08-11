#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,zhi[11] = {4,9,25,49,121,169,289,361,529,841,961};
    cin>>t>>m;
    int a,b,c;
    for (int i = 0;i < t;i++){
        cin>>a>>b>>c;
        if (b*b-4*a*c < 0)  cout<<"NO"<<endl;
        else if(b*b-4*a*c == 0){
            if (-b%(a*2)){
                a*=2;
                bool flag = false;
                if (b < 0){
                    b = -b;
                    flag = true;
                }
                for (int i = min(b,a);i > 0;i--){
                    if (b%i == 0 && a%i == 0){
                        b/=i;
                        a/=i;
                    }
                }
                if (flag)  b = -b;
                cout<<-b<<'/'<<a<<endl;
            }else{
                cout<<-b/(2*a)<<endl;
            }
        }else{
            bool flag = false;
            for (int i = 2;i < 32;i++){
                if (i*i == b*b-4*a*c){
                    if ((b+i)%(2*a)){
                        int b2 = b+i;
                        int a2 = 2*a;
                        if (b2 < 0){
                            b2 = -b2;
                            flag = true;
                        }
                        for (int j = min(b2+i,a2);j > 0;j--){
                            if (b2%j == 0 && a2%j == 0){
                                b2 /= j;
                                a2/=j;
                            }
                        }
                        if (flag) b2 = -b2;
                        cout<<-b2<<'/'<<a2<<endl;
                    }else  cout<<(-b+i)/(2*a)<<endl;
                }
                flag = true;
            }
            if (flag == false){
                if (b == 0){
                    continue;
                }else if (-b%(a*2)){
                    a*=2;
                    bool flag = false;
                    if (b < 0){
                        b = -b;
                        flag = true;
                    }
                    for (int i = min(b,a);i > 0;i--){
                        if (b%i == 0 && a%i == 0){
                            b/=i;
                            a/=i;
                        }
                    }
                    if (flag)  b = -b;
                    cout<<-b<<'/'<<a<<'+'<<endl;
                }else{
                    cout<<-b/(2*a)<<'+'<<endl;
                }
                int q2 = 0,r = b*b-4*a*c;
                while (r){
                    flag = false;
                    for (int i = 0;i < 11;i++){
                        if (r%zhi[i] == 0){
                            r /= zhi[i];
                            q2 += sqrt(zhi[i]);
                            flag = true;
                        }
                    }
                    if (flag == false)  break;
                }
                if (q2%(2*a)){
                    q2 /= 2*a;
                    flag = true;
                }
                int a2 = a*2;
                for (int i = 2;i < min(q2,a2) && flag == false;i++){
                    if (q2%i == 0 && a2%i == 0){
                        q2 /= i;
                        a2 /= i;
                    }
                }
                if (flag)  cout<<q2<<"*sqrt("<<r<<')'<<endl;
                else if (q2 == 1)  cout<<"sqrt("<<r<<")/"<<a2<<endl;
                else  cout<<q2<<"*sqrt("<<r<<")/"<<a2<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
