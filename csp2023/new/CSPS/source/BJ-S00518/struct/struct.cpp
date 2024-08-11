#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream outFile("struct.out");
    outFile << "ERR";
    outFile.close();
    return 0;
}
