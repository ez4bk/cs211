#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    //Input matrix A(l * m) to an array
    FILE* matrix_a_fp = fopen(argv[1], "r");
    if (!matrix_a_fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    char buff[256];

    fscanf(matrix_a_fp, "%s", buff);
    char length_l = atoi(buff);
    int** matrix_a = malloc( length_l * sizeof(int*) );

    fscanf(matrix_a_fp, "%s", buff);
    char length_m = atoi(buff);

    //Declear each element in matrix_a as an another array
    for ( unsigned char i=0; i<length_l; i++ ) {
        matrix_a[i] = malloc( length_m * sizeof(int) );
    }

    for ( unsigned char i=0; i<length_l; i++ ) {
        for (unsigned char j=0; j<length_m; j++){
            fscanf(matrix_a_fp, "%s", buff);
            *(matrix_a[i]+j) = atoi(buff);
        }
    }

    fclose(matrix_a_fp);

    //Input matrix B(m * n) to an array
    FILE* matrix_b_fp = fopen(argv[2], "r");
    if (!matrix_b_fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    fscanf(matrix_b_fp, "%s", buff);
    char length_mb = atoi(buff);
    if (length_mb!=length_m){
        perror("Not able to multiply");
        return EXIT_FAILURE;
    }

    int** matrix_b = malloc( length_m * sizeof(int*) );

    fscanf(matrix_b_fp, "%s", buff);
    char length_n = atoi(buff);
    for ( unsigned char i=0; i<length_m; i++ ) {
        matrix_b[i] = malloc( length_n * sizeof(int) );
    }

    for ( unsigned char i=0; i<length_m; i++ ) {
        for (unsigned char j=0; j<length_n; j++){
            fscanf(matrix_b_fp, "%s", buff);
            *(matrix_b[i]+j) = atoi(buff);
        }
    }

    fclose(matrix_b_fp);

    //Create the product matrix array
    int** matrix_c = malloc( length_l * sizeof(int*) );
    for ( unsigned char i=0; i<length_l; i++ ) {
        matrix_c[i] = malloc( length_n * sizeof(int) );
    }

    
    for ( unsigned char i=0; i<length_l; i++ ) {
        for (unsigned char j=0; j<length_n; j++){
            *(matrix_c[i]+j) = 0;
        }
    }
    

    
    for (unsigned char i=0; i<length_l; i++){
        for (unsigned char j=0; j< length_n; j++){
            for (unsigned char k=0; k< length_m; k++){
                *(matrix_c[i]+j) += (*(matrix_a[i]+k)) * (*(matrix_b[k]+j));
            }
        }
    }

    for ( unsigned char i=0; i<length_l; i++ ) {
        for (unsigned char j=0; j<length_n; j++){
            printf("%d ", *(matrix_c[i]+j));
        }

    }

    for ( unsigned char i=0; i<length_l; i++ ) {
        free( matrix_a[i] );
    }
    free( matrix_a );
    for ( unsigned char i=0; i<length_m; i++ ) {
        free( matrix_b[i] );
    }
    free( matrix_b );
    for ( unsigned char i=0; i<length_l; i++ ) {
        free( matrix_c[i] );
    }
    free( matrix_c );

    return 0;

}
