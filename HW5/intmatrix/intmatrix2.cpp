/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAN BE ADDED except intmatrix2.h
-----------------------------------------------------------------*/
#include "intmatrix2.h"

/*----------------------------------------------------------------
Definition of routines of intmatrix2 class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
bool intmatrix2::_show = false;


/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
// Constructor
intmatrix2::intmatrix2() : rows_(0), cols_(0), mat_(nullptr) {}

intmatrix2::intmatrix2(int r, int c) : rows_(r), cols_(c) {
    mat_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        mat_[i] = new int[cols_];
        std::fill_n(mat_[i], cols_, 0);
    }
}

intmatrix2::intmatrix2(int r, int c, int val) : rows_(r), cols_(c) {
    mat_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        mat_[i] = new int[cols_];
        std::fill_n(mat_[i], cols_, val);
    }
}

intmatrix2::intmatrix2(const std::string& str) {
    std::istringstream iss(str);
    std::string row_str;
    std::vector< std::vector<int> > data;
    size_t expected_cols = 0;
    bool isValid = true;

    while (std::getline(iss, row_str, '|')) {
        std::istringstream row_iss(row_str);
        int num;
        std::vector<int> row_data;
        while (row_iss >> num) {
            row_data.push_back(num);
        }
        if (expected_cols == 0) {
            expected_cols = row_data.size();
        } else if (row_data.size() != expected_cols) {
            isValid = false;
            break;
        }
        data.push_back(row_data);
    }

    if (!isValid || data.empty()) {
        rows_ = 0;
        cols_ = 0;
        mat_ = nullptr;
        return;
    }

    rows_ = data.size();
    cols_ = expected_cols;
    mat_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        mat_[i] = new int[cols_];
        for (int j = 0; j < cols_; ++j) {
            mat_[i][j] = j < data[i].size() ? data[i][j] : 0;
        }
    }
}


// Destructor
intmatrix2::~intmatrix2() {
    for (int i = 0; i < rows_; ++i) {
        delete[] mat_[i];
    }
    delete[] mat_;
}

// Copy constructor
intmatrix2::intmatrix2(const intmatrix2& rhs) : rows_(rhs.rows_), cols_(rhs.cols_) {
    mat_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        mat_[i] = new int[cols_];
        for (int j = 0; j < cols_; ++j) {
            mat_[i][j] = rhs.mat_[i][j];
        }
    }
}

// Assignment operator
intmatrix2& intmatrix2::operator=(const intmatrix2& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < rows_; ++i) {
            delete[] mat_[i];
        }
        delete[] mat_;

        rows_ = rhs.rows_;
        cols_ = rhs.cols_;
        mat_ = new int*[rows_];
        for (int i = 0; i < rows_; ++i) {
            mat_[i] = new int[cols_];
            for (int j = 0; j < cols_; ++j) {
                mat_[i][j] = rhs.mat_[i][j];
            }
        }
    }
    return *this;
}

//HW document says:
// [operator bool() const
// Return true if matrix is empty
// else return false]
//But seems like assert(!h) triggers a failure, so I assume that it should return true if metrix is not empty

intmatrix2::operator bool() const {
    return rows_ > 0 && cols_ > 0 && mat_ != nullptr;
}

bool intmatrix2::isEqual(const intmatrix2& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            if (mat_[i][j] != other.mat_[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Implementation of the operator<<
std::ostream& operator<<(std::ostream& os, const intmatrix2& mat) {
  if (mat.rows_ == 0 || mat.cols_ == 0) {
    os << "Empty Matrix" << std::endl;
  } else {
    for (int i = 0; i < mat.rows_; ++i) {
      for (int j = 0; j < mat.cols_; ++j) {
        os << mat.mat_[i][j] << ' ';
      }
      os << std::endl;  // Newline at the end of each row
    }
  }
  return os;
}

intmatrix2 intmatrix2::add(const intmatrix2& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return intmatrix2();
    }

    intmatrix2 result(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result.mat_[i][j] = mat_[i][j] + other.mat_[i][j];
        }
    }
    return result;
}

intmatrix2 intmatrix2::mult(const intmatrix2& other) const {
    if ((rows_ == 1 && cols_ == 1) || (other.rows_ == 1 && other.cols_ == 1)) {
        int scalar = (rows_ == 1 && cols_ == 1) ? mat_[0][0] : other.mat_[0][0];
        const intmatrix2& matrix = (rows_ == 1 && cols_ == 1) ? other : *this;
        intmatrix2 result(matrix.rows_, matrix.cols_);
        for (int i = 0; i < matrix.rows_; ++i) {
            for (int j = 0; j < matrix.cols_; ++j) {
                result.mat_[i][j] = scalar * matrix.mat_[i][j];
            }
        }
        return result;
    }
    if (cols_ != other.rows_) {
        return intmatrix2();
    }
    intmatrix2 result(rows_, other.cols_);

    //matrixs multiplication
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                result.mat_[i][j] += mat_[i][k] * other.mat_[k][j];
            }
        }
    }
    return result;
}

//EOF
