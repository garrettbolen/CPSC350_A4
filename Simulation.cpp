#include "Simulation.h"

Simulation::Simulation(string filename){
  inFS.open(filename);
}

Simulation::~Simulation(){
  inFS.close();
  delete windows;
}

void Simulation::run(){
  string line = "";
  int num = 0;
  getline(inFS, line);
  num = stoi(line);
  for(int i = 0; i < num; ++i){
    windows->insertFront(1);
  }

}
