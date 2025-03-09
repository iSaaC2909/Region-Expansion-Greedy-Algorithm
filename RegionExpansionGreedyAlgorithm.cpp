#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the Task structure that holds cost, benefit, and benefit-to-cost ratio
struct Task {
    int cost;
    int benefit;
    float benefitCostRatio;  // Benefit-to-cost ratio for greedy selection

    Task(int c, int b) : cost(c), benefit(b) {
        benefitCostRatio = static_cast<float>(b) / c;  // Calculate benefit-to-cost ratio
    }
};

// Comparator function for sorting tasks by benefit-to-cost ratio in descending order
bool compareTasks(const Task& a, const Task& b) {
    return a.benefitCostRatio > b.benefitCostRatio;
}

// Region Expansion Greedy Algorithm
int regionExpansionGreedy(vector<Task>& tasks, int budget) {
    // Sort tasks based on benefit-to-cost ratio in descending order
    sort(tasks.begin(), tasks.end(), compareTasks);

    int totalBenefit = 0;
    int totalCost = 0;

    // Initialize region (empty set of tasks)
    vector<Task> selectedTasks;

    for (const auto& task : tasks) {
        // If adding this task exceeds the budget, stop
        if (totalCost + task.cost > budget) {
            break;
        }

        // Add the task to the region
        selectedTasks.push_back(task);
        totalCost += task.cost;
        totalBenefit += task.benefit;
    }

    // Output the selected tasks
    cout << "Selected tasks: \n";
    for (const auto& task : selectedTasks) {
        cout << "Cost: " << task.cost << ", Benefit: " << task.benefit << endl;
    }

    // Return the total benefit of the selected tasks
    return totalBenefit;
}

int main() {
    // Define the tasks with cost and benefit
    vector<Task> tasks = {
        Task(3, 6),
        Task(2, 4),
        Task(5, 8),
        Task(6, 7),
        Task(4, 5)
    };

    // Define the budget
    int budget = 10;

    // Call the region expansion greedy algorithm and get the maximum total benefit
    int maxBenefit = regionExpansionGreedy(tasks, budget);

    // Output the maximum benefit achieved within the budget
    cout << "Maximum total benefit within budget: " << maxBenefit << endl;

    return 0;
}
