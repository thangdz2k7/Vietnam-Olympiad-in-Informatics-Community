#include <iostream>
#include <vector>
#include "sgamelib.h"

using namespace std;

namespace PicaPicaPicachu{
    void wowowowowow(){
        int Nebula, Mountain, Quest; 
        cin >> Nebula >> Mountain >> Quest;
        
        vector<int> Height(Mountain);
        for (int i = 0; i < Mountain; i++) 
            cin >> Height[i];
        
        vector<int> LeftBound(Quest), RightBound(Quest), Peak(Quest);
        for (int i = 0; i < Quest; i++) 
            cin >> LeftBound[i] >> RightBound[i] >> Peak[i];
        
        vector<int> answers = solve(Nebula, Mountain, Quest, Height, LeftBound, RightBound, Peak);
        
        for(int result : answers) 
            cout << result << " ";
        cout << "\n";
        
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    PicaPicaPicachu::wowowowowow();

    return 0;
}