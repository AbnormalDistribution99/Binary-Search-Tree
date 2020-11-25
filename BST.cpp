#include "BST.h"
#include <iostream>

using namespace std;

bool BSTUser::find (Node* node, string k, int v) {
	if (node == NULL) return false;
	if (k == node->key && v == node->value) return true;
	if (k < node->key || (k == node->key && v < node->value)) {
		if (node->leftChild == NULL) {
			return false;
		} else {
			return find(node->leftChild, k, v);
		}
	}
	else {
		if (node->rightChild == NULL) {
			return false;
		} else {
			return find(node->rightChild, k, v);
		}
	}
}
bool BSTUser::find(string k, int v) {
	if (root == NULL) {
		return false;
	}
	return find(root, k, v);
}

bool BSTUser::insert (Node* node, string k, int v) {
	if (k == node->key && v == node->value) return false;
	if (k < node->key || (k == node->key && v < node->value)) {
		if (node->leftChild == NULL) {
			node->leftChild = new Node(node, k, v);
			return true;
		} else {
			return insert(node->leftChild, k, v);
		}
	}
	else {
		if (node->rightChild == NULL) {
			node->rightChild = new Node(node, k, v);
			return true;
		} else {
			return insert(node->rightChild, k, v);
		}
	}
}
bool BSTUser::insert(string k, int v) {
	if (root == NULL) {
		root = new Node(NULL, k, v);
		return true;
	}
	return insert(root, k, v);
}
BSTUser::Node* BSTUser::findMin(Node *node) {
	while (node -> leftChild != NULL) node = node -> leftChild;
	return node;
}
BSTUser::Node* BSTUser::findMax(Node *node) {
	while (node -> rightChild != NULL) node = node -> rightChild;
	return node;
}
bool BSTUser::remove(Node *node, string k, int v) {
	if (node == NULL) return false;
	if (node->key == k && node->value == v) {
		if (node -> rightChild != NULL) {
			Node *minNode = findMin(node->rightChild);
			node->key = minNode->key;
			node->value = minNode->value;
			remove (node->rightChild, minNode->key, minNode->value);
		} else if (node -> leftChild != NULL) {
			Node *maxNode = findMax(node->rightChild);
			node->key = maxNode->key;
			node->value = maxNode->value;
			remove (node->leftChild, maxNode->key, maxNode->value);
		} else {
			if (node->parent->leftChild == node) node->parent->leftChild = NULL;
			else node->parent->rightChild = NULL;
			delete node;
		}
		return true;
	} else if (k < node->key || (k == node->key && v < node->value)) {
		return remove(node->leftChild, k, v);
	} else {
		return remove(node->rightChild, k, v);
	}
}
bool BSTUser::remove(string k, int v) {
	return remove(root, k, v);
}

void BSTUser::display(Node *node, int mode) {
	if (node == NULL) return;
	if (mode == 1) cout << node->key <<" @ " << node->value << "\n"; //pre-order
	display(node->leftChild, mode);
	if (mode == 0) cout << node->key <<" @ " << node->value << "\n"; //in-order
	display(node->rightChild, mode);
	if (mode == 2) cout << node->key <<" @ " << node->value << "\n"; //post-order
}
void BSTUser::display(int mode) {
	display(root, mode);
}
void BSTUser::save(Node *node, ofstream &fout) {
	if (node == NULL) return;
	save(node->leftChild, fout);
	save(node->rightChild, fout);
	fout << node->key <<" @ " << node->value << "\n";
}

void BSTUser::save(string filename) {
	ofstream fout;
	fout.open(filename.c_str());
	save(root, fout);
	fout.close();
}


bool BSTTicket::find (Node* node, int k, string v) {
	if (k == node->key && v == node->value) return true;
	if (k < node->key || (k == node->key && v < node->value)) {
		if (node->leftChild == NULL) {
			return false;
		} else {
			return find(node->leftChild, k, v);
		}
	}
	else {
		if (node->rightChild == NULL) {
			return true;
		} else {
			return find(node->rightChild, k, v);
		}
	}
}
bool BSTTicket::find(int k, string v) {
	if (root == NULL) {
		return false;
	}
	return find(root, k, v);
}
bool BSTTicket::insert (Node* node, int k, string v) {
	if (k == node->key && v == node->value) return false;
	if (k < node->key || (k == node->key && v < node->value)) {
		if (node->leftChild == NULL) {
			node->leftChild = new Node(node, k, v);
			return true;
		} else {
			return insert(node->leftChild, k, v);
		}
	}
	else {
		if (node->rightChild == NULL) {
			node->rightChild = new Node(node, k, v);
			return true;
		} else {
			return insert(node->rightChild, k, v);
		}
	}
}
bool BSTTicket::insert(int k, string v) {
	if (root == NULL) {
		root = new Node(NULL, k, v);
		return true;
	}
	return insert(root, k, v);
}
BSTTicket::Node* BSTTicket::findMin(Node *node) {
	while (node -> leftChild != NULL) node = node -> leftChild;
	return node;
}
BSTTicket::Node* BSTTicket::findMax(Node *node) {
	while (node -> rightChild != NULL) node = node -> rightChild;
	return node;
}
bool BSTTicket::remove(Node *node, int k, string v) {
	if (node == NULL) return false;
	if (node->key == k && node->value == v) {
		if (node -> rightChild != NULL) {
			Node *minNode = findMin(node->rightChild);
			node->key = minNode->key;
			node->value = minNode->value;
			delete minNode;
			minNode = NULL;
		} else if (node -> leftChild != NULL) {
			Node *maxNode = findMax(node->rightChild);
			node->key = maxNode->key;
			node->value = maxNode->value;
			delete maxNode;
			maxNode = NULL;
		} else {
			if (node->parent->leftChild == node) node->parent->leftChild = NULL;
			else node->parent->rightChild = NULL;
			delete node;
		}
		return true;
	} else if (k < node->key || (k == node->key && v < node->value)) {
		return remove(node->leftChild, k, v);
	} else {
		return remove(node->rightChild, k, v);
	}
}
bool BSTTicket::remove(int k, string v) {
	return remove(root, k, v);
}

void BSTTicket::display(Node *node, int mode, ostream &out) {
	if (node == NULL) return;
	if (mode == 1) out << node->value <<" @ " << node->key << "\n"; //pre-order
	display(node->leftChild, mode, out);
	if (mode == 0) out << node->value <<" @ " << node->key << "\n"; //in-order
	display(node->rightChild, mode, out);
	if (mode == 2) out << node->value <<" @ " << node->key << "\n"; //post-order
}
void BSTTicket::display(int mode) {
	display(root, mode, cout);
}

void BSTTicket::save(Node *node, ofstream &out) {
	if (node == NULL) return;
	save(node->leftChild, out);
	save(node->rightChild, out);
	out << node->value <<" @ " << node->key << "\n";;
}

void BSTTicket::save(string filename) {
	ofstream fout;
	fout.open(filename.c_str());
	save(root, fout);
	fout.close();
}
