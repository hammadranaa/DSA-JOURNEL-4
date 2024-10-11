#include<iostream>
using namespace std;

class node {
private:
	int val;
	node* next;

public:
	node(int);
	node();
	int get_val();
	void set_val(int);
	void set_next(node*);
	node* get_next();




};