import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		while(T-->0)
		{
		    String tokens[]=br.readLine().split(" ");
		    int N=Integer.parseInt(tokens[0]);
		    int M=Integer.parseInt(tokens[1]);
		    String words[]=br.readLine().split(" ");
		    int L=words.length;
		    int A[][]=new int[L][26];
		    for(int i=0; i<L;i++)for(int j=0; j<26; j++)A[i][j]=0;
		    for(int i=0; i<L; i++)
		    {
		        int l=words[i].length();
		        for(int j=0; j<l ;j++)
		        A[i][words[i].charAt(j)-97]=1;
		    }
		    int a=0;
		    for(int i=1; i<L; i++)
		    {
		        for(int j=0; j<26; j++)
		        {
		            if(A[i][j]==1 && A[i-1][j]==1)
		            {
		                a++;
		                break;
		            }
		        }
		    }
		    a=L-a-1;
		    //System.out.println(a);
		    if(a<=M)System.out.println("Welcome to a world without rules");
		    else System.out.println("Very poor choice of words");
		}
	}
}