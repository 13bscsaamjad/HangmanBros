#include<string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

class Hangman {
protected:
	int numletters;					//stores lenghth of words
	int guesses;					//stores number of guesses
	vector<string> allwords;		//vector to store all the words from file
	vector<string> selectedwords;	//words of given length by the user on which game is played
	string word;					//stores random selected word on which game is played
	string playingword;				//stores current appearance of the word on which game is played Example# "--a--h--t"
	void readfile ();				//function to read the file "dictionary.txt"
	void numlettersandguesses ();	//function to promt the user to enter the number of letter in the words and number of guesses
	void selectwords ();			//function to select words of given length from all the words and store them in vector
	void randomword ();				//function to select random word from the selected words of given length on which game is played
public:
	void run ();					//function to play the game: Read in the file, prompt number of guesses,prompt number of letters, play!
};

class EvilHangman : protected Hangman {
private:
    map<string, vector<string> > maping;		//map to store the name of the families against the list of mambers of that family
    string familyname;						//stores family name that equals key in the map
    vector<string> familymembers;			//stores family members in vectors which are corresponding to the keys in the map
public:
    void run ();							//function to play the game: Read in the file, prompt number of guesses,prompt number of letters, prompt whether to display possible words, play!
};
