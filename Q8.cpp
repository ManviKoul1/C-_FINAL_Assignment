/*Q8: There are two processes, A and B, that can access a common variable x. They can access it in
sequence, A first and then B, or B first then A. But in one day they access it only once. A logbook is
maintained by the OS showing which process accessed x when.
You got a series of entries of the log, but you want to make sure that this log has not been
altered by anyone. Your output is the answer to the question: Is the log valid or not?
Ex: Input: AB, output: Yes
Input: ABAABB, output: No*/

//MANVI KOUL
//This code demonstrates the use of 2 processes A & B and their access//
#include <iostream>

using namespace std;

int main()
{

string s;
bool ans = true;

cin >> m;

for(int i=0;i<m.size();i++){
    if(i%2 == 0 && i!=m.size()-1){
        if(m[i] ==  m[i+1]){
            ans = false;
        }
    }
}

if(ans == true){
    cout << "YES it's done";
}
else{
    cout << "Ooops!!NO";
}


    return 0;
}
