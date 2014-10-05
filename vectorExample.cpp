#include "job.h"
#include <vector>
#include <string>
using namespace std;

int main () {
	
	vector<Job *> queue;

	queue.push_back(new Job("pr0n", 1));
	queue.push_back(new Job("Print", 5));
	queue.push_back(new Job("test", 0));

	cout << "Number of elements in queue: " << queue.size() << endl;

	for (int i = 0; i<queue.size(); i++)
		cout << "Job " << i << ": " << queue[i]->name << "=== Priority: " << queue[i]->priorityLevel << endl;

	queue.clear();

	return 0;
}