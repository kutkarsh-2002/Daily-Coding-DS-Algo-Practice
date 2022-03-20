class Solution {
public:
    int countCollisions(string dir) {
        
        /*int n=directions.size();
        int coll=0;
        
        for(int i=0; i<n-1; i++){
            
            if(directions[i]=='R' && directions[i+1]=='L'){
                coll+=2;
            }
            else if((directions[i]=='S' || directions[i+1]=='S') && (directions[i]=='R' || directions[i+1]=='R' || directions[i]=='L' || directions[i+1]=='L')){
                coll+=1;
                
                if(directions[i+1]=='L' || directions[i+1]=='R'){
                    directions[i+1]='S';
                }
            }
        }
        
        return coll;*/
        
        int res(0), n(size(dir)), i(0), carsFromRight(0);
        
        while (i < n and dir[i] == 'L') i++; // skipping all the cars going to left from beginning as they will never collide
        
        for ( ; i<n; i++) {
            if (dir[i] == 'R')  carsFromRight++;
            else {
                // if dir[i] == 'S' then there will be carsFromRight number of collission
                // if dir[i] == 'L' then there will be carsFromRight+1 number of collision (one collision for the rightmost cars and carsFromRight collision for the cars coming from left)
                res += (dir[i] == 'S') ? carsFromRight : carsFromRight+1;
                carsFromRight = 0;
            }
        }
        return res;
    }
};

/*if(directions[i]=='S' && directions[i+1]=='S'){
                continue;
            }
            else if(directions[i]==directions[i+1])
            {
                i++;
            }
            else if(directions[i]=='L' && directions[i]=='R'){
                i++;
            }
            else if(directions[i]!=directions[i+1] && (directions[i]!='S' && directions[i+1]!='S'))
            {
                coll+=2;
                directions[i]='S';
                directions[i+1]='S';
            }
            else if((directions[i]=='S' || directions[i+1]=='S') && directions[i]!=directions[i+1]){
                coll+=1;
                directions[i+1]='S';
            }
            
            */