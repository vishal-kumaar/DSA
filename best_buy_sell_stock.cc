#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector <int> prices){
    int maxProfit = 0, bestBuy = prices.front();

    for (int i = 1; i < prices.size(); i++){
        bestBuy = min(prices[i], bestBuy);
        maxProfit = max(prices[i] - bestBuy, maxProfit);
    }
 
    return maxProfit;
}

int main(){
    // vector <int> prices = {7, 1, 5, 3, 6, 4};
    vector <int> prices = {10, 8, 2, 1, -6, 10};

    int result = maxProfit(prices);

    cout << result << endl;
}