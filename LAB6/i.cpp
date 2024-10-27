#include <iostream>
#include <string>

using namespace std;

void custom_sort(const string& input_str) {
    int freq[26] = {0};
    
    for (char ch : input_str) {
        freq[ch - 'a']++;
    }
    
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            cout << static_cast<char>(i + 'a');
        }
    }
    cout << endl;
}

int main() {
    string input_str;
    cin >> input_str;
    custom_sort(input_str);
    return 0;
}