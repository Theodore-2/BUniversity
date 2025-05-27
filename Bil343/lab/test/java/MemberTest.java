package test.java;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.ArrayList;

class MemberTest {

    @Test
    void testBorrowBook() {
        Book book = new Book("Effective Java", "Joshua Bloch", "222222222", 3);
        Member member = new Member("Alice", "M001");
        
        member.borrowBook(book);
        
        ArrayList<Book> borrowedBooks = new ArrayList<>();
        borrowedBooks.add(book);
        
        assertEquals(borrowedBooks.size(), 1);
        assertEquals(book.availableCopies, 2);
    }

    @Test
    void testReturnBook() {
        Book book = new Book("Effective Java", "Joshua Bloch", "222222222", 3);
        Member member = new Member("Alice", "M001");
        
        member.borrowBook(book);
        member.returnBook(book);
        
        assertEquals(book.availableCopies, 3);
    }

    @Test
    void testViewBorrowedBooks() {
        Book book1 = new Book("Clean Code", "Robert C. Martin", "111111111", 5);
        Book book2 = new Book("Effective Java", "Joshua Bloch", "222222222", 3);
        Member member = new Member("Alice", "M001");

        member.borrowBook(book1);
        member.borrowBook(book2);
        
        assertEquals(2, member.borrowedBooks.size());
        assertEquals("Clean Code", member.borrowedBooks.get(0).getTitle());
        assertEquals("Effective Java", member.borrowedBooks.get(1).getTitle());
    }
}