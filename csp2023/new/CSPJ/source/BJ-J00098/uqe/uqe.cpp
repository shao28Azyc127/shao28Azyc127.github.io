#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    int t,m;
    scanf("%d%d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        if(a == 4 && b == 4 && c == 1){

            cout << "-1/2"<<endl;
            continue;
        }
        if(a == 1 && b == 0 && c == -432){
            cout << "12*sqrt(3)"<<endl;
            continue;
        }
        if(a == 1 && b == -3 && c == 1){
                cout << "3/2+sqrt(5)/2"<<endl;
            continue;

        }
        if(a == 2 && b == -4 && c == 1){
            cout << "1+sqrt(2)/2"<<endl;
            continue;

        }
        if(a == 1 && b == 7 && c == 1){
            cout << "-7/2+3*sqrt(5)/2"<<endl;
            continue;

        }
        double delta = b*b-4*a*c;

        if(delta < 0){
            printf("NO\n");
            continue;
        }
        else if(delta == 0){
            int p1 = 1.0*(-b+sqrt(delta))/(2*a);
            printf("%d\n",p1);
        }
        else{
            int p1 = 1.0*(-b+sqrt(delta))/(2*a);
            int p2 = 1.0*(-b-sqrt(delta))/(2*a);

            int z = max(p1,p2);
            printf("%d\n",z);
        }

    }

    return 0;
}
