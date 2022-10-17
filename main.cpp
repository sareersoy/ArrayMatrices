#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> ItemsThatAreGonnabeDeleted;
int point=0;
void display(int** TDARR, int n, ofstream &cout2){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout2<<TDARR[i][j]<< " ";}
        cout2<<endl;}}
int leftUpCross(int ** TDARR3, int x, int y, int n2, int value){
    while(x-1>=0 && y-1>=0){
        if(TDARR3[y-1][x-1]==value){
            point+=value;
            TDARR3[y-1][x-1]=0;}
        x=x-1; y=y-1;}
return point;}
int leftDownCross(int ** TDARR3, int x, int y, int n2, int value){
    while(x-1>=0 && y+1<=n2-1){
        if(TDARR3[y+1][x-1] == value){
            point+=value;
        TDARR3[y+1][x-1]=0;}
    x=x-1; y=y+1;} return point;}
int rightUpCross(int ** TDARR3, int x, int y, int n2, int value){
    while(x+1<=n2-1 && y-1>=0){
        if(TDARR3[y-1][x+1] == value){
            point+=value;
            TDARR3[y-1][x+1]=0;}
        x=x+1; y=y-1;} return point;}
int rightDownCross(int ** TDARR3, int x, int y, int n2, int value){
    while(x+1<n2-1 && y+1<=n2-1){
        if(TDARR3[y+1][x+1] == value){
            point+=value;
            TDARR3[y+1][x+1]=0;}
        x=x+1; y=y+1;}
    return point;}
int UpDownward(int ** TDARR3, int x, int y, int n2, int value){
    y=0;
    while(y<=n2-1){
        if(TDARR3[y][x]==value){
            point+=value;
            TDARR3[y][x]=0;}
        y++;} return point;}
int RightLeftWard(int ** TDARR3, int x, int y, int n2, int value){
    x=0;
    while(x<n2){
        if(TDARR3[y][x]==value){
            point+=value;
            TDARR3[y][x]=0;} x++;} return point;}
