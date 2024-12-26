//3. Video Streaming Platform Recommendation System
//A video streaming platform generates recommendations for users based on the popularity of movies and TV shows. Each item in the
//catalog has attributes like total views, user ratings, and release year. The system must sort the catalog to prioritize trending 
//content by combining popularity and recency. Furthermore, personalized recommendations require sorting by relevance to each user's 
//viewing history, making the sorting process dynamic and computationally intensive.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// Video Item Class
class VideoItem {
public:
    std::string title;
    int total_views;        // Total views of the video
    float user_ratings;     // Average user rating (1.0 to 5.0)
    int release_year;       // Year of release

    // Constructor to initialize a video item
    VideoItem(std::string t, int views, float ratings, int year)
        : title(t), total_views(views), user_ratings(ratings), release_year(year) {}

    // Function to calculate relevance score based on global popularity
    float calculateGlobalScore() const {
        // Simple scoring: views + ratings * 100 + recency factor (scaled by release year)
        return total_views + user_ratings * 100 + (2024 - release_year) * 10;
    }
};

// User Class
class User {
public:
    std::string name;
    std::unordered_map<std::string, float> watched_history;  // Map of movie title to a relevance score for the user

    // Constructor to initialize a user
    User(std::string n) : name(n) {}

    // Function to add a watched video with a weight (higher value means the user liked it more)
    void addWatchedVideo(const std::string& title, float score) {
        watched_history[title] = score;
    }

    // Function to calculate personalized relevance score for a given video
    float calculatePersonalizedScore(const VideoItem& video) const {
        // Check if user has watched the video and has a weight for it
        auto it = watched_history.find(video.title);
        if (it != watched_history.end()) {
            return it->second;  // Return the personalized relevance score from watched history
        }
        return 0.0;  // If the user hasn't watched it, return 0 as default score
    }
};

// Comparator to sort video items based on a combined global and personalized score
class VideoComparator {
public:
    User* currentUser;  // Pointer to the current user to calculate personalized scores

    VideoComparator(User* user) : currentUser(user) {}

    bool operator()(const VideoItem& video1, const VideoItem& video2) {
        // Calculate the global popularity score for both videos
        float globalScore1 = video1.calculateGlobalScore();
        float globalScore2 = video2.calculateGlobalScore();

        // Calculate the personalized score based on the user's watched history
        float personalizedScore1 = currentUser->calculatePersonalizedScore(video1);
        float personalizedScore2 = currentUser->calculatePersonalizedScore(video2);

        // Combine the scores: prioritize personalized score, then global score
        float totalScore1 = personalizedScore1 * 2 + globalScore1;  // Personalized score gets double weight
        float totalScore2 = personalizedScore2 * 2 + globalScore2;

        return totalScore1 > totalScore2;  // Sort in descending order (higher score comes first)
    }
};

// Function to display the list of video items
void displayVideos(const std::vector<VideoItem>& videos) {
    for (const auto& video : videos) {
        std::cout << "Title: " << video.title 
                  << ", Views: " << video.total_views 
                  << ", Rating: " << video.user_ratings 
                  << ", Release Year: " << video.release_year 
                  << std::endl;
    }
}

int main() {
    // Create some video items (Movies or TV Shows)
    std::vector<VideoItem> catalog = {
        VideoItem("The Matrix", 1000000, 4.8, 1999),
        VideoItem("Avengers: Endgame", 25000000, 4.9, 2019),
        VideoItem("Breaking Bad", 5000000, 4.9, 2008),
        VideoItem("Stranger Things", 30000000, 4.7, 2016),
        VideoItem("The Crown", 15000000, 4.5, 2016)
    };

    // Create a user and add some watched history with relevance scores
    User user("John Doe");
    user.addWatchedVideo("Avengers: Endgame", 4.9);  // Loved this movie
    user.addWatchedVideo("Breaking Bad", 4.8);       // Loved this TV show
    user.addWatchedVideo("Stranger Things", 4.2);    // Liked this show

    // Sort the catalog based on a personalized relevance score
    VideoComparator comparator(&user);
    std::sort(catalog.begin(), catalog.end(), comparator);

    // Display the sorted list of videos based on the user's preferences and global popularity
    std::cout << "Personalized Video Recommendations for " << user.name << ":\n";
    displayVideos(catalog);

    return 0;
}
