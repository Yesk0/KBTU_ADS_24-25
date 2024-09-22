#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

void findNonRepeatingCharacters(int N, const vector<char>& stream) {
    unordered_map<char, int> charCount;
    queue<char> nonRepeatingQueue;       
    vector<string> results;

    for (int i = 0; i < N; ++i) {
        char currentChar = stream[i];
        charCount[currentChar]++;

        if (charCount[currentChar] == 1) {
            nonRepeatingQueue.push(currentChar);
        }

        while (!nonRepeatingQueue.empty() && charCount[nonRepeatingQueue.front()] > 1) {
            nonRepeatingQueue.pop();
        }

        if (nonRepeatingQueue.empty()) {
            results.push_back("-1");
        } else {
            results.push_back(string(1, nonRepeatingQueue.front()));
        }
    }

    for (const auto& result : results) {
        cout << result << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int N;
        cin >> N; 
        vector<char> stream(N);

        for (int i = 0; i < N; ++i) {
            cin >> stream[i]; 
        }

        findNonRepeatingCharacters(N, stream);
    }

    return 0;
}
