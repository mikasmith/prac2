#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
    double s1, s2, s3;
    double score=0.0;
    double prev_score=0.0;
    int n, winner=0; 
    
    while(4==scanf("%d%lg%lg%lg", &n, &s1, &s2, &s3)){
        
        if(s1<s2 && s1<s3){
            score= (s2+s3)/2;
        }else if(s2<s1 && s2<s3){
            score= (s1+s3)/2;
        }else{
            score= (s1+s2)/2;
        }

        if(score > prev_score){
            winner= n;
            prev_score= score; 
            
        }
    }

    printf("%d\n", winner);
    return EXIT_SUCCESS;
}
