#include <iostream>
#include <algorithm>

using namespace std;

struct StringSearch {

    static bool caseInsensitiveCharCompare(char a, char b) {
        return tolower(a) == tolower(b);
    }

    static bool caseInsensitiveSubstringSearch(const string &str,
                                               const string &substr) {
        auto it = search(str.begin(), str.end(), substr.begin(),
                         substr.end(), caseInsensitiveCharCompare);
        return it != str.end();
    }
};