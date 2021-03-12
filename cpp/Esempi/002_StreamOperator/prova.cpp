#include <iostream>

int main(){
    /*
        3 base 10 -> 0011 base 2
        Con l'operatore '<<' si fa lo shift di due cifre verso destra, quindi
        0011 -> 1100 = (2^3+2^4)b10 = (12)b10
    */
    std::cout << (3<<2) << std::endl;

    return 0;
}