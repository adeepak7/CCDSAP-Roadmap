/*
    Solve for the string: abaxabab
    it covers all the cases.
*/

#include <bits/stdc++.h>
using namespace std;

int z[1000001];

inline void ZAlgorithm(string s){
    
    int len = s.length();
    
    int left = 0;
    int right = 0;
    
    z[0] = 0;
    
    for(int k=1;k<len;k++){
        
        if(k>right){
            
            left = right = k;
            
            while(right<len && s[right]==s[right-left]){
                right++;
            }
            
            z[k] = right-left;
            right--;
        
        }else{
            // We are operating inside the Z-Box
            int k1 = k - left;
            
            //If the z[k1] does not cross the right bound, we just copy it
            if(z[k1] <= right-k){
                
                z[k] = z[k1];
            
            }else{ // Else we change our Z-Box by assigning left = k and check for further matches.
                
                left = k;
                while(right<len && s[right]==s[right-left]){
                    right++;
                }
                
                z[k] = right-left;
                right--;
            }
            
        }
    }
}


int main(){
    
    string pat, s;
    cin>>pat>>s;
    
    s = pat + "$" + s;
    
    int len = s.length();
    int patLen = pat.length();
    
    ZAlgorithm(s);
    
    int cnt = 0;
    
    for(int i=1;i<len;i++){
        if(z[i] == patLen){
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
    
    return 0;
}