#include "hangmanbros.h"
#include<cstdlib>
using namespace std;

void Hangman::readfile () {
	ifstream stream;
	stream.open("dictionary.txt");
	if (!stream)
		return;
	char arr [128];
	while(stream.getline(arr,128)) {
		allwords.push_back(arr);		
	}
	return;
}

void Hangman::numlettersandguesses () {
	
	cout<<"Please enter the length of the word to guess: ";
	cin>>numletters;
	while (numletters==26||numletters==27||numletters>29) {
	cout<<"No word of this length in this dictionary. Please enter the length of the word to guess again: ";
	cin>>numletters;
	}
	cout<<"Please enter the number of guesses you wish to have: ";
	cin>>guesses;
}

void Hangman::selectwords () {
	for (int i = 0; i < allwords.size(); i++) {
		if (allwords[i].size() == numletters) {
			selectedwords.push_back(allwords[i]);
		}
	}
}

void Hangman::randomword() {
	int index = 0;
	srand(time(NULL));
	index = rand() % (selectedwords.size());
	word = selectedwords[index];
}

void Hangman::run () {	
	readfile ();
	numlettersandguesses ();
	selectwords ();
	randomword ();	
	cout<<"You have "<<guesses<<" guesses remaining.";
	
	for ( int i = 0; i < numletters; i++) {
		playingword += '-';
	}
	cout<<endl;
	cout<<playingword;
	char guess;

	while (guesses != 0) {
		cout<<"\nPlease guess a letter: ";
		cin>>guess;
		int temp = 0;
		
		for(int j = 0; j < numletters; j++) {
			if(word[j] == guess) {
				temp++;
				playingword[j] = guess;
			}
		}
		
		if (temp == 0)
			guesses--;
		
		if(playingword == word) {
			cout<<"Congratulations, you guessed the word "<<playingword;
			break;
		}
		if (guesses != 0) {
			cout<<"You have "<<guesses<<" guesses remaining.";
			cout<<'\n'<<playingword;
		}
	}

	if (guesses == 0) {
		cout<<endl;
		cout<<"You have ran out of guesses. The word is "<<(word)<<".";
	}
	return;
}


void EvilHangman::run() {
	readfile ();
    numlettersandguesses ();
    selectwords ();
	char leftpossiblewords;
	cout<<"Print the number of possible words left after each guess? (Y) or (N): ";	
	cin >> leftpossiblewords;
	cout<<"You have "<<guesses<<" guesses remaining.";
	cout<<endl;
	for (int i = 0; i < numletters; i++) {
		cout<<'-';
	}
	cout<<endl;
	if (leftpossiblewords == 'Y') {
		cout<<"There are "<<selectedwords.size()<<" possible words left.";
	}
	cout<<endl;
	char guess;
	int whilecounter = 0;
	
	while (guesses != 0) {
		whilecounter++;
		if (whilecounter > 1 && leftpossiblewords == 'Y') {
			cout<<"\nThere are "<<selectedwords.size()<<" possible words left.";
		}
		if(whilecounter > 1) {
			cout<<endl;
		}

		cout<<"Please guess a letter: ";
		cin>>guess;
		string tempfamilyname;
		for ( int i = 0; i < selectedwords.size(); i++) {
			string word = selectedwords[i];
			
			if (whilecounter == 1) {
				for ( int m = 0; m < numletters; m++) {
						familyname.push_back(' ');
				}
			}

			if (whilecounter > 1) {
				tempfamilyname = familyname;
			}

			for ( int j = 0; j < numletters; j++) { 
				
				if (whilecounter == 1 && word[j] == guess) {
					familyname [j] = guess;
				}

				if (whilecounter == 1 && word[j] != guess) {
					familyname [j] = '-';
				}
				
				if (whilecounter > 1 && word[j] == guess) {
					tempfamilyname [j] = guess;
				}				
			}
			if (whilecounter == 1) {
				maping [familyname].push_back(word);
				familyname.clear();
			}
			
			if (whilecounter > 1) {
				maping [tempfamilyname].push_back(word);
			}
		}
		
		int large = 0;
		for (map<string,vector<string> >::iterator it = maping.begin(); it != maping.end(); it++) {
			if (it->second.size() >= large) {
				large = it->second.size();
				familyname.clear();
				familyname = it->first;
				selectedwords.clear();
				selectedwords = it->second;
			}
		}
			
		int temp = 0;
		for ( int i = 0; i < familyname.size(); i++) {
			if (familyname[i] == guess) {
				temp++;
			}
		}

		if (temp != 0) {
			cout<<"You have "<<guesses<<" guesses remaining.";
			cout<<'\n'<<familyname;
		}

		if (temp == 0) {
			guesses--;
			if ( guesses > 0 ) {
				cout<<"You have "<<guesses<<" guesses remaining.";
				cout<<'\n'<<familyname;
			}
		}

		if (guesses == 0) {
			cout<<"\nYou have ran out of guesses. The word is ("<<selectedwords[0]<<").";
			return;
		}
		maping.clear();

		if (selectedwords.size() == 1) {
			if(familyname == selectedwords[0]) {
				cout<<"Congratulations, you guessed the word";
				cout<<'\n'<<familyname;
				return;
			}
		}
	}
}
