/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		String inp = sc.nextLine();
		String s = "";
		while(inp.equals("\\begin{thebibliography}{99}") == false)
		{
		    s = s + " " + inp;
		    inp = sc.nextLine();
		}
		//System.out.println(s);
		inp = sc.nextLine();
		String arr[] = new String[100];
		int ref = 0;
		while(inp.equals("\\end{thebibliography}") == false)
		{
		    arr[ref++] = inp;
		    inp = sc.nextLine();
		}
		String Arr[] = new String[100];
		int prev = 0;
		for(int i = 0; i < ref; ++i)
		{
		    int ind = s.indexOf("\\cite{", prev);
		    prev = ind + 1;
		    Arr[i] = s.substring(ind + 6, s.indexOf('}', ind));
		}
		int correct = 1;
		for(int i = 0; i < ref; ++i)
		{
		    //System.out.println(Arr[i] + "  " + arr[i].substring(arr[i].indexOf('{') + 1, arr[i].indexOf('}')));
		    if(Arr[i].equals(arr[i].substring(arr[i].indexOf('{') + 1, arr[i].indexOf('}'))) == false)
		    {
		        correct = 0;
		        break;
		    }
		}
		if(correct == 1)
		{
		    System.out.println("Correct");
		}
		else{
		    System.out.println("Incorrect");
		    System.out.println("\\begin{thebibliography}{99}");
		    for(int i = 0; i < ref; ++i){
		        for(int j = 0; j < ref; ++j)
		        {
		            if(Arr[i].equals(arr[j].substring(arr[j].indexOf('{') + 1, arr[j].indexOf('}'))))
		            System.out.println(arr[j]);
		        }
		    }
		    System.out.println("\\end{thebibliography}");
		}
	}
}