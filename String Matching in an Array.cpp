#include <bits/stdc++.h>

using namespace std;

// SOLUTION
vector<string> stringMatching(vector<string> &words)
{
    string str{};

    sort(words.begin(), words.end(), [](string &a, string &b)
         { return a.length() < b.length(); });

    for (string &word : words)
        str += " " + word;

    string word{};
    istringstream ss{str};
    int start{0};

    vector<string> ans{};

    while (ss >> word)
    {
        start += word.length() + 1;

        auto found = str.find(word, start);

        if (found != string::npos)
            ans.push_back(word);
    }

    return ans;
}