// Recommending songs according to the user's preferences

#include<stdio.h>
#include<unordered_set>
#include<string>

void recommendSongs() {
    
}

class User{
    private:
        int userID;
        std::unordered_set<int> likedSongs;

    public:
        User(int id): userID(id) {}

        void addLikedSong() {
            
        }

        void findSimilarUsers() {
        
        }

};

class Song{
    private:
        int songID;
        std::string songName;

    public:
        Song(int id, const std::string& name): songID(id), songName(name) {}
};

int main(){

}