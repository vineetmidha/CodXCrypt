
// Matrix implementation using operator overloading

#include<iostream>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

class matrix
{
    int a[MAX_ROWS][MAX_COLS];
    int rows, cols;
public:
    matrix(int r, int c){
        if (r > MAX_ROWS || c > MAX_COLS){
            cout << "Invalid rows: Max Rows/Cols: 10";
            return;
        }

        rows = r;
        cols = c;

        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                a[i][j] = i*cols+j+1;
            }
        }
    }

    friend ostream & operator << (ostream &, matrix &);

    bool operator==(matrix & m){
        return (rows == m.rows && cols == m.cols);
    }

    matrix operator+(matrix &m){
        matrix result(rows,cols);
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                result.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        return result;
    }

    matrix operator*(matrix &m){
        matrix result(rows, m.cols);
        for (int i=0; i<rows; i++){
            for (int j=0; j<m.cols; j++){
                result.a[i][j] = 0;
                for (int k=0; k<cols; k++){
                    result.a[i][j] += a[i][k] * m.a[k][j];
                }
            }
        }
        return result;
    }
};

ostream & operator <<(ostream & cout, matrix &m)
{
    for (int i=0; i<m.rows; i++){
        for (int j=0; j<m.cols; j++){
            cout << m.a[i][j] << " ";
        }
        cout << endl;
    }
    return cout;
}

int main()
{
    matrix m1(3,3), m2(3,3), m3(3,3);

    cout << m1 << endl;
    cout << m2 << endl;

    if (m1 == m2){
        m3 = m1 + m2;
        cout << "Addition" << endl;
        cout << m3 << endl;
    }

    m3 = m1 * m2;

    cout << "Multiplication" << endl;
    cout << m3 << endl;
}


/*
1 2 3 
4 5 6 
7 8 9 

1 2 3 
4 5 6 
7 8 9 

Addition
2 4 6 
8 10 12 
14 16 18 

Multiplication
30 36 42 
66 81 96 
102 126 150 
*/
