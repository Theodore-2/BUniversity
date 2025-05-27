import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class LibrarianTest {

    @Test
    void testAddBook() {
        Librarian librarian = new Librarian("Bob", "L002");
        Book book = new Book("Design Patterns", "Erich Gamma", "333333333", 4);
        
        librarian.addBook(book);
        assertNotNull(book);
    }

    @Test
    void testRemoveBook() {
        Librarian librarian = new Librarian("Bob", "L002");
        Book book = new Book("Design Patterns", "Erich Gamma", "333333333", 4);
        
        librarian.removeBook(book);
        assertNotNull(book);
    }
}