bool LeftSideSearch(int** TDARR, int n,  int x, int y, int val){
    bool value=false;
    if (x-1 >= 0 && val == TDARR[y][x - 1]){
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x-1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    if (y-1 >= 0 && val == TDARR[y-1][x]){
        vector<int> vec ;
        vec.push_back(y-1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    if (y+1 <= n-1  && val == TDARR[y+1][x]){
        vector<int> vec ;
        vec.push_back(y+1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;} return value;}
bool RightSideSearch(int**TDARR, int n, int x, int y, int val){
    bool value=false;
    if (x+1 >= 0 && val == TDARR[y][x + 1]){
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x+1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    if (y+1 <= n-1 && val == TDARR[y+1][x]){
        vector<int> vec ;
        vec.push_back(y+1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    if ((y-1) >= 0 && val == TDARR[y-1][x]){
        vector<int> vec ;
        vec.push_back(y-1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;} return value;}
bool UpSideSearch(int**TDARR,int n, int x, int y, int val){
    bool value=false;
    if((y-1) >= 0 && val == TDARR[y - 1][x]){
        vector<int> vec ;
        vec.push_back(y-1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    else if((x-1)>=0 && val == TDARR[y][x-1]){
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x-1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    else if((x+1)<=(n-1) && val == TDARR[y][x+1]){
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x+1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;} return value;}
bool DownSideSearch(int**TDARR, int n, int x, int y, int val){
    bool value=false;
    if ((y+1) <= (n-1) && val == TDARR[y + 1][x]){
        vector<int> vec ;
        vec.push_back(y+1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    else if ((x-1) >= 0 && val== TDARR[y][x-1]){
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x-1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;}
    else if ((x+1 ) <= (n-1) && val == TDARR[y][x+1]){
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x+1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        value = true;} return value;}
bool Searcher(int**TDARR, int n, int x, int y, int val) {
    int boole = 0;
    if (y-1 >= 0 && val == TDARR[y - 1][x] && TDARR[y - 1][x] != 0) {
        vector<int> vec ;
        vec.push_back(y-1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        if (UpSideSearch(TDARR,n,x, y - 1, val)) { boole=1;}}
    if (y+1 <= (n-1) && val == TDARR[y + 1][x] && TDARR[y + 1][x] != 0) {
        vector<int> vec ;
        vec.push_back(y+1);
        vec.push_back(x);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        if (DownSideSearch(TDARR, n, x, y + 1, val)) { boole = 1;}}
    if (x-1 >= 0 && val == TDARR[y][x - 1] && TDARR[y][x - 1] != 0) {
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x-1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        if (LeftSideSearch(TDARR,n, x - 1, y, val)) {
            boole=1;}}
    if (x+1 <= (n-1) && val == TDARR[y][x + 1] && TDARR[y][x + 1] != 0) {
        vector<int> vec ;
        vec.push_back(y);
        vec.push_back(x+1);
        ItemsThatAreGonnabeDeleted.push_back(vec);
        if (RightSideSearch(TDARR, n, x + 1, y, val)) { boole=1;}}
    if (ItemsThatAreGonnabeDeleted.size()>=2){
        int i=0;
        while(i<ItemsThatAreGonnabeDeleted.size()){
        int yval=ItemsThatAreGonnabeDeleted[i][0];
        int xval=ItemsThatAreGonnabeDeleted[i][1];
        ItemsThatAreGonnabeDeleted.erase(ItemsThatAreGonnabeDeleted.begin());
        TDARR[yval][xval]=0;}
        TDARR[y][x]=val+1;}
    return boole;}
    int main(int argc, char* argv[]) {
    ofstream cout2(argv[3],ofstream::out);
        ifstream cmdFile; //taking command lines
        cmdFile.open(argv[1]);
        int numOfCmdLines = 0; //finding number of command lines
        while (!cmdFile.eof()) {
            string temp;
            getline(cmdFile, temp);
            numOfCmdLines++;}
        cmdFile.clear();
        cmdFile.seekg(0);
        string commands[numOfCmdLines];//filling the command-array from file
        int line = 0; int k = 0;
        while (k <= numOfCmdLines) {
            getline(cmdFile, commands[line]);
            line++; k++;}
        cmdFile.close();
        static int n = stoi(commands[0]);
        int **TDARR;
        TDARR = new int *[n];
        for (int i = 0; i < n; ++i) {
            TDARR[i] = new int[n];}
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                TDARR[i][j] = 0;}}
        for (int i = 1; i < (sizeof(commands) / sizeof(commands[1])); i++) {
            vector<int> temp;
            string s = commands[i];
            string delimiter =" "; size_t pos; string token;
            while ((pos = s.find(delimiter)) != string::npos) {
                token = s.substr(0, pos);
                temp.push_back(stoi(token));
                s.erase(0, pos + delimiter.length());
                pos = s.find(delimiter);
                token = s.substr(0, pos);
                temp.push_back(stoi(token));
                s.erase(0, pos + delimiter.length());
                pos = s.find(delimiter);
                token = s.substr(0, pos);
                temp.push_back(stoi(token));
                int valu=temp[0]; int x = temp[2]; int y = temp[1];
                TDARR[y][x]=valu;
              while(Searcher(TDARR, n, x, y, valu)){
                    Searcher(TDARR, n, x, y, valu); valu+=1;}}
            ItemsThatAreGonnabeDeleted.clear();}
    ifstream cmdFile2; //taking command lines
    cmdFile2.open(argv[2]);
    int numOfCmdLines2 = 0; //finding number of command lines
    while (!cmdFile2.eof()) {
        string temp2;
        getline(cmdFile2, temp2);
        numOfCmdLines2++;}
    cmdFile2.clear();
    cmdFile2.seekg(0);
    string commands2[numOfCmdLines2];//filling the command-array from file
    int line2 = 0; int k2 = 0;
    while (k2 <= numOfCmdLines2) {
        getline(cmdFile2, commands2[line2]);
        line2++; k2++;}
    cmdFile2.close();
    static int n2 = stoi(commands2[0]);
    int **TDARR3;
    TDARR3 = new int *[n2];
    for (int i = 0; i < n2; ++i) {
        TDARR3[i] = new int[n2];}
    int k3=0;
    for (int i = 1; i <n2+1; i++) {
        string s2 = commands2[i];
        string delimiter2 = " ";
        size_t pos2; string token2;
        while ((pos2 = s2.find(delimiter2)) != string::npos) {
            int m=0; int l=0;
            while(m<(n2-1)){
            token2 = s2.substr(0, pos2);
                TDARR3[k3][l]=stoi(token2);
            s2.erase(0, pos2 + delimiter2.length());
                pos2 = s2.find(delimiter2);
            m++;l++;}
            token2 = s2.substr(0, pos2);
            TDARR3[k3][l]=stoi(token2);
            k3++;}}
    int** COMMARR;
    COMMARR=new int *[numOfCmdLines2-n2-1];
    for (int i = 0; i < numOfCmdLines2-n2-1; ++i) {
        COMMARR[i] = new int[2];} int t=0;
    for (int i = 1+n2; i <(numOfCmdLines2); i++) {
        string s2 = commands2[i];
        string delimiter2 = " ";
        size_t pos2; string token2;
        while ((pos2 = s2.find(delimiter2)) != string::npos) {
            token2 = s2.substr(0, pos2);
            COMMARR[t][0]=stoi(token2);
            s2.erase(0, pos2 + delimiter2.length());
            pos2 = s2.find(delimiter2);
            token2 = s2.substr(0, pos2);
            COMMARR[t][1]=stoi(token2);
            t=t+1;} }
            for(int i=0; i<numOfCmdLines2-n2-1; i++){
                int x = COMMARR[i][1]; int y = COMMARR[i][0]; int value=TDARR3[y][x];
                leftUpCross(TDARR3,x,y,n2,value);
                leftDownCross(TDARR3,x,y,n2,value);
                rightUpCross(TDARR3,x,y,n2,value);
                rightDownCross(TDARR3,x,y,n2,value);
                UpDownward(TDARR3,x,y,n2,value);
                RightLeftWard(TDARR3,x,y,n2,value);
                TDARR3[y][x]=0;}
cout2<<"PART 1:"<<endl;
display(TDARR, n, cout2);
cout2<<endl;
cout2<<"PART 2:"<<endl;
display(TDARR3, n2,cout2);
cout2<<"The Point Is: "<<point;}
