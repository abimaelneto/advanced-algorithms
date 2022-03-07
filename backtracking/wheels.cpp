#include<stdio.h>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct state {
    int digit[4];
    int depth;
};

int moves[8][4] = {   
    {-1, 0, 0, 0},
    {-1, 0, 0, 0},
    {0, -1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, -1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, -1},
    {0, 0, 0, 1}
};

void next_states(state s, state nexts[8]) {
    int i,j;

    for(i = 0; i < 8; i++) {
        nexts[i] = s;
        nexts[i].depth = s.depth+1;
        for(j = 0; j < 4; j++) {
            nexts[i].digit[j] += moves[i][j];
            if(nexts[i].digit[j] < 0) 
                nexts[i].digit[j] = 9;
            if(nexts[i].digit[j] > 9) 
                nexts[i].digit[j] = 0;
        }
    }
}

int equal(state s, state e) {
    int i;

    for(i = 0; i < 4; i++) {
        if (s.digit[i] != e.digit[i]) return 0;
    }
    return 1;
}

int bfs(state current, state final, char visited[10][10][10][10]) {
    state nexts[8];
    int i;

    queue<state> q;

    if(!visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]]) {
        visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]] = 1;
        q.push(current);

        while(!q.empty()) {
            current = q.front();
            q.pop();

            if(equal(current, final)) return current.depth;
            next_states(current, nexts);

            for(i = 0; i < 8; i++) {
                if(!visited[nexts[i].digit[0]][nexts[i].digit[1]][nexts[i].digit[2]][nexts[i].digit[3]]) {
                    visited[nexts[i].digit[0]][nexts[i].digit[1]][nexts[i].digit[2]][nexts[i].digit[3]] = 1;
                    q.push(nexts[i]);
                }
            }
        }
    }
    return -1;
}

int main(void) {
    int nr_tests, test, forbidden, i, j, k, l;
    char visited[10][10][10][10];
    state initial, final, aux;

    scanf("%d", &nr_tests);
    for(test = 0; test < nr_tests; test++) {
        scanf("%d %d %d %d", &initial.digit[0], &initial.digit[1], &initial.digit[2], &initial.digit[3]);
        scanf("%d %d %d %d", &final.digit[0], &final.digit[1], &final.digit[2], &final.digit[3]);
        scanf("%d", &forbidden);

        for(i = 0; i< 10; i++) {
            for(j = 0; j< 10; j++) {
                for(k = 0; k< 10; k++) {
                    for(l = 0; l< 10; l++) {
                        visited[i][j][k][l] = 0;
                    }
                }
            }
        }

        for(i=0; i< forbidden; i++) {
            scanf("%d %d %d %d", &aux.digit[0], &aux.digit[1], &aux.digit[2], &aux.digit[3]);
            visited[aux.digit[0]][aux.digit[1]][aux.digit[2]][aux.digit[3]] = 1;
        }

        initial.depth = 0;

        printf("%d\n", bfs(initial, final, visited));
    }
    return 0;
}

