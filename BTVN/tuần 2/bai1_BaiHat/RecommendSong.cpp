// Recommending songs according to the user's preferences
/*
    02/10/2026: 
    Recoding everything from scratch, 
    Having coded the data structure, still lacking interface and Business Logic

    03/10/2026:
    Finishing 
*/ 

#include<iostream>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

// Define the type of songs, optimize the speed of 
enum Genre{
    POP,
    ROCK,
    JAZZ,
    CLASSICAL,
    HIPHOP,
    RAP,
    INDIE
};

// Define the weight of interaction 
enum ActionWeight{
    VIEW = 1,
    LIKE = 3,
    DOWNLOAD = 5
};

//
class Song{
    public:
        int id;
        string title;
        string author;
        Genre genre;

        Song(){}
        Song(int id, const string& title, const string& author, Genre genre)
            : id(id), title(title), author(author), genre(genre) {}
};

class User{
    public:
        int userID;
        string name;

        unordered_map<int, int> interactions;
        
        unordered_set<int> likedSongs;
        unordered_set<int> viewedSongs;
        unordered_set<int> downloadedSongs;

        User(){}
        User(int id, const string& name): userID(id), name(name) {}

        void viewSong(int songID) {
            interactions[songID] += VIEW;
            viewedSongs.insert(songID);
        }

        void likeSong(int songID) {
            interactions[songID] += LIKE;
            likedSongs.insert(songID);
        }

        void downloadSong(int songID) {
            interactions[songID] += DOWNLOAD;
            downloadedSongs.insert(songID);
        }

        bool hasViewdSong(int songID) const {
            return viewedSongs.find(songID) != viewedSongs.end();
        }
};

class MusicPlatform{
    private:
        unordered_map<int, Song> songs;
        unordered_map<int, User> users;

        int calculateSimilarity(const User& user1, const User& user2) {
            int score = 0;
            for (const auto& [songID, weight] : user1.interactions) {
                if (user2.interactions.count(songID)) {
                    score += weight * user2.interactions.at(songID);
                }
            }
            return score;
        }
    
    public:
        void addSong(int id, string title, string author, Genre genre){
            songs[id] = Song(id, title, author, genre);
        }

        void addUser(int id, string name){
            users[id] = User(id, name);
        }

        User& getUser(int id){
            return users[id];
        }

        void recommendedSongs(int target_user_id){
            if(users.find(target_user_id) == users.end()){
                return; // User not found
            }

            const User& target_user = users[target_user_id];
            const int benchmark_similarity = 4; // Define a threshold for similarity
            
            unordered_set<int> recommendedSongIDs;

            for(const auto& [other_id, other_user] : users){
                if(other_id == target_user_id) continue; // Skip the target user

                int similarity = calculateSimilarity(target_user, other_user);
                if(similarity >= benchmark_similarity){
                    for(const auto& [songID, weight] : other_user.interactions){
                        if(!target_user.hasViewdSong(songID)){
                            recommendedSongIDs.insert(songID);
                        }
                    }
                }
            }

            if(recommendedSongIDs.empty()){
                cout << "No recommendations available for user " << target_user.name << endl;
                return; // No recommendations available
            }

            cout << "Recommended songs for user " << target_user.name << ":" << endl;
            for(int songID : recommendedSongIDs){
                const Song& song = songs[songID];
                cout << "Song ID: " << song.id << ", Title: " << song.title << endl;
            }
        }
};

int main(){
    MusicPlatform app;

    app.addSong(101, "Ngoi Sao Co Don", "Jack", Genre::POP);
    app.addSong(102, "Thuy Trieu", "Quang Hung MasterD", Genre::HIPHOP);
    app.addSong(103, "Thu Do Cypher", "Low G", Genre::RAP);
    app.addSong(104, "Cho Toi Lang Thang", "Ngot", Genre::INDIE);
    app.addSong(105, "Don't Coi", "Orijinn", Genre::RAP);

    app.addUser(1, "Long");
    app.addUser(2, "Dung");
    app.addUser(3, "Minh");

    // Dũng tương tác
    app.getUser(2).viewSong(101);
    app.getUser(2).likeSong(101);
    app.getUser(2).viewSong(103);
    app.getUser(2).likeSong(103);
    app.getUser(2).downloadSong(103);
    app.getUser(1).viewSong(105);
    app.getUser(1).likeSong(105);

    // Long tương tác giống Dũng nhưng thích thêm bài 103
    app.getUser(1).viewSong(101);
    app.getUser(1).likeSong(101);
    app.getUser(1).likeSong(103);


    // Minh tương tác với bài 102 và 104
    app.getUser(3).viewSong(102);
    app.getUser(3).likeSong(102);
    app.getUser(3).viewSong(104);
    app.getUser(3).likeSong(104);
    app.getUser(3).downloadSong(104);

    // Chạy đề xuất cho Dũng
    app.recommendedSongs(2);
}