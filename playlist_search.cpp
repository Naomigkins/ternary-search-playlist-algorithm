#include <iostream>
#include <string>

using namespace std;

int ternarySearch(string playlist[], int left, int right, string 
targetSong) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (playlist[mid1] == targetSong) {
            return mid1;
        }
        if (playlist[mid2] == targetSong) {
            return mid2;
        }

        if (targetSong < playlist[mid1]) {
            return ternarySearch(playlist, left, mid1 - 1, targetSong);
        }
        else if (targetSong > playlist[mid2]) {
            return ternarySearch(playlist, mid2 + 1, right, targetSong);
        }
        else {
            return ternarySearch(playlist, mid1 + 1, mid2 - 1, 
targetSong);
        }
    }
    return -1;
}

int main() {
    string playlist[] = {
        "Abba - Dancing Queen", 
        "Beatles - Yesterday", 
        "Coldplay - Yellow", 
        "Eminem - Stan", 
        "Michael Jackson - Thriller", 
        "Queen - Bohemian Rhapsody"
    };
    int n = sizeof(playlist) / sizeof(playlist[0]);

    string target = "Coldplay - Yellow";
    int result = ternarySearch(playlist, 0, n - 1, target);
    
    cout << "--- Media Retrieval Group Test ---" << endl;
    cout << "Searching for playlist item: '" << target << "'" << endl;
    if (result != -1) {
        cout << "Success! Target found at array index: " << result << 
endl;
    } else {
        cout << "Result: " << result << " (Song not found)" << endl;
    }

    string missingTarget = "Invalid Track Name";
    int missingResult = ternarySearch(playlist, 0, n - 1, missingTarget);
    
    cout << "\nSearching for playlist item: '" << missingTarget << "'" << 
endl;
    if (missingResult != -1) {
        cout << "Success! Target found at array index: " << missingResult 
<< endl;
    } else {
        cout << "Result: " << missingResult << " (Song not found)" << 
endl;
    }

    return 0;
}

