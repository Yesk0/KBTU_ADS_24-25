#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Date {
    int day, month, year;
    string original;

    bool operator<(const Date& other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Date> dates(n);

    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        int day = stoi(input.substr(0, 2));
        int month = stoi(input.substr(3, 2));
        int year = stoi(input.substr(6, 4));
        dates[i] = {day, month, year, input};
    }

    sort(dates.begin(), dates.end());

    for (const auto& date : dates) {
        cout << date.original << endl;
    }

    return 0;
}