#include <bits/stdc++.h>

using namespace std;

// SOLUTION
bool isVowel(char c)
{
    string vowels = "aeiou";
    return vowels.find(tolower(c)) != string::npos;
}

string toGoatLatin(string sentence)
{
    istringstream ss{sentence};
    int index{1};
    string word{};
    string result{};

    while (ss >> word)
    {
        if (!isVowel(word[0]))
        {
            word += word[0];  // Append first character to end of word
            word.erase(0, 1); // Remove first character from word
        }

        string append(index, 'a'); // Creates string of "index" number of 'a'

        result += word + "ma" + append + " ";

        index++;
    }

    result.pop_back(); // Remove the last extra space from result

    return result;
}