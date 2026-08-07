#include <bits/stdc++.h>
using namespace std;

char temp = 'a';

// string -> array of characters
// ways to declare n intialize strings

char a[10];
char b[4] = {'a', 'b', 'c', 'd'};

char c[5] = "abcd"; // automatically adds null character at the end

char x[3] = { 65, 78, 67 }; // ASCII values



// counting the lenght iof string  ..as it ends with null character '\0' we can count the length of string by counting the number of characters before null character

int length(string &str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

//  used to toggle the case of each character in the string(a-z -> 97-122 && A-Z -> 65-90)
string caseChange(string &str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] >='a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
    return str;
}

int countVowels(string str){
    int count = 0;
    for(char ch : str){
        if( (ch == 'a') || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            count++;
        }
    }
    return count;
}

int countConsonants(string str){
    int count = 0;
    for(char ch : str){
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ){
            if( !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') ){
                count++;
            }
        }
    }
    return count;
}

int countWord(string str){
    int count = 1;
    for(int i = 0; i < str.length()-1; i++){
        if(str[i] == ' ' && str[i+1] != ' '){ //i+1 is used to check if the next character is not a space, to avoid counting multiple spaces as multiple words
            count++;
        }
    }
    return count;
}

//to validate a string

bool isValid(string str){
    bool valid = true;
    for( char ch : str){
        if (!(ch >= 65 && ch <= 90) && !(ch >= 97 && ch <= 122 ) && !(ch >= 48 && ch <= 57)){
            valid = false;
        }
    }
    return valid;
}


string reverseString(string &str){
    for(int i = 0, j = str.length()-1; i < j; i++, j--){
        swap(str[i], str[j]);
        return str;
    }
}


bool areEqual(string str1, string str2 ){
    if(str1.length() == str2.length()){
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] == str2[i]) return true;
        }
    }
    return false;
}

bool isPalindrome(string str1){
    int i = 0, j = str1.length()-1;

    while(i < j){
        if(!(str1[i] == str1[j])) return false;

    i++;
    j--;
    }
    return true;
}

void findDuplicates(string &str){
    //using hashing
    //only for lower case. Similar logic for upper case or for both increase the size of the freq vector.

    vector<int> freq(26, 0);

    for(char ch : str){
        freq[(ch)-97]++;
    }
    cout << "The duplicates are"<<endl;

    for(int i=0; i < 26; i++){
        if(freq[i] > 1){
            cout<< char(i + 97)<<endl;
        }
    }


}

bool isAnagram(string &str1, string &str2){
    if(str1.length() != str2.length()) return false;
    //for lower case. Similar logic can be used for uppercase.

    vector<int> freq(26,0);
    for(char ch : str1){
        freq[ch - 97]++;
    }
    
    for(char sh : str2){
        freq[sh - 97]--;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i]!=0) return false;
    }

    return true;
}

void strPermutations(string &str, int index){
    if(index == str.length()){
        cout<< str <<endl;
        return;
    }

    for(int i=index; i < str.length(); i++){
        swap(str[index], str[i]);

        strPermutations(str, index +1);

        swap(str[index], str[i]); //backtrack
    }

}

int main(){

    string a = "abc";
    strPermutations(a,0);

    return 0;

}