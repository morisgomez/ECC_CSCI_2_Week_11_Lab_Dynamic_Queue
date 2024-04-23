/*
 Program Name: Dynamic_Queue.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/21/2024
 Version Control: 1.0
 About: Week 11, CSCI 2, Lab.
 Description:
 
 Airport Check-In System Using Dynamic Queues

    This lab assignment involves creating a simulation
    of an airport check-in system using dynamic queues.
    The system will manage passengers checking in at
    various counters (e.g. 3) and process them based on
    the order of arrival. The dynamic queues will be
    implemented in C++, using a linked list to manage
    the data efficiently and simulate real-world
    operations in an airport environment.

 Requirements:
 
 1. Passenger Node Structure: Create a struct called
 PassengerNode that includes details such as name,
 waitTime in minutes, and a pointer next.
 
 2. Check-In Queue Class: Implement a class CheckInQueue
 3. with methods to handle passenger check-ins:

 4. enqueue(string name, int waitTime): Add a passenger to
 the queue, waitTime unit is in minutes.

 5. dequeue(): Process and remove a passenger from the
 queue, returning the passenger's details.
 
 6. peek(): View the next passenger in the queue without
 removing them.
 
 7. isEmpty(): Check if the queue is empty.

 8. displayQueue(): Display all passengers in the queue.

 Simulation Environment:
 
 1. Multiple check-in counters (assume 3), each with its
 own queue.

 2. Simulate passenger arrivals and check-ins.
 Reporting: At the end of the simulation, generate a
 report that includes:

 3. Total number of passengers processed.
 4. Average waiting time in minutes.
*/

#include <iostream>
#include <string>

using namespace std;

class DynamicQueue
{
private:
    struct PassengerNode
    {
        string name;
        int waitTime;
        PassengerNode *next;
    }; //end struct Node
    
