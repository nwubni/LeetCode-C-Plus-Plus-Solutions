#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string reformat(string s)
{
    string numbers{}, letters{};

    for (char &c : s) // Separate numbers and letters from string (s)
        if (isdigit(c))
            numbers = c + numbers;
        else
            letters = c + letters;

    int add_letter = letters.length() > numbers.length();     // Use the longest length between letters and numbers to decide the order to alternate and start building the answer. If (letters) is longer, start appending a letter to the answer, else start appending a number.
    int count_down = max(letters.length(), numbers.length()); // Loop should be as long as the longest of numbers and letters
    string ans{};

    while (count_down >= 0)
    {
        if (add_letter && !letters.empty())
        {
            ans += letters.back();
            letters.pop_back();
            add_letter = false;
        }

        if (!add_letter && !numbers.empty())
        {
            ans += numbers.back();
            numbers.pop_back();
            add_letter = true;
        }

        if (!ans.empty() && (add_letter && !isdigit(ans.back()) || !add_letter && isdigit(ans.back()))) // Exit the Loop Early: Alternating will be incorrect
            return {};

        count_down--;
    }

    if (ans.length() != s.length())
        return {};

    return ans;
}