# Makefile
class Track {
private:
    string title;
    string artist;
    string album;
    int year;
public:
    Track(string t, string a, string al, int y) {
        title = t;
        artist = a;
        album = al;
        year = y;
    }
    string getTitle() { return title; }
    string getArtist() { return artist; }
    string getAlbum() { return album; }
    int getYear() { return year; }
};
