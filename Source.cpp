#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_TRIES = 10;
int letterFill(char, string, string &);

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill(char guess, string secretword, string &guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

int main()
{
	char letter;
	int num_of_wrong_guesses = 0;
	string word;
	string words[] =
		{"afghanistan", "albania", "algeria", "andorra", "angola", "anguilla", "argentina", "armenia", "aruba", "australia", "austria", "azerbaijan", "bahamas", "bahrain", "bangladesh", "barbados", "belarus", "belgium", "belize", "benin", "bermuda", "bhutan", "bolivia", "botswana", "brazil", "brunei", "bulgaria", "burundi", "cambodia", "cameroon", "chad", "chile", "china", "colombia", "congo", "croatia", "cuba", "cyprus", "denmark", "djibouti", "dominica", "ecuador", "egypt", "estonia", "ethiopia", "fiji", "finland", "france", "gabon", "gambia", "georgia", "germany", "ghana", "gibraltar", "greece", "greenland", "grenada", "guam", "guatemala", "guernsey", "guinea", "guyana", "haiti", "honduras", "hungary", "iceland", "india", "indonesia", "iran", "iraq", "ireland", "israel", "italy", "jamaica", "japan", "jersey", "jordan", "kazakhstan", "kenya", "kuwait", "laos", "latvia", "lebanon", "lesotho", "liberia", "libya", "liechtenstein", "lithuania", "luxembourg", "macau", "macedonia", "madagascar", "malawi", "malaysia", "maldives", "mali", "malta", "mauritania", "mauritius", "mexico", "moldova", "monaco", "mongolia", "montenegro", "montserrat", "morocco", "mozambique", "namibia", "nepal", "netherlands", "nicaragua", "niger", "nigeria", "norway", "oman", "pakistan", "palestine", "panama", "paraguay", "peru", "philippines", "poland", "portugal", "qatar", "reunion", "romania", "russia", "rwanda", "samoa", "satellite", "senegal", "serbia", "seychelles", "singapore", "slovakia", "slovenia", "spain", "sudan", "suriname", "swaziland", "sweden", "switzerland", "syria", "taiwan", "tajikistan", "tanzania", "thailand", "togo", "tonga", "tunisia", "turkey", "turkmenistan", "uganda", "ukraine", "uruguay", "uzbekistan", "venezuela", "vietnam", "yemen", "zambia", "zimbabwe"};

	//choose and copy a word from array of words randomly
	srand(static_cast<unsigned int>(time(NULL)));
	int n = rand() % 161;
	word = words[n];

	// Initialize the secret word with the * character.
	string unknown(word.length(), '_');

	// welcome the user
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n               **HANGMAN**              ";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n\nWelcome to hangman...Guess the country name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n";
		for (int i = 0; i < unknown.length(); i++)
		{
			cout << unknown[i] << " ";
		}
		cout << "\n\nGuess a letter: ";
		cin >> letter;

		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown) == 0)
		{
			cout << endl
				 << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl
				 << "You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word == unknown)
		{
			cout << endl
				 << word << endl;
			cout << "Yeah! You got it!";
			char choice;
			cout << "\nDo you wish to play again? (Y/N): ";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				main();
			}
			break;
		}
	}
	if (num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
		char choice;
		cout << "Do you wish to play again? (Y/N): ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			main();
		}
		else if (choice == 'N' || choice == 'n')
		{
			return 0;
		}
	}
	cin.ignore();
	return 0;
}