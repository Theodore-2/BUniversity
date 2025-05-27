public class LibrarySystemDemo {
    public static void main(String[] args) {
        testBorrowAndReturnBook();
        testMemberBorrowBook();
        testLibrarianAddRemoveBook();
    }

    public static void testBorrowAndReturnBook() {
        Book book = new Book("Clean Code", "Robert C. Martin", "111111111", 5);
        System.out.println("Initial available copies: " + book.availableCopies);

        book.borrowBook();
        System.out.println("Available copies after borrowing: " + book.availableCopies);

        book.returnBook();
        System.out.println("Available copies after returning: " + book.availableCopies);
    }

    public static void testMemberBorrowBook() {
        Member member = new Member("Alice", "M001");
        Book book = new Book("Effective Java", "Joshua Bloch", "222222222", 3);

        member.borrowBook(book);
        member.viewBorrowedBooks();
    }

    //POLİMORFİZİM
    public static void testLibrarianAddRemoveBook() {
        Member memberLibrarian = new Librarian("Bob", "L002");
        Book book = new Book("Design Patterns", "Erich Gamma", "333333333", 4);

        ((Librarian) memberLibrarian).addBook(book);
        ((Librarian) memberLibrarian).removeBook(book);
    }
}