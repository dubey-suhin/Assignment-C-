#include <iostream>
using namespace std;

class MATRIX{
    int rows, cols;
    int **a;

public:
    MATRIX(){}
    MATRIX(int x, int y){
        rows = x;
        cols = y;
        a = new int *[rows];
        for (int i = 0; i < rows; i++)
            a[i] = new int[cols];
    }
    int getVal(int i, int j) { return a[i][j]; }
    void setVal(int i, int j, int v) { a[i][j] = v; }
    MATRIX* operator+(MATRIX mat);
    MATRIX* operator-(MATRIX mat);
    MATRIX* operator*(MATRIX mat);
    void display();
};

MATRIX* MATRIX ::operator+(MATRIX mat){
    if ((rows == mat.rows) && (cols == mat.cols)){
        MATRIX* temp=new MATRIX(rows, cols);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                temp->a[i][j] = a[i][j] + mat.a[i][j];
            }
        }
        return temp;
    }
    else
        return NULL;
}

MATRIX* MATRIX ::operator-(MATRIX mat){
    if ((rows == mat.rows) && (cols == mat.cols)){
        MATRIX* temp=new MATRIX(rows, cols);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++)   {
                temp->a[i][j] = a[i][j] - mat.a[i][j];
            }
        }
        return temp;
    }
    else
        return NULL;
}
MATRIX* MATRIX ::operator*(MATRIX mat){
    if ((cols == mat.rows)){
        MATRIX* temp=new MATRIX(rows, mat.cols);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < mat.cols; j++){
                temp->a[i][j] = 0;
                for (int k = 0; k < cols; k++){
                    temp->a[i][j] += (a[i][k] * mat.a[k][j]);
                }
            }
        }
        return temp;
    }
    else
        return NULL;
}
void MATRIX::display(){
    cout << "\nValues Of Matrix :\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

int main(int argc, char const *argv[]){
    int m1(3), n1(3), m2(3), n2(3);
    MATRIX mat1(m1, n1), mat2(m2, n2) ,*mat;
    cout << "Enter Values of Matrix 1 :\n";
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n1; j++){
            int v;
            cin >> v;
            mat1.setVal(i, j, v);
        }
    }
    cout << "Enter Values of Matrix 2 :\n";
    for (int i = 0; i < m2; i++){
        for (int j = 0; j < n2; j++){
            int v;
            cin >> v;
            mat2.setVal(i, j, v);
        }
    }
    mat1.display();
    mat2.display();
    mat = mat1 + mat2;
    cout << "\nMatrix Addition";
    mat->display();

    mat = mat1 - mat2;
    cout << "\nMatrix Subtraction";
    mat->display();

    mat = mat1 * mat2;
    cout << "\nMatrix Multiplication";
    mat->display();
    return 0;
}

