// Recommending songs according to the user's preferences
/*
    02/10/2026: 
    Recoding everything from scratch, 
    Having coded the data structure, still lacking interface and Business Logic

    03/10/2026:
    Finishing 
*/ 

//#include<stdio.h>
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

        bool hasViewdSong(int songID) {
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

}