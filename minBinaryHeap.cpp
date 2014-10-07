/****************************************************
    Names       : Geoffrey Morris & Jeffrey Allen
    Date        : CS420 Spring 2014
    Assignment  : Assignment 11, Group 3
    Description : 
    Due Date: November 20, 2012
*****************************************************/

#include "minBinaryHeap.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
minBinaryHeap::minBinaryHeap() {

	numberOfItems = 0;
	heap.resize(1);

	heap[0] = NULL;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : Desired size of new heap
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
minBinaryHeap::minBinaryHeap(int size) {

	numberOfItems = 0;

  // resize parm description: (size, value)
	heap.resize(size, NULL);

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Overloaded construcor (For copy constructor)
  Incoming : The address of the minBinaryHeap heap to wanted to be copy from
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// minBinaryHeap::minBinaryHeap(minBinaryHeap& otherHeap) {

//   	numberOfItems = otherHeap.getNumberOfItems();

//     // clear my heap
//     heap.clear();

//     // resize my heap to the size of the other heap
//     heap.resize(otherHeap.getHeap().getNumberOfItems());

//     // assign the values of the other heap to my heap
//     for (int i=0; i<otherHeap.size(); i++)
//       heap[i] = otherHeap.getHeap()[i];

// }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Destructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
minBinaryHeap::~minBinaryHeap() {

	// clear method removes & destroys all
	// elements in a container
	heap.clear();

	numberOfItems = 0;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int minBinaryHeap::getParent(int index) {

  // There ain't no parent above the root
  if (index == 0)
    return 0;
  
  return (index - 1) / 2;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int minBinaryHeap::getLeftChild(int index) {

  return (index * 2) + 1;

}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int minBinaryHeap::getRightChild(int index) {

  return (index * 2) + 2;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Recursive function which moves the specified
             index down to the correct position while
             keeping the heap property of the tree
  Incoming : Index of position where hole is in tree
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void minBinaryHeap::percolateDown(int index) {

  int leftChild, rightChild, minimum;

  // Get children of job in the queue
  leftChild = getLeftChild(index);
  rightChild = getRightChild(index);

  // Failsafes
  if (rightChild >= numberOfItems) {

    if (leftChild >= numberOfItems)
      return;

    else
      minimum = leftChild;

  }

  // Finds the minimum child based on priority level
  else {

    if (heap[leftChild]->getPriorityLevel() <= heap[rightChild]->getPriorityLevel())
      minimum = leftChild;
    else
      minimum = rightChild;

  }

  // Swap and percolate down to keep heap order
  if (heap[index]->getPriorityLevel() > heap[minimum]->getPriorityLevel()) {

    Job* temp;

    temp = heap[index];
    heap[index] = heap[minimum];
    heap[minimum] = temp;

    percolateDown(minimum);

  }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Job* minBinaryHeap::getMin() {

  if (isEmpty())
    return 0;

  // copy root
  Job* minimum = heap[0];

  // Instantiate place where I want to start the percolation process
  int index = 0;

  // Move the last node in the heap to the top root and reduce the num of items
  heap[0] = heap[numberOfItems - 1];
  heap[numberOfItems - 1] = 0;
  numberOfItems--;

  // percolate the last node down the tree
  if (numberOfItems > 0)
      percolateDown(index);

  return minimum;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void minBinaryHeap::checkMin(){}
//void minBinaryHeap::insert(T* anything){}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void minBinaryHeap::sort() {



}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool minBinaryHeap::isEmpty() { 

  if (numberOfItems < 1)
    return true;
  return false;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int minBinaryHeap::getNumberOfItems() {

  return numberOfItems;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
vector<Job *> minBinaryHeap::getHeap() {

  return heap;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void minBinaryHeap::insertJob(Job * newJob) {

  // If heap is empty
  if (isEmpty()) {

    heap.resize(1);
    heap[0] = newJob;
    numberOfItems = 1;

    return;

  }

  // Increase size of heap if last job doesn't exist
  if (heap[heap.size() - 1] != NULL)
    heap.resize(heap.size() + 1, 0);

  numberOfItems = numberOfItems + 1;

  int indexOfLastJob = heap.size() - 1;

  // Put the job in the newly created last spot
  heap[indexOfLastJob] = newJob;

  // BEGINNNNN PERCOLATION UPWARRRRDS!
  int parentIndex = 0;
  Job * temp;

  // While the parent node's priority is less than current, keep swappin
  // indexOfParent job gets changed quite often here
  while ((heap[getParent(indexOfLastJob)]->getPriorityLevel() > newJob->priorityLevel) && (indexOfLastJob != 0)) {

    parentIndex = getParent(indexOfLastJob);
    temp = heap[indexOfLastJob];
    heap[indexOfLastJob] = heap[parentIndex];
    heap[parentIndex] = temp;

    indexOfLastJob = getParent(indexOfLastJob);
  
  }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void minBinaryHeap::print() {

    for (int i = 0; i<numberOfItems; i++)
      cout << "Job " << i << ": " << heap[i]->name << "\t Priority: " << heap[i]->priorityLevel << endl;

}