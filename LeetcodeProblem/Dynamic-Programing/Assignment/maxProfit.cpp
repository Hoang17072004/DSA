int maxProfit(vector<int> prices) {
	if (prices.size()<1) return 0;
	int length=prices.length();
	vector<int> buy(length+1);
	vector<int> sell(length+1);
	buy[1]=-prices[0];
	for (int i=2;i<=length;i++) {
		int price=price[i-1];
		buy[i]=max(buy[i-1],sell[i-2]-price);
		sell[i]=max(sell[i-1],buy[i-1]+price);
	}
	return sell[length];
}
