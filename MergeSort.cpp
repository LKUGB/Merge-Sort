#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& t, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int mid, int right);

int main() {
    // get input: first is random seed, second is vector length
    cout << "Please input the length of the vector: "; // prompt the user to enter the vector's length for further computations
    int length;
    cin >> length;
    srand(time(0)); //prepare random numbers with the random seed created according to the clock. In this way we can make the random number actually random.

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary vector


    // unit test for merge starts **********************************************************************************************************
    /* your code here */
    //testing the mergeSort function and the mergeSortList function with extreme cases
    //the case when the vector is already empty

    mergeSort(v, t, 0, v.size() - 1);
        cout << "The empty list is sorted:" << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i) << '\t';
        }
        cout << endl;
        v.clear(); //clear the elements in the vector to proceed to the next unit test

    //the case when the vector is already sorted
    v = {1,2,5,6,9}; //assign the vector with values that are already sorted
    mergeSort(v, t, 0, v.size() - 1);
    cout << "The list with correct order is sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;
    v.clear();

    //the case when the vector is in reverse order
    v = {81,64,25,24,2,1};
    mergeSort(v, t, 0, v.size() - 1);
    cout << "The list with reverse order is sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;
    v.clear();

    //the case when the vector has the same number on each index
    v = {6,6,6,6,6,6,6};
    mergeSort(v, t, 0, v.size() - 1);
    cout << "The list with same number on each index is sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;
    v.clear();
    //unit test finished ******************************************************************************************************************

    //resize the vector with the length inputted by the user at the beginning to sort the random vector
    v.resize(length);
    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100; //fill the vector with random numbers created by the random seed
        cout << v.at(i) << '\t'; //\t for format the vector correctly
    }
    cout << endl;
    // sort v
    /* your code here */
    mergeSort(v, t, 0, length - 1); // call the mergeSort function to sort the vector

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    // print sorted list
    cout << "Sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;


    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int mid, int right) {

    /* your code here */
    //we use l, r, i to copy the value left, mid + 1, left respectively. In this case, we can dynamically increment the value of these three parameters with l, r, i without changing the value of left, mid + 1, and right.
    int l = left; // the starting index of the left half of the vector to be merged
    int r = mid + 1; // the starting index of the right half of the vector to be merged
    int i = left; // need another variable i to equal to left because i is used to increment the index of the temporary vector, which is the vector after sorting.

    while(l <= mid && r <= right) { // when the index starting from the left is smaller than that of the middle value, and that the index starting from the mid + 1 index is smaller than the length - 1 index of the sub-vector, we continue to compare the two corresponding values on the left and right side
        if (a[l] <= a[r]) { //if the left value is smaller than the right value, we put the left value in the temporary vector (later will be copied to the original vector a)
            tmp[i] = a[l];
            l++; //we need to increment l because we want to compare the next value with the right side value that is currently larger
            i++; //we need to increment i because we have already put the smaller value on the left side in the ith index of the temporary vector, the next winner of the comparison will be put into the next index in the temporary vector
        } else {
            tmp[i] = a[r]; //this is the same when the right side is smaller than the left side value
            r++;
            i++;
        }
    }
    while(l <= mid) { //fill in the rest of the tmp vector with the numbers left in the left side of the vector if necessary
        tmp[i] = a[l];
        l++;
        i++;
    }
    while(r <= right){ //fill in the rest of the tmp vector with the numbers left in the right side of the vector if necessary
        tmp[i] = a[r];
        r++;
        i++;
    }
    for(int i = left; i <= right; i++){ //copy the temporary vector to the original vector to finish sorting the original vector entered into the function
        a[i] = tmp[i];
    }
}


void mergeSort(vector<int>& a, vector<int>& t, int left, int right) {

    /* your code here */
    if(left >= right){ //This is the base case. So when the left index is larger than the right index, we return to the last "mergeSort" recursive call and continue the next mergeSort call or merge call.
        return;
    }
    else{
        int mid = (left + right) / 2; //mid index
        mergeSort(a, t,  left, mid); // sort the left half of the vector
        mergeSort(a, t,  mid + 1, right); // sort the right half of the vector
        mergeSortedLists(a, t,left, mid, right); //merge two parts
    }
}




