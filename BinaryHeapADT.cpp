#include<iostream>
#define MAX 20
using namespace std;
class BinaryHeapADT{
    public:
         void heapSort(int a[MAX], int n);
         void buildHeap(int a[MAX], int root, int bottom);
};
void BinaryHeapADT::heapSort(int a[MAX], int n){
    int i;
    for(i=n/2;i>0 ;i--)
        buildHeap(a, i, n);
    for(i=n;i>=1;i--){
        int temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        buildHeap(a,1,i-1);
    }
}
void BinaryHeapADT::buildHeap(int a[MAX], int root, int bottom){
    int i, t;
    int done=0;
    while(root*2<=bottom && done==0){
        if(2*root==bottom)
            t=2*root;
        else{
            if(a[2*root]>a[bottom])
                t=2*root;
            else
                t=2*root+1;
        }
        if(a[t]>a[root]){
            int temp=a[t];
            a[t]=a[root];
            a[root]=temp;
            root=t;
        }
        else
            done=1;
    }
}

int main(){
    int n;
    BinaryHeapADT x;
    cout<<"Enter no of elements : ";
    cin>>n;
    int a[n];
    cout<<"Enter elements"<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<"\nBefore Sorting :"<<endl;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    x.heapSort(a,n);
    cout<<"\nAfter Sorting :"<<endl;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
