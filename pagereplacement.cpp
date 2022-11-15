#include<iostream>

int main() {
int ReferenceString[10], PageFaults = 0, s, pages , frames;

std:: cout << std:: endl << " Enter the number of Pages: \t";
std:: cin >> pages;

std:: cout << std:: endl << " Enter reference string values: " << std:: endl;

for ( int i = 0; i < pages; i++) {
std:: cout << " value no. " << i + 1 << ": \t"; std:: cin >> ReferenceString[i];
}
std:: cout << std:: endl << " What are the total number of frames: \t";
std:: cin >> frames;

int temp[ frames];

for ( int i = 0; i < frames; i++) { temp[i] = -1;
}

for ( int m = 0; m < pages; m++) { s = 0;
for ( int n = 0; n < frames; n++) {
if( ReferenceString[m] == temp[n]) { s++;
PageFaults --;
}
}
PageFaults ++;
if (( PageFaults <= frames) && (s == 0)) { temp[m] = ReferenceString[m];
}
else if (s == 0) {

temp[( PageFaults - 1) %frames] = ReferenceString[m];
}
std:: cout << std:: endl;

for ( int n = 0; n < frames; n++) { std:: cout << temp[n] << "\t";
}
}
std:: cout << std:: endl << " Total Page Faults: \t" << PageFaults << std:: endl;
return 0;
}




// PS D:\shubham\spos> g++ pagereplacement.cpp -o main
// PS D:\shubham\spos> ./main

//  Enter the number of Pages:     4

//  Enter reference string values: 
//  value no. 1:   1
//  value no. 2:   2
//  value no. 3:   3
//  value no. 4:   4

//  What are the total number of frames:   4

// 1       -1      -1      -1
// 1       2       -1      -1
// 1       2       3       -1
// 1       2       3       4
//  Total Page Faults:     4