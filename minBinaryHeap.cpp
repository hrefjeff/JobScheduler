/****************************************************
    Names       : Geoffrey Morris & Jeffrey Allen
    Date        : CS420 Spring 2014
    Assignment  : Assignment 11, Group 3
    Description : 
    Due Date: November 20, 2012
*****************************************************/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Constructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
minBinaryHeap() {

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
minBinaryHeap(int size) {

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
minBinaryHeap(minBinaryHeap& otherHeap) {

  	numberOfItems = otherHeap.getNumberOfItems();

    // clear my heap
    heap.clear();

    // resize my heap to the size of the other heap
    heap.resize(otherHeap.getHeap().size());

    // assign the values of the other heap to my heap
    for (int i=0; i<otherHeap.size(); i++)
      heap[i] = otherHeap.getHeap()[i];

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Writer(s): Jeffrey Allen
  Purpose  : Destructor for minBinaryHeap
  Incoming : N/A
  Outgoing : N/A
  Return   : N/A
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
~minBinaryHeap() {

	// clear method removes & destroys all
	// elements in a container
	heap.clear();

	numberOfItems = 0;

}

int getParent(int index) {


}

int getLeftChild(int index){}
int getRightChild(int index){}

void percolateDown(int index){}

T* getMin(){}
void checkMin(){}
void insert(T* anything){}
void sort(){}
bool isEmpty(){}

//T& getHeapValue();

void print(){}