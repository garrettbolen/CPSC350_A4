#include "Simulation.h"
#include <iostream>

Simulation::Simulation(string filename){
  inFS.open(filename);
}

Simulation::~Simulation(){
  inFS.close();
  delete windows;
}

void Simulation::run(){
  int num = 0;
  inFS >> num;
  numWindows = num;
  windows = new Window[num];
  for(int i = 0; i < num; ++i){
    Window w = {0, 0};
    windows[i] = w;
  }

  DoublyLinkedList<int> waitTimes;
  DoublyLinkedList<int> idleTimes;
  GenQueue<Student> queue;
  int time = 0;
  int nextTime = 0;
  int val = 0;
  inFS >> nextTime;
  while(true){
    time++;
    if(time == nextTime){
      inFS >> num;
      for(int i = 0; i < num; ++i){
        inFS >> val;
        Student s = {0, val};
        queue.insert(s);
      }
      inFS >> nextTime;
    }

    for(int i = 0; i < numWindows; ++i){
      if(!checkDone(windows[i]))
        windows[i].timer -= 1;
    }
    if(!queue.isEmpty()){
      for(int i = 0; i < queue.getSize(); ++i){
        int idx = findWindow();
        if(idx == -1)
          break;
        Student s = queue.remove();
        waitTimes.insertFront(s.waitTime);
        windows[idx].timer = s.windowTime;
        idleTimes.insertFront(windows[idx].idleTime);
        windows[idx].idleTime = 0;
      }
    }

  }
}

int Simulation::findWindow(){
  for(int i = 0; i < numWindows; ++i){
    if(windows[i].timer <= 0)
      return i;
  }
  return -1;
}

bool Simulation::checkDone(Window w){
  if(w.timer <= 0)
    return true;
  return false;
}
