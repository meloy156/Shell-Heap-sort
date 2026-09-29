#include "Shellsort.h"


void Shellsort (std::vector<int>& workArray) {
    int size = workArray.size();
    
    int d = size / 2;
    int flag = 0;
    do {
        flag = 0;
        for (int i = 0; (i + d) < size; ++i) {
            if (workArray[i] > workArray[i + d]) {
                std::swap(workArray[i], workArray[i + d]);
                ++flag;
            }
        }
        d = (d/2  >  0) ? d/2 : 1;
    } while(flag != 0);
}