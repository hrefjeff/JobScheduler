#include "job.h"
#include "minBinaryHeap.h"
#include <vector>
#include <string>
using namespace std;

int main () {
	
	//vector<Job *> PriorityQueue;
	minBinaryHeap PriorityQueue;

	PriorityQueue.insertJob(new Job("pr0n", 2));
	PriorityQueue.insertJob(new Job("Print", 0));
	PriorityQueue.insertJob(new Job("test", 1));
	PriorityQueue.insertJob(new Job("google", 0));

	cout << "Number of elements in PriorityQueue: " << PriorityQueue.getNumberOfItems() << endl;

	PriorityQueue.print();

	return 0;
}