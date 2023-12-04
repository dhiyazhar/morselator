#include <bits/stdc++.h>
#include "translator.hpp"
using namespace std;

int main() {

    string morse;
    // getline(cin, kata);
    getline(cin, morse);

    morse_to_text(&morse[0]);
    // text_to_morse(kata);

    return 0;
    
}