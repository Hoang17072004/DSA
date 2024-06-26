class SnapshotArray {
public:
    int snapId;
    vector<vector<pair<int,int>>> historyRecords;
    SnapshotArray(int length) {
        snapId=0;
        historyRecords.resize(length);
        for (int i=0;i<length;i++) historyRecords[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        historyRecords[index].push_back({snapId,val});
    }
    
    int snap() {
        return snapId++;

    }
    
    int get(int index, int snap_id) {
        auto it=upper_bound(historyRecords[index].begin(),historyRecords[index].end(),make_pair(snap_id,INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
