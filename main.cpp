#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#define MAX_CHAR 256
char firstNotRepeatingCharacter(std::string s) {
    bool repeatCheck[MAX_CHAR];
    vector<char> store;
    for(int i = 0; i < MAX_CHAR; i ++) {
        repeatCheck[i] = false;
    }
    for(int i = 0; i < s.size(); i ++) {

        if(!repeatCheck[s.at(i)]) {
            if(store.empty()) {store.push_back(s.at(i));}
            else {
                for(vector<char>::iterator it = store.begin(); it < store.end(); it ++) {

                    if(*it == s.at(i)) {
                        store.erase(it);
                        repeatCheck[s.at(i)] = true;
                        break;
                    }
                }
                if(!repeatCheck[s.at(i)]) {store.push_back(s.at(i));}
            }
        }
    }
    if(store.empty()) return '_';
    return store[0];
}
int main()
{
    cout << firstNotRepeatingCharacter("aaafg") << endl;
    cout << firstNotRepeatingCharacter("dfodofgdbzzz") << endl;
    cout << firstNotRepeatingCharacter("cccc");
    return 0;
}
