#include "CList.h"

CList::CList() {
	head = NULL;
}

bool CList::emptyList() {
	return head == NULL; // Simplified check
}

void CList::insertafter(int old, int New) {
	node* current = head; // Points to the current node

	if (head == NULL) {
		// If the list is empty, create a new node and point it to itself
		head = new node(old);
		head->set_next(head); // Circular link
	}

	do {
		if (current->get_val() == old) {
			node* Newnode = new node(New);
			Newnode->set_next(current->get_next());
			current->set_next(Newnode);
			return; // Exit after inserting
		}
		current = current->get_next();
	} while (current != head); // Loop until we come back to head

	// If we didn't find old, we can add the new node at the end
	node* Newnode = new node(New);
	current->set_next(Newnode);
	Newnode->set_next(head); // Complete the circular link
}


void CList::deleteNode(int pos) {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	if (pos == 0) {
		cout << "Cannot delete the first node" << endl;
		return; // Restrict deletion of the first node
	}

	node* current = head;
	node* prev = nullptr;
	int index = 0;

	// Traverse the circular list until the position is reached
	do {
		if (index == pos) {
			if (prev != nullptr) {
				prev->set_next(current->get_next());
			}

			// Handle deletion of the current node
			delete current;
			return; // Exit after deletion
		}

		prev = current;
		current = current->get_next();
		index++;
	} while (current != head);

	cout << "Position: " << pos << " not found in the list" << endl;
}

void CList::delete_begin() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return; // Return to avoid further operations
	}

	if (head->get_next() == head) {
		// Only one node in the list
		delete head;
		head = NULL; // Now the list is empty
	}
	else {
		// More than one node
		node* temp = head;
		// Find the last node to update its next pointer
		node* tail = head;
		while (tail->get_next() != head) {
			tail = tail->get_next();
		}
		head = head->get_next(); // Move head to the next node
		tail->set_next(head); // Update last node's next to new head
		delete temp; // Delete old head
	}
}

void CList::delete_end() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return; // Return to avoid further operations
	}

	if (head->get_next() == head) {
		// Only one node in the list
		delete head;
		head = NULL; // Now the list is empty
		return;
	}

	node* current = head;
	node* prev = NULL;

	// Traverse to find the last node
	while (current->get_next() != head) {
		prev = current;
		current = current->get_next();
	}

	// Now `current` is the last node
	prev->set_next(head); // Update previous node's next to head
	delete current; // Delete the last node
}





void CList::insert_begin(int value) {
	node* Newnode = new node(value);
	if (head == NULL) {
		head = Newnode;
		head->set_next(head); // Circular link
	}
	else {
		node* tail = head;
		while (tail->get_next() != head) {
			tail = tail->get_next();
		}
		tail->set_next(Newnode); // Previous last node points to new node
		Newnode->set_next(head); // New node points to the head
		head = Newnode; // Update head to the new node
	}
}

void CList::insert_end(int value) {
	node* Newnode = new node(value);
	if (head == NULL) {
		head = Newnode;
		head->set_next(head); // Circular link
	}
	else {
		node* current = head;
		while (current->get_next() != head) {
			current = current->get_next();
		}
		current->set_next(Newnode);
		Newnode->set_next(head); // New node points to head
	}
}

void CList::traverse() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	node* current = head;
	do {
		cout << current->get_val() << endl;
		current = current->get_next();
	} while (current != head);
	cout << endl;
}

int main() {
	CList* a = new CList;
	a->insert_begin(1);
	a->insert_begin(2);
	a->insert_end(3);
	a->insert_end(4);


	cout << "Node:\n";
	a->traverse();

	cout << "deleat begin:\n";
	a->delete_begin();
	a->traverse();

	cout << "deleat end:\n";
	a->delete_end();
	a->traverse();



}