    PassengerNode *rear;
    PassengerNode *front;
    int numPassengers;
    int numPassengersProcessed;
    
public:
//constructor:
    DynamicQueue()
    {
        front = NULL;
        rear = NULL;
        numPassengers = 0;
        numPassengersProcessed = 0;
    }
    
//destructor:
    ~DynamicQueue()
    {
        clear();
    }
    
//function 1: enqueue().
    void enqueue(string nam, int tim)
    {
        PassengerNode *n = new PassengerNode;
        n->name = nam;
        n->waitTime = tim;
        n->next = NULL;
        if(isEmpty()) //special case: queue is empty.
        {
            front = n;
            rear = n;
        }
        else //non-special case: not empty.
        {
            rear->next = n;
            rear = n;
        }
        numPassengers++;
    } //end enqueue() function.
    
//function 2: dequeue()
    string dequeue(string &nam)
    {
        PassengerNode *temp;
        if(isEmpty()) //if queue is empty.
        {
            cout << "Check-in line is empty!" << endl;
            return "Check-in line is empty!";
        }
        else //else not empty.
        {
            if(numPassengers == 1) //special case: 1 element in queue.
            {
                nam = front->name;
                delete front;
                rear = NULL;
                numPassengers--;
                numPassengersProcessed++;
                return nam;
            }
            else //else more than 1 element in queue.
            {
                nam = front->name;
                temp = front;
                front = front->next;
                delete temp;
                numPassengers--;
                numPassengersProcessed++;
                return nam;
            } //close inner else.
        } //close outer else.
    } //end dequeue() function.
    
//function 3: display()
    void displayQueue()
    {
        int tracker = 1;
        PassengerNode *current = front;
        if(isEmpty())
        {
            cout << "Check-in line is empty!" << endl;
        }
        else
        {
            while(current != NULL)
            {
                cout << "Passenger " << tracker << ":" << endl;
                cout << "Name: " << current->name << endl;
                cout << "Wait Time: " << current->waitTime << " minutes" << endl << endl;
                tracker++;
                current = current->next;
            } //close while loop.
        } //close else.
    } //end display() function.
    
//function 4: isEmpty()
    bool isEmpty()
    {
        if(numPassengers> 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    } //end isEmpty() function.
    
//function 5: clear()
    void clear()
    {
        string value;
        while(!isEmpty())
        {
            dequeue(value);
        } //close while loop.
    } //end clear() function.

//function 6: peek()
    //no return value, simply cout front value.
    void peek()
    {
        if(isEmpty())
        {
            cout << "Check-in line is empty!" << endl;
        }
        else
        {
            cout << "Peeking at next passenger in line:" << endl;
            cout << "Name: " << front->name << endl;
            cout << "Wait Time: " << front->waitTime << " minutes" << endl;
        }
    } //end peek() function.

//function 7: average()
    double average()
    {
        double aver = 0.0;
        PassengerNode *current = front;
        if(isEmpty())
        {
            cout << "Check-in line is empty!" << endl;
        }
        else
        {
            while(current != NULL)
            {
                aver = aver + current->waitTime;
                current = current->next;
            } //close while loop.
        } //close else.
        return aver / numPassengers;
    } //end average() function.

//function 8: getNumPassengers()
    int getNumPassengers()
    {
        return numPassengers;
    } //end getNumPassengers() function.

//function 9: getNumPassengersProcessed()
    int getNumPassengersProcessed()
    {
        return numPassengersProcessed;
    } //end getNumPassengersProcessed() function.
}; //end class Dynamic Queue.


int main()
{
//CREATE: Check-in Counter #1
    cout << "COUNTER #1:" << endl;
    //1. create an object of DynamicQueue class:
    DynamicQueue qOne;
    
    //2. enqueue some Nodes to qOne:
    qOne.enqueue("Moris", 5);
    qOne.enqueue("Ash", 10);
    qOne.enqueue("Irma", 15);
    qOne.enqueue("Carlos", 20);
    
    //3. display Nodes in qOne:
    qOne.displayQueue();
    cout << "-----" << endl << endl;
    
    //3.5 get average:
    double av1 = qOne.average();
    
    //4. dequeue(process) some passengers:
    string a;
    string b;
    string c;
    string d;
    qOne.dequeue(a);
    qOne.dequeue(b);
    qOne.dequeue(c);
    qOne.dequeue(d);
    
//CREATE: Check-in Counter #2:
    cout << "COUNTER #2:" << endl;
    //1. create an object of DynamicQueue class:
    DynamicQueue qTwo;
    
    //2. enqueue some Nodes to qOne:
    qTwo.enqueue("Andrew", 3);
    qTwo.enqueue("Milo", 6);
    qTwo.enqueue("Anthony", 9);
    qTwo.enqueue("Jussiel", 12);
    
    //3. display Nodes in qOne:
    qTwo.displayQueue();
    cout << "-----" << endl << endl;
    
    //3.5 get average:
    double av2 = qTwo.average(); //gets average of all enqueued times.
    //4. dequeue(process) some passengers:
    string e;
    string f;
    string g;
    string h;
    qTwo.dequeue(e);
    qTwo.dequeue(f);
    qTwo.dequeue(g);
    qTwo.dequeue(h);
    
//CREATE: Check-in Counter #3:
    cout << "COUNTER #3:" << endl;
    //1. create an object of DynamicQueue class:
    DynamicQueue qThree;
    
    //2. enqueue some Nodes to qOne:
    qThree.enqueue("Luis", 2);
    qThree.enqueue("Ruben", 4);
    qThree.enqueue("Lola", 6);
    qThree.enqueue("Payton", 8);
    
    //3. display Nodes in qOne:
    qThree.displayQueue();
    cout << "-----------" << endl << endl;
    
    //3.5 get average:
    double av3 = qThree.average(); //gets average of all enqueued times.
    
    //4. dequeue(process) some passengers:
    string i;
    string j;
    string k;
    string l;
    qThree.dequeue(i);
    qThree.dequeue(j);
    qThree.dequeue(k);
    qThree.dequeue(l);

//FINAL REPORT: Check-in Counter #1:
    cout << "FINAL REPORT FOR COUNTER #1:" << endl;
    cout << "Total # of passengers processed: " << qOne.getNumPassengersProcessed() << endl;
    cout << "Total average waiting time for all passengers: " << av1 << " minutes." << endl;
    cout << "-----------" << endl << endl;
    
//FINAL REPORT: Check-in Counter #2:
    cout << "FINAL REPORT FOR COUNTER #2:" << endl;
    cout << "Total # of passengers: " << qTwo.getNumPassengersProcessed() << endl;
    //cout only 4 processed because we did not dequeue all.
    //average is based on total passengers in line at start. so average of 5 not 4 (processed).
    cout << "Total average waiting time for all passengers: " << av2 << " minutes." << endl;
    cout << "-----------" << endl << endl;
    
//FINAL REPORT: Check-in Counter #3:
    cout << "FINAL REPORT FOR COUNTER #3:" << endl;
    cout << "Total # of passengers processed: " << qThree.getNumPassengersProcessed() << endl;
    cout << "Total average waiting time for all passengers: " << av3 << " minutes." << endl;
    cout << "-----------" << endl << endl;
    return 0;
}
