#include<bits/stdc++.h>
using namespace std;

struct todo
{
	char time[100], task[100];
};

void addTask()
{
    ofstream fileWrite("tasks.txt", ios::app | ios::binary);
    struct todo myTask;
    cout << "Insert task: ";
    cin >> myTask.task;
    cout << "Insert time: ";
    cin >> myTask.time;
 
    fileWrite.write((char *) &myTask, sizeof(myTask));
    cout << "Added!\n";
    fileWrite.close();
}

void showtask()
{
    ifstream fileRead("tasks.txt", ios::in | ios::binary);
    if(!fileRead)
    {
        cout << "Cannot open file\n";
        exit(EXIT_FAILURE);
    }
    struct todo myTask;
    int i = 1;
    while((fileRead.read((char *) &myTask, sizeof(struct todo))) != NULL)
    {
        cout << i++ << ": ";
        cout << myTask.task << endl; 
        cout << "Time: " << myTask.time << endl;
        cout << endl;
    }
    cout << endl;
    fileRead.close();
}

void deleteTask()
{
     
}