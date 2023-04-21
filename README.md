# Makefile
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Class to store the details of an audio track
class Track {
public:
    Track(std::string name, std::string artist, int duration) 
        : name_(name), artist_(artist), duration_(duration) {}

    std::string getName() const { return name_; }
    std::string getArtist() const { return artist_; }
    int getDuration() const { return duration_; }

private:
    std::string name_;
    std::string artist_;
    int duration_;
};

// Data structure to store the audio tracks
class MusicLibrary {
public:
    void addTrack(Track track) {
        auto it = std::find_if(tracks_.begin(), tracks_.end(), 
            [&](Track t) { return t.getName() == track.getName() && t.getArtist() == track.getArtist(); });
        if (it == tracks_.end()) {
            tracks_.push_back(track);
            std::cout << "Track " << track.getName() << " by " << track.getArtist() << " added to the library." << std::endl;
        }
        else {
            std::cout << "Track " << track.getName() << " by " << track.getArtist() << " already exists in the library." << std::endl;
        }
    }

    void removeTrack(std::string name, std::string artist) {
        auto it = std::find_if(tracks_.begin(), tracks_.end(), 
            [&](Track t) { return t.getName() == name && t.getArtist() == artist; });
        if (it != tracks_.end()) {
            tracks_.erase(it);
            std::cout << "Track " << name << " by " << artist << " removed from the library." << std::endl;
        }
        else {
            std::cout << "Track " << name << " by " << artist << " not found in the library." << std::endl;
        }
    }

    std::vector<Track> searchTracksByArtist(std::string artist) const {
        std::vector<Track> result;
        for (const auto& track : tracks_) {
            if (track.getArtist() == artist) {
                result.push_back(track);
            }
        }
        return result;
    }

    void saveTracksToFile(std::string filename) const {
        std::ofstream file(filename);
        for (const auto& track : tracks_) {
            file << track.getName() << "," << track.getArtist() << "," << track.getDuration() << std::endl;
        }
        file.close();
        std::cout << "Library saved to file " << filename << std::endl;
    }

    void loadTracksFromFile(std::string filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file " << filename << std::endl;
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name, artist;
            int duration;
            if (std::getline(iss, name, ',') && std::getline(iss, artist, ',') && (iss >> duration)) {
                addTrack(Track(name, artist, duration));
            }
            else {
                std::cout << "Error reading line from file " << filename << std::endl;
            }
        }
        file.close();
        std::cout << "Library loaded from file " << filename << std::endl;
    }

private:
    std
