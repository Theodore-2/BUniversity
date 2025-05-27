import java.util.ArrayList;


class Book {
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


class Member {
    private String name;
    private String memberId;
    private ArrayList<Book> borrowedBooks;

    
    public Member(String name, String memberId) {
        this.name = name;
        this.memberId = memberId;
        this.borrowedBooks = new ArrayList<>();
    }

    
    public void borrowBook(Book book) {
        if (book.borrowBook()) {
            borrowedBooks.add(book);
            System.out.println(name + " borrowed " + book.getTitle());
        }
    }

    
    public void returnBook(Book book) {
        if (borrowedBooks.remove(book)) {
            book.returnBook();
            System.out.println(name + " returned " + book.getTitle());
        } else {
            System.out.println(name + " has not borrowed " + book.getTitle());
        }
    }

   
    public void viewBorrowedBooks() {
        System.out.println(name + "'s borrowed books:");
        for (Book book : borrowedBooks) {
            System.out.println("- " + book.getTitle());
        }
    }
}

class Librarian extends Member {

   
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

  
    public static void testLibrarianAddRemoveBook() {
        Member memberLibrarian = new Librarian("Bob", "L002");
        Book book = new Book("Design Patterns", "Erich Gamma", "333333333", 4);

        ((Librarian) memberLibrarian).addBook(book);
        ((Librarian) memberLibrarian).removeBook(book);
    }
}