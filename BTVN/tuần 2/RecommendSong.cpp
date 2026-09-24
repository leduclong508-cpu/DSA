// Recommending songs according to the user's preferences

#include<stdio.h>
#include<unordered_set>
#include<string>
#include"Song.h"

void recommendSongs(const std::unordered_set<int>& likedSongs, const std::unordered_set<Song*>& allSongs) {

}

class User{
    private:
        int userID;
        std::unordered_set<int> likedSongs;

    public:
        User(int id): userID(id) {}

        void addLikedSong(int songID) {
            likedSongs.insert(songID);
        }

        void findSimilarUsers(const std::unordered_set<User*>& users) {}
            

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