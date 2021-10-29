#include <stdio.h>
#include <stdlib.h>


void max_heapify(int *vet, int pai, int n){
	int aux;
	int filho1 = (2*pai)+1, filho2 = (2*pai)+2, escolhido;
	if(filho1 >= n) return;
	else if(filho2 >= n){
		if(vet[filho1] > vet[pai]){
			aux = vet[filho1];
			vet[filho1] = vet[pai];
			vet[pai] = aux;
			max_heapify(vet, filho1, n);
		}
	}
	else if(vet[filho1] > vet[pai] || vet[filho2] > vet[pai]){
		if(vet[filho2] > vet[filho1]){
			escolhido = filho2;
		}
		else escolhido = filho1;
		aux = vet[escolhido];
		vet[escolhido] = vet[pai];
		vet[pai] = aux;
		max_heapify(vet, escolhido, n);
	}
}

void heap_sort(int *vet, int n){	
	int pai = (int)((n-1)/2); 
	for(int i = pai; i >= 0; i--){
		max_heapify(vet, i, n);
	}
	int aux;
	int u = n-1;
	while(u > 0){
		aux = vet[u];
		vet[u] = vet[0];
		vet[0] = aux;
		max_heapify(vet, 0, u--);
	}
}

void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
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
    }
    free(tmp);
}

void counting_sort(int* vet,int n){
    int min = 0x7fffffff;
    int max = -0x7fffffff;
    for(int i=0;i<n;i++){
        if(vet[i] > max) max = vet[i];
        if(vet[i] < min) min = vet[i];
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

int main(int argc, char *argv[]){
    
    srand(42);

    const int n = atoi(argv[1]);
    int* vet = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        vet[i] = rand()%1000;
    }

    int* unord = (int*)malloc(sizeof(int)*n);;

    cpy_vet(unord,vet,n);
    radixsort(unord,n);
    clean_cache();

    cpy_vet(unord,vet,n);
    merge_sort(unord,0,n-1);
    clean_cache();

    cpy_vet(unord,vet,n);
    heap_sort(unord,n);
    clean_cache();

    cpy_vet(unord,vet,n);
    quicksort(unord,0,n-1);


    //print_vet(vet,n);
    free(vet);
    free(unord);

    return 0;
}