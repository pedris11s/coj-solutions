import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Anita
 */
public class COJ {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BigInteger C[] = new BigInteger[307];
        BigInteger F[] = new BigInteger[307];
        
        C[0] = BigInteger.ONE;
        F[0] = BigInteger.ONE;
        /*for(int i = 0; i < 307; i++){
            C[i] = BigInteger.ZERO;
            F[i] = BigInteger.ZERO;
        }*/
        //System.out.println(C[0]);
        for(int i = 0; i <= 302; i++){
            C[i + 1] = BigInteger.ZERO;
            for(int j = 0; j <= i; j++){
                BigInteger a = C[j].multiply(C[i - j]);
                C[i + 1] = C[i + 1].add(a);
            }
        }
        for(int i = 1; i <= 302; i++){
            BigInteger x = new BigInteger(Integer.toString(i));
            F[i] = F[i - 1].multiply(x);
        }
        
        Scanner in = new Scanner(System.in);
        
        while(true){
            int n = in.nextInt();
            if(n == 0)break;
            System.out.println(C[n].multiply(F[n]));
        }
        
    }
    
}
