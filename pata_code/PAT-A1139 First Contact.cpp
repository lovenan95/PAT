#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool arr[10000][10000];
struct node {
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}

int sti(string s){
	int sign=true;
	int value=0;
	if(s[0]=='-'){
		s.erase(s.begin());
		sign=false;
	}
	for(int i=0;i<s.length();i++){
		value=value*10+s[i]-'0';
	}
	if(sign==false){
		value=-value;
	}
	return value;
} 

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {//×Ö·û´®³¤¶ÈÏàµÈËµÃ÷Í¬ÐÔ£¬¾ùÓÐ¸ººÅ»ò¾ùÃ»ÓÐ¸ººÅ 
            v[abs(sti(a))].push_back(abs(sti(b)));
            v[abs(sti(b))].push_back(abs(sti(a)));
        }
        arr[abs(sti(a))][abs(sti(b))] = arr[abs(sti(b))][abs(sti(a))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                if (arr[v[abs(c)][j]][v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}