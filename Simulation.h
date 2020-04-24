#include "GenQueue.h"
#include "Window.h"
#include <fstream>
#pragma once

using namespace std;

//This class will contain the code to run the simulation
class Simulation{
public:
  //Constructor and destructor
  Simulation(string filename);
  ~Simulation();

  //Various functions that will be useful in calculations
  void run();
  int findWindow();
  bool checkDone(Window w);
  int findLongest(DoublyLinkedList<int> l);
  double findMean(DoublyLinkedList<int> l);
  int findMedian(DoublyLinkedList<int> l);
  int findWaitingOverTen(DoublyLinkedList<int> l);
  int findIdleOverFive(DoublyLinkedList<int> l);

  //This will be the input stream for the file
  ifstream inFS;
  //This will act as the array of windows in the simulation
  Window* windows;
  int numWindows;

};
