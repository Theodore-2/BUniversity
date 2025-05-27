import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class BookTest {

    @Test
    void testBorrowBook() {
        Book book = new Book("Clean Code", "Robert C. Martin", "111111111", 5);
        assertTrue(book.borrowBook());
        assertEquals(4, book.availableCopies);
    }

    @Test
    void testBorrowBookWhenUnavailable() {
        Book book = new Book("Clean Code", "Robert C. Martin", "111111111", 1);
        book.borrowBook(); 
        assertFalse(book.borrowBook()); 
        assertEquals(0, book.availableCopies);
    }

    @Test
    void testReturnBook() {
        Book book = new Book("Clean Code", "Robert C. Martin", "111111111", 5);
        book.borrowBook(); 
        book.returnBook(); 
        assertEquals(5, book.availableCopies);
    }
}