class Attributes {
    private String title;
    private String author;
    private long ISBN;  

    public Attributes(String title, String author, long ISBN) {
        this.title = title;
        this.author = author;
        this.ISBN = ISBN;   
    }

    void displayBook() {
        System.out.println("The Book Details are:");
        System.out.printf("Title : %s%n", title);
        System.out.printf("Author : %s%n", author);
        System.out.printf("ISBN : %d%n", ISBN);
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public long getISBN() {
        return ISBN;
    }

    @Override
    public String toString() {
        return "Book{" + "title='" + title + '\'' + ", author='" + author + '\'' +  ", ISBN=" + ISBN +  "}";
    }
}
