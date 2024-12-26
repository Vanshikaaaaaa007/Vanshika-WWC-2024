//2. Stock Market Data Analysis
//A financial technology company needs to process real-time stock market data consisting of millions of trades every minute.
//Each trade record includes the timestamp, stock symbol, trade price, and trade volume. To identify patterns and generate 
//analytics, the trades must be sorted by timestamp. For deeper insights, the company also requires sorting by stock symbol
//and grouping by trading volume trends. Handling this large-scale data efficiently is crucial for providing timely analytics to clients.
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <ctime>

// Trade structure to store each trade record
struct Trade {
    std::string timestamp;  // Timestamp in string format (e.g., "2024-12-25T12:30:01Z")
    std::string symbol;     // Stock symbol (e.g., "AAPL")
    double price;           // Trade price
    int volume;             // Trade volume

    // Constructor to initialize the trade data
    Trade(std::string ts, std::string sym, double p, int v)
        : timestamp(ts), symbol(sym), price(p), volume(v) {}
    
    // For printing trade data
    void print() const {
        std::cout << "Timestamp: " << timestamp 
                  << " Symbol: " << symbol 
                  << " Price: " << price 
                  << " Volume: " << volume << std::endl;
    }
};

// Comparator for sorting trades by timestamp
bool compareTrades(const Trade& t1, const Trade& t2) {
    return t1.timestamp < t2.timestamp;
}

// Function to perform volume analysis (grouping by stock symbol)
void analyzeVolume(const std::vector<Trade>& trades) {
    std::unordered_map<std::string, int> volumeBySymbol;

    for (const auto& trade : trades) {
        volumeBySymbol[trade.symbol] += trade.volume;
    }

    // Output the total volume for each stock symbol
    std::cout << "\nTotal Volume per Symbol:\n";
    for (const auto& entry : volumeBySymbol) {
        std::cout << "Symbol: " << entry.first << " Total Volume: " << entry.second << std::endl;
    }
}

int main() {
    // Sample trades
    std::vector<Trade> trades;

    // Adding some trade records
    trades.push_back(Trade("2024-12-25T12:30:01Z", "AAPL", 150.25, 500));
    trades.push_back(Trade("2024-12-25T12:30:03Z", "GOOGL", 2750.50, 300));
    trades.push_back(Trade("2024-12-25T12:30:02Z", "AAPL", 151.00, 1000));
    trades.push_back(Trade("2024-12-25T12:30:04Z", "MSFT", 300.00, 700));
    trades.push_back(Trade("2024-12-25T12:30:00Z", "AAPL", 149.75, 800));
    trades.push_back(Trade("2024-12-25T12:30:05Z", "GOOGL", 2752.30, 500));

    // Sort trades by timestamp
    std::sort(trades.begin(), trades.end(), compareTrades);

    // Output sorted trades
    std::cout << "Sorted Trades by Timestamp:\n";
    for (const auto& trade : trades) {
        trade.print();
    }

    // Perform volume analysis (group by stock symbol)
    analyzeVolume(trades);

    return 0;
}
