class Palindrome {
    public static void main(String[] argv) {
        char[] str = {'M', 'A', 'L', 'A', 'Y', 'A', 'L', 'A', 'M'};
        int length = str.length;
        int flag = 0;
       
        System.out.println("Palindrome...");
        System.out.println("String length = " + length);
       
        for (int i = 0; i < length / 2; i++) {
            if (str[i] != str[length - 1 - i]) {
                System.out.println("It's not a palindrome");
                flag = 1;
                break;
            }
        }
       
        if (flag == 0) {
            System.out.println("It's a palindrome");
        }
    }
}

