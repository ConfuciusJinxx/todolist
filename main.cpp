#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void checktasks(const vector<string>& tasks)
{
    for (int i = 0; i < tasks.size();++i)
    {
        cout << i + 1 << "." << tasks[i];
        cout << endl;
    }
}

int main()
{
    vector<string>tasks;
    string task;
    char choice;

    ifstream Inputfile("todolist.txt");
    while (getline(Inputfile, task))
    {
        tasks.push_back(task);
    }
    Inputfile.close();

    do
    {
        cout << "A - to add a task." << endl;
        cout << "V - to view tasks."<< endl;
        cout << "Q - to quit program."<< endl;
        cout << endl;
        cin >> choice;
        
        switch (choice)
        {
        case 'A':
        case 'a':
            cout << "Enter a task:";
            cin.ignore();
            getline(cin, task);
            tasks.push_back(task);
            break;
        case 'V':
        case 'v':
            checktasks(tasks);
            break;
        }
    } while (choice != 'q' && choice != 'Q');
    ofstream output("todolist.txt");
    for (const auto v1 : tasks)
    {
        output << v1 << endl;
    }
    output.close();
}