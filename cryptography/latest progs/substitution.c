#include <stdlib.h>
#include <stdio.h>

void simplesub_encipher(char *key, const char *plaintext, char *ciphertext);
void simplesub_decipher(char *key, const char *ciphertext, char *plaintext);

int main(int argc, char *argv[]){
    /* the string to encipher / decipher */
    char *plaintext = "Defend the east wall of the castle.";
    
    /* allocate some space for results of enciphering/deciphering */
    char *ciphertext = malloc(strlen(plaintext)+1);
    char *result = malloc(strlen(plaintext)+1);
    
    /* the following lines do all the enciphering and deciphering */
    /* currently, it is being used as a caesar cipher, but this is easy to 
    change by providing a different key. The user should note that no checks 
    are performed on the length of the string or that it does not contain
    duplicate characters etc. */
    simplesub_encipher("cdefghijklmnopqrstuvwxyzab", plaintext,ciphertext);
    simplesub_decipher("cdefghijklmnopqrstuvwxyzab", ciphertext,result);
    
    /* print our results */
    printf("-->original:   %s\n-->ciphertext: %s\n-->plaintext:  %s\n",
            plaintext,ciphertext,result);
    
    free(ciphertext);
    free(result);
    
    system("PAUSE");
    return 0;
}

/*******************************************************************
void simplesub_encipher(char *key, const char *plaintext, char *ciphertext)
- Uses simple substitution cipher to encipher some text.
- takes a key, string of plaintext, result returned in ciphertext.
- ciphertext should be an array the same size as plaintext.
- The key is a string containing each of the 26 letters in the alphabet.
*******************************************************************/
void simplesub_encipher(char *key, const char *plaintext, char *ciphertext){
    int index, i, length = strlen(plaintext);    
    for(i = 0; i < length; i++){
        /* if the current character is not a letter, don't change it */
        if (!isalpha(plaintext[i])){
            ciphertext[i] = plaintext[i];    
        }else{
            index = tolower(plaintext[i]) - 'a';
            ciphertext[i] = key[index];
        }
    }
    ciphertext[i] = '\0'; /* Null terminate */  
}

/*******************************************************************
void simplesub_decipher(char *key, const char *ciphertext, char *plaintext)
- Uses simple substitution cipher to decipher some text.
- takes a key, string of ciphertext, result returned in plaintext.
- plaintext should be an array the same size as ciphertext.
- The key is a string containing each of the 26 letters in the alphabet.
*******************************************************************/
void simplesub_decipher(char *key, const char *ciphertext, char *plaintext){
    int index, i, length = strlen(ciphertext); 
    char ikey[26]; /* our inverse key */
    /* first we generate an inverse key to do decryption */
    for(i = 0; i < 26; i++) ikey[ key[i]-'a' ] = 'a' + i;
       
    for(i = 0; i < length; i++){
        /* if the current character is not a letter, don't change it */
        if (!isalpha(ciphertext[i])){
            plaintext[i] = ciphertext[i];    
        }else{
            index = tolower(ciphertext[i]) - 'a';
            plaintext[i] = ikey[index];
        }
    }
    plaintext[i] = '\0'; /* Null terminate */  
}

