int main() {
    MusicLibrary library;

    // Load tracks from file
    library.loadTracksFromFile("tracks.txt");

    // Search for tracks by artist
    vector<Track> results = library.searchTracksByArtist("The Beatles");
    for (int i = 0; i < results.size(); i++) {
       
