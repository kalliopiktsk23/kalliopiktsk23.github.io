#include <stdio.h>

int main(){
    long long n, temp, sum, dr,j;
    int flag=0, megisto;
    char xaraktiras;
    
    
    printf("please give the number to start the aliquot sequence from: ");
    scanf("%lld", &n);
    printf("provide the max aliquot lenght to look for (0 for  unlimited): ");
    scanf("%d", &megisto);
    printf("do you want to print the full sequence ('f') or just the length('l')?:");
    scanf(" %c", &xaraktiras);
    if (n<=0 || megisto<0 || (xaraktiras!='l' && xaraktiras!='f')){   
        printf("error");
        return 1;
    } 
    temp=n;      //ekxorhsh tou arxikou arithmoy ths akoloythias gia na mhn xanete o arithmmos
    while (1){
        if(xaraktiras=='f'){        //efoson o xaraktiras einai f tupwnei olh thn akolouthia h 
            printf("%lld\n", temp);  
        }
        sum=0;
      
        for ( dr = 1; dr*dr<= temp; dr++) { 
            if (temp % dr == 0) {  // kratame mono tous diairetes pou to upoloipo tous me to temp einai iso me 0 
                j = temp / dr; // ypologizoume thn diairesh toy temp me ton teleio diaireth 

                //prosthetoume ton dr an den einai idios arithmos me ton temp
                if (dr != temp) { 
                    sum = sum +dr; 
                }


                if (j != dr && j != temp) { 
                    sum = sum +j;
                }
            }
        }

        if(sum>1000000000000000){  // to athrisma dne prepei na einai akairio mikrotero toy 10^15
            return 1;
        }
        flag++;
        if(sum==0||(flag>=megisto && megisto!=0)){ 
            if(xaraktiras=='f'){
                printf("%lld\n", sum);
            }
            else{
                printf("Length of aliquot sequence %d\n", flag); // metraei epanalipeis ths for 
            }
            break;
        }
        temp=sum;
    
        
     }

}
