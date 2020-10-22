// Insert a value in sorted array

void insertInSortedArray(int a[], int &n, int value){
    if (value > a[n-1])
    {
        a[n] = value;
        n++;
        return;
    }

    int index;
    bool positionFound = false;

    for (int i=0; i<n; i++){
        if (a[i] > value){
            positionFound = true;
            index = i;
            break;
        }
    }

    if (positionFound){
        // Right Shift

        for (int i=n; i>index; i--){
            a[i] = a[i-1];
        }
        a[index] = value;
        n++;
    }
}

void display(int a[], int n){
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[50];

    int n;
    cout <<"Enter total elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    display(a, n);

    int value;
    cout << "Enter value to insert: ";
    cin >> value;

    insertInSortedArray(a, n, value);

    display(a, n);
   return 0;
}

/*

Enter total elements: 5
Enter array elements: 10
30
40
50
60
10 30 40 50 60
Enter value to insert: 20
10 20 30 40 50 60

Enter total elements: 5
Enter array elements: 10
20
30
40
50
10 20 30 40 50
Enter value to insert: 70
10 20 30 40 50 70

*/
