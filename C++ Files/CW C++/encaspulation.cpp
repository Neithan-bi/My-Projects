#include <iostream>
using namespace std;
class fixeddeposit{
    private :
        int principal;
        int time;
        float rate;
    public :
        fixeddeposit(int p, int t, float r=0.12){
            principal = p;
            time = t;
            rate = r;
        
        }
        
};
class maturityamount : public fixeddeposit{
    private :
        float amount;
        float principal;
        int time;
        float rate;
    public :
        maturityamount(int p, int t, float r=0.12) : fixeddeposit(p,t,r){
            amount = principal * time * rate + principal;
        }
        void show(){
            cout << "The maturity amount is : " << amount << endl;
        }
};
int main(){
    int p, t;
    float r;
    cout << "Enter principal, time and rate of interest : ";
    cin >> p >> t >> r;
    maturityamount m(p,t,r);
    m.show();
    return 0;
}