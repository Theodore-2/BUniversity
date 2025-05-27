import java.time.Duration;
import java.time.Instant;
import java.util.Random;

public class SingleThreadedMatrixMultiplication {
    public static void main(String[] args) {
        int[][] matrixA = generateMatrix();
        int[][] matrixB = generateMatrix();
        int[][] result = new int[2][2];

        Instant start = Instant.now();
        for (int i = 0; i < 10000; i++) {
            result = multiplyMatrices(matrixA, matrixB);
        }
        Instant end = Instant.now();

        Duration duration = Duration.between(start, end);
        System.out.println("Tek iş parçacıklı süre: " + duration.toMillis() + " ms");
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

    private static int[][] multiplyMatrices(int[][] matrixA, int[][] matrixB) {
        int[][] result = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = matrixA[i][0] * matrixB[0][j] + matrixA[i][1] * matrixB[1][j];
            }
        }
        return result;
    }
}