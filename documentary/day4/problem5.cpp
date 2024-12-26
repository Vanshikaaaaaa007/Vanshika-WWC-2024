//5. Scheduling Ads for a Social Media Platform
//social media platform runs advertisements for multiple advertisers, each targeting specific user demographics. 
//Ads are prioritized based on factors like bid amount, engagement rates, and the remaining budget. To maximize revenue and 
//user satisfaction, the platform must sort and schedule ads in real-time for millions of users while balancing competing priorities. 
//Efficient sorting directly impacts ad visibility and revenue generation.
#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Ad class to represent each advertisement
class Ad {
public:
    std::string ad_id;          // Unique identifier for the ad
    std::string advertiser_name; // Advertiser's name
    double bid_amount;           // Bid amount for the ad
    double engagement_rate;      // Engagement rate (higher is better)
    double remaining_budget;     // Remaining budget for the ad

    // Constructor to initialize an ad
    Ad(std::string id, std::string name, double bid, double engagement, double budget)
        : ad_id(id), advertiser_name(name), bid_amount(bid), engagement_rate(engagement), remaining_budget(budget) {}

    // Method to print ad details
    void print() const {
        std::cout << "Ad ID: " << ad_id
                  << ", Advertiser: " << advertiser_name
                  << ", Bid: " << bid_amount
                  << ", Engagement Rate: " << engagement_rate
                  << ", Remaining Budget: " << remaining_budget << std::endl;
    }
};

// Comparator to prioritize ads based on bid, engagement rate, and remaining budget
class AdComparator {
public:
    bool operator()(const Ad& ad1, const Ad& ad2) {
        // Compare by bid amount (higher bid is better)
        if (ad1.bid_amount != ad2.bid_amount)
            return ad1.bid_amount < ad2.bid_amount;

        // If bid amount is the same, compare by engagement rate (higher engagement is better)
        if (ad1.engagement_rate != ad2.engagement_rate)
            return ad1.engagement_rate < ad2.engagement_rate;

        // If both bid amount and engagement rate are the same, compare by remaining budget (higher budget is better)
        return ad1.remaining_budget < ad2.remaining_budget;
    }
};

// Function to display the current scheduled ads in order of priority
void displayAds(std::priority_queue<Ad, std::vector<Ad>, AdComparator>& pq) {
    std::priority_queue<Ad, std::vector<Ad>, AdComparator> temp = pq;  // Copy the priority queue for displaying
    
    std::cout << "Scheduled Ads (Sorted by Bid, Engagement, and Budget):\n";
    while (!temp.empty()) {
        temp.top().print();
        temp.pop();
    }
}

int main() {
    // Create a priority queue to manage ads, with custom comparator
    std::priority_queue<Ad, std::vector<Ad>, AdComparator> adQueue;

    // Add some sample ads to the system
    adQueue.push(Ad("A001", "BrandX", 500, 0.8, 1000));  // High bid, good engagement
    adQueue.push(Ad("A002", "BrandY", 300, 0.6, 500));   // Lower bid, moderate engagement
    adQueue.push(Ad("A003", "BrandZ", 700, 0.9, 1500));  // Very high bid, great engagement
    adQueue.push(Ad("A004", "BrandA", 600, 0.7, 1200));  // High bid, decent engagement
    adQueue.push(Ad("A005", "BrandB", 600, 0.75, 1000)); // High bid, good engagement

    // Display the initial list of scheduled ads
    displayAds(adQueue);

    // New ad arrives (higher bid, better engagement)
    std::cout << "\nNew ad arrives:\n";
    adQueue.push(Ad("A006", "BrandC", 800, 0.95, 2000));  // Extremely high bid, amazing engagement

    // Display the updated list of scheduled ads
    displayAds(adQueue);

    return 0;
}
