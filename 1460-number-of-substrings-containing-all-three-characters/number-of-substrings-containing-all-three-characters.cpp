class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> types;
        
        int sub = 0;
        int n = s.size();

          int a = -1,b = -1,c = -1;
          for(int i = 0;i<n;i++){
            if(a!=-1 && b!=-1 && c!=-1){
                int d = min(a,b);
                sub+= min(c,d)+1;

            }
            if(s[i]=='a'){
                a = i;
            }else if(s[i]=='b'){
                b = i;
            }else{
                c = i;
            }
            
          }
          if(a!=-1 && b!=-1 && c!=-1){
                int d = min(a,b);
                sub+= min(c,d)+1;

            }


    
        // for(int i = 0;i<n;i++){
        //     map<char,int> types;
        //     for(int j = i;j<n;j++){
                
        //         types[s[j]]++;
        //         if(types.size()>=3){
        //             maxsub += n-j;
        //             break;
        //         }

        //     }
        // }
        return sub;
    }
};