// Bubble Sort

#include <iostream>

using namespace std;

void bubbleSort_Ascending (int a[], int n){

    for (int i=0; i<n-1; i++) {
        bool swapped = false;
        for (int j=0; j<n-1-i; j++){
            if (a[j] > a[j+1]){
                char t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                swapped = true;
            }
        }
        if (not swapped)
            break;
    }
}

void display(int a[], int n){
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[50];

    int n;
    cout <<"Enter total elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << "Original array: ";
    display(a, n);
    
    bubbleSort_Ascending(a, n);
    
    cout << "Sorted array: ";
    display(a, n);
    
    return 0;
}

/*

Enter total elements: 5
Enter array elements:
50
40
30
20
10
Original array: 50 40 30 20 10 
Sorted array: 10 20 30 40 50 

*/
