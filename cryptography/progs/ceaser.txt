#include <stdlib.h>
#include <stdio.h>

void caesar_encipher(int key, const char *plaintext, char *ciphertext);
void caesar_decipher(int key, const char *ciphertext, char *plaintext);

int main(int argc, char *argv[]){
    /* the string to encipher / decipher */
    char *plaintext = "Defend the east wall of the castle.";
    /* allocate some space for results of enciphering/deciphering */
    char *ciphertext = malloc(strlen(plaintext)+1);
    char *result = malloc(strlen(plaintext)+1);
    
    /* the following lines do all the enciphering and deciphering */
    caesar_encipher(10, plaintext,ciphertext);
    caesar_decipher(10, ciphertext,result);
    /* print our results */
    printf("-->original:   %s\n-->ciphertext: %s\n-->plaintext:  %s\n",
            plaintext,ciphertext,result);
    
    free(ciphertext);
    free(result);
    
    system("PAUSE");
    return 0;
}

/*******************************************************************
void caesar_encipher(int key, const char *plaintext, char *ciphertext)
- Uses caesar cipher to encipher some text.
- takes a key, string of plaintext, result returned in ciphertext.
- ciphertext should be an array the same size as plaintext.
- The key is the number of places to shift the cipher alphabet 
*******************************************************************/
void caesar_encipher(int key, const char *plaintext, char *ciphertext){
    int i, length = strlen(plaintext);    
    for(i = 0; i < length; i++){
        /* if the current character is not a letter, don't change it */
        if (!isalpha(plaintext[i])){
            ciphertext[i] = plaintext[i];    
        }else{
            ciphertext[i] = (tolower(plaintext[i]) + key - 'a')%26 + 'a';
        }
    }
    ciphertext[i] = '\0'; /* Null terminate */  
}

/*******************************************************************
void caesar_decipher(int key, const char *ciphertext, char *plaintext)
- Uses caesar cipher to decipher some text.
- takes a key, string of ciphertext, result returned in plaintext.
- plaintext should be an array the same size as ciphertext.
- The key is the number of places to unshift the cipher alphabet 
*******************************************************************/
void caesar_decipher(int key, const char *ciphertext, char *plaintext){
    int i, length = strlen(ciphertext);    
    for(i = 0; i < length; i++){
        /* if the current character is not a letter, don't change it */
        if (!isalpha(ciphertext[i])){
            plaintext[i] = ciphertext[i];    
        }else{
            /* the addition of 26 just prevents things from going negative */
            plaintext[i] = (tolower(ciphertext[i]) - 'a' - key + 26)%26 + 'a';
        }
    }
    plaintext[i] = '\0'; /* Null terminate */  
}

