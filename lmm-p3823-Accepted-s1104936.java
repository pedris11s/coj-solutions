import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author mpc-tlj
 */
public class Lalal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        BigInteger fib[] = new BigInteger[107];
        fib[0] = BigInteger.ONE;
        fib[1] = BigInteger.ONE;
        
        for(int i = 2; i < 107; i++){
            BigInteger x = fib[i - 1];
            x = x.add(fib[i - 2]);
            fib[i] = x;
        }
           
        
        for(int k = 0; k < t; k++){
            int n = in.nextInt();
            n--;
            BigInteger sol = fib[n + 2].subtract(BigInteger.ONE);
            System.out.println(fib[n] + " " + sol);
        }
        
        
    }
    
}
