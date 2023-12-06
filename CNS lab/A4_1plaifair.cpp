// #include <bits/stdc++.h>
// using namespace std;

// class PlayfairCipher {
//   public:
//     static pair<vector<vector<char>>, unordered_map<char, pair<int, int>>>
//     getKeyMatrixAndPositions(const string &key) {
//         vector<vector<char>> keyMatrix(5, vector<char>(5));
//         int i = 0, j = 0;
//         unordered_set<char> set;
//         unordered_map<char, pair<int, int>> position;

//         for (char c : key) {
//             if (c == 'j')
//                 c = 'i';

//             if (set.find(c) != set.end())
//                 continue;

//             set.insert(c);
//             keyMatrix[i][j] = c;
//             position[c] = {i, j};

//             j++;
//             if (j == 5) {
//                 j = 0;
//                 i++;
//             }
//         }

//         for (char c = 'a'; c <= 'z'; c++) {
//             if (c == 'j')
//                 continue;

//             if (set.find(c) != set.end())
//                 continue;

//             set.insert(c);
//             keyMatrix[i][j] = c;
//             position[c] = {i, j};

//             j++;
//             if (j == 5) {
//                 j = 0;
//                 i++;
//             }
//         }

//         position[j] = position[i];

//         return {keyMatrix, position};
//     }

//     static vector<string> getDiagrams(const string &text) {
//         int n = text.size();
//         int i = 0;
//         vector<string> diagrams;

//         while (i + 1 < n) {
//             if (text[i] != text[i + 1]) {
//                 string d;
//                 d += tolower(text[i]);
//                 d += tolower(text[i + 1]);
//                 diagrams.push_back(d);

//                 i += 2;
//             } else {
//                 string d;
//                 d += tolower(text[i]);
//                 d += 'x';
//                 diagrams.push_back(d);

//                 i++;
//             }
//         }

//         if (i == n - 1) {
//             string d;
//             d += tolower(text[i]);
//             d += 'x';
//             diagrams.push_back(d);
//         }

//         return diagrams;
//     }

//     static string encrypt(const string &plaintext, const string &key) {
//         auto p = getKeyMatrixAndPositions(key);
//         auto keyMatrix = p.first;
//         auto position = p.second;
//         vector<string> diagrams = getDiagrams(plaintext);
//         stringstream ciphertext;

//         for (string &diagram : diagrams) {
//             auto p1 = position[diagram[0]];
//             auto p2 = position[diagram[1]];
//             auto i0 = p1.first, j0 = p1.second;
//             auto i1 = p2.first, j1 = p2.second;

//             if (i0 == i1) {
//                 diagram[0] = keyMatrix[i0][(j0 + 1) % 5];
//                 diagram[1] = keyMatrix[i0][(j1 + 1) % 5];
//             } else if (j0 == j1) {
//                 diagram[0] = keyMatrix[(i0 + 1) % 5][j0];
//                 diagram[1] = keyMatrix[(i1 + 1) % 5][j0];
//             } else {
//                 diagram[0] = keyMatrix[i0][j1];
//                 diagram[1] = keyMatrix[i1][j0];
//             }

//             ciphertext << diagram;
//         }

//         string answer = ciphertext.str();

//         transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
//         return answer;
//     }

//     static string decrypt(const string &ciphertext, const string &key) {
//         auto p = getKeyMatrixAndPositions(key);
//         auto keyMatrix = p.first;
//         auto position = p.second;

//         vector<string> diagrams = getDiagrams(ciphertext);
//         stringstream plaintext;

//         for (string &diagram : diagrams) {
//             auto p1 = position[diagram[0]];
//             auto p2 = position[diagram[1]];
//             auto i0 = p1.first, j0 = p1.second;
//             auto i1 = p2.first, j1 = p2.second;

//             if (i0 == i1) {
//                 diagram[0] = keyMatrix[i0][(j0 - 1 + 5) % 5];
//                 diagram[1] = keyMatrix[i0][(j1 - 1 + 5) % 5];
//             } else if (j0 == j1) {
//                 diagram[0] = keyMatrix[(i0 - 1 + 5) % 5][j0];
//                 diagram[1] = keyMatrix[(i1 - 1 + 5) % 5][j0];
//             } else {
//                 diagram[0] = keyMatrix[i0][j1];
//                 diagram[1] = keyMatrix[i1][j0];
//             }

//             plaintext << diagram;
//         }

//         return plaintext.str();
//     }
// };

// int main() {
//     cout << "PlayFair Cipher:\n"
//          << "Enter your choice:\n"
//          << "1. Encrypt\n"
//          << "2. Decrypt\n";

//     int choice;
//     cin >> choice;

