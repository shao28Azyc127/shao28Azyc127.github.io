#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    ifstream cin("apple.in");
    ofstream cout("apple.out");
    int n,a[100000001]= {};
    cin>>n;
    int c=n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int zn=n-1;
    int tian=0,taken;
    while(c>0)
    {
        tian++;
        for(int i=0; i<n; i+=3)
        {
            a[i]=-1;
            c--;
            if(i==zn){
                taken=tian;
            }
        }
        for(int m=0;m<n;n++){
            if(a[m]==-1){
                a[m]=a[m+1];
                a[m+1]=-1;
            }
        }
    }
    cout<<tian<<' '<<taken;
    return 0;
}
