
#include"node.h"

/**
 * @brief A class representing a singly linked list.
 */
class CList
{
private:
	node* head; ///< Pointer to the head of the list.

public:
	/**
	 * @brief Constructs an empty linked list.
	 */
	CList();

	/**
	 * @brief Checks if the list is empty.
	 * @return True if the list is empty, false otherwise.
	 */
	bool emptyList();

	/**
	 * @brief Inserts a new value after a specified old value.
	 * @param oldV The value after which the new value will be inserted.
	 * @param newV The new value to be inserted.
	 */
	void insertafter(int oldV, int newV);

	/**
	 * @brief Inserts a value at the beginning of the list.
	 * @param value The value to be inserted at the beginning.
	 */
	void insert_begin(int value);

	/**
	 * @brief Inserts a value at the end of the list.
	 * @param value The value to be inserted at the end.
	 */
	void insert_end(int value);

	/**
	 * @brief Deletes the first node with the specified value.
	 * @param value The value of the node to be deleted.
	 */
	void deleteNode(int pos);

	/**
	 * @brief Deletes the first node from the beginning of the list.
	 */
	void delete_begin();

	/**
	 * @brief Deletes the last node from the end of the list.
	 */
	void delete_end();

	/**
	 * @brief Traverses and prints the values in the list.
	 */
	void traverse();
};




