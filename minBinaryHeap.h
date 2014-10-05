/****************************************************
    Names       : Geoffrey Morris & Jeffrey Allen
    Date        : CS420 Spring 2014
    Assignment  : Assignment 11, Group 3
    Description : 
    Due Date: November 20, 2012
*****************************************************/

#ifndef _MINBINARYHEAP_H
#define _MINBINARYHEAP_H

template <class T>
class minBinaryHeap {
private:

	// Array of pointers to <instert anything here>
	vector<T *> heap;
	int numberOfItems;

	int getParent(int index);
	int getLeftChild(int index);
	int getRightChild(int index);
	void percolateDown(int index);

public:

	minBinaryHeap();
	minBinaryHeap(int size);
	minBinaryHeap(minBinaryHeap& heap);  // For copy constructor
	~minBinaryHeap();

	T* getMin();
	void checkMin();
	void insert(T* anything);
	void sort();
	bool isEmpty();

	// getters
	int  getNumberOfItems();
	vector<T *> getHeap();

	// setters

	void print();

};


#endif