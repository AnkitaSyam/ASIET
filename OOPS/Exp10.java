class ExceptionTest {

    //try-catch-finally
    static int DivTest1(int num, int den) {
        int result = 0;
        System.out.println("Numerator = "+num+ ",Denominator = "+den);

        try{
            result = num/den;
        } catch(ArithmeticException e) {
            System.out.println("Caught exception: "+e.getMessage()); 
            result = -1;
        } finally {
            System.out.println("Program Complete....");
        }
        return result;
    }

    static int DivTest2(int num, int den) throws ArithmeticException {
        return num / den;
    }

    static int DivTest3(int num, int den) {
        if (den == 0) {
            throw new ArithmeticException("Cannot divide by zero"); 
        }
        return num / den;
    }

    public static void main(String[] args) {
        // try-catch-finally
        System.out.println("\nTesting try-catch-finally");
        System.out.println("Result = "+DivTest1(5,0));

        // throws
        System.out.println("\nTesting throws");
        try{
            System.out.println("Result = "+DivTest2(5,0));
        } catch(ArithmeticException e) {
            System.out.println("Caught Exception: "+e.getMessage());
        }

        //throw
        System.out.println("\nTesting throw");
        try{
            System.out.println("Result = "+DivTest3(5,0));
        } catch(ArithmeticException e) {
            System.out.println("Caught Exception: "+e.getMessage());
        }
    }
}
        
