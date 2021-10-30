#include <stdio.h>
#include <stdlib.h>

#define time 1000

void spend_time(int n){
    int k = 0;
    for(int i=0;i<n;i++){
        if(k == 1) k--;
        else k++;
    }
}

void bubble_sort(int* vet,int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(vet[j] < vet[j-1]){
                int tmp = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = tmp;
            }
            //spend_time(100);
        }
    }
}

void merge_sort(int* vet,int ini,int fim){
    if(ini >= fim) return;

    //printf("%d %d\n", ini,fim);

    int meio = (ini+fim)/2.0;

    merge_sort(vet,ini,meio);
    merge_sort(vet,meio+1,fim);

    int* tmp = (int*)malloc((fim-ini+1)*sizeof(int));
    int i=ini;
    int j = meio+1;
    int indTmp = 0;
    while(i <= meio && j <= fim){
        if(vet[i] <= vet[j]) tmp[indTmp++] = vet[i++];
        else tmp[indTmp++] = vet[j++];
    }

    while(i <= meio){
        tmp[indTmp++] = vet[i++];
    }

    while(j <= fim){
        tmp[indTmp++] = vet[j++];
    }

    for(int k=0;k<(fim-ini+1);k++){
        vet[ini+k] = tmp[k];
        //spend_time(time);
    }
    free(tmp);

    
    
}

void counting_sort(int* vet,int n){
    int min = 0x7fffffff;
    int max = -0x7fffffff;
    for(int i=0;i<n;i++){
        if(vet[i] > max) max = vet[i];
        if(vet[i] < min) min = vet[i];
        //spend_time(time);
    }

    int *cnt = calloc(max-min+1,sizeof(int));

    for(int i=0;i<n;i++){
        cnt[vet[i]-min]++;
    }
    
    int k=0;
    for(int i=0;i<(max-min+1);i++){
        for(int j=0;j<cnt[i];j++){
            vet[k++] = i+min;
        }
        //spend_time(time);
    }
    
    free(cnt);
}

void quicksort(int* vet,int ini,int fim){
    if(ini >= fim) return;

    //printf("%d %d\n", ini,fim);

    int pivo = vet[fim];

    int i=ini-1,j=ini;
    while(j<fim){
        if(vet[j] < pivo){
            i++;
            int tmp = vet[i];
            vet[i] = vet[j];
            vet[j] = tmp;
        }
        j++;
        //spend_time(time);
    }
    vet[fim] = vet[i+1];
    vet[i+1] = pivo;

    quicksort(vet,ini,i);
    quicksort(vet,i+2,fim);
    
}

void print_vet(int* vet,int n){
    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

/*------------------------------------------------*/
/* Code to remove data from the processor caches. */
#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)
#define LARGEST_CACHE_SZ (6 * MB)
static unsigned char dummy_buffer[LARGEST_CACHE_SZ];
void clean_cache()
{
    unsigned long long i;
    for (i=0; i<LARGEST_CACHE_SZ; i++)
    dummy_buffer[i] += 1;
}

void cpy_vet(int* vet1,int* vet2,int n){
    for(int i=0;i<n;i++){
        vet1[i] = vet2[i];
    }
}



int main(){
    srand(42);

    const int n = 1e6;
    int* vet = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        vet[i] = rand()%RAND_MAX;
    }

    int* unord = (int*)malloc(sizeof(int)*n);;

    //cpy_vet(unord,vet,n);
    //bubble_sort(unord,n);
    //clean_cache();
    
    cpy_vet(unord,vet,n);
    clean_cache();
    merge_sort(unord,0,n-1);
    

    cpy_vet(unord,vet,n);
    clean_cache();
    counting_sort(unord,n);


    cpy_vet(unord,vet,n);
    clean_cache();
    quicksort(unord,0,n-1);


    //print_vet(vet,n);
    free(vet);
    free(unord);

    return 0;
}