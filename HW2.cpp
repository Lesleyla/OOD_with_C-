#include <iostream>
#include <algorithm>
#include <vector>

bool isValidSolution(const std::vector<int>& p) {
    // Check the conditions given by the puzzle
    if ((p[0] * 10 + p[1]) * p[2] != p[3] * 10 + p[4]) return false;
    if ((p[7] * 10 + p[8]) - (p[5] * 10 + p[6]) != (p[3] * 10 + p[4])) return false;

    return true;
}

void findSolutions(std::vector<std::vector<int>>& solutions) {
    std::vector<int> permutation = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Generate all permutations and check if they are valid
    do {
        if (isValidSolution(permutation)) {
            //add valid solution into result
            solutions.push_back(permutation);
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));
}

int main() {
    std::vector<std::vector<int>> solutions;
    findSolutions(solutions);

    std::cout << "Found " << solutions.size() << " solutions:" << std::endl;
    for (const auto& solution : solutions) {
        for (int num : solution) {
            std::cout << num << " ";
        }
        //every line shows one solution
        std::cout << std::endl;
    }
    
    return 0;
}