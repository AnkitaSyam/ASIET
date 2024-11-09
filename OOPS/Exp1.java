import java.util.Scanner;

class PalindromeNumber {
    public static void main(String[] args) {
        int num; // num = 545
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        num = sc.nextInt();

        int reverse = 0; 
        int temp = num;

        while(temp > 0) {
            int remainder = temp % 10; // remainder = 545 % 10 = 5
            reverse = reverse * 10 + remainder; // reverse = 0 *10 + 5 = 5
            temp = temp/10; // assign new value to temp, temp = 54
        }
        
        if(num == reverse) {
            System.out.println(num+ " is a palindrome");
        }
        else {
            System.out.println(num+ " is not a palindrome");  
        }
    }
}
