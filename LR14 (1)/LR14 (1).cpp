// LR14 (1).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    service* root = nullptr;
    char name[35];
    int num_spiv;
    char deletename[35];
    double salary;
    int k;
    char maxname[35]; int i = 0; char servicename[35];
    int numNodes; double maxsalary=0;
    do {
        cout << "Binary Search Tree Menu" << endl;
        cout << "1. Add nodes" << endl;
        cout << "2. Display tree contents" << endl;
        cout << "3. Display tree in left to right order" << endl;
        cout << "4. Display service with the highest salary" << endl;
        cout << "5. Delete node by name" << endl;
        cout << "6. Count employees for a service" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "Enter the number for the binary tree: ";
            cin >> numNodes;

            cin.ignore();

            for (int i = 0; i < numNodes; ++i) {


                cout << "Enter name for node " << i + 1 << ": ";
                cin.getline(name, sizeof(name));
                cout << "Enter num_spiv for node " << i + 1 << ": ";
                cin >> num_spiv;
                cout << "Enter salary for node " << i + 1 << ": ";
                cin >> salary;

                cin.ignore();
                root = insert(root, num_spiv, salary, name);
            }
            break;
        case 2:
            cout << "Contents of the binary search tree:" << endl;
            cout << "Name\t\tnum\tsalary\n";
            printtree(root); break;
        case 3:
            cout << endl << endl;
            cout << "Name\t\tnum\tsalary\n";
            зліванаправо(root); break;
        case 4:
            while (root->name[i] != '\0' && i < 34) {
                maxname[i] = root->name[i];
                i++;
            }
            maxname[i] = '\0';

          
            найбільша(root, maxname, maxsalary);

            cout << "Service with the highest salary: " << maxname << ", Salary: " << maxsalary << endl;
            break;
        case 5:
            cout << "Enter name for del:";
            cin.getline(deletename, sizeof(deletename));
            deleteNodeByName(root, deletename);
            break;
        case 6:
            cout << "Enter name for count:";
            cin.ignore();
            cin.getline(servicename, 35);

            cout << endl << "Count " << servicename<<": " << countEmployees(root, servicename);
            break;
        case 7:break;
        default: break;
        }
    } while (k < 7);
   
    
   
   

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
