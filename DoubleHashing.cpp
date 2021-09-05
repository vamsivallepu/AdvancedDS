#include <bits/stdc++.h>
using namespace std;

class DHashing {
   private:
    int size;
    int *ht;

   public:
    DHashing(int size) {
        this->size = size;
        ht = (int *)calloc(size, sizeof(int));
    }
    int prime(int n) {
        if (n & 1)
            n -= 2;
        else
            n--;

        int i, j;
        for (i = n; i >= 2; i -= 2) {
            if (i % 2 == 0) continue;
            for (j = 3; j <= sqrt(i); j += 2) {
                if (i % j == 0) break;
            }
            if (j > sqrt(i)) return i;
        }
        return 2;
    }
    int hash1(int key) { return key % size; }
    int hash2(int key) {
        int m = prime(size);
        return m - (key % m);
    }
    void insert(int key) {
        int i = hash1(key);
        if (ht[i] != 0) {
            int k = hash2(key);
            int j = 1;
            while (1) {
                int newi = (i + j * k) % size;
                if (ht[newi] == 0) {
                    ht[newi] = key;
                    break;
                }
                j++;
            }
        } else {
            ht[i] = key;
        }
    }
    int search(int key) {
        int i = hash1(key);
        int j = hash2(key);
        int k = 0;
        while (ht[(i + k * j) % size] != key) {
            if (ht[(i + k * j) % size] == 0) {
                cout << "Key doesn't exist\n";
                return -1;
            }
            i++;
        }
        return (i + k * j) % size;
    }
    void remove(int key) {
        int s = search(key);
        if (s == -1) {
            cout << "Element doesn't exist. Can't delete";
        } else {
            ht[s] = 0;
        }
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "[ " << i << " : " << ht[i] << " ]" << endl;
        }
    }
};

int main() { 
    int size;
    cout<<"Enter the size of Hash Table" <<endl;
    cin>>size;
    DHashing myTable(size);
    cout << "1. Insert \n 2. Remove \n 3. Search \n 4. Any other to Quit" << endl;
    while (1)
    {
        int choice;
        
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter element to insert : ";
            int ele;
            cin >> ele;
            myTable.insert(ele);
            break;
        case 2:
            cout<<"Enter element to delete : ";
            cin >> ele;
            myTable.remove(ele);
            break;
        case 3:
            cout<<"Enter element to search : ";
            cin >> ele;
            if (myTable.search(ele) != -1)
                cout << "Found" << endl;
            else
                cout << "Not Found" <<endl;
            break;
        default:
            myTable.display();
            exit(0);
        }
    }
 }
