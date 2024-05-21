string largestMerge(string word1, string word2) {
        string merge="";
        int i=0,j=0;
        while(i<word1.size()&&j<word2.size()) {
            if (word1.substr(i)>word2.substr(j)) {
                merge+=word1[i];
                i++;
            } else {
                merge+=word2[j];
                j++;
            }
        }
        if (i==word1.size()) merge+=word2.substr(j); else merge+=word1.substr(i);
        return merge;
    }
