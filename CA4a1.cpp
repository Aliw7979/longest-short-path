#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;
#define MAX 500000
void solver(vector<int> adj[],int v, vector<bool>& visited,vector<int>& way);

int main() {
	int n, m, k,first,x=0;
	cin >> n >> m >> k;
	vector<bool> duplicate(MAX);
	int temp1, temp2;
	vector<int> dj[MAX];
	vector<int> way;
	for (int i = 0;i < m;i++) {
		
		cin >> temp1 >> temp2;
	    dj[temp1].push_back(temp2);
	    dj[temp2].push_back(temp1);
	}
	
	for (int i = 1;i <= n;i++) {
		way.push_back(i);
		duplicate[i] = true;
		solver(dj, i, duplicate, way);
		if (way.size() > k) {
			break;
		}
		else {
			way.clear();
			fill(duplicate.begin(), duplicate.end(), false);
		}
	}
	int last = way.size();
	for (int i = 0;i < last;i++) {
		for (int j = 0;j < dj[way[last-1]].size();j++) {
			if (way[i] == dj[way[last-1]][j]) {
				x = 1;
				first = i;
				break;
			}
		}
		if (x == 1) {
			break;
		}
	}
	cout << last - first  << endl;
	for (int i = first;i < last;i++) {
		cout << way[i] << " ";
	}
}

void solver(vector<int> adj[],int v, vector<bool>& visited,vector<int>& way) {
	for (int i = 0;i < adj[v].size();i++) {
		if (visited[adj[v][i]] == false) {
			visited[adj[v][i]] = true;
			way.push_back(adj[v][i]);
			solver(adj, adj[v][i], visited, way);
			break;
		}

	}
}