#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>


#define ll long long
#define ld long double

using namespace std;

vector<string> tasks;

void save_tasks_to_file() {
    ofstream file("C:/Users/user/OneDrive/Desktop/programing/VS Projects/progect1_todo_list/tasks.txt");
    for (const auto& task : tasks) {
        file << task << endl;
    }
    file.close();
}

void load_tasks_from_file() {
    ifstream file("C:/Users/user/OneDrive/Desktop/programing/VS Projects/progect1_todo_list/tasks.txt");
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();
}

void fastIO(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



void Add_task() {
    string task;
    string more;
    do
    {
        cout << "enter the task : ";
        cin.ignore(1, '\n');
        getline(cin, task);

        tasks.push_back(task);
        save_tasks_to_file();
        cout << "do you what to add more tasks ? (y/n) ";
        cin >> more;
    } while (more == "y");

    cout << endl << endl;
}

void show_tasks()
{
    if (tasks.size() == 0)
    {
        cout << "your list is empty !" << endl << endl;
        return;
    }

    cout << "Your tasks :" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << " . " << tasks[i] << '.' << endl;
    }
    cout << "------------------------------------------------------------------" << endl;

    cout << endl << endl;
}

void search_on_task()
{
    if (tasks.size() == 0)
    {
        cout << "your list is empty !" << endl << endl;
        return;
    }

    string str;
    cout << "enter the string you want to search on : ";
    cin.ignore(1, '\n');
    getline(cin, str);


    bool flag = 0;

    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].find(str) != string::npos)
        {
            cout << i + 1 << " . " << tasks[i] << endl << endl;
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        cout << "sorry, task not found :-(" << endl << endl;
    }


}

void Delete_task()
{
    if (tasks.size() == 0)
    {
        cout << "your list is empty !" << endl << endl;
        return;
    }

    int order; 
    cout << "enter the id/order of the task you want to delete from your list : ";
    cin >> order;

    if (order > tasks.size())
    {
        cout << "the element is not available" << endl << endl;
        return;
    }

    char sure;
    cout << "are you sure to delete this task from your list ? (y/n) ";
    cin >> sure;


    if (sure == 'y')
    {
        tasks.erase(tasks.begin() + order - 1);
        save_tasks_to_file();
        cout << "The task has been deleted successfully" << endl << endl;
    }


}

void update_task()
{
    if (tasks.size() == 0)
    {
        cout << "your list is empty !" << endl << endl;
        return;
    }

    int order;
    cout << "enter the order of the task : ";
    cin >> order;

    if (order > tasks.size())
    {
        cout << "the element is not available" << endl << endl;
        return;
    }

    string done = "(Done)";
    string not_done = "(Not done)";

    char mark;
    cout << "mark as done or not done ? (d/n) ";
    cin >> mark;

    if (mark == 'd')
    {
        tasks[order - 1] += done;
        save_tasks_to_file();
    }
    else if (mark == 'n')
    {
        tasks[order - 1] += not_done;
        save_tasks_to_file();
    }

    cout << "marked successfully" << endl << endl;


}

void clear_list() {
    if (tasks.empty())
    {
        cout << "list is already empty" << endl << endl;
    }
    else
    {
        cout << "are you sure ? (y/n) ";
        char ans; cin >> ans;
        if (ans == 'y')
        {
            tasks.clear();
            save_tasks_to_file();
            cout << "list has been cleared successfully" << endl << endl;
        }
        else
        {
            return;
        }
    }
}


void banner()
{
    cout << "----------------" << endl;
    cout << "     My list    " << endl;
    cout << "----------------" << endl;
    
}

short take_choice()  // taking the choice from user and return it
{

    cout << endl;
    short int choice;
    cout << "1. Add Task." << endl;
    cout << "2. Show Tasks." << endl;
    cout << "3. Search On Task." << endl;
    cout << "4. Delete Task." << endl;
    cout << "5. Update/mark task." << endl;
    cout << "6. Clear list." << endl;
    cout << "7. Exit." << endl;
    
    cout << "ENTER YOUR CHOICE'S NUMBER : ";
    cin >> choice;

    return choice;
}

void perform_choice(short choice) {

    bool flag = 0;
    
    while (!flag)
    {
        
        if (choice == 1)
        {
            Add_task();
            flag = 1;
        }
        else if (choice == 2)
        {
            show_tasks();
            flag = 1;
        }
        else if (choice == 3)
        {
            search_on_task();
            flag = 1;
        }
        else if (choice == 4)
        {
            Delete_task();
            flag = 1;
        }
        else if (choice == 5)
        {
            update_task();
            flag = 1;
        }
        else if (choice == 6)
        {
            clear_list();
            flag = 1;
        }
        else
        {
            flag = 1;
            cout << "wrong operation, please try again : " << endl << endl;
            perform_choice(take_choice());
        }
    }
    
    
}





signed main()
{

    fastIO();
    
    load_tasks_from_file();
    
    banner();

    while (true)
    {
        short int choice = take_choice();
        if (choice != 7)
        {
            string ans;
            perform_choice(choice);
            cout << "want to make more operations ? (y/n) ";
            cin >> ans;

            if (ans == "y")
            {
                continue;
            }
            else
            {
                cout << "Good bye !" << endl << endl;
                return 0;
            }
        }
        else
        {
            cout << "Good bye !" << endl << endl;
            return 0;
        }
    }


    save_tasks_to_file();

    


}


