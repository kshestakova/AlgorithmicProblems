#include<iostream>
#include <vector>

using namespace std;

bool checkAllInSubstring(string substring, string target, int& minIndex, int& maxIndex)
{
    minIndex = substring.size() - 1;
    maxIndex = 0;
    for(int i = 0; i < target.size(); i++)
    {
        //cout << "Checking symbol: " << target[i] << endl;
        int f = substring.find(target[i]);
        if(f == string::npos) return false;
        else
        {
            substring.replace(f, 1, " ");
            //cout << "Find: " << f << endl;
            minIndex = min(minIndex, f);
            maxIndex = max(maxIndex, f);
        }
    }
    //cout << "Found: " << substring.substr(minIndex, maxIndex - minIndex + 1) << endl;
    //cout << "minIndex: " << minIndex << "  maxIndex: " << maxIndex << endl;
    return true;
}

string minSubstring(string corpus, string target) {
    if(corpus == target) return target;
    if(corpus.size() < target.size()) return "";
    if(corpus.find(target) != string::npos) return target;

    int n = corpus.size();
    int minIndex = n - 1, maxIndex = 0;
    int minD = n + 1;
    string result = "";
    for(int l = 0; l < n; ++l)
    {
        for(int r = n-1; r > l; --r)
        {
            //cout << "Checking substring: " << corpus.substr(l, r-l+1) << endl;
            if(checkAllInSubstring(corpus.substr(l, r-l+1), target, minIndex, maxIndex))
            {
                if(maxIndex - minIndex + 1 < minD)
                {

                    minD = maxIndex - minIndex + 1;
                    //cout << "~~~~~~~~ NEW RESULT ~~~~~~~~ " << corpus.substr(l + minIndex, minD) << endl;
                    result = corpus.substr(l + minIndex, minD );
                }
            }
            else break;
        }
    }

    return result;
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