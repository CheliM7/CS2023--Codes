#include <iostream>
#include <vector>

using namespace std;

//defining the function that calculates the median
double median(vector<int> temp_array) {
    int n = temp_array.size();
    if (n % 2 == 0) {
        return (double)(temp_array[n/2] + temp_array[n/2-1]) / 2.0;
    } else {
        return (double)temp_array[n/2];
    }
}

//defining a function that iterates over an array creating sub arrays
void run_median(vector<int> &vec , int new_array){
    if (vec.size() == 0){
        vec.push_back(new_array);
    }

    else{
    //sorting process
    for (int i = 0 ; i < vec.size() ; i++){

        if (vec[i] > new_array){
            vec.insert(vec.begin() + i , new_array);
            break;
            }
        }
    }
}

int main()
{
    int data_input[10] = {8,6,3,3,1,9,9,3,7,1};
    vector<int> new_array = {};

    for (int i = 0 ; i < 10 ; i++){
        cout << '[';
        run_median(new_array , data_input[i]);
        for (int i =0 ; i < new_array.size() ; i++){
            cout << new_array[i] << " ";
        }
        cout<<']';
        cout << " Median is : " << median(new_array) << endl;
    }

    return 0;
}
