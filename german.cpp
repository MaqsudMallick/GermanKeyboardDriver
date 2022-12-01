#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define index(k) k&0x00FF

bool flag[256] = {true};

void pressKey(vector<int> key){
        INPUT ip;
        ip.type = INPUT_KEYBOARD; ip.ki.wScan = 0; ip.ki.time = 0; ip.ki.dwExtraInfo = 0; ip.ki.wVk = 0x08; 
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        ip.ki.wVk = 0;
        ip.ki.dwFlags = KEYEVENTF_UNICODE;
        if(GetKeyState(VK_RSHIFT) & 0x8000 && key.size()>2) ip.ki.wScan = key[2];
        else if(GetKeyState(VK_LSHIFT) & 0x8000 || GetKeyState(VK_RSHIFT) & 0x8000) ip.ki.wScan = key[0];
        else ip.ki.wScan = key[1];
        SendInput(1, &ip, sizeof(INPUT));
        ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        flag[index(key[0])] = false;
}

void setKey(int okey, vector<int> nkey){
    if(GetKeyState(okey) & 0x8000 && flag[index(nkey[0])]) {cout<<"Key Pressed "<<char(nkey[0])<<endl; pressKey(nkey);}
    if(!(GetKeyState(okey) & 0x8000)) flag[index(nkey[0])] = true;
}

int main(){
    unordered_map<int, vector<int>> binds;
    binds=    {{0x59,{0x005A, 0x007A}},{0x5A, {0x0059, 0x0079}}, {0xDE, {0x00C4, 0x00E4}}, {0xBA, {0x00D6, 0x00F6}},
    {0xDB, {0x00DC, 0x00FC}}, {0xBD, {0x1E9E, 0x00DF, 0x003F}}, {0x37, {0x0026, 0x0037, 0x005B}},
    {0x38, {0x002A, 0x0038, 0x007B}}, {0x39, {0x0028, 0x0039, 0x007D}}, {0x30, {0x0029, 0x0030, 0x005D}},
    {0xBF, {0x005F, 0x002D}}, {0xBC, {0x003C,0x002C,0x003B}}, {0xBE, {0x003E,0x002E,0x003A}},
    {0x32, {0x0040, 0x0032, 0x0022}}, {0xC0, {0x0060, 0x007E, 0x027}}, {0xDD, {,0x002F}} };
    while(true)
        for(auto b: binds)
            setKey(b.first,b.second);
    
}