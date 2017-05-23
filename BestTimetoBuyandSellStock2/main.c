#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    for(int i=0;i<pricesSize-1;i++){
        int temp = prices[i+1]-prices[i];
        if(temp>0)
            profit += temp;
    }
    return profit;
}

int main(int argc, char *argv[])
{
	int result;
	int prices[4] = {1, 3, 1, 4};
	result = maxProfit(prices, 4);
	printf("%d\n", result);
}
