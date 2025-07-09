// The job is done upto adding colors yet.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

// Simple ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// CROSS PLATFORM CLEAR SCREEN FUNCTION ADDING
void clearScreen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Function to load words from the file
vector<string> loadWords(const string &filename)
{
  vector<string> words;
  ifstream file(filename);
  string word;
  while (file >> word)
  {
    words.push_back(word);
  }
  return words;
}

vector<string> getSuggestions(const vector<string> &words, const string &input)
{
  vector<string> suggestions;
  for (int i = 0; i < words.size(); i++)
  {
    string word = words[i];

    // comparing the substring(starting of the word) with what user typed.
    if (word.substr(0, input.size()) == input)
    {
      suggestions.push_back(word);
    }
  }
  return suggestions;
}

int main()
{
  vector<string> wordList = loadWords("words.txt");

  string userInput = "";
  char ch;
  cout << CYAN << "Start Typing(press Enter to autoComplete): \n " << RESET;

  while (true)
  {
    ch = _getch();

    if (ch == '\r')
    {
      if (!userInput.empty())
      {
        vector<string> suggestions = getSuggestions(wordList, userInput);
        if (!suggestions.empty())
        {
          userInput = suggestions[0];
        }
        cout << GREEN << "\n Autocompleted word is : " << BLUE << userInput << RESET << endl;
        break; // thinking of removing it or adding a function instead of it. 🤔
      }
    }
    else if (ch == 8)
    {
      if (!userInput.empty())
      {
        userInput.pop_back();
      }
    }
    else
    {
      userInput += ch;
    }

    clearScreen();
    cout << CYAN << "Start Typing(press Enter key to AutoComplete):\n"
         << RESET;
    cout << WHITE << "You Typed : " << BLUE << userInput << RESET << endl;

    vector<string> suggestions = getSuggestions(wordList, userInput);
    if (!userInput.empty() && !suggestions.empty())
    {
      cout << WHITE << "Suggestions: " << GREEN << suggestions[0] << RESET << endl;
    }
    else if (!userInput.empty())
    {
      cout << RED << "No Suggestions Found :(" << RESET << endl;
    }
  }

  return 0;
}