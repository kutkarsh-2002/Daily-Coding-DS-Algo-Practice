class Solution {
public:
//     string getHint(string secret, string guess) {
        
//     }
    
    string getHint(string secret, string guess) {
    int n = secret.length();
    int m = guess.length();
    
    int bulls = 0;
    int cows = 0;
    
    string ans;
     //calculatung bulls and changing the corrensponding characters to 'a' and 'b' (for instance) so that they do not interfere in calculating cows
    for(int i=0; i<n && i<m; i++){
        if(secret[i] == guess[i]){
            bulls++;
            secret[i] = 'a';
            guess[i] = 'b';
        }
    }
    
    unordered_map<char,int> freq_secret; //frequency of chararacters in sceret
    unordered_map<char,int> freq_guess; //frequency of characters in guess
    
    for(int i=0; i<n; i++){
        freq_secret[secret[i]]++;
    }
    
    for(int i=0; i<m; i++){
        freq_guess[guess[i]]++;
    }
    //calculating cows
    for(auto itr : freq_guess){
        char g = itr.first;
        int freq = itr.second;
        
        cows += min(freq, freq_secret[g]);
		//let say if secret has less number of the given character in it so we can only arrange that much elements to make then bulls and if secret has higher frequency than guess then we can arrange all the same element **note : remember that bulls has nothing to do with the frequency thats why we already excluded the by changing them from number to some other character**
    }
    
    ans = to_string(bulls) + "A" + to_string(cows) + "B";
    
    return ans;
    
}
};