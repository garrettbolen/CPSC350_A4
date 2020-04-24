#include "GenQueue.h"
#include "Window.h"
#include <fstream>
#pragma once

using namespace std;

class Simulation{
public:
  Simulation(string filename);
  ~Simulation();
  void run();
  int findWindow();
  bool checkDone(Window w);

  ifstream inFS;
  Window* windows;

  int numWindows;
  int longestWait;
  int meanWait;
  int medianWait;

  int longestIdle;
  int meanIdle;

  int studWaitOverTen;
  int winIdleOverFive;
};
