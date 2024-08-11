#include<iostream>
#include<fstream>
using namespace std;
short lock[10][10][10][10][10]={};
int main(){
    ifstream fin("lock.in");
    ofstream fout("lock.out");
    int n,n1,n2,n3,n4,n5;
    fin>>n;
    for(int i=1;i<=n;++i){
        fin>>n1>>n2>>n3>>n4>>n5;
        if(n==1){
            fout<<81<<endl;
            fin.close();
            fout.close();
            return 0;
        }
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    for(int i4=1;i4<10;++i4)
                        if(lock[n1][i1][i2][i3][i4]==i-1) lock[n1][i1][i2][i3][i4]=i;
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    for(int i4=1;i4<10;++i4)
                        if(lock[i1][n2][i2][i3][i4]==i-1) lock[i1][n2][i2][i3][i4]=i;
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    for(int i4=1;i4<10;++i4)
                        if(lock[i1][i2][n3][i3][i4]==i-1) lock[i1][i2][n3][i3][i4]=i;
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    for(int i4=1;i4<10;++i4)
                        if(lock[i1][i2][i3][n4][i4]==i-1) lock[i1][i2][i3][n4][i4]=i;
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    for(int i4=1;i4<10;++i4)
                        if(lock[i1][i2][i3][i4][n5]==i-1) lock[i1][i2][i3][i4][n5]=i;
        for(int i1=1;i<10;++i1)
            for(int i2=1;i<10;++i2)
                for(int i3=1;i<10;++i3)
                    if(lock[n1][n2][i1][i2][i3]==i-1) lock[n1][n2][i1][i2][i3]=i;
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    if(lock[i1][n2][n3][i2][i3]==i-1) lock[i1][n2][n3][i2][i3]=i;
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    if(lock[i1][i2][n3][n4][i3]==i-1) lock[i1][i2][n3][n4][i3]=i;
        for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    if(lock[i1][i2][i1][n4][n5]==i-1) lock[i1][i2][i1][n4][n5]=i;
    }
    int ans=0;
    for(int i1=1;i1<10;++i1)
            for(int i2=1;i2<10;++i2)
                for(int i3=1;i3<10;++i3)
                    for(int i4=1;i4<10;++i4)
                        for(int i5=5;i5<10;++i5)
                            if(lock[i1][i2][i3][i4][i5]==n) ++ans;
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}
