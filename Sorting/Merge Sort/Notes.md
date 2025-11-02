# Merge Sort Implementation Notes

## Time Complexity 
$O(NlogN)$  
Why?  
Divides the array in half recursively: log n levels of recursion  
At each level, you process all n elements total  

The n in O(nlogn) represents a linear pass through all elements in the input. The log(n) portion represents the number of times the input is split or reduced in size  

Merging each of the subarrays takes O(n) time where n is the combined number of elements in the two subarrays because we have to compare each element of each subarray in order to combine them into one sorted array.

## Space Complexity
$O(N)$  
Why?  
Need O(n) space for the temporary arrays created during splitting and merging. Program creates copies of subarrays at every level. Even though theres $log n$ levels, at each level it's storing roughly $n$ elements total across all subarrays.

<details>
<summary><h2>Unoptimized Program</h2></summary>

```cpp
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
```
</details>

# Performance Optimizations

1. **Eliminated O(n) erase operations:** Replaced `erase(begin())` with integer indices to traverse arrays, reducing merge complexity from O(n²) to O(n).

2. **Pass by reference:** Avoid unnecessary vector copies in function parameters.

<details>
<summary><h2>Slight Optimization</h2></summary>

```cpp
std::vector<int> mergeSort(std::vector<int> &list){
    /*Stop mergesort once we reach an array with only one element*/
    if (list.size() == 1){
        return list;
    }
    
    /*Find middle value to split the array in*/
    int mid = list.size() / 2;
    /*Create two new arrays, and divide original into half*/
    std::vector<int> firsthalf(list.begin(), list.begin() + mid);
    std::vector<int> secondhalf(list.begin() + mid, list.end());

    /*Continue to break down the array until it reaches base case*/
    firsthalf = mergeSort(firsthalf);
    secondhalf = mergeSort(secondhalf);

    /*Sort the subarrays*/
    return merge(firsthalf, secondhalf);
}

std::vector<int> merge(std::vector<int> &listone, std::vector<int> &listtwo){
    std::vector<int> returnArray = {};

    /*Check which value is smaller and store it in new array*/
    int i = 0, j = 0;
    while(listone.size() > i && listtwo.size() > j){
        if (listone[i] >= listtwo[j]){
            returnArray.push_back(listtwo[j]);
            j++;
        }
        else{
            returnArray.push_back(listone[i]);
            i++;
        }
    }

    /*Add any existing values left to the return array*/
    while(listone.size() > i){
        returnArray.push_back(listone[i]);
        i++;
    }

    while(listtwo.size() > j){
        returnArray.push_back(listtwo[j]);
        j++;
    }
    return returnArray;
}

```
</details>

## Issues Found in Implementation

### Issue 1: Not Capturing Return Values in `mergeSort()` (lines 33-34)
When calling `mergeSort(firsthalf)` and `mergeSort(secondhalf)`, the return values are not being assigned back to the variables. The recursive calls return the sorted arrays, but they're being discarded.

**Problem:**
```cpp
mergeSort(firsthalf);
mergeSort(secondhalf);
```

The sorted results need to be captured and used for the merge step.

---

### Issue 2: Wrong Loop Condition in `merge()` (line 42)
The `while` loop uses `||` (OR) operator, which causes the loop to continue even when one list is empty. This leads to accessing elements in an empty vector, causing undefined behavior or crashes.

**Problem:**
```cpp
while(listone.size() > 0 || listtwo.size() > 0)
```
---

# Goals 
Improve space complexity to $O(logN)$ by implementing algorithm in-place.