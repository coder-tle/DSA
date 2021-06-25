    void preProcess(){
        for(int i = 0; i<1001; i++){
            for(int j = 0; j<1001; j++){
                cache[i][j] = INT_MAX;
            }
        }
    }
    int lcs2(int na, int nb, string *sA, string * sB)
    {
        // your code here
        if(na<1||nb<1)
            return 0;
    
    if(cache[na][nb]==INT_MAX){    
        if((*sA)[na-1]==(*sB)[nb-1])
            cache[na][nb]= 1 + lcs2(na-1, nb-1, sA, sB);
        else{
            cache[na][nb] =  max(lcs2(na-1, nb, sA, sB), lcs2(na, nb-1, sA, sB));
        }
    }
    return cache[na][nb];
    }
