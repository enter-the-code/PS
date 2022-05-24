#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#define MAX 100
#define INF 99999999
using namespace std;
long long int gcd, lcm, tmp;
long long int resA = 0, resB = 0;
 
int main() {
 
    cin >> gcd >> lcm;
 
    tmp = lcm / gcd;
 
    
    for (long long int i = 1; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            //약수 두 수
            long long int tmpA = i;
            long long int tmpB = tmp / i;

            bool isAble = true;
            long long int cnt = 0;
            for (long long int j = 1; j <= tmpA; j++) {
                if (tmpA % j == 0 && tmpB % j == 0) {
                    cnt++;
                }
                if (cnt > 1) {
                    isAble = false;
                    break;
                }
            }
            if (isAble) {
                resA = tmpA * gcd;
                resB = tmpB * gcd;
            }
        }
    }

    cout << resA << " " << resB << "\n";
}

