#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (register int i = 0; i < n; ++i)
	    cin >> v[i];
    int ans=0;
    //思路就是统计出现的字符串，然后做相应的加减处理！
    ans+=count(v.begin(), v.end(), "++X");
    ans+=count(v.begin(), v.end(), "X++");
    ans-=count(v.begin(), v.end(), "--X");
    ans-=count(v.begin(), v.end(), "X--");
    cout<<ans<< endl;
    return 0;
}
