#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string>
using namespace std;

string champ_name[5];
string second_name[5];

//01234 represent ABCDE cycle
int champ[5] = {0,0,0,0,0};
int second[5] = {0,0,0,0,0};

void random_sort(){
    srand(time(NULL));
    int count1 = 0;
    int used1[5] = {0,0,0,0,0};
    while(count1 < 5){
        int index1 = rand() % 5;
        if(index1 < 0){
            index1 = -index1;
        }
        if(used1[index1] == 0){
            used1[index1] = 1;
            champ[count1] = index1;
            count1 ++;
        }
        else{
            continue;
        }
    }

    int count2 = 0;
    int used2[5] = {0,0,0,0,0};
    while(count2 < 5){
        int index2 = rand() % 5;
        if(index2 < 0){
            index2 = -index2;
        }
        if(used2[index2] == 0){
            used2[index2] = 1;
            second[count2] = index2;
            count2 ++;
        }
        else{
            continue;
        }
    }
}

int check(){
    int again = 0;
    if(champ[0] == second[0] || champ[0] == second[1]){
        again = 1;
    }
    if(champ[1] == second[2]){
        again = 1;
    }
    if(champ[2] == second[3]){
        again = 1;
    }
    if(champ[3] == second[4] || champ[4] == second[4]){
        again = 1;
    }
    if(again == 0){
        return 1;
    }
    else{
        return 0;
    }
}

//A,B,C 為3取2  //D,E為4取2
int main(){
    // cout << "A循環冠軍 : ";
    cin >> champ_name[0];
    // cout << "B循環冠軍 : ";
    cin >> champ_name[1];
    // cout << "C循環冠軍 : ";
    cin >> champ_name[2];
    // cout << "D循環冠軍 : ";
    cin >> champ_name[3];
    // cout << "E循環冠軍 : ";
    cin >> champ_name[4];

    // cout << "A循環亞軍 : ";
    cin >> second_name[0];
    // cout << "B循環亞軍 : ";
    cin >> second_name[1];
    // cout << "C循環亞軍 : ";
    cin >> second_name[2];
    // cout << "D循環亞軍 : ";
    cin >> second_name[3];
    // cout << "E循環亞軍 : ";
    cin >> second_name[4];
    
    random_sort();
    while(check() == 0){
        for(int i = 0; i < 5; i++){
            champ[i] = 0;
            second[i] = 0;
        }
        random_sort();
    }

    cout << "甲區 : \n";
    cout << champ_name[champ[0]] << '\n';
    cout << second_name[second[0]] << '\n';
    cout << second_name[second[1]] << '\n';
    cout << "乙區 : \n";
    cout << champ_name[champ[1]] << '\n'; 
    cout << second_name[second[2]] << '\n';
    cout << "丙區 : \n";
    cout << champ_name[champ[2]] << '\n'; 
    cout << second_name[second[3]] << '\n';
    cout << "丁區 : \n";
    cout << champ_name[champ[3]] << '\n';
    cout << champ_name[champ[4]] << '\n';
    cout << second_name[second[4]];


}