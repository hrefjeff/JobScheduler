/****************************************************
    Names       : Geoffrey Morris & Jeffrey Allen
    Date        : CS420 Spring 2014
    Assignment  : Assignment 11, Group 3
    Description : 
    Due Date: November 20, 2012
*****************************************************/

#ifndef _JOB_H
#define _JOB_H

#include <iostream>
#include <string>
using namespace std;

//template <class T>
class Job { //friend class PriorityQueue;

public:
	
    string name;
	int priorityLevel;

//public:
	
//    T* data;
    Job();
    Job(string, int);
    ~Job();
    int getPriorityLevel();

    //Job<T>* next;     // Took out because jobs don't point to other jobs
    //Job(T e, Node* n);// Again, no job points to other job
    //template <class T1> friend class LinkedList;
    //friend ostream& operator<< <>(ostream& os, const LinkedList<T>& l);
    
};

#endif