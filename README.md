# 🗺️ Smart Route Finder using Dijkstra’s Algorithm (C++)

A C++ console-based application that finds the **shortest route between major Kolkata landmarks** using **Dijkstra’s Algorithm**.  
This project demonstrates real-world application of **graphs, priority queues, and shortest path algorithms**.

---

## 📌 Project Description

The Smart Route Finder represents Kolkata landmarks as nodes in a **weighted graph**, where edges denote approximate distances (in kilometers).  
Users provide a **start** and **destination**, and the program calculates:

- Shortest path
- Total distance
- Intermediate locations (if any)

---

## 🧠 Algorithm Used

**Dijkstra’s Algorithm**
- Graph representation: Adjacency List
- Uses Min Heap (`priority_queue`) for efficiency

**Time Complexity:** `O(E log V)`  
**Space Complexity:** `O(V + E)`

---

## 🗺️ Available Locations

| Code | Location |
|----|----|
| HB | Howrah Bridge |
| VM | Victoria Memorial |
| PS | Park Street |
| NM | New Market |
| SL | Salt Lake |
| AP | Kolkata Airport |

---

## ⚙️ Tech Stack

- **Language:** C++
- **STL Used:**  
  `map`, `vector`, `priority_queue`, `algorithm`
- **Concepts:**  
  Graphs, Greedy Algorithms, Shortest Path, Path Reconstruction

---

## 📂 Project Structure

