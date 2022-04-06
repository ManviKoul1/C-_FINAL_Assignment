/* Q3: You have a binary string with length N. You are allowed to do swap() operations of two elements
only if the index parity of both elements is the same. This means that: you can swap() an element at
index 2, with any element at index4, 6, 8 etc. (even parity), similarly the element at index 3 can be
swapped with the element at index1, 5,7,9 etc.
Ex: Given string 1110, you can swap 2nd and 4th char to get 1011. But, you can never get 1101 if you
follow the swap rules.
Now, the task is to find the number of times substring 01 can occur for all such possible swaps.

Ex: 1110 does not have any substring of 01. Now you can swap2nd and 4th to get 1011, this will have
‘one’ occurrence of 01. We can now perform more swaps but we will never get any more 01
substrings here.
Input: 00100 output should be 1, for: 01010-> 2, for 10001-> 2*/

//MANVI KOUL
//This code demonstrates the use of string with swap operations//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int max(int a,int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int count(string s){
int i = 0, res = 0;    
    
    while(i+1<s.size()){
        if(s[i] == '0' && s[i+1] == '1'){
            res++;
            i += 2;
        }
        else{
            i++;
        }
    }
    
return res;    
}

string merge(string even,string odd){
    string ans;
    int n = even.size(),m = odd.size();
    int i=0,j=0,k=0;
    
    while(i<n && j<m){
        if(k%2 == 0){
            ans += even[i];
            i++;
        }
        else{
            ans += odd[j];
            j++;
        }
        k++;
    }
    
    while(i<n){
        ans += even[i];
        i++;
    }
    while(j<m){
        ans += odd[j];
        j++;
    }
    
 return ans;   
}

int main()
{

string s;
cin >> s;

string even;
string odd;

for(int i=0;i<s.size();i++){
    if(i%2 == 0){
        even += s[i];
    }
    else{
        odd += s[i];
    }
}


sort(even.begin(),even.end());
sort(odd.rbegin(),odd.rend());

string s1 = merge(even,odd);

reverse(odd.begin(), odd.end());

string s2 = merge(even,odd);

reverse(even.begin(),even.end());

string s3 = merge(even,odd);

reverse(odd.begin(),odd.end());

string s4 = merge(even,odd);

int count1 = count(s1);
int count2 = count(s2);
int count3 = count(s3);
int count4 = count(s4);


int ans = max(count1,max(count2,max(count3,count4)));

cout << ans;

    return 0;
}
