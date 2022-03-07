#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void printJobs(vector<pair<int, int> > jobs, int n_jobs) {
    for(int i = 0; i < n_jobs; i++) {
        cout << jobs[i].first << " " << jobs[i].second << endl;
    }
}

bool sortByRelativeWeight(const pair<int,int> &a,
              const pair<int,int> &b)
{
    float relativeWeightA = (float) a.first/a.second;
    float relativeWeightB = (float) b.first/b.second;
    
    return ( relativeWeightA < relativeWeightB);
}

int main() {
    
    // read number of tests
    int n_tests = 0;
    cin >> n_tests;
    
    // main loop for each test
    for ( int test = 0; test < n_tests; test++) {
        vector <pair<int, int> > jobs;

        //reads number of jobs to be read
        int n_jobs;
        cin >> n_jobs;

        // saves job's info in jobs vector
        for(int job = 0; job < n_jobs ; job++) {
            
            int job_duration;
            int job_weight;

            cin >> job_duration;
            cin >> job_weight;
            
            // insert jobs in jobs vector
            jobs.push_back(make_pair(job_duration, job_weight));
        }

        // put jobs in order, by weight
        sort(jobs.begin(), jobs.end(), sortByRelativeWeight);
        
        // printJobs(jobs, n_jobs);
        // calculates completion for all jobs, with jobs vector already sorted
        int total_scheduling_time = 0;
        int accumulated_job_time = 0;

        for(int job = 0; job < n_jobs ; job++) {
            // definition of completion
            accumulated_job_time += jobs[job].first;
            
            // accumulates scheduling time
            total_scheduling_time += jobs[job].second * accumulated_job_time;
        }

        //prints output
        cout << total_scheduling_time << endl;
            
    }
    return 0;
}

