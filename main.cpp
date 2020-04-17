#include "GenQueue.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  GenQueue<int> q;
  q.insert(1);
  q.insert(2);
  q.insert(3);
  cout << q.isEmpty() << endl;

  cout << q.remove() << endl;
  cout << q.remove() << endl;
  cout << q.remove() << endl;
  cout << q.isEmpty() << endl;
  return 0;
}
