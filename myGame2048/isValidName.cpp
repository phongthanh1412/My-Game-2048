#include"functions.h"

bool isValidChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;

    return 0;
}
bool isValidName(string name) {
    for (int i = 0; i < name.size(); i++) {
        if (!isValidChar(name[i]))
            return 0;
    }
    if (name.length() < 1 || name.length() > 14)
        return 0;
    return 1;
}