// __define-ocg__
class Solution {
public:
    struct Item {
        double value;
        double weight;

        Item(double v, double w) {
            value = v;
            weight = w;
        }
    };

    // Sort by value/weight ratio descending
    static bool comp(Item a, Item b) {
        double r1 = a.value / a.weight;
        double r2 = b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        int n = val.size();
        vector<Item> items;

        for (int i = 0; i < n; i++) {
            items.push_back(Item(val[i], wt[i]));
        }

        sort(items.begin(), items.end(), comp);

        double tot_val = 0.0;
        int varOcg = 0; // __define-ocg__

        for (int i = 0; i < n; i++) {
            if (items[i].weight <= capacity) {
                capacity -= items[i].weight;
                tot_val += items[i].value;
            } else {
                // Take fractional part
                tot_val += (capacity / items[i].weight) * items[i].value;
                break;
            }
        }

        return round(tot_val * 1e6) / 1e6; // Round to 6 decimal places
    }
};
