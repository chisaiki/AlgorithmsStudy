# Merge Sort Implementation Notes

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

**Hint:** The loop should only continue while BOTH lists have elements to compare. Once one list is empty, the remaining elements should be handled by the cleanup loops below.

---

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