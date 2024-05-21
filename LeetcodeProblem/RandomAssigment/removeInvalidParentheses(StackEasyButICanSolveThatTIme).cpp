class Solution {
public:
    set<string> validExpressions;
    int minimumRemoved=INT_MAX;
    void recurse(string &s,int index,int leftCount,int rightCount,string &expression,int removeCount) {
        if (index==s.size() ) {
            if (leftCount==rightCount) {
                if (removeCount<=minimumRemoved) {
                    if (removeCount<minimumRemoved) {
                        validExpressions.clear();
                        minimumRemoved=removeCount;
                    }
                    validExpressions.insert(expression);
                }
            }
        } else {
            char currentCharacter=s[index];
            int length=expression.size();
            if (currentCharacter!='('&&currentCharacter!=')') {
                expression.push_back(currentCharacter);
                recurse(s,index+1,leftCount,rightCount,expression,removeCount);
                expression.pop_back();
            } else {
                recurse(s,index+1,leftCount,rightCount,expression,removeCount+1);
                expression.push_back(currentCharacter);
                if (currentCharacter=='(') recurse(s,index+1,leftCount+1,rightCount,expression,removeCount);
                else if (rightCount<leftCount) {
                    recurse(s,index+1,leftCount,rightCount+1,expression,removeCount);
                }
                expression.pop_back();
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string express="";
        recurse(s,0,0,0,express,0);
        return vector<string>(validExpressions.begin(),validExpressions.end());
    }
};
