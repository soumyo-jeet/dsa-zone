#include <stdio.h>
#include <stdlib.h>

typedef struct HashTable {
    int size;
    int *arr;
    int elec;
} hashTable;

hashTable *initHashTable (int s)
{
    hashTable *ht = (hashTable *) malloc(sizeof(hashTable));
    ht->size = s;
    ht->arr = (int *) malloc(sizeof(int) * s);
    ht->elec = 0;

    for(int i = 0; i < s; i++)
    {
        ht->arr[i] = 0;
    }

    return ht;
}

void insert (hashTable *ht, int x, int s)
{
    if(ht->elec == s) 
    {
        printf("Element count exceeded!");
        return;
    }

    int id = x % ht->size;
    while(ht->arr[id] != 0)
    {
        id = (id + 1) % ht->size;
    }

    ht->arr[id] = x;
    ht->elec ++;
}

void display (hashTable *ht)
{
    printf("\n Display of the hashtable: \n");
    for(int i = 0; i < ht->size; i++)
    {
        printf("%d ", ht->arr[i]);
    }
}

int search (hashTable *ht, int x)
{
    int id = x % ht->size, c = 0;
    while(ht->arr[id] != x && ht->arr[id] != 0 && c != ht->elec)
    {
        id = (id + 1) % ht->size;
        
    }

    if(ht->arr[id] != x) return -1;
    return id;
}

int remove (hashTable *ht, int x)
{
    int id = x % ht->size, c = 0;
    while(ht->arr[id] != x && ht->arr[id] != 0 && c != ht->elec)
    {
        id = (id + 1) % ht->size;
        
    }

    if(ht->arr[id] != x) return 0;
    ht->arr[id] = 0;
    ht->elec --;
    return 1;
}


int main()
{
    int s;
    printf("Size of the hash table: ");
    scanf("%d", &s);
    hashTable *ht = initHashTable(s);

    int as;
    printf("Number of element want to put: ");
    scanf("%d", &as);

    int f;
    printf("1. Insert, 2. Search, 3. Display, 4. Delete: ");
    scanf("%d", &f);
    while(f != 5)
    {
        if(f==1)
        {
            int x;
            printf("Element: ");
            scanf("%d", &x);
            insert(ht,x,as);
        }

        else if(f == 2)
        {
            int x;
            printf("Element: ");
            scanf("%d", &x);
            int r = search(ht, x);
            printf("Present at: %d\n", r);
        }

        else if(f == 3)
        {
            display(ht);
        }

        else if(f==4)
        {
            int x;
            printf("Element: ");
            scanf("%d", &x);
            int r = remove(ht, x);
            if(r == 1) printf("Deleted succesfully!");
        }
        else break;

        printf("1. Insert, 2. Search, 3. Display, 4. Delete: ");
        scanf("%d", &f);
    }
    
    free(ht->arr);
    free(ht);
}