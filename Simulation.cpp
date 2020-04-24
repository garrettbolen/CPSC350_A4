#include "Simulation.h"
#include <iostream>

//Constructor
Simulation::Simulation(string filename){
  inFS.open(filename);
}

//Destructor
Simulation::~Simulation(){
  inFS.close();
  delete windows;
}

//The run method houses the code for the entire simulation
void Simulation::run(){
  //This initial block of code sets up the window array
  int num = 0;
  inFS >> num;
  numWindows = num;
  windows = new Window[num];
  for(int i = 0; i < num; ++i){
    Window w = {0, 0};
    windows[i] = w;
  }

  //These lists will store the wait time and idle time of students and windows
  DoublyLinkedList<int> waitTimes;
  DoublyLinkedList<int> idleTimes;

  //This is the queue students will join
  GenQueue<Student> queue;

  //Various integers that will be useful in the loop
  int time = 0;
  int nextTime = 0;
  int val = 0;
  inFS >> nextTime;

  //This loop will go while the file reader isn't at the end or the queue isn't empty
  while(!inFS.eof() || !queue.isEmpty()){
    time++;
    //This checks to see if the clock tick has reached the next time students will enter the queue
    if(time == nextTime){
      //If it has, this block of code will populate the queue with the appropriate number of students
      inFS >> num;
      for(int i = 0; i < num; ++i){
        inFS >> val;
        Student s = {0, val};
        queue.insert(s);
      }
      inFS >> nextTime;
    }

    //This block of code decrements the timer on each window that has a student at it;
    for(int i = 0; i < numWindows; ++i){
      if(!checkDone(windows[i]))
        windows[i].timer--;
    }
    //If the queue isn't empty, it will see if there's a free window available
    if(!queue.isEmpty()){
      for(int i = 0; i < queue.getSize(); ++i){
        int idx = findWindow();
        //if there is no free window, the queue remains the same
        if(idx == -1)
          break;
        //Otherwise if there is a window that student leaves the queue
        Student s = queue.remove();
        //In the next few lines the wait time and idle time are logged and other values updated
        waitTimes.insertFront(s.waitTime);
        windows[idx].timer = s.windowTime;
        idleTimes.insertFront(windows[idx].idleTime);
        windows[idx].idleTime = 0;
      }
    }

    //This loop will check for idle windows and update the idle time accordingly
    for(int i = 0; i < numWindows; ++i){
      if(checkDone(windows[i]))
        windows[i].idleTime++;
    }
    //This loop will go through and update student wait times for those still in queue
    ListNode<Student>* curr = queue.myQueue->front;
    while(curr != NULL){
      curr->data.waitTime++;
      curr = curr->next;
    }
  }
  cout << "Wait Times: " << endl;
  ListNode<int>* curr2 = waitTimes.front;
  while(curr2 != NULL){
    cout << curr2->data << endl;
    curr2 = curr2->next;
  }
  cout << "Idle Times: " << endl;
  ListNode<int>* curr3 = idleTimes.front;
  while(curr3 != NULL){
    cout << curr3->data << endl;
    curr3 = curr3->next;
  }
  //Here all of the calculation stat functions are called and printed out
  cout << "Mean student wait time: " << findMean(waitTimes) << " minutes" << endl;
  cout << "Median student wait time: " << findMedian(waitTimes) << " minutes" << endl;
  cout << "Longest student wait time: " << findLongest(waitTimes) << " minutes" << endl;
  cout << "Number of students waiting over 10 minutes: " << findWaitingOverTen(waitTimes) << endl;
  cout << "Mean window idle time: " << findMean(idleTimes) << " minutes" << endl;
  cout << "Longest window idle time: " << findLongest(idleTimes) << " minutes" << endl;
  cout << "Number of windows idle over 5 minutes: " << findIdleOverFive(idleTimes) << endl;


}

//This method checks to see if there is an open window by finding one with a timer of 0
int Simulation::findWindow(){
  for(int i = 0; i < numWindows; ++i){
    if(windows[i].timer <= 0)
      return i;
  }
  //-1 is returned if no window was found
  return -1;
}

//This method checks if a windows timer is done
bool Simulation::checkDone(Window w){
  if(w.timer <= 0)
    return true;
  return false;
}

//This method takes a linked list in and returns the biggest value
int Simulation::findLongest(DoublyLinkedList<int> l){
  int longest = 0;
  ListNode<int>* curr = l.front;
  while(curr != NULL){
    if(curr->data > longest)
      longest = curr->data;
    curr = curr->next;
  }
  return longest;
}

//This method calculates the mean of a linked list
double Simulation::findMean(DoublyLinkedList<int> l){
  double mean = 0.0;
  double sum = 0.0;
  ListNode<int>* curr = l.front;
  while(curr != NULL){
    sum += curr->data;
    curr = curr->next;
  }
  mean = sum/l.getSize();
  return mean;
}

//This method finds the median of a linked list
int Simulation::findMedian(DoublyLinkedList<int> l){
  int median = 0;
  int arr[l.getSize()];
  //All of the values in the list are transfered into an array
  ListNode<int>* curr = l.front;
  int n = 0;
  while(curr != NULL){
    arr[n] = curr->data;
    n++;
    curr = curr->next;
  }
  //These nested loops sort the array in ascending order
  for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(arr[i]>arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
  //The median is found by taking the middle index of the sorted array
  median = arr[l.getSize()/2];
  return median;
}

//This method finds the number of students who had a wait time >10
int Simulation::findWaitingOverTen(DoublyLinkedList<int> l){
  int count = 0;
  ListNode<int>* curr = l.front;
  while(curr != NULL){
    if(curr->data > 10)
      count++;
    curr = curr->next;
  }
  return count;
}

//This method finds the number of windows who had an idle time >5
int Simulation::findIdleOverFive(DoublyLinkedList<int> l){
  int count = 0;
  ListNode<int>* curr = l.front;
  while(curr != NULL){
    if(curr->data > 5)
      count++;
    curr = curr->next;
  }
  return count;
}
