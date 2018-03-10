//Pair
//Abdullah Amjad
//Danish Ahmed

#include "hangmanbros.h"

using namespace std;

int main() { 
 char ch; 
 cout <<"Which version do you want to play? (O) or (E): "; 
 cin >>ch; 
 
 if (ch == 'O') {
	 Hangman hangman;
	 hangman.run ();
 }

 else {
	 EvilHangman hangman;
	 hangman.run();
 }
 return 0; 
}
