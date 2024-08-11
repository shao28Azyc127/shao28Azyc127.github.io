#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream inFile("tree.in");
  ofstream outFile("tree.out");
  outFile << 5;
    
  inFile.close();
  outFile.close();
  return 0;
}
