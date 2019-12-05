import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;


public class GUIghaksjfz {

  
    public static void main(String[] args) {
       Scanner leer= new Scanner(System.in);
       int cas=leer.nextInt();
        for (int k = 1; k <= cas; k++) {
            System.out.println("Case #"+k+":");
        
       int t=leer.nextInt();
       persona[] lista= new persona[t];
        PriorityQueue<persona> cola= new PriorityQueue<>();
        for (int i = 1; i <= t; i++) {
           lista[i-1]=new persona(leer.nextInt(),leer.nextInt(),leer.nextInt(),i);
        }
        persona aux;
        cola.add(lista[0]);
        int pos = 1;
        int time=0;
       
       while(!cola.isEmpty() || pos<t){
           if(cola.isEmpty()){
           cola.add(lista[pos]);
           pos++;
           }
           aux=cola.poll();
           time=Math.max(time,aux.t );
           time+=aux.d;
         System.out.println(aux.num+" "+time);
        
         while(pos<t && lista[pos].t<=time){
         cola.add(lista[pos]);
         pos++;
         }       
       }
        }
    }
    static class persona implements Comparable<persona>{
    int t,d,p,num;

        public persona(int t, int d, int p, int num) {
            this.t = t;
            this.d = d;
            this.p = p;
            this.num = num;
        }

        @Override
        public int compareTo(persona o) {
           if(this.p==o.p){
           return this.t-o.t;
           }else{
           return o.p-this.p;
           }
        }
        }
}
