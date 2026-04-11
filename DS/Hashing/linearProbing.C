#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pair
{
    char *key, *value;
} pair;

typedef struct HashTable
{
    int size;
    int elec;
    pair **arr;
} hashTable;

hashTable *initHashTable(int s)
{
    hashTable *ht = (hashTable *)malloc(sizeof(hashTable));
    ht->size = s;
    ht->arr = (pair **)malloc(sizeof(pair *) * s);
    ht->elec = 0;

    for (int i = 0; i < s; i++)
    {
        ht->arr[i] = NULL;
    }

    return ht;
}

pair *createPair(char *key, char *value)
{
    pair *p = (pair *)malloc(sizeof(pair));
    p->key = strdup(key);
    p->value = strdup(value);

    return p;
}

int hash(char *s, hashTable *ht)
{
    int c = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        c += s[i];
    }

    return (c % ht->size);
}

void insert(hashTable *ht, char *key, char *value)
{
    int id = hash(key, ht);
    while (ht->arr[id] != NULL)
    {
        id = (id + 1) % ht->size;
    }

    ht->arr[id] = createPair(key, value);
    ht->elec++;
}

void display(hashTable *ht)
{
    printf("\n Display of the hashtable: \n");
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->arr[i] == NULL)
            continue;
        printf("%s : %s \n", ht->arr[i]->key, ht->arr[i]->value);
    }
}

int search(hashTable *ht, char *key)
{
    int id = hash(key, ht), c = 0;
    while (ht->arr[id] != NULL && strcmp(ht->arr[id]->key, key) != 0)
    {
        id = (id + 1) % ht->size;
    }

    if (ht->arr[id] == NULL || strcmp(ht->arr[id]->key, key) != 0)
        return -1;
    return id;
}

int remove(hashTable *ht, char *key)
{
    int id = hash(key, ht), c = 0;
    while (ht->arr[id] != NULL && strcmp(ht->arr[id]->key, key) != 0)
    {
        id = (id + 1) % ht->size;
    }

    if (ht->arr[id] == NULL || strcmp(ht->arr[id]->key, key) != 0)
        return 0;

    ht->arr[id] = NULL;
    ht->elec--;
    return 1;
}

int main()
{
    int s;
    printf("Size of the hash table: ");
    scanf("%d", &s);
    hashTable *ht = initHashTable(s);

    char *key = (char *) malloc(sizeof(char)*50), *value = (char *) malloc(sizeof(char)*50);

    int f;
    printf("1. Insert, 2. Search, 3. Display, 4. Delete: ");
    scanf("%d", &f);
    while (f != 5)
    {
        if (f == 1)
        {
            printf("Key: ");
            scanf("%s", key);
            printf("Value: ");
            scanf("%s", value);
            printf("Got %s : %s\n", key, value);

            insert(ht, key, value);
        }

        else if (f == 2)
        {
            printf("Key: ");
            scanf("%s", key);
            int r = search(ht, key);
            char ans[100];
            if (r != -1)
                strcpy(ans, ht->arr[r]->value);
            else
                strcpy(ans, "Not Found!");

            printf("Value: %s\n", ans);
        }

        else if (f == 3)
        {
            display(ht);
        }

        else if (f == 4)
        {
            printf("Key: ");
            scanf("%s", key);
            int r = remove(ht, key);
            if (r == 1)
                printf("Deleted succesfully!");
        }
        else
            break;

        printf("1. Insert, 2. Search, 3. Display, 4. Delete: ");
        scanf("%d", &f);
    }

    free(ht->arr);
    free(ht);
    free(key);
    free(value);
}