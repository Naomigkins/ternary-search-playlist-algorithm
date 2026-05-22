# 🎵 Ternary Search Divide-and-Conquer Playlist Algorithm

A custom C++ console application designed to optimize media retrieval efficiency on mobile devices. This project implements a modified divide-and-conquer search paradigm by dividing an alphabetized playlist into three sublists at each step (Ternary Search) rather than the standard two-way split (Binary Search).

---

## 🛠️ Tech Stack & Theoretical Focus
* **Language:** C++ (ISO/IEC 14882)
* **Paradigm:** Divide-and-Conquer (Recursive Implementation)
* **Algorithmic Mechanics:** Ternary Array Partitioning & Logarithmic Index Hunting
* **Data Types:** Multi-string Arrays (`std::string`)

---

## 🧠 Code Architecture & Logic Breakdown

The algorithm operates by establishing two distinct midpoints (`mid1` and `mid2`) to split the sorted array into three equal chunks:

1. **Calculate Midpoints:** 
   * `mid1 = left + (right - left) / 3`
   * `mid2 = right - (right - left) / 3`
2. **Immediate Key Match:** It immediately checks if the target song matches either `playlist[mid1]` or `playlist[mid2]`. If found, it returns the index right away.
3. **3-Way Boundary Pruning:** If an instant match isn't found, it drops two-thirds of the search space by shifting the recursive boundaries:
   * **Left Chunk:** If the target is alphabetically smaller than `mid1`, it searches between `left` and `mid1 - 1`.
   * **Right Chunk:** If the target is alphabetically larger than `mid2`, it searches between `mid2 + 1` and `right`.
   * **Middle Chunk:** If it falls in between, it narrows down to `mid1 + 1` and `mid2 - 1`.

---

## 📉 Assignment Analysis & Theoretical Foundations (Part 2)

### 1. Time Complexity Breakdown
The time complexity of this 3-way split algorithm in the worst case is **$O(\log_3 n)$**. 

* **Mathematical Explanation:** At each operational step, the algorithm reduces the search space array by a factor of 3. The maximum number of divisions required to reduce an array of size $n$ down to a single element is modeled by the equation:
  $$3^k = n \implies k = \log_3 n$$
* **String Comparison Factor:** Because the array consists of strings, comparing two strings of maximum length $m$ takes $O(m)$ time. Therefore, the absolute worst-case time complexity is technically $O(m \cdot \log_3 n)$.

### 2. Algorithmic Comparison: Ternary Search vs. Binary Search
How does $O(\log_3 n)$ stack up against Binary Search's $O(\log_2 n)$?

* **In Terms of Big-O Notation:** They are **asymptotically equivalent**. By using the mathematical logarithmic base-change rule:
  $$\log_3 n = \frac{\log_2 n}{\log_2 3} \approx 0.63 \cdot \log_2 n$$
* **The Reality:** In Big-O notation, constant multipliers are dropped. Therefore, both algorithms are categorized strictly as **$O(\log n)$**.
* **Performance Tradeoff:** While Ternary Search performs fewer total partition drops ($0.63 \cdot \log_2 n$), it requires **more conditional comparisons per step** (checking two mid-points instead of one). In real-world environments, this extra comparison overhead often makes Binary Search slightly faster in execution, despite the smaller theoretical step count.

---

## 🔧 How to Compile and Run Locally

### Prerequisites
A standard C++ compiler installed (such as `g++` or Clang).

### Execution Steps
1. Clone this repository:
   ```bash
   git clone https://github.com
   ```
2. Navigate into the folder:
   ```bash
   cd ternary-search-playlist-algorithm
   ```
3. Compile the code:
   ```bash
   g++ main.cpp -o playlist_searcher
   ```
4. Run the executable:
   * **Windows:** `playlist_searcher.exe`
   * **macOS/Linux:** `./playlist_searcher`

---

## 🎓 Cybersecurity & Optimization Context
Logarithmic searching paradigms are critical in cybersecurity for parsing vast sets of log data, matching cryptographic signatures rapidly, and processing high-throughput firewall traffic matrices without creating operational bottlenecks.
