int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue <int> pq;
        int time=0;
        for (auto course: courses) {
            if (time+course[0]<=course[1]) {
                pq.push(course[0]);
                time+=course[0];
            } else if (!pq.empty()&&pq.top()>=course[0]) {
                time=time-pq.top()+course[0];
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size();
    }
