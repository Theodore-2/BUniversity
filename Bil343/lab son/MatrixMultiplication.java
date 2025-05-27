import java.time.Duration;
import java.time.Instant;
import java.util.Random;

public class MatrixMultiplication {
    public static void main(String[] args) throws InterruptedException {
        // matris üretme
        int[][] matrixA = generateMatrix();
        int[][] matrixB = generateMatrix();

        System.out.println("Matrix A:");
        printMatrix(matrixA);

        System.out.println("Matrix B:");
        printMatrix(matrixB);

        // 2. kısım single thread
        Instant startSingle = Instant.now();
        for (int i = 0; i < 10000; i++) {
            multiplySingleThread(matrixA, matrixB);
        }
        Instant endSingle = Instant.now();
        long singleThreadDuration = Duration.between(startSingle, endSingle).toMillis();
        System.out.println("single thread süre: " + singleThreadDuration + " ms");

        // task 3 multi thread
        Instant startMulti = Instant.now();
        for (int i = 0; i < 10000; i++) {
            multiplyMultiThread(matrixA, matrixB);
        }
        Instant endMulti = Instant.now();
        long multiThreadDuration = Duration.between(startMulti, endMulti).toMillis();
        System.out.println("multi thread süre: " + multiThreadDuration + " ms");

        // 4. performans ölçücümü
        System.out.println("Performans karşılaştırması:");
        System.out.println("single süre: " + singleThreadDuration + " ms");
        System.out.println("multi süre: " + multiThreadDuration + " ms");
    }

    private static int[][] generateMatrix() {  
        Random rand = new Random();
        int[][] matrix = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                matrix[i][j] = rand.nextInt(10); 
            }
        }
        return matrix;
    }

    private static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }

    private static int[][] multiplySingleThread(int[][] matrixA, int[][] matrixB) {
        int[][] result = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = matrixA[i][0] * matrixB[0][j] + matrixA[i][1] * matrixB[1][j];
            }
        }
        return result;
    }

    private static int[][] multiplyMultiThread(int[][] matrixA, int[][] matrixB) throws InterruptedException {
        int[][] result = new int[2][2];

        Thread row1 = new Thread(() -> result[0] = computeRow(0, matrixA, matrixB));
        Thread row2 = new Thread(() -> result[1] = computeRow(1, matrixA, matrixB));

        row1.start();
        row2.start();

        row1.join();
        row2.join();

        return result;
    }

    private static int[] computeRow(int row, int[][] matrixA, int[][] matrixB) {
        int[] resultRow = new int[2];
        for (int j = 0; j < 2; j++) {
            resultRow[j] = matrixA[row][0] * matrixB[0][j] + matrixA[row][1] * matrixB[1][j];
        }
        return resultRow;
    }
}