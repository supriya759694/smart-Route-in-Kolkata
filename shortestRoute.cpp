
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

// Graph as adjacency list: map<node, vector<pair<neighbor, weight>>> (Kolkata landmarks with approx distances in km)
map<string, vector<pair<string, int>>> graph = {
    {"HB", {{"VM", 5}, {"PS", 6}, {"AP", 15}}},  // Howrah Bridge
    {"VM", {{"HB", 5}, {"PS", 3}, {"NM", 2}}},   // Victoria Memorial
    {"PS", {{"HB", 6}, {"VM", 3}, {"NM", 1}, {"SL", 10}}},  // Park Street
    {"NM", {{"VM", 2}, {"PS", 1}, {"SL", 12}}},  // New Market
    {"SL", {{"PS", 10}, {"NM", 12}, {"AP", 8}}}, // Salt Lake
    {"AP", {{"SL", 8}, {"HB", 15}}}              // Kolkata Airport
};

// Dijkstra's algorithm (unchanged)
pair<int, vector<string>> dijkstra(const string& start, const string& end) {
    map<string, int> distances;
    map<string, string> previous;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;  // Min-heap

    // Initialize distances
    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if (node == end) break;

        for (const auto& neighbor : graph[node]) {
            int newDist = dist + neighbor.second;
            if (newDist < distances[neighbor.first]) {
                distances[neighbor.first] = newDist;
                previous[neighbor.first] = node;
                pq.push({newDist, neighbor.first});
            }
        }
    }

    // Reconstruct path
    vector<string> path;
    string current = end;
    while (current != "") {
        path.push_back(current);
        if (previous.find(current) == previous.end()) break;
        current = previous[current];
    }
    reverse(path.begin(), path.end());

    if (path.empty() || path[0] != start) {
        return {numeric_limits<int>::max(), {}};  // No path
    }
    return {distances[end], path};
}

int main() {
    string start, end;
    cout << "Smart Route Finder for Kolkata (Dijkstra's Algorithm)" << endl;
    cout << "Available locations:" << endl;
    cout << "  HB: Howrah Bridge" << endl;
    cout << "  VM: Victoria Memorial" << endl;
    cout << "  PS: Park Street" << endl;
    cout << "  SL: Salt Lake" << endl;
    cout << "  NM: New Market" << endl;
    cout << "  AP: Kolkata Airport" << endl;
    cout << "Enter start location (e.g., HB): ";
    cin >> start;
    transform(start.begin(), start.end(), start.begin(), ::toupper);  // Convert to uppercase

    cout << "Enter end location (e.g., AP): ";
    cin >> end;
    transform(end.begin(), end.end(), end.begin(), ::toupper);

    if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
        cout << "Error: Invalid locations. Please use HB, VM, PS, SL, NM, or AP." << endl;
        return 1;
    }

    auto [distance, path] = dijkstra(start, end);
    if (distance == numeric_limits<int>::max()) {
        cout << "No path found between " << start << " and " << end << "." << endl;
    } else {
        cout << "Shortest Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Total Distance: " << distance << " km" << endl;

        // Intermediate locations (exclude start and end)
        vector<string> intermediates;
        if (path.size() > 2) {
            for (size_t i = 1; i < path.size() - 1; ++i) {
                intermediates.push_back(path[i]);
            }
        }
        cout << "Intermediate Locations: ";
        if (intermediates.empty()) {
            cout << "None";
        } else {
            for (size_t i = 0; i < intermediates.size(); ++i) {
                cout << intermediates[i];
                if (i < intermediates.size() - 1) cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
