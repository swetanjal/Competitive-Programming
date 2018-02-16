import java.util.*;
import java.lang.*;
import java.io.*;
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String words[]=br.readLine().split(" ");
		String W[]=new String[100005];
		int L=words[0].length();
		int l=words[1].length();
		int cnt=0;
		for(int i=0; i<L; i++)
		{
		    for(int j=0; j<l; j++)
		    {
		        String X="";
		        for(int k=0; k<=i; k++)X+=words[0].charAt(k);
		        for(int k=0; k<=j; k++)X+=words[1].charAt(k);
		        W[cnt++]=X;    
		    }
		    
		}
		for(int i=0; i<cnt-1; i++)
		{
		    for(int j=0; j<cnt-1-i; j++)
		    {
		        if(W[j].compareTo(W[j+1])>0)
		        {
		            String tmp=W[j];
		            W[j]=W[j+1];
		            W[j+1]=tmp;
		        }
		    }
		}
		System.out.println(W[0]);
	}
}