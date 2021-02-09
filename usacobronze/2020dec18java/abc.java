import java.util.Scanner;
public class abc {
    private int max(int a, int b) {
        if (a>b) return a;
        return b;
    }
    private int min(int a, int b) {
        if (b<a) return b;
        return a;
    }
    // private int[] lowest2(int[] inp) {
        
    //     return ;
    // }
    public static void main(String[] args) {
        int inp;
        int[] low2 = new int[2];
        int highest=0;
        Scanner s=new Scanner(System.in);
        abc m=new abc();
        for (int i=0;i<7;i++) {
            int t=s.nextInt();
            highest=m.max(highest,t);
        }
        s.close();
        int[] inp=new int[2];

    }
}