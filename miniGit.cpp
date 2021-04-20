#include "miniGit.h"
#include<filesystem>
miniGit::miniGit() {}
miniGit::~miniGit() {}

void miniGit::add() {
  // prompt user to enter a file name
  cout << "Enter a file name: ";
  string filename;
  getline(cin, filename);

  // check that is exists
  while (!std::filesystem::exists(filename)) {
	cout << "File not found. Enter a valid filename: ";
	getline(cin, filename);
  }

  // see if file has already been added
  bool       file_added = false;
  singlyNode *searchPtr = DLL_head->SLL_head;

  // search through SLL
  while (searchPtr->next != nullptr and !file_added) {
	if (searchPtr->fileName == filename) {
	  file_added = true;
	  cout << "File " << filename << " already added. The same file cannot be added twice." << endl;
	}
	searchPtr = searchPtr->next;
  }

  // add the file as an SLL node
  if (!file_added) {
	auto *toAdd = new singlyNode;
	toAdd->next        = nullptr;
	toAdd->fileName    = filename;
	toAdd->fileVersion = filename + "_v00";
	searchPtr->next    = toAdd;
  }
}

void miniGit::remove() {
  // Empty list
  if (DLL_head == nullptr) return;

  // Read in filename to be removed
  cout << "Enter a file name: ";
  string filename;
  cin >> filename;

  singlyNode *curr = DLL_head->SLL_head;
  singlyNode *prev = nullptr;

  // Search for filename in the linked list; if found, delete it
  while (curr != nullptr) {
	if (curr->fileName == filename) {
	  prev->next = curr->next;
	  delete curr;
	  curr = nullptr;
	} else {
	  prev = curr;
	  curr = curr->next;
	}
  }
}

void miniGit::commit() {
  // TODO The current SLL should be traversed in its entirety, and for every node: see writeup

  // TODO Once all the files have been scanned, the final step of the commit will create a new DLL node of the repo

}

void miniGit::checkout() {
  // TODO issue a warning to the user that they will loose their local changes if they checkout a different version before making a commit with their current local changes

  // TODO This step will require a search through the DLL for a node with matching commit number

  // TODO must disallow add, remove, and commit operations when the current version is different from the most recent commit (the last DLL node)
}
void miniGit::init() {

}
