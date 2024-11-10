import java.util.Scanner;

class MatrixMultiplication {
    public static void main(String[] args) {
        int[][] a = new int[10][10];
        int[][] b = new int[10][10];
        int[][] c = new int[10][10];

        Scanner sc = new Scanner(System.in);

        System.out.println("MATRIX A");
        System.out.print("Enter the number of rows: ");
        int m = sc.nextInt();
        System.out.print("Enter the number of columns: ");
        int n = sc.nextInt();

        System.out.println("\nMATRIX B");
        System.out.print("Enter the number of rows: ");
        int p = sc.nextInt();
        System.out.print("Enter the number of columns: ");
        int q = sc.nextInt();

        if(n != p) {
            System.out.println("\nMultiplication not possible");
            return;
        }

        System.out.println("\nEnter the elemnts of Matrix A: ");
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        System.out.println("\nEnter the elemnts of Matrix B: ");
        for(int i=0; i<p; i++) {
            for(int j=0; j<q; j++) {
                b[i][j] = sc.nextInt();
            }
        }

        System.out.println("\nMATRIX A: ");
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        } 

        System.out.println("\nMATRIX B: ");
        for(int i=0; i<p; i++) {
            for(int j=0; j<q; j++) {
                System.out.print(b[i][j]+" ");
            }
            System.out.println();
        } 
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<q; j++) {
                for(int k=0; k<n; k++){
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        } 

        System.out.println("\nMATRIX C: ");
        for(int i=0; i<m; i++) {
            for(int j=0; j<q; j++) {
                System.out.print(c[i][j]+" ");
            }
            System.out.println();
        }
    }
}
