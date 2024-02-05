#include "entry.h"
class Scoreboard {
	entry board[5];
	int size=0;

	public:
	bool add(entry e) {
		bool added = false;
		for (int i = 0; i < size; i++) {
			entry exist = board[i];
			if (e.score > exist.score) {
				for (int j = size; j >= i+1; j--) {
					if (j == 5) {
						continue;
					}
					board[j] = board[j-1];
				}
				board[i] = e;
				if (size < 5) {
					size++;
				}
				added = true;
				return true;
			}
		}
			if (size < 5) {
				board[size++] = e;
                return true;
			} else {
				cout << "PUNO NA" << endl;
                return false;
			}
    }

    // TODO add method banCollege here
    int banCollege(string college) {
        int ctr = 0;
        for (int i = size-1; i >=0; i--) {
            entry e = board[i];
            if (college.compare(e.college) == 0){
                for (int j = i; j <= i; j++) {
                    board[j] = board[j+1];
                }
                ctr++;
            }
        }
        size -= ctr;
        return ctr;
    }

    // TODO add method removeLower here
    int removeLower(int score) {
        int ctr = 0;
        for(int i=size-1;i>=0;i--){
            entry e = board[i];
            if(score > e.score){
                ctr++;
                for(int j=i;j<=i;j++){
                    board[j]=board[j+1];
                }
            }
        }
        size -= ctr;
        return ctr;
    }
    //TODO add method forceFirst here
    int forceFirst(string college){
        int index = 0;
        int count = 0;
        for(int i=0;i<size;i++){
            if(board[i].college.compare(college) == 0){
                index=i;
                break;
            }
            count++;
        }
        if(count==0){
            return 0;
        }
        for(int j=0;j<size;j++){
            board[j]=board[index];
            index++;
        }
        size -= count;
        return count;
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            if (i >= size) {
                cout << i+1 << ". (none)" << endl;
            } else {
            	entry e = board[i];
                cout << i+1 << ". " << e.name << " (" << e.college << ")" << " - " << e.score << endl;
            }
        }
        cout << endl;
    }
};