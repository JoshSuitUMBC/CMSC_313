//Title: matrixLibrary.cpp
//Author: Joshua Suit
//Date: 4/16/2024
//Description: Solves a specific matrix equation by using general functions to handle operations.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Matrix {
    private:

        //creates vector of vectors to create a 2d vector for the matrix
        vector<::vector<int>> value;

    public:

        // Name: Matrix (default constructor)
        // Desc: Creates a new matrix object using passed in rowNum and colNum, 
        // and setting the value to zero.
        // Preconditions: None
        // Postconditions: Creates a new matrix object with default variables
        Matrix(int rowNum, int colNum) : value(rowNum, vector<int>(colNum, 0)){  
        }

        // Name: Matrix (constructor)
        // Desc: Creates a new matrix object using passed in rowNum and colNum, 
        // and setting the value to the passed in values.
        // Preconditions: None
        // Postconditions: Creates a new matrix object with default variables
        Matrix(const vector<::vector<int>>& info) : value(info){}

        //sets rowNum to the value of the passed in number size
        int rowNum() const{
            return value.size();
        }

        //sets colNum to the value of the passed in number size
        int colNum() const{
            return value[0].size();
        }
        
        //set curLocation to passed in indexes
        int& curLocation(int i, int j){
            return value[i][j];
        }

        //set curLocation constant to passed in indexes
        int curLocation(int i, int j) const{
            return value[i][j];
        }

        // Name: PrintMatrix 
        // Desc: outputs the calculated matrix
        // Preconditions: matrix is created
        // Postconditions: solved matrix is displayed
        void PrintMatrix() const{

            //counter to know when to place end bracket
            int counter = 0;
            
            //print first bracket
            cout << "[ ";

            //for the number of rows
            for (const auto& rowNum : value){

                // for the numbers in each row
                for (int number : rowNum){

                    //display the number found
                    cout << number << " ";   
                }

                //if the first row has printed
                //the print the end bracket
                if (counter >= 1){
                    cout << "]";
                }

                //increases counter by 1
                counter += 1;
                //end line to properly space each row
                cout << endl;
            }

        }

        // Name: ScalarMatrix 
        // Desc: scalar multiplies all matrix values by scalar multiple
        // Preconditions: matrix is created
        // Postconditions: matrix has all values multiplied
        Matrix ScalarMatrix(int scalar) const{

            //creates variable for the end calculation
            Matrix calculation = *this;

            //for every row
            for (int i = 0; i < rowNum(); ++i){

                //for every column
                for (int j = 0; j < colNum(); ++j){

                    //calculation multiplies each value by scalar
                    calculation.curLocation(i,j) *= scalar;
                }
            }

            //returns the calculation found
            return calculation;
        }

        // Name: TransposeMatrix 
        // Desc: transposes the mantrix by swapping around values
        // Preconditions: matrix is created
        // Postconditions: matrix has all values swapped orientation
        Matrix TransposeMatrix() const{

            //gets the column and row values
            Matrix calculation(colNum(), rowNum());

            //for every row
            for (int i = 0; i < rowNum(); ++i){

                //for every column
                for (int j = 0; j < colNum(); ++j){

                    //take the value and invert the placement
                    calculation.curLocation(j, i) = value[i][j];
                }
            }

            //return the final calculation
            return calculation;
        }

        // Name: AddMatrix 
        // Desc: adds the value 
        // Preconditions: matrix is created
        // Postconditions: matrix has all values swapped orientation
        Matrix AddMatrix(const Matrix& otherVal) const {

            //gets the column and row values
            Matrix calculation(rowNum(), colNum());

            //for every row
            for (int i = 0; i < rowNum(); ++i){

                //for every column
                for (int j = 0; j < colNum(); ++j){

                    //takes the value and increases it by the passed in value
                    calculation.curLocation(i, j) = value[i][j] + otherVal.curLocation(i, j);
                }
            }

            return calculation;
        }
        // Name: MultiplyMatrix 
        // Desc: takes all the data from two matricies and multiplies them together
        //       into one new matrix
        // Preconditions: matrix is created
        // Postconditions: matrix is updated
        Matrix MultiplyMatrix(const Matrix& otherVal) const {

            //gets row number and column number of passed in value
            Matrix calculation(rowNum(), otherVal.colNum());

            //for every row
            for (int i = 0; i < rowNum(); ++i){

                //for ever column in passed in value
                for (int j = 0; j < otherVal.colNum(); ++j){

                    //for every column in current column
                    for (int k = 0; k < colNum(); ++k){

                        //adds and multiplies the two matrices together
                        calculation.curLocation(i, j) 
                        += value[i][k] * otherVal.curLocation(k, j);
                    }
                }

            }

            return calculation;
        }

};

int main() {

    //Creates first matrix 
    Matrix matrixA({{6,4}, {8,3}});

    //Creates second matrix 
    Matrix matrixB({{1,2,3}, {4,5,6}});

    //Creates third matrix 
    Matrix matrixC({{2,4,6}, {1,3,5}});

    //creates matrix of matrixB scaled multiplied by 3
    Matrix scalarB = matrixB.ScalarMatrix(3);

    //creates matrix of matrixC transposed
    Matrix transposeC = matrixC.TransposeMatrix();

    //creates matrix of scaled matrixB multiplied by transposeC
    Matrix matrixProduct = scalarB.MultiplyMatrix(transposeC);

    //creates matrix of matrixA added by the previous matrix product
    Matrix matrixD = matrixA.AddMatrix(matrixProduct);

    //tells what is happening
    cout << "Solved Matrix: " << endl;
    
    //prints final calculated matrix
    matrixD.PrintMatrix();

    return 0;
}

