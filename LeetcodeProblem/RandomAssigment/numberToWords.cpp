class Solution {
private:
    string LESS20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",                                "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string TENS[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string THOUSANDS[4] = {"", "Thousand", "Million", "Billion"};
public:
    string Less1000(int num)
    {
        if(num==0) return "";
        if(num<20) return  LESS20[num] + " ";
        if(num<100) return TENS[num/10] + " " + Less1000(num%10);
        return LESS20[num/100] + " Hundred "  + Less1000(num%100);
    }
    string numberToString(int num, int i)
    {
        if(num==0) return "";
        if(num%1000==0) return numberToString(num/1000, i+1);
        return numberToString(num/1000, i+1) + Less1000(num%1000)  + THOUSANDS[i] + " ";
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string res = numberToString(num, 0);
        return res.substr(0, res.find_last_not_of(' ')+1);
    } 
};
