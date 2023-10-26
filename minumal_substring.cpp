#include<iostream>
#include <vector>

using namespace std;


bool checkAllInSubstring(string substring, string target)
{
    //cout << "Checking substring: " << substring << endl;
    for(int i = 0; i < target.size(); i++)
    {
        int f = substring.find(target[i]);
        if(f == string::npos) return false;
        substring.replace(f, 1, " ");
    }
    return true;
}

string minSubstring(string corpus, string target) {
    if(corpus == target) return target;
    if(corpus.size() < target.size()) return "";
    if(corpus.find(target) != string::npos) return target;

    int n = corpus.size();
    for(int d = target.size(); d <= n; d++)
    {
        for(int l = 0; l < n-d+1; ++l)
        {

            if(checkAllInSubstring(corpus.substr(l, d), target))
            {
                return corpus.substr(l, d);
            }
        }
    }

    return "";
}


int main()
{
    string corpus = "aaaaaaaaaaaabc", target = "abc";
    cout << minSubstring(corpus, target) << endl; // expected: abc
    corpus = "a", target ="a";
    cout << minSubstring(corpus, target) << endl; // expected: BANC
    corpus = "ADOBECODEBANC", target = "ABC";
    cout << minSubstring(corpus, target) << endl; // expected: ""
    corpus = "a", target = "aa";
    cout << minSubstring(corpus, target) << endl; // expected: ""
    corpus = "aa", target = "a";
    cout << minSubstring(corpus, target) << endl; // expected: "a"
    corpus = "qxsncfwvbslazxuoxnedkukropehlwfbwxqycntdfgghecvdqbhcwtukkauwzzzvystcfohmupvastekunmqiidtjxriyqdyiyapohekxblrurbpgphoykjhjarhtwfduhvkpzumahdxagmivtxvgiepjvxetehnmczddurgdwdecrmzklxqubgfzfjslqizvheadvghrlnvcbxpnuhjxpqywzrkrbjokqpolxxflkapnzeatmltdbrackkwlvmwlbmxbjcmvebieilzwyszckzgulcihpgsssrtdvhaaligvvfrwaqyksegdjqmywfsoyotuxtwieefbjwxjpxvhcemnwzn", 
    target = "absakloiiordbdfbfda";
    cout << minSubstring(corpus, target) << endl; // expected: "fgghecvdqbhcwtukkauwzzzvystcfohmupvastekunmqiidtjxriyqdyiyapohekxblrurb"
}