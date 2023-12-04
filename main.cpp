#include <bits/stdc++.h>
#include "translator.hpp"
#include "page.hpp"
using namespace std;

int main(){

    string morse;
    // getline(cin, kata);
    getline(cin, morse);

    morse_to_text(&morse[0]);

    return 0;
    
}