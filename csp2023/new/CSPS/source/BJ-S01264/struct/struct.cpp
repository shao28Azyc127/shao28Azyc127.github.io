#include<bits/stdc++.h>
using namespace std;
int n;
struct tt{
    int k;
    string s;
    string t[105];
    string n[105];
    int addr;
    string vars[105];
    int nvp=0;
}a[100];
int main(){
cin>>n;
int tptr;
int op;
for(int i=0;i<n;i++)
    {

    cin>>op;
    }
    if(op==1)
        {
            cin>>a[tptr].s>>a[tptr].k;
            for(int j=0;j<a[tptr].k;j++){
                cin>>a[tptr].t[j]>>a[tptr].n[j];
            }

    }
    else if(op==2)
    {
        string t,n;
        cin>>t>>n;
        for(int i=0;i<100;i++)
            {
                if(a[i].s==t)
                {
                    a[i].vars[nvp]=n;
                    a[i].nvp++;
                }
            }

    }


