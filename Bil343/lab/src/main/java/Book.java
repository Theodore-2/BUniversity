public class Book { //ENCAPSULATİON
    private String title;
    private String author;
    private String ISBN;
    private int totalCopies;
    int availableCopies;

    public Book(String title, String author, String ISBN, int totalCopies) {
        this.title = title;
        this.author = author;
        this.ISBN = ISBN;
        this.totalCopies = totalCopies;
        this.availableCopies = totalCopies;
    }

    public boolean borrowBook() {
        if (availableCopies > 0) {
            availableCopies--;
            return true;
        } else {
            System.out.println("No copies available for " + title);
            return false;
        }
    }

    public void returnBook() {
        if (availableCopies < totalCopies) {
            availableCopies++;
        } else {
            System.out.println("All copies of " + title + " are already returned.");
        }
    }

    public String getTitle() {
        return title;
    }
}