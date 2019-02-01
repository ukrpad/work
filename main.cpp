#include <iostream>

using namespace std;

void init();
void check_mask();
int pre_valid();
void valid();

int matrix[32]; 

int main()
{
  init();
  check_mask();
  valid();
  return 0;
}

void init() {
    cout << "Введите битовую маску(х32):" << endl;
    for(int i = 0; i < 32; i++) {
    cin >> matrix[i];
    }
}

void check_mask() {
    for(int i = 0; i < 32; i++) {
        if(matrix[i] != 0 && matrix[i] != 1) {
            cout << "Маска недействительная";
            exit(0);
        }
    }
}

int pre_valid() {
    int i;
    for(i = 1; i < 32; i++) {
        if(matrix[i] != 0) {
            return i;
        }
    }
    cout << "Маска действительная";
    exit(0);
}

void valid() {
    int index = pre_valid();
    for(int i = index + 1; i < 32; i++) {
        if(matrix[i] == 0 && matrix[i+1] == 1) {
            cout << "Маска недействительная";
            exit(0);
        }
    }
    cout << "Маска действительная";
}