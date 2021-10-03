#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void free_mat(int** mat,int n,int m){
    for(int i=0;i<n;i++){
        free(mat[i]);
    }
    free(mat);
}

int** alloc_mat(int n,int m){
    //alloc pointers for lines
    int ** mat = malloc(n*sizeof(int*));
    if(mat == NULL) return NULL;

    for(int i=0;i<n;i++){
        //alloc lines
        mat[i] = malloc(m*sizeof(int));

        //if error occurs, free all previous alloced memory and return NULL
        if(mat[i] == NULL){
            for(int j=i-1;j>=0;j--){
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }

    return mat;
}

int main(int argc,char* argv[]){
    //Verify Input
    if(argc < 2){
        printf("usage: ./program matrix_size technique\n\n");
        printf("technique: li - loop interchange\n");
        printf("           lu - loop unrolling\n");
        return 1;
    }

    //Read matrix size
    int matrix_size = atoi(argv[1]);
    if(matrix_size <=0){
        printf("invalid matrix size\n");
        return 2;
    }

    //Read technique
    if(strcmp("li",argv[2]) && strcmp("lu",argv[2])){ //if not li nor lu
        printf("invalid value for technique\n");
        return 3;
    }

    //generate matrix
    int** A = alloc_mat(matrix_size,matrix_size);
    int** B = alloc_mat(matrix_size,matrix_size);
    int** C = alloc_mat(matrix_size,matrix_size);

    /* Starting matrix with random values
    for(int i=0;i<matrix_size;i++){
        for(int j=0;j<matrix_size;j++){
            A[i][j] = rand();
            B[i][j] = rand();
            C[i][j] = 0;
        }
    }*/

    /* Normal Multiplication
    for(int i=0;i<matrix_size;i++){
        for(int j=0;j<matrix_size;j++){
            for(int k=0;k<matrix_size;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    */
   
   
    if(!strcmp("li",argv[2])){  //Loop Interchand

        for(int i=0;i<matrix_size;i++){
            for(int k=0;k<matrix_size;k++){
                for(int j=0;j<matrix_size;j++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

    }else if(!strcmp("lu",argv[2])){  //Loop Unrolling 4
        if(matrix_size%4 != 0){
            printf("error, for this technique the matrix size must be divisible by 4\n");
            return 4;
        }
        for(int i=0;i<matrix_size;i++){
            for(int j=0;j<matrix_size;j++){
                for(int k=0;k<matrix_size;k+=4){
                    C[i][j] += A[i][k] * B[k][j];
                    C[i][j] += A[i][k+1] * B[k+1][j];
                    C[i][j] += A[i][k+2] * B[k+2][j];
                    C[i][j] += A[i][k+3] * B[k+3][j];
                }
            }
        }
    }

    free_mat(A,matrix_size,matrix_size);
    free_mat(B,matrix_size,matrix_size);
    free_mat(C,matrix_size,matrix_size);

    return 0;
}