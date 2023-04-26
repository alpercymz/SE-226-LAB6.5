#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


//Q1
vector<int> sameNumberGenerator(vector<int> list1, vector<int> list2) {
    vector<int> sameNumbers;

    set<int> set1(list1.begin(), list1.end());
    set<int> set2(list2.begin(), list2.end());

    set_intersection(set1.begin(), set1.end(),
                     set2.begin(), set2.end(),
                     back_inserter(sameNumbers));

    return sameNumbers;
}

//Q2

vector<string> findPalindromes(vector<string> words) {
    vector<string> palindromes;

    for (string word : words) {
        if (word == string(word.rbegin(), word.rend())) {
            palindromes.push_back(word);
        }
    }

    return palindromes;
}

//Q3

vector<int> primeFinder(vector<int> list) {
    int i = 0;
    while (i < list.size()) {
        if (list[i] > 1) {
            bool is_prime = true;
            for (int j = 2; j < list[i]; j++) {
                if (list[i] % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (!is_prime) {
                list.erase(list.begin() + i);
                continue;
            }
        } else {
            list.erase(list.begin() + i);
            continue;
        }
        i++;
    }
    return list;
}

//Q4


vector<string> anagramFinder(string word, vector<string> wordList) {
    string word_chars = word;
    word_chars.erase(remove_if(word_chars.begin(), word_chars.end(), ::isspace), word_chars.end());
    transform(word_chars.begin(), word_chars.end(), word_chars.begin(), ::tolower);
    sort(word_chars.begin(), word_chars.end());

    vector<string> anagrams;
    for (string w : wordList) {
        string w_chars = w;
        w_chars.erase(remove_if(w_chars.begin(), w_chars.end(), ::isspace), w_chars.end());
        transform(w_chars.begin(), w_chars.end(), w_chars.begin(), ::tolower);
        sort(w_chars.begin(), w_chars.end());

        if (w_chars == word_chars) {
            anagrams.push_back(w);
        }
    }

    return anagrams;
}

int main() {
    //Q1 test


    vector<int> list1 = {1, 2, 3, 4, 5};
    vector<int> list2 = {2, 4, 6, 8, 10};
    vector<int> sameNumbers = sameNumberGenerator(list1, list2);

    for (int i = 0; i < sameNumbers.size(); i++) {
        cout << sameNumbers[i] << " ";
    }
    cout<<endl;


    //Q2 test



    vector<string> words = {"kayak", "ata", "alper", "eye", "level"};

    vector<string> palindromes = findPalindromes(words);

    for (string palindrome : palindromes) {
        cout << palindrome << " ";
    }
    cout<<endl;



    //Q3 test

    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

    vector<int> primes = primeFinder(list);

    for (int prime : primes) {
        cout << prime << " ";
    }
    cout<<endl;


    //Q4 test


    string word = "listen";
    vector<string> wordList = {"enlist", "google", "inlets", "banana"};

    vector<string> anagram_list = anagramFinder(word, wordList);

    for (string anagram : anagram_list) {
        cout << anagram << " ";
    }
    cout<<endl;


    return 0;
}
