import java.util.*;

public class Freckles {

    static int padre[] = new int[10005];

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n = leer.nextInt(), l = leer.nextInt(), x, y, dist, pos = 0;
        long total = 0, suma = 0;
        arista[] cola = new arista[l];
        for (int i = 0; i <= n; i++) {
            padre[i] = i;
        }
        for (int i = 0; i < l; i++) {
            x = leer.nextInt();
            y = leer.nextInt();
            dist = leer.nextInt();
            cola[i] = new arista(x, y, dist);
            total += dist;
        }
        Arrays.sort(cola);
        int lane = 0;
        while (pos < l) {
            arista aux = cola[pos];
            pos++;
            int u = find(aux.a);
            int v = find(aux.b);
            if (u != v) {
                suma += aux.peso;
                padre[u] = v;
            } else {
                lane = Math.max(lane, aux.peso);
            }
        }
        System.out.println((total - suma) + " " + lane);
    }

    public static class arista implements Comparable<arista> {

        public int a, b, peso;

        public arista(int x, int y, int peso) {
            this.a = x;
            this.b = y;
            this.peso = peso;
        }

        @Override
        public int compareTo(arista o) {
            if (this.peso > o.peso) {
                return -1;
            }
            if (this.peso < o.peso) {
                return 1;
            }
            return 0;
        }
    }

    public static int find(int x) {
        if (padre[x] != x) {
            padre[x] = find(padre[x]);
        }
        return padre[x];
    }
}
