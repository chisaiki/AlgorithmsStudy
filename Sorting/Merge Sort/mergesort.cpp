#include <iostream>
#include <vector>

std::vector<int> mergeSort(std::vector<int> list);

std::vector<int> merge(std::vector<int> listone, std::vector<int> listtwo);

int main(){
    std::vector<int> values = {1, 4, 2, 45, 123, 9, 0, 12};

    std::cout << "Before Sort: ";
    for (auto &x: values){
        std::cout << x << ", "; 
    }

    values = mergeSort(values);
    std::cout << "\nAfter Sort: ";
    for (auto &x: values){
        std::cout << x << ", "; 
    }
}


std::vector<int> mergeSort(std::vector<int> list){
    if (list.size() == 1){
        return list;
    }
    
    /*Find middle value to split the array in*/
    int mid = list.size() / 2;
    std::vector<int> firsthalf(list.begin(), list.begin() + mid);
    std::vector<int> secondhalf(list.begin() + mid, list.end());

    firsthalf = mergeSort(firsthalf);
    secondhalf = mergeSort(secondhalf);

    return merge(firsthalf, secondhalf);
}

std::vector<int> merge(std::vector<int> listone, std::vector<int> listtwo){
    std::vector<int> returnArray = {};

    while(listone.size() > 0 && listtwo.size() > 0){
        if (listone[0] > listtwo[0]){
            returnArray.push_back(listtwo[0]);
            listtwo.erase(listtwo.begin());
        }
        else{
            returnArray.push_back(listone[0]);
            listone.erase(listone.begin());
        }
    }

    while(listone.size() > 0){
        returnArray.push_back(listone[0]);
        listone.erase(listone.begin());
    }

    while(listtwo.size() > 0){
        returnArray.push_back(listtwo[0]);
        listtwo.erase(listtwo.begin());
    }

    return returnArray;
}