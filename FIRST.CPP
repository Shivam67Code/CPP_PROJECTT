#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

// Color codes for Windows console
enum Color
{
  DEFAULT = 7,
  BLUE = 9,
  GREEN = 10,
  CYAN = 11,
  RED = 12,
  YELLOW = 14,
  WHITE = 15
};

// Set console text color
void setColor(int color)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color);
}

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

  setColor(CYAN);
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
      setColor(GREEN);
      cout << "\nAutocompleted: ";
      setColor(BLUE);
      cout << userInput << "\n";
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
    clearScreen(); // that clear function called fro just once yet
    setColor(WHITE);
    cout << "Typed: ";
    setColor(BLUE);
    cout << userInput << "\n";

    vector<string> suggestions = getSuggestions(wordList, userInput);
    if (!suggestions.empty())
    {
      setColor(WHITE);
      cout << "Suggestion: ";
      setColor(GREEN);
      cout << suggestions[0] << "\n";
    }
    else
    {
      setColor(RED);
      cout << "No suggestions found.\n";
    }
  }

  setColor(DEFAULT);
  return 0;
}
