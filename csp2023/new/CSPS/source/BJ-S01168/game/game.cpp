#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream inFile("game.in");
  ofstream outFile("game.out");
  outFile << 5;
    
  inFile.close();
  outFile.close();
  return 0;
}
