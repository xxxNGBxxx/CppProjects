#include <iostream>

char* reverse(char* s);

int main(){

    char c[] = {'a','b','c'};

    char* s = reverse(c);

    std::cout << s <<std::endl;

    return 0;
}

 // char *ptr = reverse(STR); Reverse the characters of STR[] in place, and return STR.

char* reverse(char *s) {
    char symbol;
    char* first;
    char* second;

      /* Point q at the last character in s[], or at &s[0] if s is empty. */
    for (second = s; *second != '\0'; ++second)
    ;
    if (second > s){
    --second;
    }

    /* Simultaneously sweep p from front to back and q from back to front,
    * swapping characters at p and q, until the pointers meet. */
    for (first = s; first < second; ++first, --second) {
        symbol = *first;
        *first = *second;
        *second = symbol;
    }
    return s;
}
