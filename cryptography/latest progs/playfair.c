#include <stdlib.h>
#include <stdio.h>

void playfair_encipher(char *key, const char *plaintext, char *ciphertext);
void playfair_decipher(char *key, const char *ciphertext, char *plaintext);
void prepare_for_playfair(char *originaltext, char *plaintext);

int main(int argc, char *argv[]){
    /* the string to encipher / decipher */
    char *originaltext = "Defend the east wall of the castle.";
    
    /* allocate some space for results of enciphering/deciphering */
    char *plaintext = malloc(strlen(originaltext)+2);
    char *ciphertext = malloc(strlen(originaltext)+2);
    char *result = malloc(strlen(originaltext)+2);
    
    /* we have to remove punctuation, spacing etc. and make the string an
    even number of bytes long */
    prepare_for_playfair(originaltext,plaintext);
    
    /* the following lines do all the enciphering and deciphering */
    playfair_encipher("cdefghiklmnopqrstuvwxyzab", plaintext,ciphertext);
    playfair_decipher("cdefghiklmnopqrstuvwxyzab", ciphertext,result);
    
    /* print our results */
    printf("-->original:   %s\n-->cleaned:    %s\n-->ciphertext: %s\n-->plaintext:  %s\n",
            originaltext,plaintext,ciphertext,result);
    
    free(plaintext);
    free(ciphertext);
    free(result);
    
    system("PAUSE");
    return 0;
}

/*******************************************************************
void playfair_encipher(char *key, const char *plaintext, char *ciphertext)
- Uses playfair cipher to encipher some text.
- takes a key, string of plaintext, result returned in ciphertext.
- ciphertext should be an array the same size as plaintext.
- The key is a string containing each of the 26 letters in the alphabet.
*******************************************************************/
void playfair_encipher(char *key, const char *plaintext, char *ciphertext){
    int i = 0, length = strlen(plaintext); 
    char a,b;   
    int a_ind, b_ind, a_row, b_row, a_col, b_col;   
     
    for(i = 0; i < length; i+=2){
        a = tolower(plaintext[i]);
        b = tolower(plaintext[i+1]);
        
        a_ind = (int)strchr(key,a) - (int)key;
        b_ind = (int)strchr(key,b) - (int)key;
        a_row = a_ind / 5;
        b_row = b_ind / 5;
        a_col = a_ind % 5;
        b_col = b_ind % 5;

        if(a_row == b_row){
            if(a_col == 4){
                ciphertext[i] = key[a_ind - 4];
                ciphertext[i+1] = key[b_ind + 1];
            }else if(b_col == 4){
                ciphertext[i] = key[a_ind + 1];
                ciphertext[i+1] = key[b_ind - 4];
            }else{
                ciphertext[i] = key[a_ind + 1];
                ciphertext[i+1] = key[b_ind + 1];
            }
        }else if(a_col == b_col){
            if(a_row == 4){
                ciphertext[i] = key[a_ind - 20];
                ciphertext[i+1] = key[b_ind + 5];
            }else if(b_row == 4){
                ciphertext[i] = key[a_ind + 5];
                ciphertext[i+1] = key[b_ind - 20];
            }else{
                ciphertext[i] = key[a_ind + 5];
                ciphertext[i+1] = key[b_ind + 5];
            }
        }else{
            ciphertext[i] = key[5*a_row + b_col];
            ciphertext[i+1] = key[5*b_row + a_col];
        }       
    }while (i < length);
    ciphertext[length] = '\0';
}

/*******************************************************************
void playfair_decipher(char *key, const char *ciphertext, char *plaintext)
- Uses playfair cipher to decipher some text.
- takes a key, string of ciphertext, result returned in plaintext.
- plaintext should be an array the same size as ciphertext.
- The key is a string containing each of the 26 letters in the alphabet.
*******************************************************************/
void playfair_decipher(char *key, const char *ciphertext, char *plaintext){
    int i, length = strlen(ciphertext); 
    char a,b;   
    int a_ind, b_ind, a_row, b_row, a_col, b_col;   
     
    for(i = 0; i < length; i+=2){
        a = tolower(ciphertext[i]);
        b = tolower(ciphertext[i+1]);
        
        a_ind = (int)strchr(key,a) - (int)key;
        b_ind = (int)strchr(key,b) - (int)key;
        a_row = a_ind / 5;
        b_row = b_ind / 5;
        a_col = a_ind % 5;
        b_col = b_ind % 5;
        if(a_row == b_row){
            if(a_col == 0){
                plaintext[i] = key[a_ind + 4];
                plaintext[i+1] = key[b_ind - 1];
            }else if(b_col == 0){
                plaintext[i] = key[a_ind - 1];
                plaintext[i+1] = key[b_ind + 4];
            }else{
                plaintext[i] = key[a_ind - 1];
                plaintext[i+1] = key[b_ind - 1];
            }
        }else if(a_col == b_col){
            if(a_row == 0){
                plaintext[i] = key[a_ind + 20];
                plaintext[i+1] = key[b_ind - 5];
            }else if(b_row == 0){
                plaintext[i] = key[a_ind - 5];
                plaintext[i+1] = key[b_ind + 20];
            }else{
                plaintext[i] = key[a_ind - 5];
                plaintext[i+1] = key[b_ind - 5];
            }
        }else{
            plaintext[i] = key[5*a_row + b_col];
            plaintext[i+1] = key[5*b_row + a_col];
        }
    }
    plaintext[length] = '\0'; /* Null terminate */  
}

/************************************************************************
void prepare_for_playfair(char *originaltext, char *plaintext)
- removes all characters that are not letters. i.e. all numbers, punctuation,
 spaces etc. are removed (uppercase is also converted to lowercase). If the length
 of the string is odd, an x is appended to make it an even length
- playfair can only encrypt even length strings.
- If you want numbers, punctuation etc. you must spell it out e.g.
 'stop' for period, 'one', 'two' etc.
**************************************************************************/
void prepare_for_playfair(char *originaltext, char *plaintext){
    int i, j, length = strlen(originaltext);
    
    for(i = 0, j = 0; i < length; i++, j++){
        while(!isalpha(originaltext[i])) i++;
        if(i >= length) break;
        plaintext[j] = tolower(originaltext[i]);
    }
    /* if the string is an even length, leave it */
    if (j % 2 == 0) plaintext[j] = '\0';
    /* else append an 'x' */
    else {
        plaintext[j] = 'x';
        plaintext[j+1] = '\0';
    }
}

