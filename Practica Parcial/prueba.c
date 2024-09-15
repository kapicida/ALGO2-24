#include <stdbool.h>

int VoltearNumero(int pNum)
{
    if(pNum<10){
    return pNum;
    }
    else{
        return pNum % 10+VoltearNumero(pNum/10);
    }
}

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    
    if(x<10){
        return true;
    }
    
    int inverso;
    int digito = 0;

    while(x>0){
        digito = x % 10;
        inverso = inverso * 10 + digito;
        x=x/10;
    }
    if(inverso == x){
        return true;
    }
}

int main(){
printf("%s",isPalindrome(121));
}