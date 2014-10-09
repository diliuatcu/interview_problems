#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// print all anagram groups in a given string


vector<string> strsplit(string str,string dil){
    int pos = 0;
    vector<string> result;
    while((pos = str.find(dil))!=std::string::npos){
        string token = str.substr(0,pos);
        if(token.size()!=0) result.push_back(token);
        str.erase(0,pos+dil.size());
    }
    if(str.size()!=0) result.push_back(str);
    return result;
}

vector<vector<string> > anagrams(string str){
    vector<string> words = strsplit(str," ");
    unordered_map<string,int> aprd;
    vector<vector<string> > result;

    for(int i = 0;i<words.size();i++){
        string tmp(words[i]);
        std::sort(tmp.begin(),tmp.end());
        if(aprd.find(tmp)==aprd.end()){
            aprd[tmp] = i;
        }
        else {
            if(aprd[tmp]<0) {
                result[-aprd[tmp]-1].push_back(words[i]);
            }
            else{
                vector<string> anaggrp;
                anaggrp.push_back(words[aprd[tmp]]);
                anaggrp.push_back(words[i]);
                result.push_back(anaggrp);
                aprd[tmp] = -result.size();
            }
        }
    }
    return result;
}

int main(){
    vector<vector<string> > anagrp = anagrams("abb bab  bbb acd abb cda f  ");
    for(int i = 0;i<anagrp.size();i++){
        for(int j = 0;j<anagrp[i].size();j++)
            cout<<anagrp[i][j]<<" ";
        cout<<endl;
    }
}
