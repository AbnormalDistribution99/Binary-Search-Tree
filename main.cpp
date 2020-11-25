#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "BST.h"

using namespace std;

BSTUser bstUser;
BSTTicket bstTicket;

void printInputDescription() {
	cout << ">> ";
}

void printErrorCommand() {
	cout << "An error in your input was detected and your requested action cannot be completed" << endl;
}
void handleCommand(stringstream &ss, string cmd) {
	if (cmd == "exit") {
		// exit program
		exit(0);
	} else if (cmd == "load") {
		// parses the contents of the file
		string file, str;
		getline(ss, file, ' ');

		ifstream fin(file.c_str());
		while (true) {
			str = "";
			getline(fin, str);
			if (str == "") break;
			stringstream fs(str);
			getline(fs, cmd, ' ');
			/* Call handleCommand function recursively so that
			commands in file including "load" will be executed properly */
			handleCommand(fs, cmd);
		}
	} else if (cmd == "display") {
		string bst, mode;
		getline(ss, bst, ' ');
		getline(ss, mode, ' ');
		int iMode;
		if (mode == "in") iMode = 0;
		else if (mode == "pre") iMode = 1;
		else if (mode == "post") iMode = 2;
		else {
			printErrorCommand();
			return;
		}
		mode[0] = toupper(mode[0]);
		if (bst == "user") {
			cout << "User's " << mode <<" Order Traversal" << endl << endl;
			bstUser.display(iMode);
		} else if (bst == "ticket") {
			cout << "Ticket's " << mode <<" Order Traversal" << endl << endl;
			bstTicket.display(iMode);
		} else {
			printErrorCommand();
			return;
		}
	} else if (cmd == "new") {
		bstUser.empty();
		bstTicket.empty();
	} else if (cmd == "remove") {
		string user, ts;
		int ticket;
		getline(ss, user, ' ');
		getline(ss, ts, ' ');
		ticket = atoi(ts.c_str());
		if (bstUser.remove(user, ticket) && bstTicket.remove(ticket, user)) {
			cout << "User @ ticket " << user << " @ " << ticket << " was removed" << endl;
		} else {
			cout << "User @ ticket " << user << " @ " << ticket << " doesn't exist" << endl;
		}
	} else if (cmd == "find") {
		string user, ts;
		int ticket;
		getline(ss, user, ' ');
		getline(ss, ts, ' ');
		ticket = atoi(ts.c_str());
		if (bstUser.find(user, ticket) && bstTicket.find(ticket, user)) {
			cout << "User @ ticket " << user << " @ " << ticket << " was found" << endl;
		} else {
			cout << "User @ ticket " << user << " @ " << ticket << " doesn't exist" << endl;
		}
	} else if (cmd == "add") {
		string user, ts;
		int ticket;
		getline(ss, user, ' ');
		getline(ss, ts, ' ');
		ticket = atoi(ts.c_str());
		if (bstUser.insert(user, ticket) && bstTicket.insert(ticket, user)) {
			cout << "Added " << user << " @ " << ticket << " to system" << endl;
		} else {
			cout << "User @ ticket " << user << " @ " << ticket << " already exists" << endl;
		}
	} else if (cmd == "save") {
		string bst, file;
		getline(ss, bst, ' ');
		getline(ss, file, ' ');
		getline(ss, file, ' ');
		if (bst == (string)"user") bstUser.save(file);
		else bstTicket.save(file);
	} else {
		// Input commands may be wrong command then display this message
		printErrorCommand();
	}
}

int main() {
	string str;
	string cmd;
	while (true) {
		// Print Input description
		printInputDescription();
		// Input command line
		getline(cin, str);
		stringstream ss(str);
		//Get command token
		getline(ss, cmd, ' ');
		// Do actions accorging to command category
		handleCommand(ss, cmd);
	}
	return 0;
}
