#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Pada problem ini, dapat diselesaikan dengan hash table

#define TABLE_SIZE 200003  // Size dari Tablenya

struct HashTable { //Deklarasi Hash tablenya dengan struct
    char **key;
    int size;
};

struct HashTable* createHashTable(int size) {  //Function untuk membuat hash table
    struct HashTable *table = (struct HashTable *)malloc(sizeof(struct HashTable));
    table->key = (char **)calloc(size, sizeof(char *));
    table->size = size;
    return table;
}

int Hash(char *string, int size) { //Function hashnya
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % size;
}

void insertHash(struct HashTable *table, char *words) { //Function untuk insert kata menjadi hash
    int index = hash(word, table->size);
    while (table->key[index] != NULL) {
        index = (index + 1) % table->size;
    }
    table->keys[index] = word;
}

e
bool search(struct HashTable *table, char *words) { //Function untuk searching dengan boolean
    int index = hash(word, table->size);
    while (table->key[index] != NULL) {
        if (strcmp(table->key[index], words) == 0) return true;
        index = (index + 1) % table->size;
    }
    return false;
}

char* concatenate(char *str1, char *str2) { // Function untuk Concatenate dari 2 strings
    int len1 = strlen(str1), len2 = strlen(str2);
    char *results = (char *)malloc(len1 + len2 + 1);
    strcpy(results, str1);
    strcat(results, str2);
    return results;
}

int main() {
    int a, b, c;
    scanf("%d", &a); //memasukkan input
    
    struct HashTable *dictionary = createHashTable(TABLE_SIZE);
    
    for (int i = 0; i < a; i++) {
        char *words = (char *)malloc(101);
        scanf("%s", words);
        insertHash(dictionary, words); //memanggil function insert hash
    }
    
    scanf("%d", &b);
    char AndaS[b][101];
    for (int i = 0; i < b; i++) {
        scanf("%s", AndaS[i]);
    }
    
    scanf("%d", &c);
    char Players[c][101];
    bool used[c];
    memset(used, 0, sizeof(used)); //memakai memset
    
    for (int i = 0; i < c; i++) {
        scanf("%s", Players[i]);
    }
    
    int matchesCount = 0;
    
    for (int i = 0; i < b; i++) {
        bool matched = false;
        for (int j = 0; j < c && !matched; j++) {
            if (!used[j]) {
                char *concat1 = concatenate(AndaS[i], Players[j]); //pemanggilan function concatenate
                char *concat2 = concatenate(Players[j], AndaS[i]);
                if (search(dictionary, concat1) || search(dictionary, concat2)) { //pemanggilan function search
                    used[j] = true;
                    matchesCount++;
                    matched = true;
                }
                free(concat1);
                free(concat2); //Untuk membersihkan sisa memory dari concat
            }
        }
    }
    
    printf("%d\n", matchesCount);
    free(dictionary->key); //Untuk membersihkan sisa memory dari dictionary
    free(dictionary);
    getch();
    return 0;
}
