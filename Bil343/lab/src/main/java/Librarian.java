public class Librarian extends Member { //INHERİTANCE

    public Librarian(String name, String memberId) {
        super(name, memberId);
    }

    public void addBook(Book book) {
        System.out.println("Librarian added the book: " + book.getTitle());
    }

    public void removeBook(Book book) {
        System.out.println("Librarian removed the book: " + book.getTitle());
    }
}