/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquare.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has magicsquare class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
NOTHING CAN BE CHANGED
-----------------------------------------------------------------*/
#include "magicsquare.h"

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
std::vector< std::vector<int> > magicsquare::allocate(int n) {
    return std::vector< std::vector<int> >(n, std::vector<int>(n, 0));
}

void magicsquare::fillSquare(std::vector< std::vector<int> >& square) {
    int n = square.size();
    int num = 1;
    int i = n / 2;
    int j = n - 1;

    while (num <= n * n) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) j = 0;
            if (i < 0) i = n - 1;
        }

        if (square[i][j]) {
            j -= 2;
            i++;
            continue;
        } else
            square[i][j] = num++;

        j++; i--;
    }
}
bool magicsquare::verifyMagicSquare(const std::vector< std::vector<int> >& square, int n, int sum) {
    // Check rows and columns
    for (int i = 0; i < n; i++) {
        if (std::accumulate(square[i].begin(), square[i].end(), 0) != sum) return false;
        int colSum = 0;
        for (int j = 0; j < n; j++)
            colSum += square[j][i];
        if (colSum != sum) return false;
    }

    // Check diagonals
    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < n; i++) {
        diag1Sum += square[i][i];
        diag2Sum += square[i][n - 1 - i];
    }
    if (diag1Sum != sum || diag2Sum != sum) return false;

    return true;
}


void magicsquare::print_magic_square(int n) {
    std::vector< std::vector<int> > square = allocate(n);
    fillSquare(square);

    int sum = n * (n * n + 1) / 2;
    // Printing the header
    std::cout << "Magic square for n = " << n << " sum = " << sum << "\n";

    if (verifyMagicSquare(square, n, sum)) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                //set fixed width, ensuring alignment
                std::cout << std::setw(5) << square[i][j];
            }
            //new line after each row
            std::cout << std::endl;
        }
    } else {
        std::cout << "Failed to create a valid Magic Square." << std::endl;
    }
    // Printing the separator line
    std::cout << "------------------------\n";
}
    
//EOF
