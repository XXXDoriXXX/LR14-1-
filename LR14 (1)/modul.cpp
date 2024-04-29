#include "Header.h";
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
service* insert(service* root, int num_spiv, double salary, char name[])
{
    if (root == NULL) {
        service* newtre = new service;
        for (int i = 0; i < 35; i++) {
            newtre->name[i] = name[i];
        }
        newtre->num_spiv = num_spiv;
        newtre->salary = salary;
        newtre->l = NULL;
        newtre->r = NULL;
        return newtre; 
    }
    if (root->name[0] > name[0]) {
        root->l = insert(root->l, num_spiv, salary, name);
    }
    else {
        root->r = insert(root->r, num_spiv, salary, name);
    }
    return root; 
}

void printtree(service* root) {
    if (root != NULL) {
        cout << root->name << "\t\t" << root->num_spiv << "\t" << root->salary << endl;
        printtree(root->l);
        printtree(root->r);
    }
    else return;
}
void зліванаправо(service* root) {
    if (root != NULL) {
        printtree(root->l);
        cout << root->name << "\t\t" << root->num_spiv << "\t" << root->salary << endl;
        printtree(root->r);
    }
    else return;
}
void найбільша(service* root,char maxname[], double& maxsalary) {
    if (root == NULL) {
        return;
    }
    найбільша(root->l,maxname,maxsalary);
    if (root->salary > maxsalary) {
        maxsalary = root->salary;
        int i = 0;
        while (root->name[i] != '\0' && i < 34) {
            maxname[i] = root->name[i];
            i++;
        }
        maxname[i] = '\0';
    }
    найбільша(root->r, maxname, maxsalary);
}
int countEmployees(service* root, char serviceName[]) {
    if (root == NULL) return 0;

    if (strcmp(serviceName, root->name) < 0)
        return countEmployees(root->l, serviceName);
    else if (strcmp(serviceName, root->name) > 0)
        return countEmployees(root->r, serviceName);
    else {
        // Current service matches the specified service name
        int count = root->num_spiv;
        // Recursively count employees in left and right subtrees
        count += countEmployees(root->l, serviceName);
        count += countEmployees(root->r, serviceName);
        return count;
    }
}


void deleteNodeByName(service*& root, const char name[]) {
    service* parent = nullptr;
    service* curr = root;
    while (curr != nullptr && strcmp(curr->name, name) != 0) {
        parent = curr;
        if (strcmp(name, curr->name) < 0) {
            curr = curr->l;
        }
        else {
            curr = curr->r;
        }
    }
    if (curr == nullptr) {
        return;
    }

    if (curr->l == nullptr && curr->r == nullptr) {
        if (curr != root) {
            if (parent->l == curr) {
                parent->l = nullptr;
            }
            else {
                parent->r = nullptr;
            }
        }
        else {
            root = nullptr;
        }
        delete curr;
    }
    else if (curr->l != nullptr || curr->r != nullptr) {
        service* child = (curr->l != nullptr) ? curr->l : curr->r;
        if (curr != root) {
            if (curr == parent->l) {
                parent->l = child;
            }
            else {
                parent->r = child;
            }
        }
        else {
            root = child;
        }
        delete curr;
    }
    else {
        service* successorParent = curr;
        service* successor = curr->r;
        while (successor->l != nullptr) {
            successorParent = successor;
            successor = successor->l;
        }
        curr->num_spiv = successor->num_spiv;
        curr->salary = successor->salary;
        if (successorParent->l == successor) {
            successorParent->l = successor->r;
        }
        else {
            successorParent->r = successor->r;
        }
        delete successor;
    }
}

























