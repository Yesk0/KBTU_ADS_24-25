#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void custom_sort(const string& input_str) {
    vector<char> vowels, consonants;
    
    for (char ch : input_str) {
        if (is_vowel(ch)) {
            vowels.push_back(ch);
        } else {
            consonants.push_back(ch);
        }
    }
    
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());
    
    for (char ch : vowels) {
        cout << ch;
    }
    for (char ch : consonants) {
        cout << ch;
    }
    cout << endl;
}

int main() {
    int n;
    string input_str;
    cin >> n >> input_str;
    custom_sort(input_str);
    return 0;
}