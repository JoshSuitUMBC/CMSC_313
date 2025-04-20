//Title: matrixLibrary2.c
//Author: Joshua Suit
//Date: 4/16/2024
//Description: Solves a specific matrix equation by using general functions to handle operations.

#include <stdio.h>

//defines constants 
#define ROWNUM_A 2
#define COLNUM_A 2
#define ROWNUM_B 2
#define COLNUM_B 3
#define ROWNUM_C 2
#define COLNUM_C 3

// Name: PrintMatrix 
// Desc: outputs the calculated matrix
// Preconditions: matrix is created
// Postconditions: solved matrix is displayed
void PrintMatrix(int rowNum, int colNum, int matrix[rowNum][colNum]){

    //counter to know when to place end bracket
    int counter = 0;
            
    //print first bracket
    printf("[ ");
    
    //for the numbers of rows
    for (int i = 0; i < rowNum; i++){

        //for the numbers of columns
        for (int j = 0; j < colNum; j++){

            //print the matrix value in the section
            printf("%d ", matrix[i][j]);
        }

        //if the first row has printed
        //then print the end bracket
        if (counter >= 1){
                printf("]");
        }

        //counter increases by 1
        counter += 1;

        //print new line
        printf("\n");
    }
}

// Name: ScalarMatrix 
// Desc: scalar multiplies all matrix values by scalar multiple
// Preconditions: matrix is created
// Postconditions: matrix has all values multiplied
void ScalarMatrix(int rowNum, int colNum, int scalar, int input[rowNum][colNum], 
                  int output[rowNum][colNum]){

    //for number of rows
     for (int i = 0; i < rowNum; i++){

        //for the numbers of columns
        for (int j = 0; j < colNum; j++){

            //new matrix outputted is the previous inputted 
            // matrix multiplied by scalar number
            output[i][j] = input[i][j] * scalar;
        }
    }
}

// Name: TransposeMatrix 
// Desc: transposes the mantrix by swapping around values
// Preconditions: matrix is created
// Postconditions: matrix has all values swapped orientation
void TransposeMatrix(int rowNum, int colNum, int input[rowNum][colNum], 
                     int output[colNum][rowNum]){

    //for number of rows
    for (int i = 0; i < rowNum; i++){

        //for the numbers of columns
        for (int j = 0; j < colNum; j++){

           //new outputted matrix equals the inverted position
           //of current matrix
           output[j][i] = input[i][j];
        }
    }
}

// Name: MultiplyMatrix 
// Desc: takes all the data from two matricies and multiplies them together
//       into one new matrix
// Preconditions: matrix is created
// Postconditions: new matrix is created
void MultiplyMatrix(int rowNum1, int colNum1, int matrix1[rowNum1][colNum1], 
                    int rowNum2, int colNum2, int matrix2[rowNum2][colNum2], 
                    int output[rowNum1][colNum2]){

        //for number of rows in the first matrix
        for (int i = 0; i < rowNum1; i++){

            //for number of columns in the second matrix
            for (int j = 0; j < colNum2; j++){

                //initializes the output as zero's before true values go in
                output[i][j] = 0;

                //for the number of columns in first matrix
                for (int k = 0; k < colNum1; k++){

                    //output adds to it's value the multiple of matrix 1 and 2
                    output[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Name: AddMatrix 
// Desc: takes all the data from two matricies and multiplies them together
//       into one new matrix
// Preconditions: matrix is created
// Postconditions: new matrix is created
void AddMatrix(int rowNum, int colNum, int matrixA[rowNum][colNum], 
               int matrixB[rowNum][colNum], int output[rowNum][colNum]){

    //for the numbers of rows
    for (int i = 0; i < rowNum; i++){

        //for the numbers of columns
        for (int j = 0; j < colNum; j++){

           //output equals the value of matrix a and b put together in that slot
           output[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

int main(){

    //creates variables for all the matrices for the equation
    int matrixA[ROWNUM_A][COLNUM_A] = { {6, 4}, {8, 3} };
    int matrixB[ROWNUM_B][COLNUM_B] = { {1, 2, 3}, {4, 5, 6} };
    int matrixC[ROWNUM_C][COLNUM_C] = { {2, 4, 6}, {1, 3, 5} };

    //creates new matrix to be scaled up form of matrixB
    int scalarB[ROWNUM_B][COLNUM_B];

    //scales up matrixB by value of 3
    ScalarMatrix(ROWNUM_B, COLNUM_B, 3, matrixB, scalarB);

    //creates new matrix to be transpose form of matrixC
    int transposeC[COLNUM_C][ROWNUM_C];

    //transposes matrixC
    TransposeMatrix(ROWNUM_C, COLNUM_C, matrixC, transposeC);

    //creates new matrix for product of multiplication of 2 matricies
    int matrixProduct[ROWNUM_B][ROWNUM_A];

    //multiplies the two matricies
    MultiplyMatrix(ROWNUM_B, COLNUM_B, scalarB, COLNUM_C, ROWNUM_C, transposeC, matrixProduct);

    //creates new matrix to add previous matricies to
    int matrixD[ROWNUM_A][COLNUM_A];

    //adds matricies together
    AddMatrix(ROWNUM_A, COLNUM_A, matrixA, matrixProduct, matrixD);

    //text to show what occurred
    printf("Solved Matrix is: ");
    printf("\n");

    //prints the calculated matrix
    PrintMatrix(ROWNUM_A, COLNUM_A, matrixD);
   
    return 0;
}