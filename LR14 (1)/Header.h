#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
struct service
{
	char name[35];
	int num_spiv;
	double salary;
	struct service* l;
	struct service* r;
	
};

service* insert(service* root, int num_spiv, double salary, char name[]);
void printtree(service* root);
void зліванаправо(service* root);
void найбільша(service* root, char maxname[], double& maxsalary);
int countEmployees(service* root, char serviceName[]);
void deleteNodeByName(service*& root, const char name[]);
#endif