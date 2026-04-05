#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void code(int size,vector<string> &v,string a="",int i=0){

    if(i==size){
        v.push_back(a);
        return;
    }
    code(size,v,a+"0",i+1);
    code(size,v,a+"1",i+1);
}

int main() {

    ifstream file("C:\\Users\\petar\\OneDrive\\Desktop\\prog\\AnnaK.txt");
    ofstream zip("C:\\Users\\petar\\OneDrive\\Desktop\\prog\\zip.bin",ios::binary);
    char ch;
    map<char,long long> m;
    unordered_map<char,string> um;
    unordered_map<string,char> table;
    //counter
    while(file.get(ch)){
        m[ch]++;
    }
    file.clear();
    file.seekg(0,ios::beg);
    //sorter
    vector<pair<char,long long>> v(m.begin(),m.end());
    for(int i=0;i<v.size();i++){
        for(int y=i;y<v.size();y++){
            if(v[i].second<v[y].second){
                swap(v[i],v[y]);
            }
        }
    }
    //char to binary
    long long t=1,c=0,p=0;
    while(t<v.size()){
        t*=2;
        c++;
    }
    vector<string> v1;
    code(c,v1);
    for(auto a:v){
        um[a.first]=v1[p];
        table[v1[p]]=a.first;
        p++;
        cout<<a.first<<" "<<a.second<<endl;
    }
    //print
    for(auto a:um){
        cout<<a.first<<" "<<a.second<<endl;
    }
    //write
    unsigned char buffer = 0;
    int bitCount = 0;
    while(file.get(ch)){
        string code=um[ch];
        for(char bit:code){
            buffer<<=1;
            if(bit=='1'){
                buffer|=1;
            }
            bitCount++;
            if(bitCount==8){
                zip.write((char*)&buffer,1);
                bitCount=0;
                buffer=0;
            }
        }
    }
    if(bitCount > 0) {
        buffer <<= (8 - bitCount);
        zip.write((char*)&buffer, 1);
    }
    //close
    file.close();
    zip.close();
    //reopen
    ifstream zip1("C:\\Users\\petar\\OneDrive\\Desktop\\prog\\zip.bin",ios::binary);
    ofstream decomp("C:\\Users\\petar\\OneDrive\\Desktop\\prog\\decomp.txt");
    //decompress
    string bukva="";
    unsigned char byte;
    while(zip1.read((char*)&byte,1)){
        for(int i=7;i>=0;i--){
            bool bit=(byte>>i)&1;
            if(bit){
                bukva+="1";
            }
            else{
                bukva+="0";
            }
            if(table.count(bukva)){
                decomp<<table[bukva];
                bukva="";
            }
        }
    }
    //close
    zip1.close();
    decomp.close();


    return 0;
}