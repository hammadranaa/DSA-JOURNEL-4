#include"node.h"



node::node()
{
	val = 0;
	next = NULL;



}

node::node(int a)
{
	val = a;
	next = NULL;



}


int node::get_val() {

	return val;
}


void node::set_val(int a) {

	this->val = a;


}

void node::set_next(node* n) {

	this->next = n;

}

node* node::get_next() {
	return next;
}
