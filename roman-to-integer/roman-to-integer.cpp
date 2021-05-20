class Solution{
public:
    int romanToInt(string s) {
        
//         map<char,int>m{
//         {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
//         };
        
        
//         int sum=0;
        
//         for(int i=0; i<s.size(); i++){
            
//             if(m[s[i]]>=m[s[i+1]]){
//                 sum+=m[s[i]];
//             }
//             else if(m[s[i]]<m[s[i+1]] && s.size()==2){
//                 sum=m[s[i+1]]-m[s[i]];
//             }
//         }
        
        
//             return sum;
        int total=0;
        for(int i=0;i<s.length();i++){
            if((s[i]=='I')&&(s[i+1]=='V')){
                total+=4;
                i++;
            }
            else if((s[i]=='I')&&(s[i+1]=='X')){
                total+=9;
                i++;
            }
            else if((s[i]=='X')&&(s[i+1]=='L')){
                total+=40;
                i++;
            }
            else if((s[i]=='X')&&(s[i+1]=='C')){
                total+=90;
                i++;
            }
            else if((s[i]=='C')&&(s[i+1]=='D')){
                total+=400;
                i++;
            }
            else if((s[i]=='C')&&(s[i+1]=='M')){
                total+=900;
                i++;
            }
            else if(s[i]=='I'){
                total+=1;
            }
            else if(s[i]=='V'){
                total+=5;
            }
            else if(s[i]=='X'){
                total+=10;
            }
            else if(s[i]=='L'){
                total+=50;
            }
            else if(s[i]=='C'){
                total+=100;
            }
            else if(s[i]=='D'){
                total+=500;
            }
            else if(s[i]=='M'){
                total+=1000;
            }
        }
        return total;
        
    }
};