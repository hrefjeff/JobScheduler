#include "job.h"
#include "minBinaryHeap.h"
#include <vector>
#include <string>
using namespace std;

int main () {
	
	minBinaryHeap PriorityQueue;

	PriorityQueue.insertJob(new Job("ls", 2));
	PriorityQueue.insertJob(new Job("Print", 0));
	PriorityQueue.insertJob(new Job("test", 1));
	PriorityQueue.insertJob(new Job("google", 0));

	cout << "Number of elements in PriorityQueue: " << PriorityQueue.getNumberOfItems() << endl;

	PriorityQueue.print();

	cout << "**********POPPED THE MINIMUM I'M SWEATIN! WHOOO!**********" << endl; 
	cout << "Popped:" << PriorityQueue.getMin()->name << endl;
	cout << "**********************************************************" << endl;

	PriorityQueue.print();

		cout << "**********POPPED THE MINIMUM I'M SWEATIN! WHOOO!**********" << endl; 
	cout << "Popped:" << PriorityQueue.getMin()->name << endl;
	cout << "**********************************************************" << endl;

	PriorityQueue.print();


	return 0;
}