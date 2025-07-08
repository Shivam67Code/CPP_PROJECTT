#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

vector<string> loadWords(const string &filename)
{
  vector<string> words;
  ifstream file(filename);
  string words;
  while (file >> words)
  {
    words.push_back(word)
  }
  return words;
}

vector<string> getSuggestions(const vector<string> &words, const string &input)
{
  vector<string> suggestions;
  for (int i = 0; i < words.size(); i++)
  {
    string word = words[i];

    // comparing teh substring(starting of the word) with wjat user typed.
    if (word.substr(0, input.size()) == input)
    {
      suggestions.push_back(input);
    }
  }
  return suggestions;
}

int main()
{
  vector<string> wordsList = loadWords("words.txt");
  string userInput = "";

  char ch;

  while (true)
  {
    ch = _getch();
    if (ch = '\r')
    {
      vector<string> suggestions = getSuggestions(wordsList, userInput);
    }
  }
}