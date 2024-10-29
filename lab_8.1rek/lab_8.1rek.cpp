#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str, int i) {
    if (strlen(str) < 3 || str[i + 2] == '\0')
        return 0;

    if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!')
        return 1 + Count(str, i + 1);
    else
        return Count(str, i + 1);
}

char* Change(char* dest, const char* str, char* t, int i) {
    if (str[i + 2] == '\0') {
        while (str[i] != '\0') {
            *t++ = str[i++];
        }
        *t = '\0';
        return dest;
    }

    if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
        strcat(t, "***");
        return Change(dest, str, t + 3, i + 3);
    }
    else {
        *t++ = str[i++];
        *t = '\0';
        return Change(dest, str, t, i);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of '!!!'" << endl;

    char* dest1 = new char[151];
    dest1[0] = '\0';

    char* dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
