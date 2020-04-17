#include <fstream>
#pragma once

class Simulation{
public:
  Simulation(string filename);
  ~Simulation();
  void run();

  ifstream inFS;
  DoublyLinkedList<bool>* windows;

  int longestWait;
  int meanWait;
  int medianWait;

  int longestIdle;
  int meanIdle;

  int studWaitOverTen;
  int winIdleOverFive;
};
