class NumberContainers {
private:
    unordered_map<int, int> indexToNumber; 
    unordered_map<int, set<int>> numberToIndices;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber); // Clean up empty sets
            }
        }

        // Update the index to the new number
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(int number) {
        // If the number has no indices, return -1
        if (numberToIndices.count(number) == 0 || numberToIndices[number].empty()) {
            return -1;
        }

        // Return the smallest index (set maintains sorted order)
        return *numberToIndices[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
