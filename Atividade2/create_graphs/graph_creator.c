#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void merge_sort(int* vet,int ini,int fim,int* aux){
    if(ini >= fim) return;

    //printf("%d %d\n", ini,fim);

    int meio = (ini+fim)/2.0;

    merge_sort(vet,ini,meio,aux);
    merge_sort(vet,meio+1,fim,aux);

    int i=ini;
    int j = meio+1;
    int indTmp = 0;
    while(i <= meio && j <= fim){
        if(vet[i] <= vet[j]) aux[ini+indTmp++] = vet[i++];
        else aux[ini+indTmp++] = vet[j++];
    }

    while(i <= meio){
        aux[ini+indTmp++] = vet[i++];
    }

    while(j <= fim){
        aux[ini+indTmp++] = vet[j++];
    }

    for(int k=ini;k<=fim;k++){
        vet[k] = aux[k];
    }
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

int next(int n){
    n /= 10000;
    n *= 10000;
    n+=10000;
    return n;
}

int main(){
    srand(42);
    const int maxN = 200000;
    const int maxK = 1e9;

    int* vet = (int*)malloc(sizeof(int)*maxN);
    for(int i=0;i<maxN;i++){
        vet[i] = rand()%maxK;
    }
    vet[0] = maxK;
    vet[1] = 0;

    for(int n=10;n<=maxN;n=next(n)){
        int* unord = (int*)malloc(sizeof(int)*n);
        int* aux = (int*)malloc(sizeof(int)*n);

        cpy_vet(unord,vet,n);
        

        clock_t begin = clock();
        merge_sort(unord,0,n-1,aux);
        //counting_sort(unord,n);
        //quicksort(unord,0,n-1);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%d %lf\n", n,time_spent);
        free(unord);
        free(aux);
    }

    free(vet);
    //clean_cache();
    
    //cpy_vet(unord,vet,n);
    //merge_sort(unord,0,n-1);
    //clean_cache();

    //cpy_vet(unord,vet,n);
    //counting_sort(unord,n);
    //clean_cache();

    //cpy_vet(unord,vet,n);
    //quicksort(unord,0,n-1);


    //print_vet(vet,n);
    
    //free(unord);

    return 0;
}