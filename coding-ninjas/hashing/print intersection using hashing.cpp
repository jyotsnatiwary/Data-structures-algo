#include<unordered_map>
using namespace std;
void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    unordered_map<int, int> omap ;
    int i;
    for(i=0; i< size1; i++){
        if(omap.count(input1[i]) == 0){
            omap[input1[i]] = 1;
        }
        else{
            omap[input1[i]]++;
        }
    }
    
    for(i =0; i<size2; i++){
        if(omap.count(input2[i]) > 0){
            if(omap[input2[i]] > 0){
                cout << input2[i] << endl;
                omap[input2[i]]--;
            }
        }
    }    
}

