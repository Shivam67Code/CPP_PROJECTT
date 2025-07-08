#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;
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

  cout << "Start typing (press Enter to autocomplete):\n";

  while (true)
  {
    ch = _getch();

    if (ch == '\r')
    { // Enter key
      vector<string> suggestions = getSuggestions(wordList, userInput);
      if (!suggestions.empty())
      {
        userInput = suggestions[0]; // autocomplete
      }
      cout << "\nAutocompleted: " << userInput << "\n";
      break;
    }
    else if (ch == 8)
    { // Backspace
      if (!userInput.empty())
      {
        userInput.pop_back();
      }
    }
    else
    {
      userInput += ch;
    }

    // Clear lIne and sHow input andSUggestion
    system("cls");
    cout << "Typed: " << userInput << "\n";

    vector<string> suggestions = getSuggestions(wordList, userInput);
    if (!suggestions.empty())
    {
      cout << "Suggestion: " << suggestions[0] << "\n";
    }
    else
    {
      cout << "No suggestions found.\n";
    }
  }

  return 0;
}
