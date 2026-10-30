/*
 * Warehouse Navigation using Dijkstra's Algorithm (C++)
 * -----------------------------------------------------
 * Builds a weighted graph of a warehouse (charging station, junctions,
 * storage locations) and finds the shortest route from the charging
 * station to a selected storage location.
 *
 * Compile: g++ -std=c++17 -o warehouse warehouse_dijkstra.cpp
 * Run:     ./warehouse
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();
const string START = "Charging Station";

class WarehouseGraph {
public:
    // Add a two-way aisle between a and b with the given weight (metres)
    void addPath(const string &a, const string &b, int w) {
        if (w < 0) {
            cerr << "Error: Dijkstra needs non-negative weights\n";
            return;
        }
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    bool hasNode(const string &n) const { return adj.count(n) > 0; }

    // Dijkstra from source: fills dist[] and prev[]
    void dijkstra(const string &source, map<string, int> &dist,
                  map<string, string> &prev) const {
        for (const auto &kv : adj) {
            dist[kv.first] = INF;
            prev[kv.first] = "";
        }
        dist[source] = 0;

        // min-heap of (distance, node)
        using P = pair<int, string>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;  // stale entry

            for (const auto &[v, w] : adj.at(u)) {
                int nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    prev[v] = u;
                    pq.push({nd, v});
                }
            }
        }
    }

    // Returns the path from source to target (empty if unreachable)
    vector<string> shortestPath(const string &source, const string &target,
                                int &total) const {
        map<string, int> dist;
        map<string, string> prev;
        dijkstra(source, dist, prev);

        total = dist[target];
        vector<string> path;
        if (total == INF) return path;

        for (string at = target; !at.empty(); at = prev[at])
            path.push_back(at);
        reverse(path.begin(), path.end());
        return path;
    }

    // Weight of the edge a-b
    int edgeWeight(const string &a, const string &b) const {
        for (const auto &[v, w] : adj.at(a))
            if (v == b) return w;
        return -1;
    }

    // Storage locations: racks and the packing area
    vector<string> storageLocations() const {
        vector<string> res;
        for (const auto &kv : adj)
            if (kv.first.rfind("Rack", 0) == 0 || kv.first == "Packing Area")
                res.push_back(kv.first);
        sort(res.begin(), res.end());
        return res;
    }

private:
    map<string, vector<pair<string, int>>> adj;
};

WarehouseGraph buildWarehouse() {
    WarehouseGraph g;
    // Charging station to main junctions
    g.addPath(START, "J1", 10);
    g.addPath(START, "J2", 15);
    // Junction network
    g.addPath("J1", "J2", 6);
    g.addPath("J1", "J3", 15);
    g.addPath("J2", "J4", 12);
    g.addPath("J3", "J4", 5);
    g.addPath("J3", "J5", 8);
    g.addPath("J4", "J6", 10);
    g.addPath("J5", "J6", 6);
    // Storage locations attached to junctions
    g.addPath("J1", "Rack A1", 7);
    g.addPath("J2", "Rack A2", 9);
    g.addPath("J3", "Rack B1", 4);
    g.addPath("J4", "Rack B2", 6);
    g.addPath("J5", "Rack C1", 5);
    g.addPath("J6", "Rack C2", 3);
    g.addPath("J6", "Packing Area", 8);
    g.addPath("Rack B1", "Rack B2", 3);
    return g;
}

int main() {
    WarehouseGraph g = buildWarehouse();
    vector<string> targets = g.storageLocations();

    cout << "=== Warehouse Navigation (Dijkstra) ===\n";
    cout << "Available storage locations:\n";
    for (size_t i = 0; i < targets.size(); i++)
        cout << "  " << i + 1 << ". " << targets[i] << "\n";

    cout << "\nSelect destination number: ";
    int choice;
    if (!(cin >> choice) || choice < 1 || choice > (int)targets.size()) {
        cout << "Invalid selection.\n";
        return 1;
    }
    string target = targets[choice - 1];

    int total;
    vector<string> path = g.shortestPath(START, target, total);
    if (path.empty()) {
        cout << "No route from " << START << " to " << target << ".\n";
        return 0;
    }

    cout << "\nShortest route to " << target << ":\n  ";
    for (size_t i = 0; i < path.size(); i++)
        cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
    cout << "Total distance: " << total << " m\n";

    cout << "\nStep-by-step:\n";
    for (size_t i = 0; i + 1 < path.size(); i++)
        cout << "  " << path[i] << " -> " << path[i + 1] << ": "
             << g.edgeWeight(path[i], path[i + 1]) << " m\n";

    // Distances to every storage location
    map<string, int> dist;
    map<string, string> prev;
    g.dijkstra(START, dist, prev);
    cout << "\nDistance from charging station to all storage locations:\n";
    for (const auto &t : targets)
        cout << "  " << t << string(14 - min<size_t>(t.size(), 13), ' ')
             << dist[t] << " m\n";

    return 0;
}
