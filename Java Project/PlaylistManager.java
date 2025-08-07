import java.awt.*;
import java.io.*;
import java.util.Random;
import javax.swing.*;

public class PlaylistManager extends JFrame {
    private DefaultListModel<Song> songListModel = new DefaultListModel<>();
    private JList<Song> songJList = new JList<>(songListModel);
    private Playlist playlist = new Playlist();

    public PlaylistManager() {
        setTitle("🎵 Playlist Manager");
        setSize(500, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JButton addButton = new JButton("Add Song");
        JButton deleteButton = new JButton("Delete Song");
        JButton shuffleButton = new JButton("Shuffle");
        JButton sortButton = new JButton("Sort");
        JButton saveButton = new JButton("Save");
        JButton loadButton = new JButton("Load");

        addButton.addActionListener(e -> addSongDialog());
        deleteButton.addActionListener(e -> {
            Song selected = songJList.getSelectedValue();
            if (selected != null) {
                playlist.removeSong(selected);
                refreshSongList();
            }
        });
        shuffleButton.addActionListener(e -> {
            playlist.shuffle();
            refreshSongList();
        });
        sortButton.addActionListener(e -> {
            playlist.sortByTitle();
            refreshSongList();
        });
        saveButton.addActionListener(e -> {
            try {
                FileManager.savePlaylist(playlist, "playlist.dat");
                JOptionPane.showMessageDialog(this, "Saved!");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Error saving!");
            }
        });
        loadButton.addActionListener(e -> {
            try {
                playlist = FileManager.loadPlaylist("playlist.dat");
                refreshSongList();
                JOptionPane.showMessageDialog(this, "Loaded!");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Error loading!");
            }
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(addButton);
        buttonPanel.add(deleteButton);
        buttonPanel.add(shuffleButton);
        buttonPanel.add(sortButton);
        buttonPanel.add(saveButton);
        buttonPanel.add(loadButton);

        add(new JScrollPane(songJList), BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    private void addSongDialog() {
        JTextField titleField = new JTextField();
        JTextField artistField = new JTextField();
        Object[] fields = {"Title:", titleField, "Artist:", artistField};

        int result = JOptionPane.showConfirmDialog(this, fields, "Add Song", JOptionPane.OK_CANCEL_OPTION);
        if (result == JOptionPane.OK_OPTION) {
            playlist.addSong(new Song(titleField.getText(), artistField.getText()));
            refreshSongList();
        }
    }

    private void refreshSongList() {
        songListModel.clear();
        for (Song song : playlist.getSongs()) {
            songListModel.addElement(song);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new PlaylistManager().setVisible(true));
    }
}

class Song implements Serializable {
    private String title, artist;

    public Song(String title, String artist) {
        this.title = title;
        this.artist = artist;
    }

    public String getTitle() { return title; }
    public String getArtist() { return artist; }

    @Override
    public String toString() {
        return title + " - " + artist;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Song)) return false;
        Song s = (Song) obj;
        return title.equalsIgnoreCase(s.title) && artist.equalsIgnoreCase(s.artist);
    }
}

class Playlist implements Serializable {
    private java.util.List<Song> songs = new java.util.ArrayList<>();

    public void addSong(Song s) {
        songs.add(s);
    }

    public void removeSong(Song s) {
        songs.remove(s);
    }

    public java.util.List<Song> getSongs() {
        return songs;
    }

    public void shuffle() {
        java.util.Collections.shuffle(songs, new Random());
    }

    public void sortByTitle() {
        songs.sort((a, b) -> a.getTitle().compareToIgnoreCase(b.getTitle()));
    }
}

class FileManager {
    public static void savePlaylist(Playlist p, String filename) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(filename))) {
            out.writeObject(p);
        }
    }

    public static Playlist loadPlaylist(String filename) throws IOException, ClassNotFoundException {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(filename))) {
            return (Playlist) in.readObject();
        }
    }
}