#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile("apple.in");
    ofstream outFile("apple.out");
    long long a[1000010],b[1000010],c[1000010];
    long long n,n1=0,k=0,p=1,j=1,y=0;
    inFile>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    while(n>1)
    {
        p=1;
        j=1;
        n1=1;
        b[j]=a[p];
        while(p+3<=n)
        {
            p+=3;
            j++;
            b[j]=a[p];
            n1++;
        }
        k++;
        for(int i=1;i<=n;i++)
            if(i%3!=1) c[i]=a[i];
        n-=n1;
        for(int i=1;i<=j;i++)
            if(b[i]==n) y=k;
        for(int i=1;i<=n;i++) a[i]=c[i];
    }
    k+=1;
    if(y==0) y=k;
    outFile<<k<<" "<<y<<endl;
    inFile.close();
    outFile.close();
    return 0;
}
