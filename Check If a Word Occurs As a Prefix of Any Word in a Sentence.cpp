#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int isPrefixOfWord(string sentence, string searchWord)
{
    istringstream ss{sentence};
    int index{0};
    int match{0};
    string word{};

    while (ss >> word)
    {
        for (int i{0}; i < searchWord.length() && i < word.length() && word[i] == searchWord[i]; i++)
            match++;

        index++;

        if (match == searchWord.length())
            break;

        match = 0;
    }

    return !match ? -1 : index;
}