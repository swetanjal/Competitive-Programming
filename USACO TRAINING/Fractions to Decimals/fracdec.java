/*
ID: swetanj2
LANG: JAVA
TASK: fracdec
 */
import java.io.*;
public class fracdec
{
    public static void main(String [] args)throws IOException
    {
        //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br=new BufferedReader(new FileReader("fracdec.in"));
        PrintWriter pw=new PrintWriter(new BufferedWriter(new FileWriter("fracdec.out")));
        String S=br.readLine();
        String tokens[]=S.split(" ");
        int num=Integer.parseInt(tokens[0]);
        int den=Integer.parseInt(tokens[1]);
        String ans="";
        ans=ans+(num/den)+".";
        int dot=ans.length()-1;
        int carry=num%den;
        boolean A[]=new boolean[1000005];
        char fool[]=new char[100005];
        for(int i=0; i<=dot; i++)fool[i]=ans.charAt(i);
        int pos[]=new int[1000005];
        for(int i=0; i<100005; i++)A[i]=false;
        int c=dot+1; int lol=-1; int flag=0;
        while(true)
        {
            if(A[carry*10]){
                lol=pos[carry*10];
                flag=1;
                break;
            }
            A[carry*10]=true;
            pos[carry*10]=c;
            fool[c++]=(char)(((carry*10)/den)+48);
            //ans=ans+((carry*10)/den);
            carry=(carry*10)%den;
            if(carry==0)break;
        }
        if(flag==1)
        {
            int curr=0;
            //int l=ans.length();
            for(int i=0; i<lol; i++)
            {
                pw.append(""+fool[i]);
                curr++;
                if(curr>75){
                    pw.append("\n");
                    curr=0;
                }
            }
            pw.append("(");
            curr++;
            if(curr>75){
                    pw.append("\n");
                    curr=0;
            }
            for(int i=lol; i<c; i++)
            {
                pw.append(""+fool[i]);
                curr++;
                if(curr>75){
                    pw.append("\n");
                    curr=0;
                }
            }
            pw.append(")");
        }
        //ans=ans.substring(0,dot+1+lol)+"("+ans.substring(dot+1+lol)+")";
        else
        {
            //int l=ans.length();
            int curr=0;
            for(int i=0; i<c; i++)
            {
                pw.append(""+fool[i]);
                curr++;
                if(curr>75 && i!=c-1){
                    pw.append("\n");
                    curr=0;
                }
            }
        }
        pw.append("\n");
        pw.close();
    }
}