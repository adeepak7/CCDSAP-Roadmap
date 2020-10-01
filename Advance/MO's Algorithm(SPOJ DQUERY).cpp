#include <bits/stdc++.h>
using namespace std;

int n,q;

long long current_answer=0;

long long answers[200010];
int BLOCK_SIZE;
int arr[30010];

pair< pair<int, int>, int> queries[200010];

int frequency[1000010];

inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

inline void addE(int x)
{
    if(frequency[x] == 0){
        current_answer ++;
    }
    frequency[x] ++ ;
}


inline void removeE(int x)
{
    if(frequency[x] == 1){
        current_answer --;
    }
    frequency[x] -- ;
}

int main()
{

    scanf("%d",&n);

    BLOCK_SIZE = static_cast<int>(sqrt(n));


    for(int i = 1; i <= n; i++)
        scanf("%d",&arr[i]);

    scanf("%d",&q);

    for(int i = 0; i < q; i++) {
        scanf("%d %d",&queries[i].first.first,&queries[i].first.second);
        queries[i].second = i;
    }


    sort(queries, queries + q, mo_cmp);


    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < q; i++) {

        int left = queries[i].first.first;
        int right = queries[i].first.second;

        //cout<<"LEFT : "<<left<<" RIGHT : "<<right<<endl;

        while(mo_right < right) {
            mo_right++;
            addE(arr[mo_right]);
        }
        while(mo_right > right) {
            removeE(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            removeE(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            addE(arr[mo_left]);
        }

        answers[queries[i].second] = current_answer;
    }


    for(int i = 0; i < q; i++)
        printf("%d\n",answers[i]);

    return 0;
}
