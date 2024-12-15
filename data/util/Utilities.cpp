#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

struct Utilities {
    static bool caseInsensitiveCharCompare(char a, char b) {
        return tolower(a) == tolower(b);
    }

    static bool caseInsensitiveSubstringSearch(const string &str,
                                               const string &substr) {
        auto it = search(str.begin(), str.end(), substr.begin(),
                         substr.end(), caseInsensitiveCharCompare);
        return it != str.end();
    }

    static string getTime() {
        time_t rawTime;
        char buffer[80];

        time(&rawTime);
        const tm *timeInfo = localtime(&rawTime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeInfo);
        string str(buffer);
        return str;
    }
};
