// Warning: DO NOT MODIFY THIS FILE.
// Doing so will nullify your score for this problem.

#include <iostream>
#include "board.h"
using namespace std;

int main() {
	entry player1;
	Scoreboard* board = new Scoreboard();
    char ans;
    string college;
    int score;
	do {
		cout << "Op: ";
		cin >> ans;
        switch (ans) {
            case 'a':
        		cout << "Enter name: ";
                cin.ignore();
        		getline(cin, player1.name);
        		cout << "Enter college: ";
        		cin >> player1.college;
        		cout << "Enter score: ";
        		cin >> player1.score;
        		board->add(player1);
                break;
            case 'b':
                cout << "Enter college to ban: ";
                cin >> college;
                cout << "Number of entries removed: " << board->banCollege(college) << endl;
                break;
            case 'l':
                cout << "Enter score baseline: ";
                cin >> score;
                cout << "Number of entries removed: " << board->removeLower(score) << endl;
                break;
            case 'f':
                cout<<"Enter college to force first: ";
                cin>>college;
                cout<<"Number of entries removed: "<<board->forceFirst(college)<<endl;
                break;
            case 'p':
                board->print();
                break;
            case 'x':
                cout << "Exiting";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
	} while (ans != 'x');

	return 0;
}