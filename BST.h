#include <string>
#include <vector>
#include <fstream>

using namespace std;

// define BST by user
class BSTUser {
public:
	//define item in the BST
	class Node {
	public:
		string key;
		int value;
		Node *parent;
		Node *leftChild;
		Node *rightChild;
		Node(Node* p = NULL, string k = "", int v = 0) {
			key = k;
			value = v;
			parent = p;
			leftChild = rightChild = NULL;
		}
		void empty() {
			if (leftChild != NULL) leftChild->empty();
			if (rightChild != NULL) rightChild->empty();
			delete leftChild;
			delete rightChild;
			leftChild = rightChild = NULL;
		}
	};
	Node * root;
	ofstream fout;
	BSTUser() {
		root = NULL;
	}
	void empty() {
		if (root != NULL) root->empty();
		root = NULL;
	}
	bool find (Node* node, string k, int v);
	bool find(string k, int v);
	bool insert (Node* node, string k, int v);
	bool insert(string k, int v);
	Node* findMin(Node *node);
	Node* findMax(Node *node);
	bool remove(Node *node, string k, int v);
	bool remove(string k, int v);
	void display(Node *node, int mode);
	void display(int mode);
	void save(Node *node, ofstream &fout);
	void save(string filename);
};

// define BST by ticket
class BSTTicket {
public:
	//define item in the BST
	class Node {
	public:
		int key;
		string value;
		Node *parent;
		Node *leftChild;
		Node *rightChild;
		Node(Node* p = NULL, int k = 0, string v = "") {
			key = k;
			value = v;
			parent = p;
			leftChild = rightChild = NULL;
		}
		void empty() {
			if (leftChild != NULL) leftChild->empty();
			if (rightChild != NULL) rightChild->empty();
			delete leftChild;
			delete rightChild;
			leftChild = rightChild = NULL;
		}
	};
	Node * root;
	BSTTicket() {
		root = NULL;
	}
	void empty() {
		if (root != NULL) root->empty();
		root = NULL;
	}
	bool find (Node* node, int k, string v);
	bool find(int k, string v);
	bool insert (Node* node, int k, string v);
	bool insert(int k, string v);
	Node* findMin(Node *node);
	Node* findMax(Node *node);
	bool remove(Node *node, int k, string v);
	bool remove(int k, string v);
	void display(Node *node, int mode, ostream &out);
	void display(int mode);
	void save(Node *node, ofstream &fout);
	void save(string filename);
};
