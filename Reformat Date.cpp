#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string reformatDate(string date)
{
    map<string, string> months{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
    istringstream ss{date};
    string day{}, month{}, year{};

    ss >> day >> month >> year;

    day = (day.length() < 4 ? "0" : "") + day.substr(0, day.length() - 2); // Remove the last two characters from day and prepend "0" if necessary

    return year + "-" + months[month] + "-" + day;
}