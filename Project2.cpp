/* Project2.cpp
 * Alexis Torres
 * EE312, Spring 2022
 * Project 2, Matrix Multiplication
 */

// matrix-multiplication <Project2.cpp>
// EE 312 Project 2 submission by
// Alexis Torres
// at39625
// Slip days used: 0
// Spring 2022

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(double a[],
                      const uint32_t a_rows,
                      const uint32_t a_cols,
                      double b[],
                      const uint32_t b_cols,
                      double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order


    uint32_t counter1 = 0;
   while (counter1 < a_rows) { //loops until the counter is equal to a_row
       uint32_t counter2 = 0;
        while(counter2 < b_cols){
            double sum = 0;
            uint32_t counter3 = 0; // resets and counters to move through the array
            while (counter3 < a_cols){
                sum = sum + (a[(counter1*a_cols) + counter3] * b[(counter3*b_cols)+ counter2] ); // moves though the array (row major order) offset
                counter3++;                                                                    // by the counters to
            }
            c[(counter1*b_cols) + counter2] = sum; // location of the element in the c matrix (result matrix)
            counter2++;
        }
        counter1++;
   }

}

double** multiplyMatricesPtr(double** a,
                             const uint32_t a_rows,
                             const uint32_t a_cols,
                             double** b,
                             const uint32_t b_cols) {

    double **multMatrix = (double**) malloc(a_rows* sizeof(double*)); // allocate memory to the matrix
    uint32_t i;
    for (i = 0; i< a_rows; i++){
        double *matrixCol = (double*) malloc(a_cols * sizeof(double));
        multMatrix [i] = matrixCol;
    }
    uint32_t counter1 = 0;
    while (counter1 < a_rows) { //loops until the counter is equal to a_row. the variable = 0 is to reset the counters
        uint32_t counter2 = 0;
        while(counter2 < b_cols){
            uint32_t counter3 = 0;
            double sum = 0;
            while (counter3 < a_cols){
                sum = sum + (a[counter1][counter3] * b[counter3][counter2]); // moves through the array similar to multmatrix funtion
                counter3++;
            }
            multMatrix[counter1][counter2] = sum;
            counter2++;
        }
        counter1++;
    }
    return multMatrix;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix( double** a,
                          const uint32_t a_rows,
                          const uint32_t a_cols) {
    double **transpMatrix = (double**) malloc(a_cols * sizeof(double*)); //allocates memory for the matrix
    uint32_t i =0;
    for (i = 0; i< a_cols; i++){
        double *transpMatrixCol = (double*) malloc(a_rows * sizeof(double)); // the rows of A become the columns of the Transpose
        transpMatrix [i] = transpMatrixCol;
    }
    uint32_t transpCounter1 = 0; //Counters to move through the arrays
    for(transpCounter1 = 0; transpCounter1< a_rows; transpCounter1++){
        uint32_t transpCounter2 = 0;
        for(transpCounter2= 0; transpCounter2 < a_cols; transpCounter2++ ){
            transpMatrix[transpCounter2][transpCounter1] = a[transpCounter1][transpCounter2]; // flips the rows and columns of matrix a to get transpMatrix
        }
    }
    return transpMatrix ;
    }


