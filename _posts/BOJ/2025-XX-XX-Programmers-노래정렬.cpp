#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Music { int id, cnt; };
struct Node { int cnt; vector<Music> m; };
map<string, int> maps;
vector<Node> datas; vector<int> answer;
int idGen;

vector<int> solution(vector<string> genres, vector<int> plays) {
    int N = genres.size();
    for(int i = 0; i < N; i++) {
        if(maps[genres[i]] == 0) {
            maps[genres[i]] = ++idGen;
            datas.push_back({ 0, {} });
        }
        datas[maps[genres[i]] - 1].cnt += plays[i];
        datas[maps[genres[i]] - 1].m.push_back({ i, plays[i] });
    }
    sort(datas.begin(), datas.end(), [](Node a, Node b) {
        return a.cnt > b.cnt;
    });
    for(auto d : datas) {
        sort(d.m.begin(), d.m.end(), [](Music a, Music b) {
            return a.cnt == b.cnt ? a.id < b.id : a.cnt > b.cnt;
        });
        answer.push_back(d.m[0].id);
        if(d.m.size() > 1)
            answer.push_back(d.m[1].id);
    }
    return answer;
}
