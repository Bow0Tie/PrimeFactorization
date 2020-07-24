#include <iostream> 
using namespace std;
int i;
template <class T> class BinaryTree {

public:
	BinaryTree() {
	}
	struct  binaryTree {
		int key;
		T data;
		binaryTree *binaryLeft;
		binaryTree *binaryRight;
	};
	binaryTree *root;//Корень
	void summarize(BinaryTree &added) {
		void (BinaryTree::*ptrAddAlienElem)(binaryTree*) = &BinaryTree::addAlienElem;
		goLtR(added.root, ptrAddAlienElem);
	}
	void deleteALL() {
		clear(root);
	}
	T find(int key) {
		binaryTree* previous = root;
		while (true) {
			if (previous == nullptr) {
				cout << "Ничего тут нет" << endl;
				return NULL;
			}
			if (key > (previous->key)) {
				previous = previous->binaryRight;
			}
			if (key < (previous->key))
			{
				previous = previous->binaryLeft;
			}
			if (key == (previous->key))
			{
				return previous->data;
			}
		}
	}
private:
	void printIt(binaryTree* current) {
		cout << "Index:" << current->key << endl << "Element:" << current->data << endl;
		
	}
	void  addAlienElem(binaryTree* current) {
		insert(current->key, current->data);
	}
public:
	void printAll() {
		
		void (BinaryTree::*ptrPrint)(binaryTree*) = &BinaryTree::printIt;
		goLtR(root, ptrPrint);
	}
	void insert(int key, T data) {
		binaryTree* previous = root;
		while (true) {
			if (previous == nullptr) {
				root = create_node(key, data);
				return;
			}
			if (key > (previous->key)) {
				if (previous->binaryRight == nullptr) {
					previous->binaryRight = create_node(key, data);
					return;
				}
				previous = previous->binaryRight;
			}
			if (key < (previous->key))
			{
				if (previous->binaryLeft == nullptr)
				{
					previous->binaryLeft = create_node(key, data);
					return;
				}
				previous = previous->binaryLeft;
			}
			if (key == (previous->key))
			{
				cout << "This element already exists" << endl;
				return;
			}
		}
	}
	void deleteElem(int key) {
		bool delEl = false;
		binaryTree* current;
		i = 0;
		current = root;
		current = del(root, key, delEl);
		if (i == 0)
		{
			root = current;
		}
	}
private:
	void goLtR(binaryTree* node, void (BinaryTree::*funk)(binaryTree*)) {
		if (node != nullptr) {
			goLtR(node->binaryLeft, funk);
			(this->*funk)(node);
			goLtR(node->binaryRight, funk);
		}
	}
	void clear(binaryTree* node) {
		if (node != nullptr) {
			clear(node->binaryLeft);
			clear(node->binaryRight);
			node = nullptr;
		}
	}


	binaryTree* create_node(int key, T data) {
		binaryTree* current = new binaryTree();
		current->key = key;
		current->data = data;
		return current;
	}
	binaryTree* del(binaryTree* previous, int key, bool &deleted) {
		bool dell;
		if (previous == nullptr)
		{
			deleted = false;
			i++;
			return(previous);
		}
		if (key < previous->key)
		{
			previous->binaryLeft = del(previous->binaryLeft, key, dell);
			deleted = dell;
			i++;
			return(previous);
		}
		if (key > previous->key)
		{
			previous->binaryRight = del(previous->binaryRight, key, dell);
			deleted = dell;
			i++;
			return(previous);
		}
		if (previous->binaryRight == nullptr && previous->binaryLeft == nullptr)
		{
			delete previous;
			deleted = true;
			return(nullptr);
		}
		if (previous->binaryLeft == nullptr)
		{
			binaryTree *x = previous->binaryRight;
			delete previous;
			deleted = true;
			return(x);
		}
		if (previous->binaryRight == nullptr)
		{
			binaryTree *x = previous->binaryLeft;
			delete previous;
			deleted = true;
			return(x);
		}
		previous->binaryRight = supp_del(previous->binaryRight, previous);
		deleted = true;
		return(previous);
	}
	binaryTree* supp_del(binaryTree* gde_ishem, binaryTree* save)
	{
		if (gde_ishem->binaryLeft != nullptr)
		{
			gde_ishem->binaryLeft = supp_del(gde_ishem->binaryLeft, save);
			return(gde_ishem);
		}
		save->key = gde_ishem->key;
		save->data = gde_ishem->data;
		binaryTree *x = gde_ishem->binaryRight;
		delete gde_ishem;
		return(x);
	}
};