//     switch (choice) {
//     case 1: {
//         cout << "Enter plaintext: ";
//         string plaintext;
//         cin.get();
//         getline(cin, plaintext);
//         plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), ::isspace),
//                         plaintext.end());

//         cout << "Enter key : ";
//         string key;
//         cin >> key;

//         string ciphertext = PlayfairCipher::encrypt(plaintext, key);

//         cout << "Plaintext:  " << plaintext << "\n"
//              << "Ciphertext: " << ciphertext << "\n";
//     } break;

//     case 2: {
//         cout << "Enter ciphertext: ";
//         string ciphertext;
//         cin >> ciphertext;

//         cout << "Enter key : ";
//         string key;
//         cin >> key;

//         string plaintext = PlayfairCipher::decrypt(ciphertext, key);

//         cout << "Ciphertext: " << ciphertext << "\n"
//              << "Plaintext:  " << plaintext << "\n";
//     } break;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to remove spaces and duplicate letters from the key
string prepareKey(string key) {
    string preparedKey = "";
    vector<bool> used(26, false); // to keep track of used letters

    // Remove spaces from the key and convert to uppercase
    for (char c : key) {
        if (isalpha(c)) {
            c = toupper(c);
            if (!used[c - 'A']) {
                preparedKey += c;
                used[c - 'A'] = true;
            }
        }
    }

    // Fill the remaining spaces with the alphabet (except 'J' which is combined with 'I')
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c != 'J' && !used[c - 'A']) {
            preparedKey += c;
            used[c - 'A'] = true;
        }
    }

    return preparedKey;
}

// Create the Playfair matrix from the key
vector<vector<char>> createMatrix(const string& key) {
    vector<vector<char>> matrix(5, vector<char>(5));

    string preparedKey = prepareKey(key);
    int k = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = preparedKey[k++];
        }
    }

    return matrix;
}

// Find the row and column indices of a character in the matrix
void findPosition(const vector<vector<char>>& matrix, char c, int& row, int& col) {
    if (c == 'J')
        c = 'I'; // treat 'J' as 'I'

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] == c) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Encrypt using the Playfair cipher
string encryptPlayfair(const string& plaintext, const string& key) {
    vector<vector<char>> matrix = createMatrix(key);
    string ciphertext = "";
    int len = plaintext.length();

    for (int i = 0; i < len; i += 2) {
        char a = plaintext[i];
        char b = (i + 1 < len) ? plaintext[i + 1] : 'X'; // If the text length is odd, add 'X' at the end

        int rowA, colA, rowB, colB;
        findPosition(matrix, a, rowA, colA);
        findPosition(matrix, b, rowB, colB);

        // Case 1: In the same row
        if (rowA == rowB) {
            ciphertext += matrix[rowA][(colA + 1) % 5];
            ciphertext += matrix[rowB][(colB + 1) % 5];
        }
        // Case 2: In the same column
        else if (colA == colB) {
            ciphertext += matrix[(rowA + 1) % 5][colA];
            ciphertext += matrix[(rowB + 1) % 5][colB];
        }
        // Case 3: Forming a rectangle
        else {
            ciphertext += matrix[rowA][colB];
            ciphertext += matrix[rowB][colA];
        }
    }

    return ciphertext;
}

// Decrypt using the Playfair cipher
string decryptPlayfair(const string& ciphertext, const string& key) {
    vector<vector<char>> matrix = createMatrix(key);
    string plaintext = "";
    int len = ciphertext.length();

    for (int i = 0; i < len; i += 2) {
        char a = ciphertext[i];
        char b = (i + 1 < len) ? ciphertext[i + 1] : 'X'; // If the text length is odd, add 'X' at the end

        int rowA, colA, rowB, colB;
        findPosition(matrix, a, rowA, colA);
        findPosition(matrix, b, rowB, colB);

        // Case 1: In the same row
        if (rowA == rowB) {
            plaintext += matrix[rowA][(colA + 4) % 5]; // Decrement by 1
            plaintext += matrix[rowB][(colB + 4) % 5]; // Decrement by 1
        }
        // Case 2: In the same column
        else if (colA == colB) {
            plaintext += matrix[(rowA + 4) % 5][colA]; // Decrement by 1
            plaintext += matrix[(rowB + 4) % 5][colB]; // Decrement by 1
        }
        // Case 3: Forming a rectangle
        else {
            plaintext += matrix[rowA][colB];
            plaintext += matrix[rowB][colA];
        }
    }

    return plaintext;
}

int main() {
    string key, plaintext, ciphertext;

    cout << "Enter the key: ";
    cin >> key;
    cin.ignore(); // Clear the newline character from the input buffer

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Remove spaces and convert to uppercase
    plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), ::isspace), plaintext.end());
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

    ciphertext = encryptPlayfair(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;

    string decryptedText = decryptPlayfair(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}