class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> outputs;
        int n=input.length();
        for (int i=0;i<n;i++) {
            if (input[i]=='+'||input[i]=='-'||input[i]=='*') {
                string left=input.substr(0,i);
                string right=input.substr(i+1);
                vector<int> lval=diffWaysToCompute(left);
                vector<int> rval=diffWaysToCompute(right);
                for (int l: lval) {
                    for (int r: rval) {
                        switch(input[i]) {
                            case '+':
                                outputs.push_back(l+r);
                                break;
                            case '-':
                                outputs.push_back(l-r);
                                break;
                            default:
                            outputs.push_back(l*r);
                        }
                    }
                }
            }
        }
        if (outputs.empty()) outputs.push_back(stoi(input));
        return outputs;
    }
};
