#include "GenQueue.h"
#include "Simulation.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  if(argc < 2){
    cout << "Invalid number of arguments." << endl;
    return -1;
  }

  //This checks to see if the file exists
  string filename = argv[1];
  ifstream test(filename);
  if(!test.is_open()){
    cout << "Invalid filename." << endl;
    test.close();
    return -1;
  }
  test.close();

  //The simulation is created and ran
  Simulation s(filename);
  s.run();
  return 0;
}
